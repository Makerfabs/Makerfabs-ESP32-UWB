#include "dw3000.h"

#define APP_NAME "SS TWR RESP STS NO DATA v1.0"

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
static uint8_t tx_report_msg[] = {0x41, 0x88, 0, 0xCA, 0xDE, 'V', 'E', 'W', 'A', 0xE1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* Length of the common part of the frame (up to and including the function code, see NOTE 3 below). */
#define ALL_MSG_COMMON_LEN 10
/* Index to access some of the fields in the frames involved in the process. */
#define ALL_MSG_SN_IDX 2
#define REPORT_MSG_POLL_RX_TS_IDX 10
#define REPORT_MSG_RESP_TX_TS_IDX 14
/* Frame sequence number, incremented after each transmission. */
static uint8_t frame_seq_nb = 0;

/* Hold copy of status register state here for reference so that it can be examined at a debug breakpoint. */
static uint32_t status_reg = 0;

/* Delay between frames, in UWB microseconds. See NOTE 1 below. */
#define POLL_RX_TO_RESP_TX_DLY_UUS (550 + CPU_COMP)

/* Timestamps of frames transmission/reception. */
static uint64_t poll_rx_ts;
static uint64_t resp_tx_ts;

/* Hold the amount of errors that have occurred */
static uint32_t errors[23] = {0};

extern dwt_config_t config_option_sp3;
extern dwt_config_t config_option_sp0;

/* Externally declared structures for TX configuration. */
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


int16_t stsQual; /* This will contain STS quality index and status */
int goodSts = 0; /* Used for checking STS quality in received signal */
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

  /* Enabling LEDs here for debug so that for each TX the D1 LED will flash on DW3000 red eval-shield boards.
     * Note, in real low power applications the LEDs should not be used. */
    dwt_setleds(DWT_LEDS_ENABLE | DWT_LEDS_INIT_BLINK) ;

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
         * Set CP encryption key and IV (nonce).
         * See Note 11 below.
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

        /* Activate reception immediately. */
        dwt_rxenable(DWT_START_RX_IMMEDIATE);

        /* Poll for reception of a packet or error/timeout. See NOTE 5 below. */
        /* STS Mode 3 packets are polled for differently than STS Mode 0 frames */
        while (!((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) & (SYS_STATUS_RXFR_BIT_MASK | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_ND_RX_ERR)))
        { };

        /*
         * Need to check the STS has been received and is good.
         */
        goodSts = dwt_readstsquality(&stsQual);

        /*
         * At this point of the program, we are expecting the POLL packet to be received.
         * Since the POLL packet will have no PHY payload (i.e. no data in the packet), we only check
         * to see if the packet has been received correctly and the quality of the STS is good.
         * When using No Data STS mode we do not get RXFCG but RXFR
         */
        if (status_reg & SYS_STATUS_RXFR_BIT_MASK)
        {
            /*
             * Checking for the SP3 mode POLL packet
             */
            if (goodSts >= 0)
            {
                uint32_t resp_tx_time, report_tx_time;
                int ret;

                /* Retrieve poll reception timestamp. */
                poll_rx_ts = get_rx_timestamp_u64();

                /* Calculate the required delay time before sending the RESP packet. */
                resp_tx_time = (poll_rx_ts                               /* Received timestamp value */
                        + ((POLL_RX_TO_RESP_TX_DLY_UUS                   /* Set delay time */
                                + get_rx_delay_time_data_rate()          /* Added delay time for data rate set */
                                + get_rx_delay_time_txpreamble()         /* Added delay for TX preamble length */
                                + ((1<<(config_option_sp3.stsLength+2))*8)) /* Added delay for STS length */
                                * UUS_TO_DWT_TIME)) >> 8;                /* Converted to time units for chip */
                dwt_setdelayedtrxtime(resp_tx_time);

                /* Response TX timestamp is the transmission time we programmed plus the antenna delay. */
                resp_tx_ts = (((uint64_t)(resp_tx_time & 0xFFFFFFFEUL)) << 8) + TX_ANT_DLY;

                /* Send the SP3 RESP packet. */
                dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS_BIT_MASK);
                dwt_writetxfctrl(0, 0, 1); /* Zero offset in TX buffer, ranging. */
                ret = dwt_starttx(DWT_START_TX_DELAYED);

                /* If dwt_starttx() returns an error, abandon this ranging exchange and proceed to the next one. See NOTE 9 & 10 below. */
                if (ret == DWT_SUCCESS)
                {
                    /* Poll DW IC until TX packet sent event set. See NOTE 5 below. */
                    while (!(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS_BIT_MASK))
                    { };

                    /* Clear TXFRS event. */
                    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS_BIT_MASK);


                    /*
                     * Now reconfigure device to SP0 mode and send REPORT frame
                     */
                    /* Configure DW IC. See NOTE 12 below. */
                    dwt_configurestsmode(DWT_STS_MODE_OFF);

                    /* Set the delay to be twice the previous time period with respect to the RX timestamp of the POLL packet. */
                    report_tx_time = (poll_rx_ts                               /* Received timestamp value */
                            + ((((POLL_RX_TO_RESP_TX_DLY_UUS) * 2)             /* Set delay time */
                                    + (get_rx_delay_time_data_rate() * 2)    /* Added delay time for data rate set */
                                    + (get_rx_delay_time_txpreamble() * 2)   /* Added delay for TX preamble length */
                                    + (((1<<(config_option_sp3.stsLength+2))*8)) * 2) /* Added delay for STS length */
                                    * UUS_TO_DWT_TIME)) >> 8;                /* Converted to time units for chip */
                    dwt_setdelayedtrxtime(report_tx_time);

                    /* Write all timestamps in the report frame. See NOTE 6 & 7 below. */
                    resp_msg_set_ts(&tx_report_msg[REPORT_MSG_POLL_RX_TS_IDX], poll_rx_ts);
                    resp_msg_set_ts(&tx_report_msg[REPORT_MSG_RESP_TX_TS_IDX], resp_tx_ts);

                    /* Write and send the response frame. See NOTE 8 below. */
                    tx_report_msg[ALL_MSG_SN_IDX] = frame_seq_nb;

                    dwt_writetxdata(sizeof(tx_report_msg), tx_report_msg, 0); /* Zero offset in TX buffer. */
                    dwt_writetxfctrl(sizeof(tx_report_msg), 0, 0); /* Zero offset in TX buffer, not ranging. */
                    ret = dwt_starttx(DWT_START_TX_DELAYED);

                    /* If dwt_starttx() returns an error, abandon this ranging exchange and proceed to the next one. See NOTE 9 & 10 below. */
                    if (ret == DWT_SUCCESS)
                    {
                        /* Poll DW IC until TX frame sent event set. See NOTE 5 below. */
                        while (!(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS_BIT_MASK))
                        { };

                        /* Clear TXFRS event. */
                        dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS_BIT_MASK);

                        /* Increment frame sequence number after transmission of the report frame (modulo 256). */
                        frame_seq_nb++;
                    }
                }
                else
                {
                    // Delayed TX has failed - too "late"
                }
            }
            else
            {
                errors[PREAMBLE_COUNT_ERR_IDX] += 1;
                /* Clear RX error events in the DW IC status register. */
                dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
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
            /* Clear RX error events in the DW IC status register. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
        }
}

/*****************************************************************************************************************************************************
 * NOTES:
 *
 * 1. The single-sided two-way ranging scheme implemented here has to be considered carefully as the accuracy of the distance measured is highly
 *    sensitive to the clock offset error between the devices and the length of the response delay between packets. To achieve the best possible
 *    accuracy, this response delay must be kept as low as possible. In order to do so, 6.8 Mbps data rate is advised in this example and the response
 *    delay between packets is defined as low as possible. The user is referred to User Manual for more details about the single-sided two-way ranging
 *    process.
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
 * 2. The sum of the values is the TX to RX antenna delay, experimentally determined by a calibration process. Here we use a hard coded typical value
 *    but, in a real application, each device should have its own antenna delay properly calibrated to get the best possible precision when performing
 *    range measurements.
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
 * 5. We use polled mode of operation here to keep the example as simple as possible but all status events can be used to generate interrupts. Please
 *    refer to DW IC User Manual for more details on "interrupts". It is also to be noted that STATUS register is 5 bytes long but, as the event we
 *    use are all in the first bytes of the register, we can use the simple dwt_read32bitreg() API call to access it instead of reading the whole 5
 *    bytes.
 * 6. As we want to send final TX timestamp in the final frame, we have to compute it in advance instead of relying on the reading of DW IC
 *    register. Timestamps and delayed transmission time are both expressed in device time units so we just have to add the desired response delay to
 *    response RX timestamp to get final transmission time. The delayed transmission time resolution is 512 device time units which means that the
 *    lower 9 bits of the obtained value must be zeroed. This also allows to encode the 40-bit value in a 32-bit words by shifting the all-zero lower
 *    8 bits.
 * 7. In this operation, the high order byte of each 40-bit timestamps is discarded. This is acceptable as those time-stamps are not separated by
 *    more than 2**32 device time units (which is around 67 ms) which means that the calculation of the round-trip delays (needed in the
 *    time-of-flight computation) can be handled by a 32-bit subtraction.
 * 8. dwt_writetxdata() takes the full size of the frame as a parameter but only copies (size - 2) bytes as the check-sum at the end of the frame is
 *    automatically appended by the DW IC. This means that our variable could be two bytes shorter without losing any data (but the sizeof would not
 *    work anymore then as we would still have to indicate the full length of the frame to dwt_writetxdata()).
 * 9. When running this example on the DW3000 platform with the POLL_RX_TO_RESP_TX_DLY response delay provided, the dwt_starttx() is always
 *     successful. However, in cases where the delay is too short (or something else interrupts the code flow), then the dwt_starttx() might be issued
 *     too late for the configured start time. The code below provides an example of how to handle this condition: In this case it abandons the
 *     ranging exchange and simply goes back to awaiting another poll packet. If this error handling code was not here, a late dwt_starttx() would
 *     result in the code flow getting stuck waiting subsequent RX event that will will never come. The companion "initiator" example (ex_06a) should
 *     timeout from awaiting the "response" and proceed to send another poll in due course to initiate another ranging exchange.
 * 10. The user is referred to DecaRanging ARM application (distributed with DW3000 product) for additional practical example of usage, and to the
 *     DW IC API Guide for more details on the DW IC driver functions.
 * 11. This example will set the STS key and IV upon each iteration of the main while loop. While this has the benefit of keeping the STS count in
 *     sync with the responder device (which does the same), it should be noted that this is not a 'secure' implementation as the count is reset upon
 *     each iteration of the loop. An attacker could potentially recognise this pattern if the signal was being monitored. While it serves it's
 *     purpose in this simple example, it should not be utilised in any final solution.
 * 12. Desired configuration by user may be different to the current programmed configuration. dwt_configure is called to set desired
 *     configuration.
 ****************************************************************************************************************************************************/
