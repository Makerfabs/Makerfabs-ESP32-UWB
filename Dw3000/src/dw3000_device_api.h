/*! ----------------------------------------------------------------------------
 * @file    deca_device_api.h
 * @brief   DW3000 API Functions
 *
 * @attention
 *
 * Copyright 2013-2020(c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */

#ifndef _DECA_DEVICE_API_H_
#define _DECA_DEVICE_API_H_

#ifdef __cplusplus
//extern "C" {
#endif

#include "dw3000_types.h"

#ifndef DWT_NUM_DW_DEV
#define DWT_NUM_DW_DEV (1)
#endif

#define DWT_BIT_MASK(bit_num)   (((uint32_t)1)<<(bit_num))

/* MACRO */
#define dwt_write32bitreg(addr,value)  dwt_write32bitoffsetreg(addr,0,value)
#define dwt_read32bitreg(addr)     dwt_read32bitoffsetreg(addr,0)
#define dwt_writefastCMD(cmd)     dwt_writetodevice(cmd,0,0,0)

#define dwt_or8bitoffsetreg(addr, offset, or_val) dwt_modify8bitoffsetreg(addr, offset, -1, or_val)
#define dwt_and8bitoffsetreg(addr, offset, and_val) dwt_modify8bitoffsetreg(addr, offset, and_val, 0)
#define dwt_and_or8bitoffsetreg(addr,offset, and_val, or_val) dwt_modify8bitoffsetreg(addr,offset,and_val,or_val)
#define dwt_set_bit_num_8bit_reg(addr,bit_num) dwt_modify8bitoffsetreg(addr,0,-1,DWT_BIT_MASK(bit_num))
#define dwt_clr_bit_num_8bit_reg(addr,bit_num) dwt_modify8bitoffsetreg(addr,0,~DWT_BIT_MASK(bit_num),0)

#define dwt_or16bitoffsetreg(addr, offset, or_val) dwt_modify16bitoffsetreg(addr, offset, -1, or_val)
#define dwt_and16bitoffsetreg(addr, offset, and_val) dwt_modify16bitoffsetreg(addr, offset, and_val, 0)
#define dwt_and_or16bitoffsetreg(addr,offset, and_val, or_val) dwt_modify16bitoffsetreg(addr,offset,and_val,or_val)
#define dwt_set_bit_num_16bit_reg(addr,bit_num) dwt_modify16bitoffsetreg(addr,0,-1,DWT_BIT_MASK(bit_num))
#define dwt_clr_bit_num_16bit_reg(addr,bit_num) dwt_modify16bitoffsetreg(addr,0,~DWT_BIT_MASK(bit_num),0)

#define dwt_or32bitoffsetreg(addr, offset, or_val) dwt_modify32bitoffsetreg(addr, offset, -1, or_val)
#define dwt_and32bitoffsetreg(addr, offset, and_val) dwt_modify32bitoffsetreg(addr, offset, and_val, 0)
#define dwt_and_or32bitoffsetreg(addr,offset, and_val, or_val) dwt_modify32bitoffsetreg(addr,offset,and_val,or_val)
#define dwt_set_bit_num_32bit_reg(addr,bit_num) dwt_modify32bitoffsetreg(addr,0,-1,DWT_BIT_MASK(bit_num))
#define dwt_clr_bit_num_32bit_reg(addr,bit_num) dwt_modify32bitoffsetreg(addr,0,~DWT_BIT_MASK(bit_num),0)

/* */
#define DWT_SUCCESS (0)
#define DWT_ERROR   (-1)

#define DWT_TIME_UNITS      (1.0/499.2e6/128.0) //!< = 15.65e-12 s

#define DWT_A0_DEV_ID       (0xDECA0300)        //!< DW3000 MPW A0 (non PDOA) silicon device ID
#define DWT_A0_PDOA_DEV_ID  (0xDECA0310)        //!< DW3000 MPW A0 (with PDOA) silicon device ID
#define DWT_B0_DEV_ID       (0xDECA0301)        //!< DW3000 MPW B0 (non PDOA) silicon device ID
#define DWT_B0_PDOA_DEV_ID  (0xDECA0311)        //!< DW3000 MPW B0 (with PDOA) silicon device ID
#define DWT_C0_DEV_ID       (0xDECA0302)        //!< DW3000 MPW C0 (non PDOA) silicon device ID
#define DWT_C0_PDOA_DEV_ID  (0xDECA0312)        //!< DW3000 MPW C0 (with PDOA) silicon device ID

#define DELAY_20uUSec           (20)/*Delay of 20uSec(measured 24uSec)*/
#define MAX_RETRIES_FOR_PLL     (6)
#define MAX_RETRIES_FOR_PGF     (3)

typedef enum
{
     AOA,
     NON_AOA
}dw3000type_e;

typedef enum {
    DW3000_SPI_RD_BIT    = 0x0000U,
    DW3000_SPI_WR_BIT    = 0x8000U,
    DW3000_SPI_AND_OR_8  = 0x8001U,
    DW3000_SPI_AND_OR_16 = 0x8002U,
    DW3000_SPI_AND_OR_32 = 0x8003U,
}spi_modes_e;

//! fast commands
#define CMD_DB_TOGGLE     0x13   //!< Toggle double buffer pointer
#define CMD_CLR_IRQS      0x12   //!< Clear all events/clear interrupt
#define CMD_CCA_TX_W4R    0x11   //!< Check if channel clear prior to TX, enable RX when TX done
#define CMD_DTX_REF_W4R   0x10   //!< Start delayed TX (as DTX_REF below), enable RX when TX done
#define CMD_DTX_RS_W4R    0xF    //!< Start delayed TX (as DTX_RS below), enable RX when TX done
#define CMD_DTX_TS_W4R    0xE    //!< Start delayed TX (as DTX_TS below), enable RX when TX done
#define CMD_DTX_W4R       0xD    //!< Start delayed TX (as DTX below), enable RX when TX done
#define CMD_TX_W4R        0xC    //!< Start TX (as below), enable RX when TX done
#define CMD_CCA_TX        0xB    //!< Check if channel clear prior to TX
#define CMD_DRX_REF       0xA    //!< Enable RX @ time = DREF_TIME + DX_TIME
#define CMD_DTX_REF       0x9    //!< Start delayed TX (RMARKER will be @ time = DREF_TIME + DX_TIME)
#define CMD_DRX_RS        0x8    //!< Enable RX @ time = RX_TIME + DX_TIME
#define CMD_DTX_RS        0x7    //!< Start delayed TX (RMARKER will be @ time = RX_TIME + DX_TIME)
#define CMD_DRX_TS        0x6    //!< Enable RX @ time = TX_TIME + DX_TIME
#define CMD_DTX_TS        0x5    //!< Start delayed TX (RMARKER will be @ time = TX_TIME + DX_TIME)
#define CMD_DRX           0x4    //!< Enable RX @ time specified in DX_TIME register
#define CMD_DTX           0x3    //!< Start delayed TX (RMARKER will be @ time set in DX_TIME register)
#define CMD_RX            0x2    //!< Enable RX
#define CMD_TX            0x1    //!< Start TX
#define CMD_TXRXOFF       0x0    //!< Turn off TX or RX, clear any TX/RX events and put DW3000 into IDLE

//! constants for selecting the bit rate for data TX (and RX)
//! These are defined for write (with just a shift) the TX_FCTRL register
#define DWT_BR_850K     0   //!< UWB bit rate 850 kbits/s
#define DWT_BR_6M8      1   //!< UWB bit rate 6.8 Mbits/s
#define DWT_BR_NODATA   2   //!< No data (SP3 packet format)

//! constants for specifying the (Nominal) mean Pulse Repetition Frequency
//! These are defined for direct write (with a shift if necessary) to CHAN_CTRL and TX_FCTRL regs
#define DWT_PRF_16M     1   //!< UWB PRF 16 MHz
#define DWT_PRF_64M     2   //!< UWB PRF 64 MHz
#define DWT_PRF_SCP     3   //!< SCP UWB PRF ~100 MHz

//! constants for specifying Preamble Acquisition Chunk (PAC) Size in symbols
#define DWT_PAC8        0   //!< PAC  8 (recommended for RX of preamble length  128 and below
#define DWT_PAC16       1   //!< PAC 16 (recommended for RX of preamble length  256
#define DWT_PAC32       2   //!< PAC 32 (recommended for RX of preamble length  512
#define DWT_PAC4        3   //!< PAC  4 (recommended for RX of preamble length  < 127

//! constants for specifying SFD Types and size
#define DWT_SFD_IEEE_4A 0   //!< IEEE 8-bit ternary
#define DWT_SFD_DW_8    1   //!< DW 8-bit
#define DWT_SFD_DW_16   2   //!< DW 16-bit
#define DWT_SFD_IEEE_4Z 3   //!< IEEE 8-bit binary (4z)
#define DWT_SFD_LEN8    (8) //!< IEEE, and DW 8-bit are length 8
#define DWT_SFD_LEN16   (16)//!< DW 16-bit is length 16

//! constants for specifying TX Preamble length in symbols
//! These are defined to allow them be directly written into byte 2 of the TX_FCTRL register
//! (i.e. a four bit value destined for bits 20..18 but shifted left by 2 for byte alignment)
#define DWT_PLEN_4096   0x03    //! Standard preamble length 4096 symbols
#define DWT_PLEN_2048   0x0A    //! Non-standard preamble length 2048 symbols
#define DWT_PLEN_1536   0x06    //! Non-standard preamble length 1536 symbols
#define DWT_PLEN_1024   0x02    //! Standard preamble length 1024 symbols
#define DWT_PLEN_512    0x0d    //! Non-standard preamble length 512 symbols
#define DWT_PLEN_256    0x09    //! Non-standard preamble length 256 symbols
#define DWT_PLEN_128    0x05    //! Non-standard preamble length 128 symbols
#define DWT_PLEN_64     0x01    //! Standard preamble length 64 symbols
#define DWT_PLEN_32     0x04    //! Non-standard length 32
#define DWT_PLEN_72     0x07    //! Non-standard length 72

#define DWT_SFDTOC_DEF          129  // default SFD timeout value

#define DWT_PHRMODE_STD         0x0     // standard PHR mode
#define DWT_PHRMODE_EXT         0x1     // DW proprietary extended frames PHR mode

#define DWT_PHRRATE_STD         0x0     // standard PHR rate
#define DWT_PHRRATE_DTA         0x1     // PHR at data rate (6M81)

// Define DW3000 PDOA modes
#define DWT_PDOA_M0           0x0     // DW PDOA mode is off
#define DWT_PDOA_M1           0x1     // DW PDOA mode  mode 1
#define DWT_PDOA_M3           0x3     // DW PDOA mode  mode 3

// Define DW3000 STS modes
#define DWT_STS_MODE_OFF         0x0     // STS is off
#define DWT_STS_MODE_1           0x1     // STS mode 1
#define DWT_STS_MODE_2           0x2     // STS mode 2
#define DWT_STS_MODE_ND          0x3     // STS with no data
#define DWT_STS_MODE_SDC         0x8     // Enable Super Deterministic Codes
#define DWT_STS_CONFIG_MASK      0xB


#define DWT_SFD_COUNT_WARN      (0x2000 >> 7)   // SFD count warning bit (STS quality status bit)

// Defined constants for "mode" bitmask parameter passed into dwt_starttx() function.
#define DWT_START_TX_IMMEDIATE      0x00    //! Send the frame immediately
#define DWT_START_TX_DELAYED        0x01    //! Send the frame at specified time (time must be less that half period away)
#define DWT_RESPONSE_EXPECTED       0x02    //! Will enable the receiver after TX has completed
#define DWT_START_TX_DLY_REF        0x04    //! Send the frame at specified time (time in DREF_TIME register + any time in DX_TIME register)
#define DWT_START_TX_DLY_RS         0x08    //! Send the frame at specified time (time in RX_TIME_0 register + any time in DX_TIME register)
#define DWT_START_TX_DLY_TS         0x10    //! Send the frame at specified time (time in TX_TIME_LO register + any time in DX_TIME register)

#define DWT_START_TX_CCA            0x20    //! Send the frame if no preamble detected within PTO time

