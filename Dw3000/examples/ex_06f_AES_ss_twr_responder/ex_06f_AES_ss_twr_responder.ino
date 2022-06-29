#include "dw3000.h"
#include "dw3000_mac_802_15_4.h"

#define APP_NAME "SS TWR AES RESP v1.0"

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4; // spi select pin

/* This SS-TWR example will use sample MAC data frame format as defined by mac_frame_802_15_4_format_t structure */
mac_frame_802_15_4_format_t     mac_frame;

#if 0
static dwt_aes_config_t aes_config=
{
    .key_load           = AES_KEY_Load,         // load the key into the AES engine see Note 14 below
    .key_size           = AES_KEY_128bit,       // use 128bit key
    .key_src            = AES_KEY_Src_Register, // the key source is IC registers
    .aes_core_type      = AES_core_type_CCM,    // Use CCM core
    .aes_key_otp_type   = AES_key_RAM,
    .key_addr           = 0
}; 
#endif 

static dwt_aes_config_t aes_config= {
  AES_key_RAM,
  AES_core_type_CCM,
  MIC_0,
  AES_KEY_Src_Register,
  AES_KEY_Load,
  0,
  AES_KEY_128bit,
  AES_Encrypt
};

#define SRC_ADDR        0x1122334455667788 /* this is the address of the initiator */
#define DEST_ADDR       0x8877665544332211 /* this is the address of the responder */
#define DEST_PAN_ID     0x4321             /* this is the PAN ID used in this example */

/* Default communication configuration. We use default non-STS DW mode. */
static dwt_config_t config =
{
    5,               /* Channel number. */
    DWT_PLEN_128,    /* Preamble length. Used in TX only. */
    DWT_PAC8,        /* Preamble acquisition chunk size. Used in RX only. */
    9,               /* TX preamble code. Used in TX only. */
    9,               /* RX preamble code. Used in RX only. */
    1,               /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,      /* Data rate. */
    DWT_PHRMODE_STD, /* PHY header mode. */
    DWT_PHRRATE_STD, /* PHY header rate. */
    (129 + 8 - 8),   /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_OFF, /* STS disabled */
    DWT_STS_LEN_64,/* STS length see allowed values in Enum dwt_sts_lengths_e */
    DWT_PDOA_M0      /* PDOA mode off */
};

/* Default antenna delay values for 64 MHz PRF. See NOTE 2 below. */
#define TX_ANT_DLY 16385
#define RX_ANT_DLY 16385

/* Optional keys according to the key index - In AUX security header*/
static dwt_aes_key_t    keys_options[NUM_OF_KEY_OPTIONS]=
{
    {0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x11223344, 0x55667788, 0x99AABBCC, 0xDDEEFF00, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0xFFEEDDCC, 0xBBAA9988, 0x77665544, 0x33221100, 0x00000000, 0x00000000, 0x00000000, 0x00000000}
};

/* MAC payload data of the frames used in the ranging process. See NOTE 3 below. */
/* Poll message from the initiator to the responder */
static uint8_t rx_poll_msg[] = {'P','o','l','l',' ','m','e','s','s','a','g','e'};
/* Response message to the initiator. The first 8 bytes are used for Poll RX time and Response TX time.*/
static uint8_t tx_resp_msg[] = {0,0,0,0,0,0,0,0,'R','e','s','p','o','n','s','e'};

/* Index to access some of the fields in the frames involved in the process. */
#define ALL_MSG_SN_IDX 2            //sequence number byte index in MHR
#define RESP_MSG_POLL_RX_TS_IDX 0   //index in the MAC payload for Poll RX time
#define RESP_MSG_RESP_TX_TS_IDX 4   //index in the MAC payload for Response TX time
#define RESP_MSG_TS_LEN 4

/* Buffer to store received response message.
 * Its size is adjusted to longest frame that this example code can handle. */
#define RX_BUF_LEN 127 /* The received frame cannot be bigger than 127 if STD PHR mode is used */
static uint8_t rx_buffer[RX_BUF_LEN];

