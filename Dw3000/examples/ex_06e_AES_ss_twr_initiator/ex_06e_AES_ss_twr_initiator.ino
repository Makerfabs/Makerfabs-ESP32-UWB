#include "dw3000.h"
#include "dw3000_mac_802_15_4.h"

#define APP_NAME "SS TWR AES INIT v1.0"

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4; // spi select pin

/* Sample of 802_15_4 frame*/
#if 0
mac_frame_802_15_4_format_t     mac_frame=
{
    /*
    * Frame control[0] = 0x09 = Data frame, security enabled, PEND not set, no ACK required, PANID compression set to zero (no PANID for source)
    * Frame control[1] = 0xEC = With seq num, no IEs, using extended address, frame ver 2 (IEEE Std 802.15.4)
    */
    .mhr_802_15_4.frame_ctrl[0]=0x09,
    .mhr_802_15_4.frame_ctrl[1]=0xEC,

    /* Sequence number initialize value*/
    .mhr_802_15_4.sequence_num=0x00,

    .mhr_802_15_4.dest_pan_id[0]=0x21,
    .mhr_802_15_4.dest_pan_id[1]=0x43,


    /* Set the Security Control field in the Auxiliary Security Header
    *  Security Control = 0xF:
    *                         Security level: 0x7 = MIC 16 (data confidentiality OFF, data authenticity Yes),
    *                         Key Identifier Mode: 0x1 = key determined from key index field,
    *                         Frame Counter Suppression: 0x0 = has the frame counter and the frame counter generates the nonce.
    *                         ASN in Nonce: 0x0 = frame counter is used to generate the nonce (CCM* nonce = SRC ADDR (8), Frame Counter (4) and Nonce Security Level (1) - set to 0x7 above)
    *  This means that format of the AUX header is Security Control (1 octet) + Fame Counter (4 octets) + Key Identifier (1 octet) = 6 octets
    */
    .mhr_802_15_4.aux_security.security_ctrl=0x0F,

};
#endif
mac_frame_802_15_4_format_t     mac_frame= {
  {
    {0x09, 0xEC},
    0x00,
    {0x21, 0x43},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    { 0x0F, {0x00, 0x00, 0x00, 0x00}, 0x00 }
  },
  0x00
};

#if 0
static dwt_aes_config_t aes_config=
{
    .key_load           = AES_KEY_Load,         // load the key into AES engine see Note 15 below
    .key_size           = AES_KEY_128bit,       // use 128bit key
    .key_src            = AES_KEY_Src_Register, // the key source is IC registers
    .aes_core_type      = AES_core_type_CCM,    // Use CCM core
    .aes_key_otp_type   = AES_key_RAM,
    .key_addr           = 0
};
#endif

static dwt_aes_config_t aes_config = {
  AES_key_RAM,
  AES_core_type_CCM,
  MIC_0,
  AES_KEY_Src_Register,
  AES_KEY_Load,
  0,
  AES_KEY_128bit,
  AES_Encrypt
};

/* Initiator data */
#define DEST_ADDR       0x1122334455667788 /* this is the address of the responder */
#define SRC_ADDR        0x8877665544332211 /* this is the address of the initiator */
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


/* Optional keys according to the key index - In AUX security header*/
static dwt_aes_key_t    keys_options[NUM_OF_KEY_OPTIONS]=
{
    {0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x11223344, 0x55667788, 0x99AABBCC, 0xDDEEFF00, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0xFFEEDDCC, 0xBBAA9988, 0x77665544, 0x33221100, 0x00000000, 0x00000000, 0x00000000, 0x00000000}
};

/* Inter-ranging delay period, in milliseconds. */
#define RNG_DELAY_MS 1000

/* Default antenna delay values for 64 MHz PRF. See NOTE 2 below. */
#define TX_ANT_DLY 16385
#define RX_ANT_DLY 16385

/* MAC payload data of the frames used in the ranging process. See NOTE 3 below. */
/* Poll message from the initiator to the responder */
static uint8_t tx_poll_msg[] = {'P','o','l','l',' ','m','e','s','s','a','g','e'};
/* Response message to the initiator. The first 8 bytes are used for Poll RX time and Response TX time.*/
static uint8_t rx_resp_msg[] = {0,0,0,0,0,0,0,0,'R','e','s','p','o','n','s','e'};

#define START_RECEIVE_DATA_LOCATION     8   //MAC payload user data starts at index 8 (e.g. 'R' - in above response message)

