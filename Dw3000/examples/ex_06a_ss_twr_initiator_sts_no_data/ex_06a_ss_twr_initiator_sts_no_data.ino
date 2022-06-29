#include "dw3000.h"

#define APP_NAME "SS TWR INIT STS NO DATA v1.0"

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4; // spi select pin

/* Inter-ranging delay period, in milliseconds. */
#define RNG_DELAY_MS 1000

/* Default antenna delay values for 64 MHz PRF. See NOTE 2 below. */
#define TX_ANT_DLY 16385
#define RX_ANT_DLY 16385

/* Frames used in the ranging process. See NOTE 3 below. */
static uint8_t rx_report_msg[] = {0x41, 0x88, 0, 0xCA, 0xDE, 'V', 'E', 'W', 'A', 0xE1, 0, 0, 0, 0, 0, 0};

/* Length of the common part of the frame (up to and including the function code, see NOTE 3 below). */
#define ALL_MSG_COMMON_LEN 10
/* Indexes to access some of the fields in the frames defined above. */
#define ALL_MSG_SN_IDX 2
#define REPORT_MSG_POLL_RX_TS_IDX 10
#define REPORT_MSG_RESP_TX_TS_IDX 14
#define REPORT_MSG_TS_LEN 4

/* Buffer to store received response frame.
 * Its size is adjusted to longest frame that this example code is supposed to handle. */
#define RX_BUF_LEN 24
static uint8_t rx_buffer[RX_BUF_LEN];

/* Hold copy of status register state here for reference so that it can be examined at a debug breakpoint. */
static uint32_t status_reg = 0;

/* Delay between frames, in UWB microseconds. See NOTE 1 below. */
#define POLL_TX_TO_RESP_RX_DLY_UUS (450 + CPU_COMP)
#define POLL_TX_TO_REPORT_RX_DLY_UUS (650 + CPU_COMP)
/* Receive response timeout. See NOTE 5 below. */
#define RESP_RX_TIMEOUT_UUS 1000

/* Hold copies of computed time of flight and distance here for reference so that it can be examined at a debug breakpoint. */
static double tof;
static double distance;

/* Hold the amount of errors that have occurred */
static uint32_t errors[23] = {0};

extern dwt_config_t config_option_sp3;
extern dwt_config_t config_option_sp0;

extern dwt_txconfig_t txconfig_options;
extern dwt_txconfig_t txconfig_options_ch9;

/*
 * 128-bit STS key to be programmed into CP_KEY register.
 *
 * This key needs to be known and programmed the same at both units performing the SS-TWR.
 * In a real application for security this would be private and unique to the two communicating units
 * and chosen/assigned in a secure manner lasting just for the period of their association.
 *
 * Here we use a default KEY as specified in the IEEE 802.15.4z annex
 */
static dwt_sts_cp_key_t cp_key =
{
        0x14EB220F,0xF86050A8,0xD1D336AA,0x14148674
};

/*
 * 128-bit initial value for the nonce to be programmed into the CP_IV register.
 *
 * The IV, like the key, needs to be known and programmed the same at both units performing the SS-TWR.
 * It can be considered as an extension of the KEY. The low 32 bits of the IV is the counter.
 * In a real application for any particular key the value of the IV including the count should not be reused,
 * i.e. if the counter value wraps the upper 96-bits of the IV should be changed, e.g. incremented.
 *
 * Here we use a default IV as specified in the IEEE 802.15.4z annex
 */
static dwt_sts_cp_iv_t cp_iv =
{
        0x1F9A3DE4,0xD37EC3CA,0xC44FA8FB,0x362EEB34
};

/*
 * The 'poll' packet initiating the ranging exchange includes a 32-bit counter which is part
 * of the IV used to generate the scrambled timestamp sequence (STS) in the transmitted packet.
 */
static void send_tx_poll_msg(void)
{
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS_BIT_MASK);
    dwt_writetxfctrl(0, 0, 1); /* Zero offset in TX buffer, ranging. */
    /* Start transmission. */
    dwt_starttx(DWT_START_TX_IMMEDIATE);

    /* Poll DW IC until TX frame sent event set. See NOTE 7 below. */
    while (!(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS_BIT_MASK))
    { };

    /* Clear TXFRS, TXFRB & TXPRS events. */
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS_BIT_MASK | SYS_STATUS_TXFRB_BIT_MASK | SYS_STATUS_TXPRS_BIT_MASK);
}


int16_t stsQual; /* This will contain STS quality index and status */
int goodSts = 0; /* Used for checking STS quality in received signal */
uint32_t poll_tx_ts, resp_rx_ts, poll_rx_ts, resp_tx_ts;
int32_t rtd_init, rtd_resp;
float clockOffsetRatio;
uint8_t firstLoopFlag = 0;