// Defined constants for "mode" bitmask parameter passed into dwt_rxenable() function.
#define DWT_START_RX_IMMEDIATE      0x00    //! Enable the receiver immediately
#define DWT_START_RX_DELAYED        0x01    //! Set up delayed RX, if "late" error triggers, then the RX will be enabled immediately
#define DWT_IDLE_ON_DLY_ERR         0x02    //! If delayed RX failed due to "late" error then if this
                                            //! flag is set the RX will not be re-enabled immediately, and device will be in IDLE when function exits
#define DWT_START_RX_DLY_REF        0x04    //! Enable the receiver at specified time (time in DREF_TIME register + any time in DX_TIME register)
#define DWT_START_RX_DLY_RS         0x08    //! Enable the receiver at specified time (time in RX_TIME_0 register + any time in DX_TIME register)
#define DWT_START_RX_DLY_TS         0x10    //! Enable the receiver at specified time (time in TX_TIME_LO register + any time in DX_TIME register)

// Defined constants when SPI CRC mode is used:
typedef enum
{
    DWT_SPI_CRC_MODE_NO = 0,    /* No CRC */
    DWT_SPI_CRC_MODE_WR,        /* This is used to enable SPI CRC check (the SPI CRC check will be enabled on DW3000 and CRC-8 added for SPI write transactions) */
    DWT_SPI_CRC_MODE_WRRD       /* This is used to optionally enable additional CRC check on the SPI read operations, while the CRC check on the SPI write operations is also enabled */
}dwt_spi_crc_mode_e;


// Defined constants for "mode" bit field parameter passed to dwt_setleds() function.
#define DWT_LEDS_DISABLE     0x00
#define DWT_LEDS_ENABLE      0x01
#define DWT_LEDS_INIT_BLINK  0x02
// Default blink time. Blink time is expressed in multiples of 14 ms. The value defined here is ~225 ms.
#define DWT_LEDS_BLINK_TIME_DEF 0x10

#define GPIO_PIN2_RXLED         (((uint32_t)0x1)<<6)    /* The pin operates as the RXLED output */
#define GPIO_PIN3_TXLED         (((uint32_t)0x1)<<9)    /* The pin operates as the TXLED output */

#define GPIO_PIN0_EXTTXE        (((uint32_t)0x2)<<0)    /* The pin operates as the EXTTXE output (output TX state) */
#define GPIO_PIN1_EXTRXE        (((uint32_t)0x2)<<3)    /* The pin operates as the EXTRXE output (output RX state) */

#define GPIO_PIN4_EXTDA         (((uint32_t)0x1)<<12)   /* The pin operates to support external DA/PA */
#define GPIO_PIN5_EXTTX         (((uint32_t)0x1)<<15)   /* The pin operates to support external PA */
#define GPIO_PIN6_EXTRX         (((uint32_t)0x1)<<18)   /* The pin operates to support external LNA */

// Defined constants for "lna_pa" bit field parameter passed to dwt_setlnapamode() function
#define DWT_LNA_PA_DISABLE     0x00
#define DWT_LNA_ENABLE         0x01
#define DWT_PA_ENABLE          0x02
#define DWT_TXRX_EN            0x04

//Reset options
#define DWT_RESET_ALL          0x00
#define DWT_RESET_CTRX         0x0F
#define DWT_RESET_RX           0xEF
#define DWT_RESET_CLEAR        0xFF

//frame filtering configuration options
#define DWT_FF_ENABLE_802_15_4      0x2             // enable FF for 802.15.4
#define DWT_FF_DISABLE              0x0             // disable FF
#define DWT_FF_BEACON_EN            0x001           // beacon frames allowed
#define DWT_FF_DATA_EN              0x002           // data frames allowed
#define DWT_FF_ACK_EN               0x004           // ack frames allowed
#define DWT_FF_MAC_EN               0x008           // mac control frames allowed
#define DWT_FF_RSVD_EN              0x010           // reserved frame types allowed
#define DWT_FF_MULTI_EN             0x020           // multipurpose frames allowed
#define DWT_FF_FRAG_EN              0x040           // fragmented frame types allowed
#define DWT_FF_EXTEND_EN            0x080           // extended frame types allowed
#define DWT_FF_COORD_EN             0x100           // behave as coordinator (can receive frames with no dest address (PAN ID has to match))
#define DWT_FF_IMPBRCAST_EN         0x200           // allow MAC implicit broadcast
#define DWT_FF_MAC_LE0_EN           0x408           // mac frames allowed if address in LE0_PEND mathces source address
#define DWT_FF_MAC_LE1_EN           0x808           // mac frames allowed if address in LE1_PEND mathces source address
#define DWT_FF_MAC_LE2_EN           0x1008           // mac frames allowed if address in LE2_PEND mathces source address
#define DWT_FF_MAC_LE3_EN           0x2008           // mac frames allowed if address in LE3_PEND mathces source address


// SYS_STATE_LO register errors
#define DW_SYS_STATE_TXERR          0xD0000         // TSE is in TX but TX is in IDLE in SYS_STATE_LO register

//DW3000 interrupt events

#define DWT_INT_SCRC            0x00000004          // SPI write CRC error event
#define DWT_INT_TFRS            0x00000080          // frame sent
#define DWT_INT_LDED            0x00000400          // micro-code has finished execution
#define DWT_INT_RFCG            0x00004000          // frame received with good CRC
#define DWT_INT_RPHE            0x00001000          // receiver PHY header error
#define DWT_INT_RFCE            0x00008000          // receiver CRC error
#define DWT_INT_RFSL            0x00010000          // receiver sync loss error
#define DWT_INT_RFTO            0x00020000          // frame wait timeout
#define DWT_INT_LDEERR          0x00040000          // CIA error
#define DWT_INT_RXOVRR          0x00100000          // receiver overrun
#define DWT_INT_RXPTO           0x00200000          // preamble detect timeout
#define DWT_INT_LCSSERR         0x00400000          // LCSS set up error
#define DWT_INT_SFDT            0x04000000          // SFD timeout
#define DWT_INT_HPDWARN         0x08000000          // HPDWARN timeout
#define DWT_INT_CPERR           0x10000000          // STS Error
#define DWT_INT_ARFE            0x20000000          // frame rejected (due to frame filtering configuration)
#define DWT_INT_ALL             0x3FFFFFFF
#define DWT_INT_RX              (DWT_INT_LDED | DWT_INT_RFCG | DWT_INT_RPHE | DWT_INT_RFCE | DWT_INT_RFSL | DWT_INT_RFTO | DWT_INT_LDEERR | DWT_INT_RXPTO | DWT_INT_SFDT | DWT_INT_ARFE)


//DW3000 SLEEP and WAKEUP configuration parameters
#define DWT_PGFCAL       0x0800
#define DWT_GOTORX       0x0200
#define DWT_GOTOIDLE     0x0100
#define DWT_SEL_OPS3     0x00C0
#define DWT_SEL_OPS2     0x0080                     // Short OPS table
#define DWT_SEL_OPS1     0x0040                     // SCP
#define DWT_SEL_OPS0     0x0000                     // Long OPS table
#define DWT_ALT_OPS      0x0020
#define DWT_LOADLDO      0x0010
#define DWT_LOADDGC      0x0008
#define DWT_LOADBIAS     0x0004
#define DWT_RUNSAR       0x0002
#define DWT_CONFIG       0x0001                     // download the AON array into the HIF (configuration download)

#define DWT_PRES_SLEEP   0x20                       // allows for SLEEP_EN bit to be "preserved", although it will self - clear on wake up
#define DWT_WAKE_WUP     0x10                       // wake up on WAKEUP PIN
#define DWT_WAKE_CSN     0x8                        // wake up on chip select
#define DWT_BROUT_EN     0x4                        // enable brownout detector during sleep/deep sleep
#define DWT_SLEEP        0x2                        // enable sleep (if this bit is clear the device will enter deep sleep)
#define DWT_SLP_EN       0x1                        // enable sleep/deep sleep functionality

//DW3000 IDLE/INIT mode definitions
#define DWT_DW_INIT      0x0
#define DWT_DW_IDLE      0x1
#define DWT_DW_IDLE_RC   0x2

#define DWT_READ_OTP_PID  0x10    //read part ID from OTP
#define DWT_READ_OTP_LID  0x20    //read lot ID from OTP
#define DWT_READ_OTP_BAT  0x40    //read ref voltage from OTP
#define DWT_READ_OTP_TMP  0x80    //read ref temperature from OTP

//DW3000 OTP operating parameter set selection
#define DWT_OPSET_LONG   (0x0<<11)
#define DWT_OPSET_SCP    (0x1<<11)
#define DWT_OPSET_SHORT  (0x2<<11)

//Conversion factor to convert clock offset from PPM to ratio
#define CLOCK_OFFSET_PPM_TO_RATIO (1.0/(1<<26))

#define AON_SLPCNT_LO (0x102) //address of SLEEP counter bits [19:12] in AON memory
#define AON_SLPCNT_HI (0x103) //address of SLEEP counter bits [27:20] in AON memory
#define AON_SLPCNT_CAL_CTRL (0x104) //address of SLEEP counter cal control
#define AON_SLPCNT_CAL_LO   (0x10E) //address of SLEEP counter cal value low byte
#define AON_SLPCNT_CAL_HI   (0x10F) //address of SLEEP counter cal value high byte

#define DW_CIA_DIAG_LOG_MAX (0x8)   //CIA to copy to swinging set a maximum set of diagnostic registers in Double Buffer mode
#define DW_CIA_DIAG_LOG_MID (0x4)   //CIA to copy to swinging set a medium set of diagnostic registers in Double Buffer mode
#define DW_CIA_DIAG_LOG_MIN (0x2)   //CIA to copy to swinging set a minimal set of diagnostic registers in Double Buffer mode
#define DW_CIA_DIAG_LOG_ALL (0x1)   //CIA to log all diagnostic registers
#define DW_CIA_DIAG_LOG_OFF (0x0)   //CIA to log reduced set of diagnostic registers

// Call-back data RX frames flags
#define DWT_CB_DATA_RX_FLAG_RNG  0x01 // Ranging bit
#define DWT_CB_DATA_RX_FLAG_ND   0x02 // No data mode
#define DWT_CB_DATA_RX_FLAG_CIA  0x04 // CIA done
#define DWT_CB_DATA_RX_FLAG_CER  0x08 // CIA error
#define DWT_CB_DATA_RX_FLAG_CPER 0x10 // CP error

// LDO and BIAS tune kick
#define LDO_BIAS_KICK (0x180)  // Writing to bit 7 and 8

// Multiplication factors to convert carrier integrator value to a frequency offset in Hertz
#define FREQ_OFFSET_MULTIPLIER          (998.4e6/2.0/1024.0/131072.0)

// Multiplication factors to convert frequency offset in Hertz to PPM crystal offset
// NB: also changes sign so a positive value means the local RX clock is running slower than the remote TX device.
#define HERTZ_TO_PPM_MULTIPLIER_CHAN_5     (-1.0e6/6489.6e6)
#define HERTZ_TO_PPM_MULTIPLIER_CHAN_9     (-1.0e6/7987.2e6)

// Low Energy (LE) device addresses
#define LE0 0 //LE0_PEND address
#define LE1 1 //LE1_PEND address
#define LE2 2 //LE2_PEND address
#define LE3 3 //LE3_PEND address

// TX/RX call-back data
typedef struct
{
    uint32_t status;      //initial value of register as ISR is entered
    uint16_t status_hi;   //initial value of register as ISR is entered, if relevant for that event type
    uint16_t datalength;  //length of frame
    uint8_t  rx_flags;    //RX frame flags, see above
} dwt_cb_data_t;

// Call-back type for SPI read error event (if the DW3000 generated CRC does not match the one calculated by the dwt_generatecrc8 function)
typedef void(*dwt_spierrcb_t)(void);

// Call-back type for all interrupt events
typedef void (*dwt_cb_t)(const dwt_cb_data_t *);


#define SQRT_FACTOR             181 /*Factor of sqrt(2) for calculation*/
#define STS_LEN_SUPPORTED       7   /*The supported STS length options*/
#define SQRT_SHIFT_VAL          7
#define SHIFT_VALUE             11
#define MOD_VALUE               2048
#define HALF_MOD                (MOD_VALUE>>1)