/* Indexes to access some of the fields in the frames defined above. */
#define ALL_MSG_SN_IDX 2            //sequence number byte index in MHR
#define RESP_MSG_POLL_RX_TS_IDX 0   //index in the MAC payload for Poll RX time
#define RESP_MSG_RESP_TX_TS_IDX 4   //index in the MAC payload for Response TX time
#define RESP_MSG_TS_LEN 4

/* Note, the key index of 0 is forbidden to send as key index. Thus index 1 is the first.
 * This example uses this index for the key table for the encryption of initiator's data */
#define INITIATOR_KEY_INDEX     1

/* Buffer to store received response message.
 * Its size is adjusted to longest frame that this example code can handle. */
#define RX_BUF_LEN 127 /* The received frame cannot be bigger than 127 if STD PHR mode is used */
static uint8_t rx_buffer[RX_BUF_LEN];

/* Delay between frames, in UWB microseconds. See NOTE 1 below. */
#define POLL_TX_TO_RESP_RX_DLY_UUS 1720
/* Receive response timeout. See NOTE 5 below. */
#define RESP_RX_TIMEOUT_UUS 250

/* Hold copies of computed time of flight and distance here for reference so that it can be examined at a debug breakpoint. */
static double tof;
static double distance;

/* Values for the PG_DELAY and TX_POWER registers reflect the bandwidth and power of the spectrum at the current
 * temperature. These values can be calibrated prior to taking reference measurements. See NOTE 2 below. */
extern dwt_txconfig_t txconfig_options;

static uint32_t   frame_cnt=0;  /* See Note 13 */
static uint8_t    seq_cnt=0x0A; /* Frame sequence number, incremented after each transmission. */
uint32_t          status_reg;
uint8_t           nonce[13];    /* 13-byte nonce used in this example as per IEEE802.15.4 */
dwt_aes_job_t   aes_job_tx,aes_job_rx;
int8_t          status;

    
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

  /* Configure DW IC. See NOTE 14 below. */
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

    /* Set expected response's delay and timeout. See NOTE 1 and 5 below.
     * This example is paired with the SS-TWR responder and if delays/timings need to be changed
     * they must be changed in both to match. */
    dwt_setrxaftertxdelay(POLL_TX_TO_RESP_RX_DLY_UUS);
    dwt_setrxtimeout(RESP_RX_TIMEOUT_UUS);

    /* Next can enable TX/RX states output on GPIOs 5 and 6 to help debug */
    dwt_setlnapamode(DWT_LNA_ENABLE | DWT_PA_ENABLE);

    /*Configure the TX and RX AES jobs, the TX job is used to encrypt the Poll message,
     * the RX job is used to decrypt the Response message */
    aes_job_tx.mode        = AES_Encrypt;     /* this is encryption job */
    aes_job_tx.src_port    = AES_Src_Tx_buf;  /* dwt_do_aes will take plain text to the TX buffer */
    aes_job_tx.dst_port    = AES_Dst_Tx_buf;  /* dwt_do_aes will replace the original plain text TX buffer with encrypted one */
    aes_job_tx.nonce       = nonce;          /* pointer to the nonce structure*/
    aes_job_tx.header      = (uint8_t *)MHR_802_15_4_PTR(&mac_frame);/* plain-text header which will not be encrypted */
    aes_job_tx.header_len  = MAC_FRAME_HEADER_SIZE(&mac_frame);
    aes_job_tx.payload     = tx_poll_msg;    /* payload to be encrypted */
    aes_job_tx.payload_len = sizeof(tx_poll_msg); /* size of payload to be encrypted */

    aes_job_rx.mode        = AES_Decrypt;      /* this is decryption job */
    aes_job_rx.src_port    = AES_Src_Rx_buf_0; /* The source of the data to be decrypted is the IC RX buffer */
    aes_job_rx.dst_port    = AES_Dst_Rx_buf_0; /* Decrypt the encrypted data to the IC RX buffer : this will destroy original RX frame */
    aes_job_rx.header_len  = aes_job_tx.header_len;
    aes_job_rx.header      = aes_job_tx.header;/* plain-text header which will not be encrypted */
    aes_job_rx.payload     = rx_buffer;        /* pointer to where the decrypted data will be copied to when read from the IC*/

}