/* Note, the key index of 0 is forbidden to send as key index. Thus index 1 is the first.
 * This example uses this index for the key table for the encryption of responder's data */
#define RESPONDER_KEY_INDEX     2

/* Delay between frames, in UWB microseconds. See NOTE 1 below.
 * this includes the poll frame length ~ 240 us*/
#define POLL_RX_TO_RESP_TX_DLY_UUS 2000

/* Timestamps of frames transmission/reception. */
static uint64_t poll_rx_ts;
static uint64_t resp_tx_ts;

/* Values for the PG_DELAY and TX_POWER registers reflect the bandwidth and power of the spectrum at the current
 * temperature. These values can be calibrated prior to taking reference measurements. See NOTE 5 below. */
extern dwt_txconfig_t txconfig_options;

dwt_aes_job_t   aes_job_rx,aes_job_tx;
int8_t          status;
uint32_t          status_reg;

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

    /* Configure DW IC. See NOTE 13 below. */
    if(dwt_configure(&config)) /* if the dwt_configure returns DWT_ERROR either the PLL or RX calibration has failed the host should reset the device */
    {
        test_run_info((unsigned char *)"CONFIG FAILED     ");
        while (1)
        { };
    }

    /* Configure the TX spectrum parameters (power, PG delay and PG count) */
    dwt_configuretxrf(&txconfig_options);

    /* Apply default antenna delay value. See NOTE 2 below. */
    dwt_setrxantennadelay(RX_ANT_DLY);
    dwt_settxantennadelay(TX_ANT_DLY);

    /* Next can enable TX/RX states output on GPIOs 5 and 6 to help debug, and also TX/RX LEDs
     * Note, in real low power applications the LEDs should not be used. */
    dwt_setlnapamode(DWT_LNA_ENABLE | DWT_PA_ENABLE);


    /*Configure the TX and RX AES jobs, the TX job is used to encrypt the Response message,
     * the RX job is used to decrypt the Poll message */
    aes_job_rx.mode        = AES_Decrypt;           /* Mode is set to decryption */
    aes_job_rx.src_port    = AES_Src_Rx_buf_0;      /* Take encrypted frame from the RX buffer */
    aes_job_rx.dst_port    = AES_Dst_Rx_buf_0;      /* Decrypt the frame to the same RX buffer : this will destroy original RX frame */
    aes_job_rx.header_len  = MAC_FRAME_HEADER_SIZE(&mac_frame);  /* Set the header length (mac_frame contains the MAC header) */
    aes_job_rx.header      = (uint8_t *)MHR_802_15_4_PTR(&mac_frame);/* Set the pointer to plain-text header which will not be encrypted */
    aes_job_rx.payload     = rx_buffer;                             /* the decrypted RX MAC frame payload will be read out of IC into this buffer */

    aes_job_tx.mode        = AES_Encrypt;     /* this is encyption job */
    aes_job_tx.src_port    = AES_Src_Tx_buf;  /* dwt_do_aes will take plain text to the TX buffer */
    aes_job_tx.dst_port    = AES_Dst_Tx_buf;  /* dwt_do_aes will replace the original plain text TX buffer with encrypted one */
    aes_job_tx.header_len  = aes_job_rx.header_len;
    aes_job_tx.header      = aes_job_rx.header;/* plain-text header which will not be encrypted */
    aes_job_tx.payload     = tx_resp_msg;      /* payload to be sent */
    aes_job_tx.payload_len = sizeof(tx_resp_msg); /* payload length */
}