/*This Enum holds INT working options.*/
typedef enum
{
    DWT_DISABLE_INT=0,/*Disable these INT*/
    DWT_ENABLE_INT,/*Enable these INT*/
    DWT_ENABLE_INT_ONLY/*Enable only these INT*/
} dwt_INT_options_e;


/*This Enum holds the index for factor calculation.*/
typedef enum
{
    DWT_STS_LEN_32  =0,
    DWT_STS_LEN_64  =1,
    DWT_STS_LEN_128 =2,
    DWT_STS_LEN_256 =3,
    DWT_STS_LEN_512 =4,
    DWT_STS_LEN_1024=5,
    DWT_STS_LEN_2048=6
} dwt_sts_lengths_e;

#define GET_STS_REG_SET_VALUE(x)     ((uint16_t)1<<((x)+2))    /* Returns the value to set in CP_CFG0_ID for STS length. The x is the enum value from dwt_sts_lengths_e */

/* Enum used for selecting channel for DGC on-wake kick. */
typedef enum
{
    DWT_DGC_SEL_CH5=0,
    DWT_DGC_SEL_CH9
} dwt_dgc_chan_sel;

/* Enum used for selecting location to load DGC data from */
typedef enum
{
    DWT_DGC_LOAD_FROM_SW=0,
    DWT_DGC_LOAD_FROM_OTP
} dwt_dgc_load_location;

/*! ------------------------------------------------------------------------------------------------------------------
 * Structure typedef: dwt_config_t
 *
 * Structure for setting device configuration via dwt_configure() function
 *
 */
typedef struct
{
    uint8_t chan ;           //!< Channel number (5 or 9)
    uint8_t txPreambLength ; //!< DWT_PLEN_64..DWT_PLEN_4096
    uint8_t rxPAC ;          //!< Acquisition Chunk Size (Relates to RX preamble length)
    uint8_t txCode ;         //!< TX preamble code (the code configures the PRF, e.g. 9 -> PRF of 64 MHz)
    uint8_t rxCode ;         //!< RX preamble code (the code configures the PRF, e.g. 9 -> PRF of 64 MHz)
    uint8_t sfdType;         //!< SFD type (0 for short IEEE 8-bit standard, 1 for DW 8-bit, 2 for DW 16-bit, 3 for 4z BPRF)
    uint8_t dataRate ;       //!< Data rate {DWT_BR_850K or DWT_BR_6M8}
    uint8_t phrMode ;        //!< PHR mode {0x0 - standard DWT_PHRMODE_STD, 0x3 - extended frames DWT_PHRMODE_EXT}
    uint8_t phrRate;         //!< PHR rate {0x0 - standard DWT_PHRRATE_STD, 0x1 - at datarate DWT_PHRRATE_DTA}
    uint16_t sfdTO ;         //!< SFD timeout value (in symbols)
    uint8_t stsMode;         //!< STS mode (no STS, STS before PHR or STS after data)
    dwt_sts_lengths_e stsLength;    //!< STS length (the allowed values are listed in dwt_sts_lengths_e
    uint8_t pdoaMode;        //!< PDOA mode
} dwt_config_t ;


typedef struct
{
    uint8_t   PGdly;
    //TX POWER
    //31:24     TX_CP_PWR
    //23:16     TX_SHR_PWR
    //15:8      TX_PHR_PWR
    //7:0       TX_DATA_PWR
    uint32_t  power;
    uint16_t  PGcount;
} dwt_txconfig_t ;


typedef struct
{
    uint8_t       ipatovRxTime[5] ;   // RX timestamp from Ipatov sequence
    uint8_t       ipatovRxStatus ;    // RX status info for Ipatov sequence
    uint16_t      ipatovPOA ;         // POA of Ipatov

    uint8_t       stsRxTime[5] ;   // RX timestamp from STS
    uint16_t      stsRxStatus ;    // RX status info for STS
    uint16_t      stsPOA;          // POA of STS block 1
    uint8_t       sts2RxTime[5];   // RX timestamp from STS
    uint16_t      sts2RxStatus;    // RX status info for STS
    uint16_t      sts2POA;         // POA of STS block 2

    uint8_t       tdoa[6];            // TDOA from two STS RX timestamps
    uint16_t       pdoa;               // PDOA from two STS POAs signed int [1:-11] in radians

    uint16_t       xtalOffset ;        // estimated xtal offset of remote device
    uint32_t      ciaDiag1 ;          // Diagnostics common to both sequences

    uint32_t      ipatovPeak ;        // index and amplitude of peak sample in Ipatov sequence CIR
    uint32_t      ipatovPower ;       // channel area allows estimation of channel power for the Ipatov sequence
    uint32_t      ipatovF1 ;          // F1 for Ipatov sequence
    uint32_t      ipatovF2 ;          // F2 for Ipatov sequence
    uint32_t      ipatovF3 ;          // F3 for Ipatov sequence
    uint16_t      ipatovFpIndex ;     // First path index for Ipatov sequence 
    uint16_t      ipatovAccumCount ;  // Number accumulated symbols for Ipatov sequence

    uint32_t      stsPeak ;        // index and amplitude of peak sample in STS CIR
    uint16_t      stsPower ;       // channel area allows estimation of channel power for the STS
    uint32_t      stsF1 ;          // F1 for STS
    uint32_t      stsF2 ;          // F2 for STS
    uint32_t      stsF3 ;          // F3 for STS
    uint16_t      stsFpIndex ;     // First path index for STS
    uint16_t      stsAccumCount ;  // Number accumulated symbols for STS

    uint32_t      sts2Peak;        // index and amplitude of peak sample in STS CIR
    uint16_t      sts2Power;       // channel area allows estimation of channel power for the STS
    uint32_t      sts2F1;          // F1 for STS
    uint32_t      sts2F2;          // F2 for STS
    uint32_t      sts2F3;          // F3 for STS
    uint16_t      sts2FpIndex;     // First path index for STS
    uint16_t      sts2AccumCount;  // Number accumulated symbols for STS

} dwt_rxdiag_t ;


typedef struct
{
    //all of the below are mapped to a register in DW3000
    uint16_t PHE;                    //12-bit number of received header error events
    uint16_t RSL;                    //12-bit number of received frame sync loss event events
    uint16_t CRCG;                   //12-bit number of good CRC received frame events
    uint16_t CRCB;                   //12-bit number of bad CRC (CRC error) received frame events
    uint8_t  ARFE;                   //8-bit number of address filter error events
    uint8_t  OVER;                   //8-bit number of receive buffer overrun events (used in double buffer mode)
    uint16_t SFDTO;                  //12-bit number of SFD timeout events
    uint16_t PTO;                    //12-bit number of Preamble timeout events
    uint8_t  RTO;                    //8-bit number of RX frame wait timeout events
    uint16_t TXF;                    //12-bit number of transmitted frame events
    uint8_t  HPW;                    //8-bit half period warning events (when delayed RX/TX enable is used)
    uint8_t  CRCE;                   //8-bit SPI CRC error events
    uint16_t PREJ;                   //12-bit number of Preamble rejection events

} dwt_deviceentcnts_t ;

/********************************************************************************************************************/
/*                                                AES BLOCK                                                         */
/********************************************************************************************************************/

//enums below are defined in such a way as to allow a simple write to DW3000 AES configuration registers

/* For MIC size definition */
typedef enum {
    MIC_0 = 0,
    MIC_4, MIC_6, MIC_8, MIC_10, MIC_12, MIC_14, MIC_16
}dwt_mic_size_e;

/* Key size definition */
typedef enum {
    AES_KEY_128bit = 0,
    AES_KEY_192bit = 1,
    AES_KEY_256bit = 2
}dwt_aes_key_size_e;

/* Load key from RAM selection */
typedef enum {
    AES_KEY_No_Load = 0,
    AES_KEY_Load
}dwt_aes_key_load_e;

/* Key source - RAM or registers */
typedef enum {
    AES_KEY_Src_Register = 0,    /* Use AES KEY from registers */
    AES_KEY_Src_RAMorOTP         /* Use AES KEY from RAM or OTP (depending if AES_key_OTP set),
                                    AES_KEY_Load needs to be set as well */
}dwt_aes_key_src_e;

/* Operation selection */
typedef enum {
    AES_Encrypt = 0,
    AES_Decrypt
}dwt_aes_mode_e;

/* This defines the source port for encrypted/unencrypted data */
typedef enum {
    AES_Src_Scratch = 0,
    AES_Src_Rx_buf_0,
    AES_Src_Rx_buf_1,
    AES_Src_Tx_buf
}dwt_aes_src_port_e;

/* This defines the dest port for encrypted/unencrypted data */
typedef enum {
    AES_Dst_Scratch = 0,
    AES_Dst_Rx_buf_0,
    AES_Dst_Rx_buf_1,
    AES_Dst_Tx_buf,
    AES_Dst_STS_key
}dwt_aes_dst_port_e;

/* storage for 128/192/256-bit key */
typedef struct {
      uint32_t key0;
      uint32_t key1;
      uint32_t key2;
      uint32_t key3;
      uint32_t key4;
      uint32_t key5;
      uint32_t key6;
      uint32_t key7;
}dwt_aes_key_t;

typedef enum
{
    AES_core_type_GCM=0,    /* Core type GCM */
    AES_core_type_CCM       /* Core type CCM */
}dwt_aes_core_type_e;


typedef enum
{
    AES_key_RAM =0,     /* Use the AES KEY from RAM */
    AES_key_OTP         /* Use the AES KEY from OTP, key_load needs to match -> needs to be set to AES_KEY_Src_Ram */
}dwt_aes_key_otp_type_e;

typedef struct {
    dwt_aes_key_otp_type_e  aes_key_otp_type; //!< Using KEY from OTP or RAM, if this is set to AES_key_OTP, KEY from OTP is used
    dwt_aes_core_type_e     aes_core_type;    //!< Core type GCM or CCM*
    dwt_mic_size_e          mic;              //!< Message integrity code size
    dwt_aes_key_src_e       key_src;          //!< Location of the key: either as programmed in registers(128 bit) or in the RAM or in the OTP
    dwt_aes_key_load_e      key_load;         //!< Loads key from RAM or uses KEY from the registers
    uint8_t                 key_addr;         //!< Address offset of AES key when using AES key in RAM
    dwt_aes_key_size_e      key_size;         //!< AES key length configuration corresponding to AES_KEY_128/192/256bit
    dwt_aes_mode_e          mode;             //!< Operation type encrypt/decrypt
} dwt_aes_config_t ;

typedef struct {
    uint8_t             *nonce;      //!< Pointer to the nonce
    uint8_t             *header;     //!< Pointer to header (this is not encrypted/decrypted)
    uint8_t             *payload;    //!< Pointer to payload (this is encrypted/decrypted)
    uint8_t             header_len;  //!< Header size
    uint16_t            payload_len; //!< Payload size
    dwt_aes_src_port_e  src_port;    //!< Source port
    dwt_aes_dst_port_e  dst_port;    //!< Dest port
    dwt_aes_mode_e      mode;        //!< Encryption or decryption
    uint8_t             mic_size;    //!< tag_size;
}dwt_aes_job_t;

/* storage for 128-bit STS CP key */
typedef struct {
    uint32_t key0;
    uint32_t key1;
    uint32_t key2;
    uint32_t key3;
}dwt_sts_cp_key_t;

/* storage for 128-bit STS CP IV (nonce) */
typedef struct {
    uint32_t iv0;
    uint32_t iv1;
    uint32_t iv2;
    uint32_t iv3;
}dwt_sts_cp_iv_t;


#define ERROR_DATA_SIZE      (-1)
#define ERROR_WRONG_MODE     (-2)
#define ERROR_WRONG_MIC_SIZE (-3)
#define ERROR_PAYLOAD_SIZE   (-4)
#define MIC_ERROR            (0xff)
#define STS_LEN_128BIT       (16)

typedef enum
{
    DBL_BUF_STATE_EN=0,/*Double buffer enabled*/
    DBL_BUF_STATE_DIS/*Double buffer disabled*/
}dwt_dbl_buff_state_e;

typedef enum
{
    DBL_BUF_MODE_AUTO=0,/*Automatic*/
    DBL_BUF_MODE_MAN/*Manual*/
}dwt_dbl_buff_mode_e;