void setup() {
  UART_init();
  test_run_info((unsigned char *)APP_NAME);

  /* Configure SPI rate, DW3000 supports up to 38 MHz */
  /* Reset DW IC */
  spiBegin(PIN_IRQ, PIN_RST);
  spiSelect(PIN_SS);

  delay(2); // Time needed for DW3000 to start up (transition from INIT_RC to IDLE_RC, or could wait for SPIRDY event)

  while (!dwt_checkidlerc()) // Need to make sure DW IC is in IDLE_RC before proceeding 
  {
    UART_puts("IDLE FAILED\r\n");
    while (1) ;
  }

  if (dwt_initialise(DWT_DW_INIT) == DWT_ERROR)
  {
    UART_puts("INIT FAILED\r\n");
    while (1) ;
  }

  // Enabling LEDs here for debug so that for each TX the D1 LED will flash on DW3000 red eval-shield boards.
  dwt_setleds(DWT_LEDS_ENABLE | DWT_LEDS_INIT_BLINK);

  /* Apply default antenna delay value. See NOTE 2 below. */
    dwt_setrxantennadelay(RX_ANT_DLY);
    dwt_settxantennadelay(TX_ANT_DLY);

  /* Next can enable TX/RX states output on GPIOs 5 and 6 to help diagnostics, and also TX/RX LEDs */
    dwt_setlnapamode(DWT_LNA_ENABLE | DWT_PA_ENABLE);

    /* Configure DW IC. See NOTE 12 below. */
    if(dwt_configure(&config_option_sp3)) /* if the dwt_configure returns DWT_ERROR either the PLL or RX calibration has failed the host should reset the device */
    {
        test_run_info((unsigned char *)"CONFIG FAILED     ");
        while (1)
        { };
    }

    /* Configure the TX spectrum parameters (power, PG delay and PG count) */
    if(config_option_sp3.chan == 5)
    {
        dwt_configuretxrf(&txconfig_options);
    }
    else
    {
        dwt_configuretxrf(&txconfig_options_ch9);
    }
}