void loop() {
        /* Program the correct key to be used */
        dwt_set_keyreg_128(&keys_options[INITIATOR_KEY_INDEX-1]);
        /* Set the key index for the frame */
        MAC_FRAME_AUX_KEY_IDENTIFY_802_15_4(&mac_frame)=INITIATOR_KEY_INDEX;

        /* Update MHR to the correct SRC and DEST addresses and construct the 13-byte nonce
         * (same MAC frame structure is used to store both received data and transmitted data - thus SRC and DEST addresses
         * need to be updated before each transmission */
        mac_frame_set_pan_ids_and_addresses_802_15_4(&mac_frame,DEST_PAN_ID,DEST_ADDR,SRC_ADDR);
        mac_frame_get_nonce(&mac_frame,nonce);

        aes_job_tx.mic_size = mac_frame_get_aux_mic_size(&mac_frame);
        aes_config.mode = AES_Encrypt;
        aes_config.mic  = dwt_mic_size_from_bytes(aes_job_tx.mic_size);
        dwt_configure_aes(&aes_config);

        /* The AES job will take the TX frame data and and copy it to DW IC TX buffer before transmission. See NOTE 7 below. */
        status=dwt_do_aes(&aes_job_tx,aes_config.aes_core_type);
        /* Check for errors */
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

        /* Start transmission, indicating that a response is expected so that reception is enabled automatically after the frame is sent and the delay
         * set by dwt_setrxaftertxdelay() has elapsed. */
        dwt_starttx(DWT_START_TX_IMMEDIATE | DWT_RESPONSE_EXPECTED);

        /* We assume that the transmission is achieved correctly, poll for reception of a frame or error/timeout. See NOTE 8 below. */
        while (!((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) & (SYS_STATUS_RXFCG_BIT_MASK | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR)))
        { };

        /* Increment frame sequence number (modulo 256) and frame counter, after transmission of the poll message . */

        MAC_FRAME_SEQ_NUM_802_15_4(&mac_frame)=++seq_cnt;
        mac_frame_update_aux_frame_cnt(&mac_frame,++frame_cnt);

        if (status_reg & SYS_STATUS_RXFCG_BIT_MASK)
        {/* Got response */
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
            aes_config.mode=AES_Decrypt;
            PAYLOAD_PTR_802_15_4(&mac_frame)=rx_buffer;/* Set the MAC pyload ptr */

            /* This example assumes that initiator and responder are sending encrypted data */
            status=rx_aes_802_15_4(&mac_frame,frame_len,&aes_job_rx,sizeof(rx_buffer),keys_options,DEST_ADDR,SRC_ADDR,&aes_config);
            if (status!=AES_RES_OK)
            {
              do {
                switch (status)
                {
                    case AES_RES_ERROR_LENGTH:
                        test_run_info((unsigned char *)"Length AES error");
                        break;
                    case AES_RES_ERROR:
                        test_run_info((unsigned char *)"ERROR AES");
                        break;
                    case AES_RES_ERROR_FRAME:
                        test_run_info((unsigned char *)"Error Frame");
                        break;
                    case AES_RES_ERROR_IGNORE_FRAME:
                        test_run_info((unsigned char *)"Frame not for us");
                        continue;//Got frame not for us
                }
              } while (1);
            }

            /* Check that the frame is the expected response from the companion "SS TWR AES responder" example.
             * ignore the 8 first bytes of the response message as they contain the poll and response timestamps */
            if (memcmp(&rx_buffer[START_RECEIVE_DATA_LOCATION], &rx_resp_msg[START_RECEIVE_DATA_LOCATION],
                    aes_job_rx.payload_len-START_RECEIVE_DATA_LOCATION) == 0)
            {
                uint32_t poll_tx_ts, resp_rx_ts, poll_rx_ts, resp_tx_ts;
                int32_t rtd_init, rtd_resp;
                float clockOffsetRatio ;

                /* Retrieve poll transmission and response reception timestamps. See NOTE 9 below. */
                poll_tx_ts = dwt_readtxtimestamplo32();
                resp_rx_ts = dwt_readrxtimestamplo32();

                /* Read carrier integrator value and calculate clock offset ratio. See NOTE 11 below. */
                clockOffsetRatio = ((float)dwt_readclockoffset()) / (uint32_t)(1<<26);

                /* Get timestamps embedded in response message. */
                resp_msg_get_ts(&rx_buffer[RESP_MSG_POLL_RX_TS_IDX], &poll_rx_ts);
                resp_msg_get_ts(&rx_buffer[RESP_MSG_RESP_TX_TS_IDX], &resp_tx_ts);

                /* Compute time of flight and distance, using clock offset ratio to correct for differing local and remote clock rates */
                rtd_init = resp_rx_ts - poll_tx_ts;
                rtd_resp = resp_tx_ts - poll_rx_ts;

                tof = ((rtd_init - rtd_resp * (1 - clockOffsetRatio)) / 2.0) * DWT_TIME_UNITS;
                distance = tof * SPEED_OF_LIGHT;

                /* Display computed distance on LCD. */
                snprintf(dist_str, sizeof(dist_str), "DIST: %3.2f m", distance);
                test_run_info((unsigned char *)dist_str);
            }

        }
        else
        {
            /* Clear RX error/timeout events in the DW IC status register. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
        }

        /* Execute a delay between ranging exchanges. */
        Sleep(RNG_DELAY_MS);
}

/*****************************************************************************************************************************************************
 * NOTES:
 *
 * 1. The single-sided two-way ranging scheme implemented here has to be considered carefully as the accuracy of the distance measured is highly
 *    sensitive to the clock offset error between the devices and the length of the response delay between frames. To achieve the best possible
 *    accuracy, this response delay must be kept as low as possible. In order to do so, 6.8 Mbps data rate is used in this example and the response
 *    delay between frames is defined as low as possible. The user is referred to User Manual for more details about the single-sided two-way ranging
 *    process.  NB:SEE ALSO NOTE 11.
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
 * 2. The sum of the values is the TX to RX antenna delay, this should be experimentally determined by a calibration process. Here we use a hard coded
 *    value (expected to be a little low so a positive error will be seen on the resultant distance estimate. For a real production application, each
 *    device should have its own antenna delay properly calibrated to get good precision when performing range measurements.
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
 * 5. This timeout is for complete reception of a frame, i.e. timeout duration must take into account the length of the expected frame. Here the value
 *    is arbitrary but chosen large enough to make sure that there is enough time to receive the complete response frame sent by the responder at the
 *    6.8M data rate used (around 200 �s).
 * 6. In a real application, for optimum performance within regulatory limits, it may be necessary to set TX pulse bandwidth and TX power, (using
 *    the dwt_configuretxrf API call) to per device calibrated values saved in the target system or the DW IC OTP memory.
 * 7. dwt_writetxdata() takes the full size of the message as a parameter but only copies (size - 2) bytes as the check-sum at the end of the frame is
 *    automatically appended by the DW IC. This means that our variable could be two bytes shorter without losing any data (but the sizeof would not
 *    work anymore then as we would still have to indicate the full length of the frame to dwt_writetxdata()).
 * 8. We use polled mode of operation here to keep the example as simple as possible but all status events can be used to generate interrupts. Please
 *    refer to DW IC User Manual for more details on "interrupts". It is also to be noted that STATUS register is 5 bytes long but, as the event we
 *    use are all in the first bytes of the register, we can use the simple dwt_read32bitreg() API call to access it instead of reading the whole 5
 *    bytes.
 * 9. The high order byte of each 40-bit time-stamps is discarded here. This is acceptable as, on each device, those time-stamps are not separated by
 *    more than 2**32 device time units (which is around 67 ms) which means that the calculation of the round-trip delays can be handled by a 32-bit
 *    subtraction.
 * 10. The user is referred to DecaRanging ARM application (distributed with EVK1000 product) for additional practical example of usage, and to the
 *     DW IC API Guide for more details on the DW IC driver functions.
 * 11. The use of the clock offset value to correct the TOF calculation, significantly improves the result of the SS-TWR where the remote
 *     responder unit's clock is a number of PPM offset from the local initiator unit's clock.
 *     As stated in NOTE 2 a fixed offset in range will be seen unless the antenna delay is calibrated and set correctly.
 * 12. In this example, the DW IC is put into IDLE state after calling dwt_initialise(). This means that a fast SPI rate of up to 20 MHz can be used
 *     thereafter.
 * 13. Frame counter was set to zero in this example. The frame counter should be incremented each frame. When frame counter gets to its max value (uint32_t),
 *     key should be replaced.
 * 14. Desired configuration by user may be different to the current programmed configuration. dwt_configure is called to set desired
 *     configuration.
 * 15. When CCM core type is used, AES_KEY_Load needs to be set prior to each encryption/decryption operation, even if the AES KEY used has not changed.
 ****************************************************************************************************************************************************/