/*
  Lookup table default values for channel 5
*/
typedef enum
{
    CH5_DGC_LUT_0 = 0x1c0fd,
    CH5_DGC_LUT_1 = 0x1c43e,
    CH5_DGC_LUT_2 = 0x1c6be,
    CH5_DGC_LUT_3 = 0x1c77e,
    CH5_DGC_LUT_4 = 0x1cf36,
    CH5_DGC_LUT_5 = 0x1cfb5,
    CH5_DGC_LUT_6 = 0x1cff5
} dwt_configmrxlut_ch5_e;

/*
  Lookup table default values for channel 9
*/
typedef enum
{
    CH9_DGC_LUT_0 = 0x2a8fe,
    CH9_DGC_LUT_1 = 0x2ac36,
    CH9_DGC_LUT_2 = 0x2a5fe,
    CH9_DGC_LUT_3 = 0x2af3e,
    CH9_DGC_LUT_4 = 0x2af7d,
    CH9_DGC_LUT_5 = 0x2afb5,
    CH9_DGC_LUT_6 = 0x2afb5
} dwt_configmrxlut_ch9_e;

#define DBL_BUFF_OFF             0x0
#define DBL_BUFF_ACCESS_BUFFER_0 0x1
#define DBL_BUFF_ACCESS_BUFFER_1 0x3

/********************************************************************************************************************/
/*                                                     API LIST                                                     */
/********************************************************************************************************************/

static void dwt_force_clocks(int clocks);

static void dwt_xfer3000( uint32_t    regFileID,  //0x0, 0x04-0x7F ; 0x10000, 0x10004, 0x10008-0x1007F; 0x20000 etc
    uint16_t    indx,       //sub-index, calculated from regFileID 0..0x7F,
    uint16_t    length,
    uint8_t           *buffer,
    spi_modes_e mode);

static void _dwt_otpprogword32(uint32_t data, uint16_t address);

void setup_localdata();

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function returns the version of the API as defined by DW3000_DRIVER_VERSION
 *
 * input parameters
 *
 * output parameters
 *
 * returns version (DW3000_DRIVER_VERSION)
 */