void loop() {
        /* Activate reception immediately. */
        dwt_rxenable(DWT_START_RX_IMMEDIATE);

        /* Poll for reception of a frame or error/timeout. See NOTE 6 below. */
        while (!((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) & (SYS_STATUS_RXFCG_BIT_MASK | SYS_STATUS_ALL_RX_ERR)))
        { };

        /* Once a frame has been received read the payload and decrypt*/
        if (status_reg & SYS_STATUS_RXFCG_BIT_MASK)
        {
            uint32_t frame_len;

            /* Clear good RX frame event in the DW IC status register. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG_BIT_MASK);

            /* Read data length that was received */
            frame_len = dwt_read32bitreg(RX_FINFO_ID)&RXFLEN_MASK;

            /* A frame has been received: firstly need to read the MHR and check this frame is what we expect:
             * the destination address should match our source address (frame filtering can be configured for this check,
             * however that is not part of this example); then the header needs to have security enabled.
             * If any of these checks fail the rx_aes_802_15_4 will return an error
             * */
            aes_config.mode=AES_Decrypt; /* configure for decryption*/
            PAYLOAD_PTR_802_15_4(&mac_frame)=rx_buffer; /* Set the MAC frame structure payload pointer
                                                             (this will contain decrypted data if status below is AES_RES_OK) */

            status=rx_aes_802_15_4(&mac_frame, frame_len, &aes_job_rx, sizeof(rx_buffer), keys_options, DEST_ADDR, SRC_ADDR, &aes_config);
            if (status!=AES_RES_OK)
            {
                /* report any errors */
                do {
                switch (status)
                {
                    case AES_RES_ERROR_LENGTH:
                        test_run_info((unsigned char *)"AES length error");
                        break;
                    case AES_RES_ERROR:
                        test_run_info((unsigned char *)"ERROR AES");
                        break;
                    case AES_RES_ERROR_FRAME:
                        test_run_info((unsigned char *)"Error Frame");
                        break;
                    case AES_RES_ERROR_IGNORE_FRAME:
                        test_run_info((unsigned char *)"Frame not for us");
                        continue;//Got frame with wrong destination address
                }
                } while (1);
            }

            /* Check that the payload of the MAC frame matches the expected poll message
             * as should be sent by "SS TWR AES initiator" example. */
            if (memcmp(rx_buffer, rx_poll_msg, aes_job_rx.payload_len) == 0)
            {
                uint32_t          resp_tx_time;
                int             ret;
                uint8_t         nonce[13];

                /* Retrieve poll reception timestamp. */
                poll_rx_ts = get_rx_timestamp_u64();

                /* Compute response message transmission time. See NOTE 7 below. */
                resp_tx_time = (poll_rx_ts + (POLL_RX_TO_RESP_TX_DLY_UUS * UUS_TO_DWT_TIME)) >> 8;
                dwt_setdelayedtrxtime(resp_tx_time);

                /* Response TX timestamp is the transmission time we programmed plus the antenna delay. */
                resp_tx_ts = (((uint64_t)(resp_tx_time & 0xFFFFFFFEUL)) << 8) + TX_ANT_DLY;

                /* Write all timestamps in the final message. See NOTE 8 below. */
                resp_msg_set_ts(&tx_resp_msg[RESP_MSG_POLL_RX_TS_IDX], poll_rx_ts);
                resp_msg_set_ts(&tx_resp_msg[RESP_MSG_RESP_TX_TS_IDX], resp_tx_ts);

                /* Now need to encrypt the frame before transmitting*/

                /* Program the correct key to be used */
                dwt_set_keyreg_128(&keys_options[RESPONDER_KEY_INDEX-1]);
                /* Set the key index for the frame */
                MAC_FRAME_AUX_KEY_IDENTIFY_802_15_4(&mac_frame)=RESPONDER_KEY_INDEX;

                /* Increment the sequence number */
                MAC_FRAME_SEQ_NUM_802_15_4(&mac_frame)++;

                /* Update the frame count */
                mac_frame_update_aux_frame_cnt(&mac_frame,mac_frame_get_aux_frame_cnt(&mac_frame)+1);

                /* Configure the AES job */
                aes_job_tx.mic_size = mac_frame_get_aux_mic_size(&mac_frame);
                aes_job_tx.nonce    = nonce; /* set below once MHR is set*/
                aes_config.mode = AES_Encrypt;
                aes_config.mic  = dwt_mic_size_from_bytes(aes_job_tx.mic_size);
                dwt_configure_aes(&aes_config);

                /* Update the MHR (reusing the received MHR, thus need to swap SRC/DEST addresses */
                mac_frame_set_pan_ids_and_addresses_802_15_4(&mac_frame, DEST_PAN_ID, DEST_ADDR, SRC_ADDR);

                /* construct the nonce from the MHR */
                mac_frame_get_nonce(&mac_frame,nonce);

                /* perform the encryption, the TX buffer will contain a full MAC frame with encrypted payload*/
                status=dwt_do_aes(&aes_job_tx,aes_config.aes_core_type);
                if (status<0)
                {
                    test_run_info((unsigned char *)"AES length error");
                    while (1);/* Error */
                }
                else if (status & AES_ERRORS)
                {
                    test_run_info((unsigned char *)"ERROR AES");
                    while (1);/* Error */
                }

                /* configure the frame control and start transmission */
                dwt_writetxfctrl(aes_job_tx.header_len + aes_job_tx.payload_len + aes_job_tx.mic_size + FCS_LEN, 0, 1); /* Zero offset in TX buffer, ranging. */
                ret = dwt_starttx(DWT_START_TX_DELAYED);

                /* If dwt_starttx() returns an error, abandon this ranging exchange and proceed to the next one. See NOTE 10 below. */
                if (ret == DWT_SUCCESS)
                {
                    /* Poll DW IC until TX frame sent event set. See NOTE 6 below. */
                    while (!(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS_BIT_MASK))
                    { };

                    /* Clear TXFRS event. */
                    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS_BIT_MASK);
                }
            }
        }
        else
        {
            /* Clear RX error events in the DW IC status register. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
        }
}

/*****************************************************************************************************************************************************
 * NOTES:
 *
 * 1. The single-sided two-way ranging scheme implemented here has to be considered carefully as the accuracy of the distance measured is highly
 *    sensitive to the clock offset error between the devices and the length of the response delay between frames. To achieve the best possible
 *    accuracy, this response delay must be kept as low as possible. In order to do so, 6.8 Mbps data rate is used in this example and the response
 *    delay between frames is defined as low as possible. The user is referred to User Manual for more details about the single-sided two-way ranging
 *    process.
 *
 *    Initiator: |Poll TX| ..... |Resp RX|
 *    Responder: |Poll RX| ..... |Resp TX|
 *                   ^|P RMARKER|                    - time of Poll TX/RX
 *                                   ^|R RMARKER|    - time of Resp TX/RX
 *
 *                       <--TDLY->                   - POLL_TX_TO_RESP_RX_DLY_UUS (RDLY-RLEN)
 *                               <-RLEN->            - RESP_RX_TIMEOUT_UUS   (length of response frame)
 *                    <----RDLY------>               - POLL_RX_TO_RESP_TX_DLY_UUS (depends on how quickly responder can turn around and reply)
 *
 *
 * 2. The sum of the values is the TX to RX antenna delay, experimentally determined by a calibration process. Here we use a hard coded typical value
 *    but, in a real application, each device should have its own antenna delay properly calibrated to get the best possible precision when performing
 *    range measurements.
 * 3. The frames used here are Decawave specific ranging frames, complying with the IEEE 802.15.4 standard data frame encoding. The frames are the
 *    following:
 *     - a poll message sent by the initiator to trigger the ranging exchange.
 *     - a response message sent by the responder to complete the exchange and provide all information needed by the initiator to compute the
 *       time-of-flight (distance) estimate.
 *    The first 10 bytes of those frame are common and are composed of the following fields:
 *     - byte 0/1: frame control (0x8841 to indicate a data frame using 16-bit addressing).
 *     - byte 2: sequence number, incremented for each new frame.
 *     - byte 3/4: PAN ID (0xDECA).
 *     - byte 5/6: destination address, see NOTE 4 below.
 *     - byte 7/8: source address, see NOTE 4 below.
 *     - byte 9: function code (specific values to indicate which message it is in the ranging process).
 *    The remaining bytes are specific to each message as follows:
 *    Poll message:
 *     - no more data
 *    Response message:
 *     - byte 0 -> 13: poll message reception timestamp.
 *     - byte 4 -> 17: response message transmission timestamp.
 *    All messages end with a 2-byte checksum automatically set by DW IC.
 * 4. Source and destination addresses are hard coded constants in this example to keep it simple but for a real product every device should have a
 *    unique ID. Here, 16-bit addressing is used to keep the messages as short as possible but, in an actual application, this should be done only
 *    after an exchange of specific messages used to define those short addresses for each device participating to the ranging exchange.
 * 5. In a real application, for optimum performance within regulatory limits, it may be necessary to set TX pulse bandwidth and TX power, (using
 *    the dwt_configuretxrf API call) to per device calibrated values saved in the target system or the DW IC OTP memory.
 * 6. We use polled mode of operation here to keep the example as simple as possible but all status events can be used to generate interrupts. Please
 *    refer to DW IC User Manual for more details on "interrupts". It is also to be noted that STATUS register is 5 bytes long but, as the event we
 *    use are all in the first bytes of the register, we can use the simple dwt_read32bitreg() API call to access it instead of reading the whole 5
 *    bytes.
 * 7. As we want to send final TX timestamp in the final message, we have to compute it in advance instead of relying on the reading of DW IC
 *    register. Timestamps and delayed transmission time are both expressed in device time units so we just have to add the desired response delay to
 *    response RX timestamp to get final transmission time. The delayed transmission time resolution is 512 device time units which means that the
 *    lower 9 bits of the obtained value must be zeroed. This also allows to encode the 40-bit value in a 32-bit words by shifting the all-zero lower
 *    8 bits.
 * 8. In this operation, the high order byte of each 40-bit timestamps is discarded. This is acceptable as those time-stamps are not separated by
 *    more than 2**32 device time units (which is around 67 ms) which means that the calculation of the round-trip delays (needed in the
 *    time-of-flight computation) can be handled by a 32-bit subtraction.
 * 9. dwt_writetxdata() takes the full size of the message as a parameter but only copies (size - 2) bytes as the check-sum at the end of the frame is
 *    automatically appended by the DW IC. This means that our variable could be two bytes shorter without losing any data (but the sizeof would not
 *    work anymore then as we would still have to indicate the full length of the frame to dwt_writetxdata()).
 * 10. When running this example on the EVB1000 platform with the POLL_RX_TO_RESP_TX_DLY response delay provided, the dwt_starttx() is always
 *     successful. However, in cases where the delay is too short (or something else interrupts the code flow), then the dwt_starttx() might be issued
 *     too late for the configured start time. The code below provides an example of how to handle this condition: In this case it abandons the
 *     ranging exchange and simply goes back to awaiting another poll message. If this error handling code was not here, a late dwt_starttx() would
 *     result in the code flow getting stuck waiting subsequent RX event that will will never come. The companion "initiator" example (ex_06a) should
 *     timeout from awaiting the "response" and proceed to send another poll in due course to initiate another ranging exchange.
 * 11. The user is referred to DecaRanging ARM application (distributed with DW3000 product) for additional practical example of usage, and to the
 *     DW IC API Guide for more details on the DW IC driver functions.
 * 12. In this example, the DW IC is put into IDLE state after calling dwt_initialise(). This means that a fast SPI rate of up to 20 MHz can be used
 *     thereafter.
 * 13. Desired configuration by user may be different to the current programmed configuration. dwt_configure is called to set desired
 *     configuration.
 * 14. When CCM core type is used, AES_KEY_Load needs to be set prior to each encryption/decryption operation, even if the AES KEY used has not changed.
 ****************************************************************************************************************************************************/