void loop() {
        dwt_configurestsmode(DWT_STS_MODE_ND);
        /*
         * Set STS encryption key and IV (nonce).
         * See NOTE 11 below.
         */
        if (!firstLoopFlag)
        {
            /*
             * On first loop, configure the STS key & IV, then load them.
             */
            dwt_configurestskey(&cp_key);
            dwt_configurestsiv(&cp_iv);
            dwt_configurestsloadiv();
            firstLoopFlag = 1;
        }
        else
        {
            /*
             * On subsequent loops, we only need to reload the lower 32 bits of STS IV.
             */
            dwt_writetodevice(STS_IV0_ID, 0, 4, (uint8_t *)&cp_iv);
            dwt_configurestsloadiv();
        }

        /*
         * Send the poll packet to the responder.
         */
        send_tx_poll_msg();

        /* Set expected response's timeout. See NOTE 1 and 5 below. */
        set_resp_rx_timeout(RESP_RX_TIMEOUT_UUS, &config_option_sp3);

        /*
         * Set a reference time for the RX to start after TX timestamp.
         * See NOTE 10 below.
         */
        set_delayed_rx_time(POLL_TX_TO_RESP_RX_DLY_UUS, &config_option_sp3);

        /* Activate reception a set time period after the TX timestamp for the POLL packet. */
        dwt_rxenable(DWT_START_RX_DLY_TS);

        /* We assume that the transmission is achieved correctly, poll for reception of a packet or error/timeout. See NOTE 7 below. */
        /* STS Mode 3 packets are polled for differently than STS Mode 0 frames */
        while (!((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) & (SYS_STATUS_RXFR_BIT_MASK | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_ND_RX_ERR)))
        { };

        /*
         * Need to check the STS has been received and is good.
         */
        goodSts = dwt_readstsquality(&stsQual);

        /*
         * Here we are checking for a good packet, a good preamble count and good STS quality.
         * When using No Data STS mode we do not get RXFCG but RXFR.
         */
        if (status_reg & SYS_STATUS_RXFR_BIT_MASK)
        {
            /* Clear the RX events. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_GOOD);
            /*
             * Checking for the SP3 mode RESP packet with good STS
             */
            if (goodSts >= 0)
            {
                /* Retrieve poll transmission and response reception timestamps. See NOTE 8 below. */
                poll_tx_ts = dwt_readtxtimestamplo32();
                resp_rx_ts = dwt_readrxtimestamplo32();

                /* Configure DW IC. See NOTE 2 below. */
                dwt_configurestsmode(DWT_STS_MODE_OFF);

                /*
                 * Set a reference time for the RX to start after TX timestamp.
                 * See NOTE 10 below.
                 * Also, since this is the second receiver enable delay that is set with reference to the last received TX timestamp,
                 * we add ~1000us to the delay to account for the time taken turning on the receiver for the RESP message and
                 * reconfiguring the device before receiving the STS Mode 3 packet.
                 */
                set_delayed_rx_time(POLL_TX_TO_RESP_RX_DLY_UUS + POLL_TX_TO_REPORT_RX_DLY_UUS, &config_option_sp0);

                dwt_rxenable(DWT_START_RX_DLY_TS);

                /*
                 * Now wait for REPORT frame
                 */
                /* We assume that the transmission is achieved correctly, poll for reception of a frame or error/timeout. See NOTE 7 below. */
                while (!((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) & (SYS_STATUS_RXFCG_BIT_MASK | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR)))
                { };

                if (status_reg & SYS_STATUS_RXFCG_BIT_MASK)
                {
                    uint32_t frame_len;

                    /* Clear the RX events. */
                    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_GOOD);

                    /* A frame has been received, read it into the local buffer. */
                    frame_len = dwt_read32bitreg(RX_FINFO_ID) & RXFLEN_MASK;
                    if ((frame_len <= sizeof(rx_buffer)) && (frame_len != 0))
                    {
                        dwt_readrxdata(rx_buffer, frame_len, 0);

                        /* Check that the frame is the expected response from the companion "SS TWR responder" example.
                         * As the sequence number field of the frame is not relevant, it is cleared to simplify the validation of the frame. */
                        rx_buffer[ALL_MSG_SN_IDX] = 0;
                        if (memcmp(rx_buffer, rx_report_msg, ALL_MSG_COMMON_LEN) == 0)
                        {
                            /* Read carrier integrator value and calculate clock offset ratio. See NOTE 9 below. */
                            clockOffsetRatio = ((float)dwt_readclockoffset()) / (uint32_t)(1<<26);

                            /* Get timestamps embedded in response frame. */
                            resp_msg_get_ts(&rx_buffer[REPORT_MSG_POLL_RX_TS_IDX], &poll_rx_ts);
                            resp_msg_get_ts(&rx_buffer[REPORT_MSG_RESP_TX_TS_IDX], &resp_tx_ts);

                            /* Compute time of flight and distance, using clock offset ratio to correct for differing local and remote clock rates */
                            rtd_init = resp_rx_ts - poll_tx_ts;
                            rtd_resp = resp_tx_ts - poll_rx_ts;

                            tof = ((rtd_init - rtd_resp * (1 - clockOffsetRatio)) / 2.0) * DWT_TIME_UNITS;
                            distance = tof * SPEED_OF_LIGHT;

                            /* Display computed distance on LCD. */
                            snprintf(dist_str, sizeof(dist_str), "DIST: %3.2f m", distance);
                            test_run_info((unsigned char *)dist_str);
                        }
                        else
                        {
                            errors[BAD_FRAME_ERR_IDX] += 1;
                        }
                    }
                    else
                    {
                        errors[RTO_ERR_IDX] += 1;
                    }
                }
                else
                {
                    check_for_status_errors(status_reg, errors);
                }
            }
            else
            {
                errors[PREAMBLE_COUNT_ERR_IDX] += 1;
            }
        }
        else
        {
            check_for_status_errors(status_reg, errors);

            if (goodSts < 0)
            {
                errors[PREAMBLE_COUNT_ERR_IDX] += 1;
            }
            if (stsQual <= 0)
            {
                errors[CP_QUAL_ERR_IDX] += 1;
            }
        }

        /* Clear RX error/timeout events in the DW IC status register. */
        dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_GOOD | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);

        /* Execute a delay between ranging exchanges. */
        Sleep(RNG_DELAY_MS);
}
/*****************************************************************************************************************************************************
 * NOTES:
 *
 * 1. The single-sided two-way ranging scheme implemented here has to be considered carefully as the accuracy of the distance measured is highly
 *    sensitive to the clock offset error between the devices and the length of the response delay between packets. To achieve the best possible
 *    accuracy, this response delay must be kept as low as possible. In order to do so, 6.8 Mbps data rate is used in this example and the response
 *    delay between packets is defined as low as possible. The user is referred to User Manual for more details about the single-sided two-way ranging
 *    process.  NB:SEE ALSO NOTE 9.
 *
 *    Initiator: |Poll TX| ..... |Resp RX|
 *    Responder: |Poll RX| ..... |Resp TX|
 *                   ^|P RMARKER|                    - time of Poll TX/RX
 *                                   ^|R RMARKER|    - time of Resp TX/RX
 *
 *                       <--TDLY->                   - POLL_TX_TO_RESP_RX_DLY_UUS (RDLY-RLEN)
 *                               <-RLEN->            - RESP_RX_TIMEOUT_UUS   (length of response packet)
 *                    <----RDLY------>               - POLL_RX_TO_RESP_TX_DLY_UUS (depends on how quickly responder can turn around and reply)
 *
 *
 * 2. The sum of the values is the TX to RX antenna delay, this should be experimentally determined by a calibration process. Here we use a hard coded
 *    value (expected to be a little low so a positive error will be seen on the resultant distance estimate). For a real production application, each
 *    device should have its own antenna delay properly calibrated to get good precision when performing range measurements.
 * 3. The frames used here are Decawave specific frames, complying with the IEEE 802.15.4 standard data frame encoding. The frames are the
 *    following:
 *     - a report frame sent by the responder to complete the exchange and provide all information needed by the initiator to compute the
 *       time-of-flight (distance) estimate.
 *    The first 10 bytes of those frames are common and are composed of the following fields:
 *     - byte 0/1: frame control (0x8841 to indicate a data frame using 16-bit addressing).
 *     - byte 2: sequence number, incremented for each new frame.
 *     - byte 3/4: PAN ID (0xDECA).
 *     - byte 5/6: destination address, see NOTE 4 below.
 *     - byte 7/8: source address, see NOTE 4 below.
 *     - byte 9: function code (specific values to indicate which frame it is in the ranging process).
 *    The remaining bytes are specific to each frame as follows:
 *    Report frame:
 *     - byte 10 -> 13: poll frame reception timestamp.
 *     - byte 14 -> 17: response frame transmission timestamp.
 *    All frames (apart from the STS Mode 3 packets) end with a 2-byte checksum automatically set by DW IC.
 * 4. Source and destination addresses are hard coded constants in this example to keep it simple but for a real product every device should have a
 *    unique ID. Here, 16-bit addressing is used to keep the frames as short as possible but, in an actual application, this should be done only
 *    after an exchange of specific frames used to define those short addresses for each device participating to the ranging exchange.
 * 5. This timeout is for complete reception of a packet, i.e. timeout duration must take into account the length of the expected packet. Here the value
 *    is arbitrary but chosen large enough to make sure that there is enough time to receive the complete response packet sent by the responder at the
 *    6.8M data rate used (around 200 �s).
 * 6. In a real application, for optimum performance within regulatory limits, it may be necessary to set TX pulse bandwidth and TX power, (using
 *    the dwt_configuretxrf API call) to per device calibrated values saved in the target system or the DW IC OTP memory.
 * 7. We use polled mode of operation here to keep the example as simple as possible but all status events can be used to generate interrupts. Please
 *    refer to DW IC User Manual for more details on "interrupts". It is also to be noted that STATUS register is 5 bytes long but, as the event we
 *    use are all in the first bytes of the register, we can use the simple dwt_read32bitreg() API call to access it instead of reading the whole 5
 *    bytes.
 * 8. The high order byte of each 40-bit time-stamps is discarded here. This is acceptable as, on each device, those time-stamps are not separated by
 *    more than 2**32 device time units (which is around 67 ms) which means that the calculation of the round-trip delays can be handled by a 32-bit
 *    subtraction.
 * 9. The use of the clock offset value to correct the TOF calculation, significantly improves the result of the SS-TWR where the remote
 *     responder unit's clock is a number of PPM offset from the local initiator unit's clock.
 *     As stated in NOTE 2 a fixed offset in range will be seen unless the antenna delay is calibrated and set correctly.
 * 10. The receiver is enabled with reference to the timestamp of the previously received signal.
 *    The receiver will start after a defined delay.
 *    This defined delay is currently the same as the delay between the responder's received
 *    timestamp of it's last received packet and the timestamp of the transmitted signal that is
 *    sent in response.
 *    This means that the initiator needs to reduce it's delay by the configured preamble length.
 *    This allows for the receiver to enable on the initiator at the same time as responder is
 *    transmitting it's packet. It should look something like this:
 *
 *    Initiator: |Poll TX| ..... |Resp RX|
 *    Responder: |Poll RX| ..... |Resp TX|
 *                   ^|P RMARKER|                    - time of Poll TX/RX
 *                                   ^|R RMARKER|    - time of Resp TX/RX
 *                    <--------->                    - POLL_TX_TO_RESP_RX_DLY_UUS - Preamble Length
 *                    <-------------->               - POLL_RX_TO_RESP_TX_DLY_UUS (depends on how quickly responder can turn around and reply)
 * 11. This example will set the STS key and IV upon each iteration of the main while loop. While this has the benefit of keeping the STS count in
 *     sync with the responder device (which does the same), it should be noted that this is not a 'secure' implementation as the count is reset upon
 *     each iteration of the loop. An attacker could potentially recognise this pattern if the signal was being monitored. While it serves it's
 *     purpose in this simple example, it should not be utilised in any final solution.
 * 12. Desired configuration by user may be different to the current programmed configuration. dwt_configure is called to set desired
 *     configuration.
 ****************************************************************************************************************************************************/