int32_t dwt_apiversion(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function sets the local data structure pointer to point to the element in the local array as given by the index.
 *
 * input parameters
 * @param index    - selects the array element to point to. Must be within the array bounds, i.e. < DWT_NUM_DW_DEV
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
int dwt_setlocaldataptr();

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief Returns the PG delay value of the TX
 *
 * input parameters
 *
 * output parameters
 *
 * returns uint8_t
 */
uint8_t dwt_readpgdelay(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read V measured @ 3.3 V value recorded in OTP address 0x8 (VBAT_ADDRESS)
 *
 * NOTE: dwt_initialise() must be called prior to this function so that it can return a relevant value.
 *
 * input parameters
 *
 * output parameters
 *
 * returns the 8 bit V bat value as programmed in the factory
 */
uint8_t dwt_geticrefvolt(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read T measured @ 23 C value recorded in OTP address 0x9 (VTEMP_ADDRESS)
 *
 * NOTE: dwt_initialise() must be called prior to this function so that it can return a relevant value.
 *
 * input parameters
 *
 * output parameters
 *
 * returns the 8 bit V temp value as programmed in the factory
 */
uint8_t dwt_geticreftemp(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read part ID of the device
 *
 * NOTE: dwt_initialise() must be called prior to this function so that it can return a relevant value.
 *
 * input parameters
 *
 * output parameters
 *
 * returns the 32 bit part ID value as programmed in the factory
 */
uint32_t dwt_getpartid(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read lot ID of the device
 *
 * NOTE: dwt_initialise() must be called prior to this function so that it can return a relevant value.
 *
 * input parameters
 *
 * output parameters
 *
 * returns the 32 bit lot ID value as programmed in the factory
 */
uint32_t dwt_getlotid(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read device type and revision information of the DW3000 device (MP part is 0xDECA0130)
 *
 * input parameters
 *
 * output parameters
 *
 * returns the read value which for DW3000 is 0xDECA0130
 */
uint32_t dwt_readdevid(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to return the read OTP revision
 *
 * NOTE: dwt_initialise() must be called prior to this function so that it can return a relevant value.
 *
 * input parameters
 *
 * output parameters
 *
 * returns the read OTP revision value
 */
uint8_t dwt_otprevision(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function enables/disables the fine grain TX sequencing (enabled by default).
 *
 * input parameters
 * @param enable - 1 to enable fine grain TX sequencing, 0 to disable it.
 *
 * output parameters none
 *
 * no return value
 */
void dwt_setfinegraintxseq(uint8_t enable);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to enable GPIO for external LNA or PA functionality - HW dependent, consult the DW3000 User Manual.
 *        This can also be used for debug as enabling TX and RX GPIOs is quite handy to monitor DW3000's activity.
 *
 * NOTE: Enabling PA functionality requires that fine grain TX sequencing is deactivated. This can be done using
 *       dwt_setfinegraintxseq().
 *
 * input parameters
 * @param lna_pa - bit field: bit 0 if set will enable LNA functionality,
 *                          : bit 1 if set will enable PA functionality,
 *                          : to disable LNA/PA set the bits to 0 (
 * output parameters
 *
 * no return value
 */
void dwt_setlnapamode(uint8_t lna_pa);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function initialises the DW3000 transceiver:
 * it reads its DEV_ID register (address 0x00) to verify the IC is one supported
 * by this software (e.g. DW3000 32-bit device ID value is 0xDECA03xx).  Then it
 * does any initial once only device configurations needed for use and initialises
 * as necessary any static data items belonging to this low-level driver.
 *
 * NOTES:
 * 1.this function needs to be run before dwt_configuresleep, also the SPI frequency has to be < 3MHz
 * 2.it also reads and applies LDO and BIAS tune and crystal trim values from OTP memory
 * 3.it is assumed this function is called after a reset or on power up of the DW3000*
 *
 * input parameters
 * @param mode - mask which defines which OTP values to read.
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
int dwt_initialise(uint8_t mode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function can place DW3000 into IDLE/IDLE_PLL or IDLE_RC mode when it is not actively in TX or RX.
 *
 * input parameters
 * @param state - DWT_DW_IDLE (1) to put DW3000 into IDLE/IDLE_PLL state; DWT_DW_INIT (0) to put DW3000 into INIT_RC state;
 *                DWT_DE_IDLE_RC (2) to put DW3000 into IDLE_RC state.
 *
 * output parameters none
 *
 * no return value
 */
void dwt_setdwstate(uint8_t state);


/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to enable GPIO clocks. The clocks are needed to ensure correct GPIO operation
 *
 * input parameters
 *
 * output parameters
 *
 * no return value
 */
void dwt_enablegpioclocks(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function needs to be called after device is woken up from DEEPSLEEP/SLEEP state, to restore the
 * configuration which has not been automatically restored from AON
 *
 * input parameters
 *
 * return DWT_SUCCESS
 *
 */
void dwt_restoreconfig(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function configures STS mode: e.g. DWT_STS_MODE_OFF, DWT_STS_MODE_1 etc
 * The dwt_configure should be called prior to this to configure other parameters
 *
 * input parameters
 * @param stsMode    -   e.g. DWT_STS_MODE_OFF, DWT_STS_MODE_1 etc.
 *
 * return DWT_SUCCESS
 *
 */
void dwt_configurestsmode(uint8_t stsMode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function provides the main API for the configuration of the
 * DW3000 and this low-level driver.  The input is a pointer to the data structure
 * of type dwt_config_t that holds all the configurable items.
 * The dwt_config_t structure shows which ones are supported
 *
 * input parameters
 * @param config    -   pointer to the configuration structure, which contains the device configuration data.
 *
 * output parameters
 *
 * return DWT_SUCCESS or DWT_ERROR (e.g. when PLL CAL fails / PLL fails to lock)
 */
int dwt_configure(dwt_config_t *config);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function provides the API for the configuration of the TX spectrum
 * including the power and pulse generator delay. The input is a pointer to the data structure
 * of type dwt_txconfig_t that holds all the configurable items.
 *
 * input parameters
 * @param config    -   pointer to the txrf configuration structure, which contains the tx rf config data
 *
 * output parameters
 *
 * no return value
 */
void dwt_configuretxrf(dwt_txconfig_t *config);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function re-loads the STS AES initial value
 *
 * input parameters
 *
 * output parameters
 *
 * no return value
 */
void dwt_configurestsloadiv(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function sets the default values of the lookup tables depending on the channel selected.
 *
 * input parameters
 * @param[in] channel - Channel that the device will be transmitting/receiving on.
 *
 * no return value
 */
void dwt_configmrxlut(uint8_t channel);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function configures the STS AES 128 bit key value.
 * the default value is [31:00]c9a375fa,
 *                      [63:32]8df43a20,
 *                      [95:64]b5e5a4ed,
 *                     [127:96]0738123b
 *
 * input parameters
 * @param pStsKey - the pointer to the structure of dwt_sts_cp_key_t type, which holds the AES128 key value to generate STS
 *
 * output parameters
 *
 * no return value
 */
void dwt_configurestskey(dwt_sts_cp_key_t* pStsKey);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function configures the STS AES 128 bit initial value, the default value is 1, i.e. DW3000 reset value is 1.
 *
 * input parameters
 * @param pStsIv - the pointer to the structure of dwt_sts_cp_iv_t type, which holds the IV value to generate STS
 *
 * output parameters
 *
 * no return value
 */
void dwt_configurestsiv(dwt_sts_cp_iv_t* pStsIv);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function writes the antenna delay (in time units) to RX registers
 *
 * input parameters:
 * @param rxDelay - this is the total (RX) antenna delay value, which
 *                          will be programmed into the RX register
 *
 * output parameters
 *
 * no return value
 */
void dwt_setrxantennadelay(uint16_t antennaDly);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function writes the antenna delay (in time units) to TX registers
 *
 * input parameters:
 * @param txDelay - this is the total (TX) antenna delay value, which
 *                          will be programmed into the TX delay register
 *
 * output parameters
 *
 * no return value
 */
void dwt_settxantennadelay(uint16_t antennaDly);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function writes the supplied TX data into the DW3000's
 * TX buffer.  The input parameters are the data length in bytes and a pointer
 * to those data bytes.
 *
 * input parameters
 * @param txDataLength   - This is the total length of data (in bytes) to write to the tx buffer.
 *                         Note: the size of tx buffer is 1024 bytes.
 *                         The standard PHR mode allows to transmit frames of up to 127 bytes (including 2 byte CRC)
 *                         The extended PHR mode allows to transmit frames of up to 1023 bytes (including 2 byte CRC)
 *                         if > 127 is programmed, DWT_PHRMODE_EXT needs to be set in the phrMode configuration
 *                         see dwt_configure function
 * @param txDataBytes    - Pointer to the user's buffer containing the data to send.
 * @param txBufferOffset - This specifies an offset in the DW IC's TX Buffer at which to start writing data.
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
int dwt_writetxdata(uint16_t txDataLength, uint8_t *txDataBytes, uint16_t txBufferOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function configures the TX frame control register before the transmission of a frame
 *
 * input parameters:
 * @param txFrameLength - this is the length of TX message (including the 2 byte CRC) - max is 1023
 *                              NOTE: standard PHR mode allows up to 127 bytes
 *                              if > 127 is programmed, DWT_PHRMODE_EXT needs to be set in the phrMode configuration
 *                              see dwt_configure function
 * @param txBufferOffset - the offset in the tx buffer to start writing the data
 * @param ranging - 1 if this is a ranging frame, else 0
 *
 * output parameters
 *
 * no return value
 */
void dwt_writetxfctrl(uint16_t txFrameLength, uint16_t txBufferOffset, uint8_t ranging);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function is used to configure frame preamble length, the frame premable length can be
 * configured in steps of 8, from 16 to 2048 symbols. If a non-zero value is configured, then the TXPSR_PE setting is ignored.
 *
 * input parameters:
 * @param preambleLength - sets the length of the preamble, value of 0 disables this setting and the length of the
 *                         frame will be dependent on the TXPSR_PE setting as configured by dwt_configure function
 *
 * output parameters
 *
 * no return value
 */
void dwt_setplenfine(uint8_t preambleLength);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This call initiates the transmission, input parameter indicates which TX mode is used see below
 *
 * input parameters:
 * @param mode - if mode = DWT_START_TX_IMMEDIATE - immediate TX (no response expected)
 *               if mode = DWT_START_TX_DELAYED - delayed TX (no response expected)  at specified time (time in DX_TIME register)
 *               if mode = DWT_START_TX_DLY_REF - delayed TX (no response expected)  at specified time (time in DREF_TIME register + any time in DX_TIME register)
 *               if mode = DWT_START_TX_DLY_RS  - delayed TX (no response expected)  at specified time (time in RX_TIME_0 register + any time in DX_TIME register)
 *               if mode = DWT_START_TX_DLY_TS  - delayed TX (no response expected)  at specified time (time in TX_TIME_LO register + any time in DX_TIME register)
 *               if mode = DWT_START_TX_IMMEDIATE | DWT_RESPONSE_EXPECTED - immediate TX (response expected - so the receiver will be automatically turned on after TX is done)
 *               if mode = DWT_START_TX_DELAYED | DWT_RESPONSE_EXPECTED - delayed TX (response expected - so the receiver will be automatically turned on after TX is done)
 *               if mode = DWT_START_TX_CCA - Send the frame if no preamble detected within PTO time
 *               if mode = DWT_START_TX_CCA  | DWT_RESPONSE_EXPECTED - Send the frame if no preamble detected within PTO time and then enable RX
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error (e.g. a delayed transmission will be cancelled if the delayed time has passed)
 */
int dwt_starttx(uint8_t mode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function configures the reference time used for relative timing of delayed sending and reception.
 * The value is at a 8ns resolution.
 *
 * input parameters
 * @param reftime - the reference time (which together with DX_TIME or TX timestamp or RX timestamp time is used to define a
 * transmission time or delayed RX on time)
 *
 * output parameters none
 *
 * no return value
 */
void dwt_setreferencetrxtime(uint32_t reftime);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This API function configures the delayed transmit time or the delayed RX on time
 *
 * input parameters
 * @param starttime - the TX/RX start time (the 32 bits should be the high 32 bits of the system time at which to send the message,
 * or at which to turn on the receiver)
 *
 * output parameters none
 *
 * no return value
 */
void dwt_setdelayedtrxtime(uint32_t starttime);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the TX timestamp (adjusted with the programmed antenna delay)
 *
 * input parameters
 * @param timestamp - a pointer to a 5-byte buffer which will store the read TX timestamp time
 *
 * output parameters - the timestamp buffer will contain the value after the function call
 *
 * no return value
 */
void dwt_readtxtimestamp(uint8_t * timestamp);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the high 32-bits of the TX timestamp (adjusted with the programmed antenna delay)
 *
 * input parameters
 *
 * output parameters
 *
 * returns high 32-bits of TX timestamp
 */
uint32_t dwt_readtxtimestamphi32(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the low 32-bits of the TX timestamp (adjusted with the programmed antenna delay)
 *
 * input parameters
 *
 * output parameters
 *
 * returns low 32-bits of TX timestamp
 */
uint32_t dwt_readtxtimestamplo32(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the PDOA result, it is the phase difference between either the Ipatov and STS POA, or
 * the two STS POAs, depending on the PDOA mode of operation. (POA - Phase Of Arrival)
 *
 * NOTE: To convert to degrees: float pdoa_deg = ((float)pdoa / (1 << 11)) * 180 / M_PI
 *
 * input parameters
 *
 * output parameters - the PDOA result (signed in [1:-11] radian units)
 *
 * no return value
 */
int16_t dwt_readpdoa(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function is used to read the TDOA (Time Difference On Arrival). The TDOA value that is read from the
 * register is 41-bits in length. However, 6 bytes (or 48 bits) are read from the register. The remaining 7 bits at
 * the 'top' of the 6 bytes that are not part of the TDOA value should be set to zero and should not interfere with
 * rest of the 41-bit value. However, there is no harm in masking the returned value.
 * 
 * input parameters
 * 
 * output parameters
 * @param tdoa: time difference on arrival - buffer of 6 bytes that will be filled with TDOA value by calling this function
 * 
 * no return value
 */
void dwt_readtdoa(uint8_t * tdoa);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the RX timestamp (adjusted time of arrival)
 *
 * input parameters
 * @param timestamp - a pointer to a 5-byte buffer which will store the read RX timestamp time
 *
 * output parameters - the timestamp buffer will contain the value after the function call
 *
 * no return value
 */
void dwt_readrxtimestamp(uint8_t * timestamp);
void dwt_readrxtimestampunadj(uint8_t * timestamp);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the RX timestamp (adjusted time of arrival) w.r.t. Ipatov CIR
 *
 * input parameters
 * @param timestamp - a pointer to a 5-byte buffer which will store the read RX timestamp time
 *
 * output parameters - the timestamp buffer will contain the value after the function call
 *
 * no return value
 */
void dwt_readrxtimestamp_ipatov(uint8_t * timestamp);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the RX timestamp (adjusted time of arrival) w.r.t. STS CIR
 *
 * input parameters
 * @param timestamp - a pointer to a 5-byte buffer which will store the read RX timestamp time
 *
 * output parameters - the timestamp buffer will contain the value after the function call
 *
 * no return value
 */
void dwt_readrxtimestamp_sts(uint8_t * timestamp);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the high 32-bits of the RX timestamp (adjusted with the programmed antenna delay)
 *
 * input parameters
 *
 * output parameters
 *
 * returns high 32-bits of RX timestamp
 */
uint32_t dwt_readrxtimestamphi32(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the low 32-bits of the RX timestamp (adjusted with the programmed antenna delay)
 *
 * input parameters
 *
 * output parameters
 *
 * returns low 32-bits of RX timestamp
 */
uint32_t dwt_readrxtimestamplo32(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the high 32-bits of the system time
 *
 * input parameters
 *
 * output parameters
 *
 * returns high 32-bits of system time timestamp
 */
uint32_t dwt_readsystimestamphi32(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to turn off the transceiver
 *
 * input parameters
 *
 * output parameters
 *
 * no return value
 */
void dwt_forcetrxoff(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This call turns on the receiver, can be immediate or delayed (depending on the mode parameter). In the case of a
 * "late" error the receiver will only be turned on if the DWT_IDLE_ON_DLY_ERR is not set.
 * The receiver will stay turned on, listening to any messages until
 * it either receives a good frame, an error (CRC, PHY header, Reed Solomon) or  it times out (SFD, Preamble or Frame).
 *
 * input parameters
 * @param mode - this can be one of the following allowed values:
 *
 * DWT_START_RX_IMMEDIATE      0x00    Enable the receiver immediately
 * DWT_START_RX_DELAYED        0x01    Set up delayed RX, if "late" error triggers, then the RX will be enabled immediately
 * DWT_IDLE_ON_DLY_ERR         0x02    If delayed RX failed due to "late" error then if this
                                       flag is set the RX will not be re-enabled immediately, and device will be in IDLE when function exits
 * DWT_START_RX_DLY_REF        0x04    Enable the receiver at specified time (time in DREF_TIME register + any time in DX_TIME register)
 * DWT_START_RX_DLY_RS         0x08    Enable the receiver at specified time (time in RX_TIME_0 register + any time in DX_TIME register)
 * DWT_START_RX_DLY_TS         0x10    Enable the receiver at specified time (time in TX_TIME_LO register + any time in DX_TIME register)

 * e.g.
 * (DWT_START_RX_DELAYED | DWT_IDLE_ON_DLY_ERR) 0x03 used to disable re-enabling of receiver if delayed RX failed due to "late" error
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error (e.g. a delayed receive enable will be too far in the future if delayed time has passed)
 */
int dwt_rxenable(int mode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief enable/disable and configure SNIFF mode.
 *
 * SNIFF mode is a low-power reception mode where the receiver is sequenced on and off instead of being on all the time.
 * The time spent in each state (on/off) is specified through the parameters below.
 * See DW3000 User Manual section 4.5 "Low-Power SNIFF mode" for more details.
 *
 * input parameters:
 * @param enable - 1 to enable SNIFF mode, 0 to disable. When 0, all other parameters are not taken into account.
 * @param timeOn - duration of receiver ON phase, expressed in multiples of PAC size. The counter automatically adds 1 PAC
 *                 size to the value set. Min value that can be set is 1 (i.e. an ON time of 2 PAC size), max value is 15.
 * @param timeOff - duration of receiver OFF phase, expressed in multiples of 128/125 μs (~1 μs). Max value is 255.
 *
 * output parameters
 *
 * no return value
 */
void dwt_setsniffmode(uint8_t enable, uint8_t timeOn, uint8_t timeOff);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This call enables the double receive buffer mode
 *
 * input parameters
 * @param dbl_buff_state - enum variable for enabling/disabling double buffering mode
 * @param dbl_buff_mode - enum variable for Receiver Auto-Re-enable
 *
 * output parameters
 *
 * no return value
 */
void dwt_setdblrxbuffmode(dwt_dbl_buff_state_e dbl_buff_state, dwt_dbl_buff_mode_e dbl_buff_mode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This call signal to the chip that the specific RX buff is free for fill
 *
 * input parameters
 * @param None
 *
 * output parameters
 *
 * no return value
 */
void dwt_signal_rx_buff_free(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This call enables RX timeout (SY_STAT_RFTO event)
 *
 * input parameters
 * @param time - how long the receiver remains on from the RX enable command
 *               The time parameter used here is in 1.0256 us (512/499.2MHz) units
 *               If set to 0 the timeout is disabled.
 *
 * output parameters
 *
 * no return value
 */
void dwt_setrxtimeout(uint32_t time);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This call enables preamble timeout (SY_STAT_RXPTO event)
 *
 * input parameters
 * @param  timeout - Preamble detection timeout, expressed in multiples of PAC size. The counter automatically adds 1 PAC
 *                   size to the value set. Min value that can be set is 1 (i.e. a timeout of 2 PAC size).
 *
 * output parameters
 *
 * no return value
 */
void dwt_setpreambledetecttimeout(uint16_t timeout);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief calibrates the local oscillator as its frequency can vary between 15 and 34kHz depending on temp and voltage
 *
 * NOTE: this function needs to be run before dwt_configuresleepcnt, so that we know what the counter units are
 *
 * input parameters
 *
 * output parameters
 *
 * returns the number of XTAL cycles per low-power oscillator cycle. LP OSC frequency = 38.4 MHz/return value
 */
uint16_t dwt_calibratesleepcnt(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief sets the sleep counter to new value, this function programs the high 16-bits of the 28-bit counter
 *
 * NOTE: this function needs to be run before dwt_configuresleep, also the SPI frequency has to be < 3MHz
 *
 * input parameters
 * @param sleepcnt - this it value of the sleep counter to program
 *
 * output parameters
 *
 * no return value
 */
 void dwt_configuresleepcnt(uint16_t sleepcnt);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief configures the device for both DEEP_SLEEP and SLEEP modes, and on-wake mode
 * i.e. before entering the sleep, the device should be programmed for TX or RX, then upon "waking up" the TX/RX settings
 * will be preserved and the device can immediately perform the desired action TX/RX
 *
 * NOTE: e.g. Tag operation - after deep sleep, the device needs to just load the TX buffer and send the frame
 *
 *
 *      mode:
 *      DWT_PGFCAL       0x0800
 *      DWT_GOTORX       0x0200
 *      DWT_GOTOIDLE     0x0100
 *      DWT_SEL_OPS      0x0040 | 0x0080
 *      DWT_LOADOPS      0x0020
 *      DWT_LOADLDO      0x0010
 *      DWT_LOADDGC      0x0008
 *      DWT_LOADBIAS     0x0004
 *      DWT_RUNSAR       0x0002
 *      DWT_CONFIG       0x0001 - download the AON array into the HIF (configuration download)
 *
 *      wake: wake up parameters
 *      DWT_SLP_CNT_RPT  0x40 - sleep counter loop after expiration
 *      DWT_PRESRVE_SLP  0x20 - allows for SLEEP_EN bit to be "preserved", although it will self-clear on wake up
 *      DWT_WAKE_WK      0x10 - wake up on WAKEUP PIN
 *      DWT_WAKE_CS      0x8 - wake up on chip select
 *      DWT_BR_DET       0x4 - enable brownout detector during sleep/deep sleep
 *      DWT_SLEEP        0x2 - enable sleep
 *      DWT_SLP_EN       0x1 - enable sleep/deep sleep functionality
 *
 * input parameters
 * @param mode - config on-wake parameters
 * @param wake - config wake up parameters
 *
 * output parameters
 *
 * no return value
 */
void dwt_configuresleep(uint16_t mode, uint8_t wake);

/*! ------------------------------------------------------------------------------------------------------------------
*
* @brief this function clears the AON configuration in DW3000
*
* input parameters:
*
* output parameters
*
* no return value
*/
void dwt_clearaonconfig(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function puts the device into deep sleep or sleep. dwt_configuresleep() should be called first
 * to configure the sleep and on-wake/wake-up parameters
 *
 * input parameters
 * @param idle_rc - if this is set to DWT_DW_IDLE_RC, the auto INIT2IDLE bit will be cleared prior to going to sleep
 *                  thus after wakeup device will stay in IDLE_RC state
 *
 * output parameters
 *
 * no return value
 */
void dwt_entersleep(uint8_t idle_rc);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief sets the auto TX to sleep bit. This means that after a frame
 * transmission the device will enter deep sleep mode. The dwt_configuresleep() function
 * needs to be called before this to configure the on-wake settings
 *
 * NOTE: the IRQ line has to be low/inactive (i.e. no pending events)
 *
 * input parameters
 * @param enable - 1 to configure the device to enter deep sleep after TX, 0 - disables the configuration
 *
 * output parameters
 *
 * no return value
 */
void dwt_entersleepaftertx(uint8_t enable);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function is used to register the different callbacks called when one of the corresponding event occurs.
 *
 * NOTE: Callbacks can be undefined (set to NULL). In this case, dwt_isr() will process the event as usual but the 'null'
 * callback will not be called.
 *
 * input parameters
 * @param cbTxDone - the pointer to the TX confirmation event callback function
 * @param cbRxOk - the pointer to the RX good frame event callback function
 * @param cbRxTo - the pointer to the RX timeout events callback function
 * @param cbRxErr - the pointer to the RX error events callback function
 * @param cbSPIErr - the pointer to the SPI error events callback function
 * @param cbSPIRdy - the pointer to the SPI ready events callback function
 *
 * output parameters
 *
 * no return value
 */
void dwt_setcallbacks(dwt_cb_t cbTxDone, dwt_cb_t cbRxOk, dwt_cb_t cbRxTo, dwt_cb_t cbRxErr, dwt_cb_t cbSPIErr, dwt_cb_t cbSPIRdy);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function checks if the IRQ line is active - this is used instead of interrupt handler
 *
 * input parameters
 *
 * output parameters
 *
 * return value is 1 if the IRQS bit is set and 0 otherwise
 */
uint8_t dwt_checkirq(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function checks if the DW3000 is in IDLE_RC state
 *
 * input parameters
 *
 * output parameters
 *
 * return value is 1 if the IDLE_RC bit is set and 0 otherwise
 */
uint8_t dwt_checkidlerc(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is the DW3000's general Interrupt Service Routine. It will process/report the following events:
 *          - RXFCG (through cbRxOk callback)
 *          - TXFRS (through cbTxDone callback)
 *          - RXRFTO/RXPTO (through cbRxTo callback)
 *          - RXPHE/RXFCE/RXRFSL/RXSFDTO/AFFREJ/LDEERR (through cbRxErr callback)
 *        For all events, corresponding interrupts are cleared and necessary resets are performed. In addition, in the RXFCG case,
 *        received frame information and frame control are read before calling the callback. If double buffering is activated, it
 *        will also toggle between reception buffers once the reception callback processing has ended.
 *
 *        /!\ This version of the ISR supports double buffering but does not support automatic RX re-enabling!
 *
 * NOTE:  In PC based system using (Cheetah or ARM) USB to SPI converter there can be no interrupts, however we still need something
 *        to take the place of it and operate in a polled way. In an embedded system this function should be configured to be triggered
 *        on any of the interrupts described above.

 * input parameters
 *
 * output parameters
 *
 * no return value
 */
void dwt_isr(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function enables the specified events to trigger an interrupt.
 * The following events can be found in SYS_ENABLE_LO and SYS_ENABLE_HI registers.
 *
 *
 * input parameters:
 * @param bitmask_lo - sets the events in SYS_ENABLE_LO_ID register which will generate interrupt
 * @param bitmask_hi - sets the events in SYS_ENABLE_HI_ID register which will generate interrupt
 * @param operation  - if set to DWT_ENABLE_INT additional interrupts as selected in the bitmask are enabled
 *                   - if set to DWT_ENABLE_INT_ONLY the interrupts in the bitmask are forced to selected state -
 *                      i.e. the mask is written to the register directly.
 *                   - otherwise (if set to DWT_DISABLE_INT) clear the interrupts as selected in the bitmask
 * output parameters
 *
 * no return value
 */
void dwt_setinterrupt(uint32_t bitmask_lo, uint32_t bitmask_hi, dwt_INT_options_e INT_options);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to set the PAN ID
 *
 * input parameters
 * @param panID - this is the PAN ID
 *
 * output parameters
 *
 * no return value
 */
void dwt_setpanid(uint16_t panID);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to set 16-bit (short) address
 *
 * input parameters
 * @param shortAddress - this sets the 16 bit short address
 *
 * output parameters
 *
 * no return value
 */
void dwt_setaddress16(uint16_t shortAddress);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to set the EUI 64-bit (long) address
 *
 * input parameters
 * @param eui64 - this is the pointer to a buffer that contains the 64bit address
 *
 * output parameters
 *
 * no return value
 */
void dwt_seteui(uint8_t *eui64);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to get the EUI 64-bit from the DW3000
 *
 * input parameters
 * @param eui64 - this is the pointer to a buffer that will contain the read 64-bit EUI value
 *
 * output parameters
 *
 * no return value
 */
void dwt_geteui(uint8_t *eui64);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read from AON memory
 *
 * input parameters
 * @param aon_address - this is the address of the memory location to read
 *
 * output parameters - None
 *
 * returns 8-bits read from given AON memory address
 */
uint8_t dwt_aon_read(uint16_t aon_address);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to write to AON memory
 *
 * @param aon_address - this is the address of the memory location to write
 * @param aon_write_data - this is the data to write
 *
 * output parameters - None
 *
 * no return value
 *
 */
void dwt_aon_write(uint16_t aon_address, uint8_t aon_write_data);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the OTP data from given address into provided array
 *
 * input parameters
 * @param address - this is the OTP address to read from
 * @param array - this is the pointer to the array into which to read the data
 * @param length - this is the number of 32 bit words to read (array needs to be at least this length)
 *
 * output parameters
 *
 * no return value
 */
void dwt_otpread(uint16_t address, uint32_t *array, uint8_t length);

static uint32_t _dwt_otpread(uint16_t address);

static uint16_t get_sts_mnth (uint16_t cipher, uint8_t threshold, uint8_t shift_val);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to enable the frame filtering - (the default option is to
 * accept any data and ACK frames with correct destination address
 *
 * input parameters
 * @param enabletype (bitmask) - enables/disables the frame filtering and configures 802.15.4 type
 *       DWT_FF_ENABLE_802_15_4      0x2             // use 802.15.4 filtering rules
 *       DWT_FF_DISABLE              0x0             // disable FF
 * @param filtermode (bitmask) - configures the frame filtering options according to
 *       DWT_FF_BEACON_EN            0x001           // beacon frames allowed
 *       DWT_FF_DATA_EN              0x002           // data frames allowed
 *       DWT_FF_ACK_EN               0x004           // ack frames allowed
 *       DWT_FF_MAC_EN               0x008           // mac control frames allowed
 *       DWT_FF_RSVD_EN              0x010           // reserved frame types allowed
 *       DWT_FF_MULTI_EN             0x020           // multipurpose frames allowed
 *       DWT_FF_FRAG_EN              0x040           // fragmented frame types allowed
 *       DWT_FF_EXTEND_EN            0x080           // extended frame types allowed
 *       DWT_FF_COORD_EN             0x100           // behave as coordinator (can receive frames with no dest address (PAN ID has to match))
 *       DWT_FF_IMPBRCAST_EN         0x200           // allow MAC implicit broadcast
 *
 * output parameters
 *
 * no return value
 */
void dwt_configureframefilter(uint16_t enabletype, uint16_t filtermode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to calculate 8-bit CRC, it uses 100000111 polynomial (i.e. P(x) = x^8+ x^2+ x^1+ x^0)
 *
 * input parameters:
 * @param byteArray     - data to calculate CRC for
 * @param flen          - length of byteArray
 * @param crcInit       - initialisation value for CRC calculation
 *
 * output parameters
 *
 * returns 8-bit calculate CRC value
 */
uint8_t dwt_generatecrc8(const uint8_t* byteArray, uint8_t flen, uint8_t crcInit);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to enable SPI CRC check in DW3000
 *
 * input parameters
 * @param crc_mode - if set to DWT_SPI_CRC_MODE_WR then SPI CRC checking will be performed in DW3000 on each SPI write
 *                   last byte of the SPI write transaction needs to be the 8-bit CRC, if it does not match
 *                   the one calculated by DW3000 SPI CRC ERROR event will be set in the status register (SYS_STATUS_SPICRC)
 *
 * @param spireaderr_cb - this needs to contain the callback function pointer which will be called when SPI read error
 *                        is detected (when the DW3000 generated CRC does not match the one calculated by  dwt_generatecrc8
 *                        following the SPI read transaction)
 *
 * output parameters
 *
 * no return value
 */
void dwt_enablespicrccheck(dwt_spi_crc_mode_e crc_mode, dwt_spierrcb_t spireaderr_cb);

/*! ------------------------------------------------------------------------------------------------------------------
* @brief This call enables the auto-ACK feature. If the responseDelayTime (parameter) is 0, the ACK will be sent a.s.a.p.
* otherwise it will be sent with a programmed delay (in symbols), max is 255.
* NOTE: needs to have frame filtering enabled as well
*
* input parameters
* @param responseDelayTime - if non-zero the ACK is sent after this delay, max is 255.
* @param enable - enables or disables the auto-ACK feature
*
* output parameters
*
* no return value
*/
void dwt_enableautoack(uint8_t responseDelayTime, uint8_t enable);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This sets the receiver turn on delay time after a transmission of a frame
 *
 * input parameters
 * @param rxDelayTime - (20 bits) - the delay is in UWB microseconds
 *
 * output parameters
 *
 * no return value
 */
void dwt_setrxaftertxdelay(uint32_t rxDelayTime);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function resets the DW3000
 *
 * NOTE: SPI rate must be <= 7MHz before a call to this function as the device will use FOSC/4 as part of internal reset
 *
 * input parameters:
 *
 * output parameters
 *
 * no return value
 */
void dwt_softreset(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the data from the RX buffer, from an offset location give by offset parameter
 *
 * input parameters
 * @param buffer - the buffer into which the data will be read
 * @param length - the length of data to read (in bytes)
 * @param rxBufferOffset - the offset in the rx buffer from which to read the data
 *
 * output parameters
 *
 * no return value
 */
void dwt_readrxdata(uint8_t *buffer, uint16_t length, uint16_t rxBufferOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the data from the RX scratch buffer, from an offset location given by offset parameter.
 *
 * input parameters
 * @param buffer - the buffer into which the data will be read
 * @param length - the length of data to read (in bytes)
 * @param rxBufferOffset - the offset in the rx buffer from which to read the data
 *
 * output parameters
 *
 * no return value
 */
void dwt_read_rx_scratch_data(uint8_t *buffer, uint16_t length, uint16_t rxBufferOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the 18 bit data from the Accumulator buffer, from an offset location give by offset parameter
 *        for 18 bit complex samples, each sample is 6 bytes (3 real and 3 imaginary)
 *
 *
 * NOTE: Because of an internal memory access delay when reading the accumulator the first octet output is a dummy octet
 *       that should be discarded. This is true no matter what sub-index the read begins at.
 *
 * input parameters
 * @param buffer - the buffer into which the data will be read
 * @param length - the length of data to read (in bytes)
 * @param accOffset - the offset in the acc buffer from which to read the data, this is a complex sample index
 *                    e.g. to read 10 samples starting at sample 100
 *                    buffer would need to be >= 10*6 + 1, length is 61 (1 is for dummy), accOffset is 100
 *
 * output parameters
 *
 * no return value
 */
void dwt_readaccdata(uint8_t *buffer, uint16_t len, uint16_t accOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the crystal offset (relating to the frequency offset of the far DW3000 device compared to this one)
 *        Note: the returned signed 16-bit number shoudl be divided by 16 to get ppm offset.
 *
 * input parameters - NONE
 *
 * return value - the (int12) signed offset value. (s[6:-4])
 *                A positive value means the local RX clock is running faster than the remote TX device.
 */
int16_t dwt_readclockoffset(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the RX carrier integrator value (relating to the frequency offset of the TX node)
 *
 * input parameters - NONE
 *
 * return value - the (int32_t) signed carrier integrator value.
 *                A positive value means the local RX clock is running faster than the remote TX device.
 */
int32_t dwt_readcarrierintegrator(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function enables CIA diagnostic data. When turned on the following registers will be logged:
 * IP_TOA_LO, IP_TOA_HI, STS_TOA_LO, STS_TOA_HI, STS1_TOA_LO, STS1_TOA_HI, CIA_TDOA_0, CIA_TDOA_1_PDOA, CIA_DIAG_0, CIA_DIAG_1
 *
 * input parameters
 * @param enable_mask :     DW_CIA_DIAG_LOG_MAX (0x8)   //CIA to copy to swinging set a maximum set of diagnostic registers in Double Buffer mode
 *                          DW_CIA_DIAG_LOG_MID (0x4)   //CIA to copy to swinging set a medium set of diagnostic registers in Double Buffer mode
 *                          DW_CIA_DIAG_LOG_MIN (0x2)   //CIA to copy to swinging set a minimal set of diagnostic registers in Double Buffer mode
 *                          DW_CIA_DIAG_LOG_ALL (0x1)   //CIA to log all diagnostic registers
 *                          DW_CIA_DIAG_LOG_MIN (0x0)   //CIA to log reduced set of diagnostic registers
 *
 * output parameters
 *
 * no return value
 */
void dwt_configciadiag(uint8_t enable_mask);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function reads the STS signal quality index
 *
 * input parameters
 * @param rxStsQualityIndex - the (int16_t) signed STS quality index value.
 *
 * output parameters
 * return value - >=0 for good and < 0 if bad STS quality.
 *
 * Note: For the 64 MHz PRF if value is >= 90% of the STS length then we can assume good STS reception.
 *       Otherwise the STS timestamp may not be accurate.
 */
int dwt_readstsquality(int16_t* rxStsQualityIndex);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function reads the STS status
 *
 * input parameters
 * @param stsstatus - the (uint8_t) STS status value.
 * @param sts_num   - 0 for 1st STS, 1 for 2nd STS (2nd only valid when PDOA Mode 3 is used)
 *
 * output parameters
 * return value 0 for good/valid STS < 0 if bad STS quality.
 */
int dwt_readstsstatus(uint16_t* stsStatus, uint8_t sts_num);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function reads the RX signal quality diagnostic data
 *
 * input parameters
 * @param diagnostics - diagnostic structure pointer, this will contain the diagnostic data read from the DW3000
 *
 * output parameters
 *
 * no return value
 */
void dwt_readdiagnostics(dwt_rxdiag_t * diagnostics);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to enable/disable the event counter in the IC
 *
 * input parameters
 * @param - enable - 1 enables (and reset), 0 disables the event counters
 * output parameters
 *
 * no return value
 */
void dwt_configeventcounters(uint8_t enable);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to read the event counters in the IC
 *
 * input parameters
 * @param counters - pointer to the dwt_deviceentcnts_t structure which will hold the read data
 *
 * output parameters
 *
 * no return value
 */
void dwt_readeventcounters(dwt_deviceentcnts_t *counters);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to program 32-bit value into the DW3000 OTP memory.
 *
 * input parameters
 * @param value - this is the 32-bit value to be programmed into OTP
 * @param address - this is the 16-bit OTP address into which the 32-bit value is programmed
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
int dwt_otpwriteandverify(uint32_t value, uint16_t address);

int dwt_otpverify(uint32_t value, uint16_t address);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to set up Tx/Rx GPIOs which could be used to control LEDs
 * Note: not completely IC dependent, also needs board with LEDS fitted on right I/O lines
 *       this function enables GPIOs 2 and 3 which are connected to LED3 and LED4 on EVB1000
 *
 * input parameters
 * @param mode - this is a bit field interpreted as follows:
 *          - bit 0: 1 to enable LEDs, 0 to disable them
 *          - bit 1: 1 to make LEDs blink once on init. Only valid if bit 0 is set (enable LEDs)
 *          - bit 2 to 7: reserved
 *
 * output parameters none
 *
 * no return value
 */
void dwt_setleds(uint8_t mode);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This is used to adjust the crystal frequency
 *
 * input parameters:
 * @param   value - crystal trim value (in range 0x0 to 0x3F) 64 steps (~1.65ppm per step)
 *
 * output parameters
 *
 * no return value
 */
void dwt_setxtaltrim(uint8_t value);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function returns the value of XTAL trim that has been applied during initialisation (dwt_init). This can
 *        be either the value read in OTP memory or a default value.
 *
 * NOTE: The value returned by this function is the initial value only! It is not updated on dwt_setxtaltrim calls.
 *
 * input parameters
 *
 * output parameters
 *
 * returns the XTAL trim value set upon initialisation
 */
uint8_t dwt_getxtaltrim(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function enables repeated frames to be generated given a frame repetition rate.
 *
 * input parameters:
 * @param framerepetitionrate - Value specifying the rate at which frames will be repeated.
 *                            If the value is less than the frame duration, the frames are sent
 *                            back-to-back.
 *
 * output parameters:
 * None
 *
 * No return value
 */
void dwt_repeated_frames(uint32_t framerepetitionrate);

/*! ------------------------------------------------------------------------------------------------------------------
* @brief This function will enable a repeated continuous waveform on the device
*
* input parameters:
* @param cw_enable: CW mode enable
* @param cw_mode_config: CW configuration mode.
*
* output parameters:
*
*/
void dwt_repeated_cw(uint8_t cw_enable, uint8_t cw_mode_config);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function sets the DW3000 to transmit cw signal at specific channel frequency
 *
 * input parameters: channel - 5 or 9
 *
 * output parameters
 *
 * no return value
 */
void dwt_configcwmode(uint8_t channel);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function sets the DW3000 to continuous tx frame mode for regulatory approvals testing.
 *
 * input parameters:
 * @param framerepetitionrate - This is a 32-bit value that is used to set the interval between transmissions.
 *  The minimum value is 4. The units are approximately 8 ns. (or more precisely 512/(499.2e6*128) seconds)).
 * @param channel - 5 or 9
 *
 * output parameters
 *
 * no return value
 */
void dwt_configcontinuousframemode(uint32_t framerepetitionrate, uint8_t channel);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function reads the raw battery voltage and temperature values of the DW IC.
 * The values read here will be the current values sampled by DW IC AtoD converters.
 *
 *
 * input parameters:
 *
 * output parameters
 *
 * returns  (temp_raw<<8)|(vbat_raw)
 */
uint16_t dwt_readtempvbat(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function takes in a raw temperature value and applies the conversion factor
 * to give true temperature. The dwt_initialise needs to be called before call to this to
 * ensure pdw3000local->tempP contains the SAR_LTEMP value from OTP.
 *
 * input parameters:
 * @param raw_temp - this is the 8-bit raw temperature value as read by dwt_readtempvbat
 *
 * output parameters:
 *
 * returns: temperature sensor value
 */
float dwt_convertrawtemperature(uint8_t raw_temp);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function takes in a raw voltage value and applies the conversion factor
 * to give true voltage. The dwt_initialise needs to be called before call to this to
 * ensure pdw3000local->vBatP contains the SAR_LVBAT value from OTP
 *
 * input parameters:
 * @param raw_voltage - this is the 8-bit raw voltage value as read by dwt_readtempvbat
 *
 * output parameters:
 *
 * returns: voltage sensor value
 */
float dwt_convertrawvoltage(uint8_t raw_voltage);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function reads the temperature of the DW3000 that was sampled
 * on waking from Sleep/Deepsleep. They are not current values, but read on last
 * wakeup if DWT_TANDV bit is set in mode parameter of dwt_configuresleep
 *
 * input parameters:
 *
 * output parameters:
 *
 * returns: 8-bit raw temperature sensor value
 */
uint8_t dwt_readwakeuptemp(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function reads the battery voltage of the DW3000 that was sampled
 * on waking from Sleep/Deepsleep. They are not current values, but read on last
 * wakeup if DWT_TANDV bit is set in mode parameter of dwt_configuresleep
 *
 * input parameters:
 *
 * output parameters:
 *
 * returns: 8-bit raw battery voltage sensor value
 */
uint8_t dwt_readwakeupvbat(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function determines the adjusted bandwidth setting (PG_DELAY bitfield setting)
 * of the DW3000. The adjustemnt is a result of DW3000 internal PG cal routine, given a target count value it will try to
 * find the PG delay which gives the closest count value.
 * Manual sequencing of TX blocks and TX clocks need to be enabled for either channel 5 or 9.
 * This function presumes that the PLL is already in the IDLE state. Please configure the PLL to IDLE
 * state before calling this function, by calling dwt_configure.
 *
 * input parameters:
 * @param target_count - uint16_t - the PG count target to reach in order to correct the bandwidth
 * @param channel - int - The channel to configure for the corrected bandwith (5 or 9)
 *
 * output parameters:
 * returns: (uint8_t) The setting that was written to the PG_DELAY register (when calibration completed)
 */
uint8_t dwt_calcbandwidthadj(uint16_t target_count, uint8_t channel);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this function calculates the value in the pulse generator counter register (PGC_STATUS) for a given PG_DELAY
 * This is used to take a reference measurement, and the value recorded as the reference is used to adjust the
 * bandwidth of the device when the temperature changes. This function presumes that the PLL is already in the IDLE
 * state.
 *
 * input parameters:
 * @param pgdly - uint8_t - the PG_DELAY (max value 63) to set (to control bandwidth), and to find the corresponding count value for
 * @param channel - int - The channel to configure for the corrected bandwith (5 or 9)
 *
 * output parameters:
 * returns (uint16_t) - The count value calculated from the provided PG_DELAY value (from PGC_STATUS) - used as reference
 * for later bandwidth adjustments
 */
uint16_t dwt_calcpgcount(uint8_t pgdly, uint8_t channel);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to write to the DW3000 device registers
 * Notes:
 *        1. Firstly we create a header (the first byte is a header byte)
 *        a. check if sub index is used, if subindexing is used - set bit-6 to 1 to signify that the sub-index address follows the register index byte
 *        b. set bit-7 (or with 0x80) for write operation
 *        c. if extended sub address index is used (i.e. if index > 127) set bit-7 of the first sub-index byte following the first header byte
 *
 *        2. Write the header followed by the data bytes to the DW3000 device
 *
 *
 * input parameters:
 * @param recordNumber  - ID of register file or buffer being accessed
 * @param index         - byte index into register file or buffer being accessed
 * @param length        - number of bytes being written
 * @param buffer        - pointer to buffer containing the 'length' bytes to be written
 *
 * output parameters
 *
 * no return value
 */
void dwt_writetodevice
(
    uint32_t      recordNumber,   // input parameter - ID of register file or buffer being accessed
    uint16_t      index,          // input parameter - byte index into register file or buffer being accessed
    uint16_t      length,         // input parameter - number of bytes being written
    uint8_t       *buffer         // input parameter - pointer to buffer containing the 'length' bytes to be written
);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to read from the DW3000 device registers
 * Notes:
 *        1. Firstly we create a header (the first byte is a header byte)
 *        a. check if sub index is used, if subindexing is used - set bit-6 to 1 to signify that the sub-index address follows the register index byte
 *        b. set bit-7 (or with 0x80) for write operation
 *        c. if extended sub address index is used (i.e. if index > 127) set bit-7 of the first sub-index byte following the first header byte
 *
 *        2. Write the header followed by the data bytes to the DW3000 device
 *        3. Store the read data in the input buffer
 *
 * input parameters:
 * @param recordNumber  - ID of register file or buffer being accessed
 * @param index         - byte index into register file or buffer being accessed
 * @param length        - number of bytes being read
 * @param buffer        - pointer to buffer in which to return the read data.
 *
 * output parameters
 *
 * no return value
 */
void dwt_readfromdevice
(
    uint32_t  recordNumber,       // input parameter - ID of register file or buffer being accessed
    uint16_t  index,              // input parameter - byte index into register file or buffer being accessed
    uint16_t  length,             // input parameter - number of bytes being read
    uint8_t   *buffer             // input parameter - pointer to buffer in which to return the read data.
);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to read 32-bit value from the DW3000 device registers
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 *
 * output parameters
 *
 * returns 32 bit register value
 */
uint32_t dwt_read32bitoffsetreg(uint32_t regFileID, uint16_t regOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to write 32-bit value to the DW3000 device registers
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 * @param regval    - the value to write
 *
 * output parameters
 *
 * no return value
 */
void dwt_write32bitoffsetreg(uint32_t regFileID, uint16_t regOffset, uint32_t regval);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to read 16-bit value from the DW3000 device registers
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 *
 * output parameters
 *
 * returns 16 bit register value
 */
uint16_t dwt_read16bitoffsetreg(uint32_t regFileID, uint16_t regOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to write 16-bit value to the DW3000 device registers
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 * @param regval    - the value to write
 *
 * output parameters
 *
 * no return value
 */
void dwt_write16bitoffsetreg(uint32_t regFileID, uint16_t regOffset, uint16_t regval);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to read an 8-bit value from the DW3000 device registers
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 *
 * output parameters
 *
 * returns 8-bit register value
 */
uint8_t dwt_read8bitoffsetreg(uint32_t regFileID, uint16_t regOffset);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function is used to write an 8-bit value to the DW3000 device registers
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 * @param regval    - the value to write
 *
 * output parameters
 *
 * no return value
 */
void dwt_write8bitoffsetreg(uint32_t regFileID, uint16_t regOffset, uint8_t regval);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function can be used to modify a 32-bit register of DW3000
 *         Used to optimize SPI transaction when only clear or set of know
 *         bits in the register is requierd
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 * @param _and      - the 32-bit value to logically AND register
 * @param _or       - the 32-bit value to logically OR register after AND operation
 *
 * output parameters
 *
 * no return value
 */
void dwt_modify32bitoffsetreg(const uint32_t regFileID, const uint16_t regOffset, const uint32_t _and, const uint32_t _or);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function can be used to modify a 16-bit register of DW3000
 *         Used to optimize SPI transaction when only clear or set of know
 *         bits in the register is requierd
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 * @param _and      - the 16-bit value to logically AND register
 * @param _or       - the 16-bit value to logically OR register after AND operation
 *
 * output parameters
 *
 * no return value
 */
 void dwt_modify16bitoffsetreg(const uint32_t regFileID, const uint16_t regOffset, const uint16_t _and, const uint16_t _or);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  this function can be used to modify a 8-bit register of DW3000
 *         Used to optimize SPI transaction when only clear or set of know
 *         bits in the register is requierd
 *
 * input parameters:
 * @param regFileID - ID of register file or buffer being accessed
 * @param regOffset - the index into register file or buffer being accessed
 * @param _and      - the 8-bit value to logically AND register
 * @param _or       - the 8-bit value to logically OR register after AND operation
 *
 * output parameters
 *
 * no return value
 */
void dwt_modify8bitoffsetreg(const uint32_t regFileID, const uint16_t regOffset, const uint8_t _and, const uint8_t _or);

/********************************************************************************************************************/
/*                                                AES BLOCK                                                         */
/********************************************************************************************************************/

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief   This function provides the API for the configuration of the AES key before first usage.
 * @param   key - pointer to the key which will be programmed to the Key register
 *          Note, key register supports only 128-bit keys.
 *
 * output parameters
 *
 * no return value
 */
void dwt_set_keyreg_128(const dwt_aes_key_t  *key);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief   This function provides the API for the configuration of the AES block before its first usage.
 *
 * input parameters
 * @param   pCfg - pointer to the configuration structure, which contains the AES configuration data.
 *
 * output parameters
 *
 * no return value
 */
void dwt_configure_aes(const dwt_aes_config_t *pCfg);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief   This Gets mic size in bytes and convert it to value to write in AES_CFG
 * @param   mic_size_in_bytes    - mic size in bytes.
 *
 *
 *
 * @Return  dwt_mic_size_e - reg value number
 */
dwt_mic_size_e dwt_mic_size_from_bytes(uint8_t mic_size_in_bytes);


/*! ------------------------------------------------------------------------------------------------------------------
 * @brief   This function provides the API for the job of encript/decript the data block
 *
 *          128 bit key shall be pre-loaded with dwt_set_aes_key()
 *          dwt_configure_aes
 *
 *          supports AES_KEY_Src_Register mode only
 *          packet sizes < 127
 *          note, the "nonce" shall be unique for every transaction
 * @param job - pointer to AES job, contains data info and encryption info.
 * @param core_type - Core type
 *
 * @return  AES_STS_ID status bits
 *
 *
 */
int8_t dwt_do_aes(dwt_aes_job_t *job, dwt_aes_core_type_e core_type);

/****************************************************************************************************************************************************
 *
 * Declaration of platform-dependent lower level functions.
 *
 ****************************************************************************************************************************************************/

extern void wakeup_device_with_io(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief  This function wakeup device by an IO pin
 *
 * @param None
 *
 * output parameters
 *
 * no return value
 */
void dwt_wakeup_ic(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief
 * NB: In porting this to a particular microprocessor, the implementer needs to define the two low
 * level abstract functions to write to and read from the SPI the definitions should be in deca_spi.c file.
 * Low level abstract function to write to the SPI, this should be used when DW3000 SPI CRC mode is used
 * Takes two separate byte buffers for write header and write data
 * returns 0 for success, or -1 for error
 *
 * Note: The body of this function is defined in deca_spi.c and is platform specific
 *
 * input parameters:
 * @param headerLength  - number of bytes header being written
 * @param headerBuffer  - pointer to buffer containing the 'headerLength' bytes of header to be written
 * @param bodylength    - number of bytes data being written
 * @param bodyBuffer    - pointer to buffer containing the 'bodylength' bytes od data to be written
 * @param crc8          - 8-bit crc, calculated on the header and data bytes
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
extern int writetospiwithcrc(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodylength, const uint8_t *bodyBuffer, uint8_t crc8);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief
 * NB: In porting this to a particular microprocessor, the implementer needs to define the two low
 * level abstract functions to write to and read from the SPI the definitions should be in deca_spi.c file.
 * Low level abstract function to write to the SPI
 * Takes two separate byte buffers for write header and write data
 * returns 0 for success, or -1 for error
 *
 * Note: The body of this function is defined in deca_spi.c and is platform specific
 *
 * input parameters:
 * @param headerLength  - number of bytes header being written
 * @param headerBuffer  - pointer to buffer containing the 'headerLength' bytes of header to be written
 * @param bodylength    - number of bytes data being written
 * @param bodyBuffer    - pointer to buffer containing the 'bodylength' bytes od data to be written
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
extern int writetospi(uint16_t headerLength, uint8_t *headerBuffer, uint16_t bodylength, uint8_t *bodyBuffer);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief
 * NB: In porting this to a particular microprocessor, the implementer needs to define the two low
 * level abstract functions to write to and read from the SPI the definitions should be in deca_spi.c file.
 * Low level abstract function to write to the SPI
 * Takes two separate byte buffers for write header and write data
 * returns 0 for success, or -1 for error
 *
 * Note: The body of this function is defined in deca_spi.c and is platform specific
 *
 * input parameters:
 * @param headerLength  - number of bytes header to write
 * @param headerBuffer  - pointer to buffer containing the 'headerLength' bytes of header to write
 * @param readlength    - number of bytes data being read
 * @param readBuffer    - pointer to buffer containing to return the data (NB: size required = headerLength + readlength)
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success (and the position in the buffer at which data begins), or DWT_ERROR for error
 */
extern int readfromspi(uint16_t headerLength, uint8_t *headerBuffer, uint16_t readlength, uint8_t *readBuffer);

// ---------------------------------------------------------------------------
//
// NB: The purpose of the deca_mutex.c file is to provide for microprocessor interrupt enable/disable, this is used for
//     controlling mutual exclusion from critical sections in the code where interrupts and background
//     processing may interact.  The code using this is kept to a minimum and the disabling time is also
//     kept to a minimum, so blanket interrupt disable may be the easiest way to provide this.  But at a
//     minimum those interrupts coming from the Decawave device should be disabled/re-enabled by this activity.
//
//     In porting this to a particular microprocessor, the implementer may choose to use #defines here
//     to map these calls transparently to the target system.  Alternatively the appropriate code may
//     be embedded in the functions provided in the deca_irq.c file.
//
// ---------------------------------------------------------------------------

typedef int decaIrqStatus_t ; // Type for remembering IRQ status


/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function should disable interrupts. This is called at the start of a critical section
 * It returns the IRQ state before disable, this value is used to re-enable in decamutexoff call
 *
 * Note: The body of this function is defined in deca_mutex.c and is platform specific
 *
 * input parameters:
 *
 * output parameters
 *
 * returns the state of the DW3000 interrupt
 */
decaIrqStatus_t decamutexon(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function should re-enable interrupts, or at least restore their state as returned(&saved) by decamutexon
 * This is called at the end of a critical section
 *
 * Note: The body of this function is defined in deca_mutex.c and is platform specific
 *
 * input parameters:
 * @param s - the state of the DW3000 interrupt as returned by decamutexon
 *
 * output parameters
 *
 * returns the state of the DW3000 interrupt
 */
void decamutexoff(decaIrqStatus_t s);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief Wait for a given amount of time.
 * NB: The body of this function is defined in deca_sleep.c and is platform specific
 *
 * input parameters:
 * @param time_ms - time to wait in milliseconds
 *
 * output parameters
 *
 * no return value
 */
void deca_sleep(uint8_t time_ms);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief Wait for a given amount of time.
 * NB: The body of this function is defined in deca_sleep.c and is platform specific
 *
 * input parameters:
 * @param time_us - time to wait in microseconds
 *
 * output parameters
 *
 * no return value
 */
void deca_usleep(uint8_t time_us);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief this reads the device ID and checks if it is the right one
 *
 * input parameters
 * None
 *
 * output parameters
 *
 * returns DWT_SUCCESS for success, or DWT_ERROR for error
 */
int dwt_check_dev_id(void);

/*! ------------------------------------------------------------------------------------------------------------------
 *
 * @brief This function runs the PGF calibration. This is needed prior to reception.
 * Note: If the RX calibration routine fails the device receiver performance will be severely affected, the application should reset and try again
 *
 * input parameters
 * @param ldoen    -   if set to 1 the function will enable LDOs prior to calibration and disable afterwards.
 *
 * return result of PGF calibration (DWT_ERROR/-1 = error)
 *
 */
int dwt_run_pgfcal(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function runs the PGF calibration. This is needed prior to reception.
 *
 * input parameters
 * @param ldoen    -   if set to 1 the function will enable LDOs prior to calibration and disable afterwards.
 *
 * return result of PGF calibration (0 = error)
 *
 */
int dwt_pgf_cal(uint8_t ldoen);



/*! ------------------------------------------------------------------------------------------------------------------
 *
 * @brief   This function is used to write a 16 bit address to a desired Low-Energy device (LE) address. For frame pending to function when
 * the correct bits are set in the frame filtering configuration via the dwt_configureframefilter. See dwt_configureframefilter for more details.
 *
 * @param addr - the address value to be written to the selected LE register
 * @param leIndex - Low-Energy device (LE) address to write to
 *
 * no return value
 *
 */
void dwt_configure_le_address(uint16_t addr, uint8_t leIndex);

/*! ------------------------------------------------------------------------------------------------------------------
 * @brief This function configures SFD type only: e.g. IEEE 4a - 8, DW-8, DW-16, or IEEE 4z -8 (binary)
 * The dwt_configure should be called prior to this to configure other parameters
 *
 * input parameters
 * @param sfdType    -   e.g. DWT_SFD_IEEE_4A, DWT_SFD_DW_8, DWT_SFD_DW_16, DWT_SFD_IEEE_4Z
 *
 * return none
 *
 */
void dwt_configuresfdtype(uint8_t sfdType);

#ifdef __cplusplus
//}
#endif

#endif /* _DECA_DEVICE_API_H_ */
