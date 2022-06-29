///*! ------------------------------------------------------------------------------------------------------------------
// * @file    deca_vals.h
// * @brief   DW3000 Register Definitions
// *          This file supports assembler and C development for DW3000 enabled devices
// *
// * @attention
// *
// * Copyright 2013-2020 (c) Decawave Ltd, Dublin, Ireland.
// *
// * All rights reserved.
// *
// */
//
#ifndef _DECA_VALS_H_
#define _DECA_VALS_H_

#ifdef __cplusplus
extern "C" {
#endif

#define FCS_LEN                 (2)
#define RX_BUFFER_0_ID          0x120000            /* Default Receive Data Buffer (and the 1st of the double buffer set) */
#define RX_BUFFER_1_ID          0x130000            /* 2nd Receive Data Buffer (when operating in double buffer mode) */

#define RF_TXCTRL_CH5           0x1C071134UL    /* */
#define RF_TXCTRL_CH9           0x1C010034UL    /* */
#define RF_TXCTRL_LO_B2         0x0E            /* */
#define RF_RXCTRL_CH9           0x08B5A833UL    /* */
#define RF_PLL_CFG_CH5          0x1F3C
#define RF_PLL_CFG_CH9          0x0F3C
#define RF_PLL_CFG_LD           0x81
#define LDO_RLOAD_VAL_B1        0x14

#define XTAL_TRIM_BIT_MASK      0x3F           /* max allowed value for XTAL trim */

#define DWT_DGC_CFG             0x32
#define DWT_DGC_CFG0            0x10000240
#define DWT_DGC_CFG1            0x1b6da489
#define PD_THRESH_NO_DATA       0xAF5F35CC      /* PD threshold for no data STS mode*/
#define PD_THRESH_DEFAULT       0xAF5F584C

#define IP_CONFIG_LO_SCP        0x0306
#define IP_CONFIG_HI_SCP        0x00000000
#define STS_CONFIG_LO_SCP       0x000C5A0A
#define STS_CONFIG_HI_SCP       0x7D

#define DWT_AUTO_CLKS          (0x200 | 0x200000 | 0x100000)  //this is the default value of CLK_CTRL register

#define ACC_BUFFER_MAX_LEN      (12288 + 1)         /* +1 is needed for "dummy" read */

#define REG_DIRECT_OFFSET_MAX_LEN   (127)
#define EXT_FRAME_LEN               (1023)
#define INDIRECT_POINTER_A_ID       0x1D0000            /* pointer to access indirect access buffer A */
#define INDIRECT_POINTER_B_ID       0x1E0000            /* pointer to access indirect access buffer B */

#define ACC_MEM_ID              0x150000

#define TX_BUFFER_ID            0x140000            /* Transmit Data Buffer */
#define SCRATCH_RAM_ID          0x160000
#define AES_KEY_RAM_MEM_ADDRESS 0x170000            /*Address of the AES keys in RAM*/

#define CIA_I_RX_TIME_LEN       5
#define CIA_C_RX_TIME_LEN       5
#define CIA_TDOA_LEN            6 /* TDOA value is 41 bits long. You will need to read 6 bytes and mask with 0x01FFFFFFFFFF */
#define CIA_I_STAT_OFFSET       3 /* RX status info for Ipatov sequence */
#define CIA_C_STAT_OFFSET       2 /* RX status info for ciphered sequence */
#define CIA_DIAGNOSTIC_OFF      (0x1 << 4)      /* bit4 in CIA_CONF + 1 */

#define DB_MAX_DIAG_SIZE        232  /* size of diagnostic data (in bytes) when DW_CIA_DIAG_LOG_MAX is set */
#define DB_MID_DIAG_SIZE         56  /* size of diagnostic data (in bytes) when DW_CIA_DIAG_LOG_MID is set */
#define DB_MIN_DIAG_SIZE         32  /* size of diagnostic data (in bytes) when DW_CIA_DIAG_LOG_MIN is set */


#define STS_ACC_CP_QUAL_SIGNTST  0x0800          /* sign test */
#define STS_ACC_CP_QUAL_SIGNEXT  0xF000          /* 12 bit to 16 bit sign extension */
#define STS_IV_LENGTH            16              /* CP initial value is 16 bytes or 128 bits*/

#define STS_KEY_LENGTH           16              /* CP AES key is 16 bytes or 128 bits*/

#define PMSC_TXFINESEQ_ENABLE   0x4d28874
#define PMSC_TXFINESEQ_DISABLE  0x0d20874

#define TXRXSWITCH_TX           0x01011100
#define TXRXSWITCH_AUTO         0x1C000000

#define ERR_RX_CAL_FAIL        0x1fffffff

#define DWT_TX_BUFF_OFFSET_ADJUST  128 // TX buffer offset adjustment when txBufferOffset > 127

#define LOGGER_MEM_ID           0x180000

#define PANADR_PAN_ID_BYTE_OFFSET       2
#define PMSC_CTRL0_PLL2_SEQ_EN          0x01000000UL    /* Enable PLL2 on/off sequencing by SNIFF mode */
#define RX_BUFFER_MAX_LEN               (1023)
#define TX_BUFFER_MAX_LEN               (1024)
#define RX_FINFO_STD_RXFLEN_MASK        0x0000007FUL    /* Receive Frame Length (0 to 127) */
#define RX_TIME_RX_STAMP_LEN            (5)             /* read only 5 bytes (the adjusted timestamp (40:0)) */
#define TX_TIME_TX_STAMP_LEN            (5)             /* 40-bits = 5 bytes */
#define SCRATCH_BUFFER_MAX_LEN          (127)           /* AES scratch memory */
#define STD_FRAME_LEN                   (127)


/* RX events mask relating to reception into RX buffer 0,  when double buffer is used */
#define RDB_STATUS_CLEAR_BUFF0_EVENTS (RDB_STATUS_CP_ERR0_BIT_MASK | RDB_STATUS_CIADONE0_BIT_MASK | RDB_STATUS_RXFR0_BIT_MASK | RDB_STATUS_RXFCG0_BIT_MASK)
/* RX events mask relating to reception into RX buffer 1,  when double buffer is used */
#define RDB_STATUS_CLEAR_BUFF1_EVENTS (RDB_STATUS_CP_ERR1_BIT_MASK | RDB_STATUS_CIADONE1_BIT_MASK | RDB_STATUS_RXFR1_BIT_MASK | RDB_STATUS_RXFCG1_BIT_MASK)

/* User defined RX timeouts (frame wait timeout and preamble detect timeout) mask. */
#define SYS_STATUS_ALL_RX_TO   (SYS_STATUS_RXFTO_BIT_MASK | SYS_STATUS_RXPTO_BIT_MASK)

/* All RX errors mask. */
#define SYS_STATUS_ALL_RX_ERR  (SYS_STATUS_RXPHE_BIT_MASK | SYS_STATUS_RXFCE_BIT_MASK | SYS_STATUS_RXFSL_BIT_MASK | SYS_STATUS_RXSTO_BIT_MASK \
                                | SYS_STATUS_ARFE_BIT_MASK | SYS_STATUS_CIAERR_BIT_MASK)

/* All STS Mode 3 RX errors mask. */
#define SYS_STATUS_ALL_ND_RX_ERR  (SYS_STATUS_CIAERR_BIT_MASK | SYS_STATUS_RXSTO_BIT_MASK)

/* All RX events after a correct packet reception mask. */
#define SYS_STATUS_ALL_RX_GOOD (SYS_STATUS_RXFR_BIT_MASK | SYS_STATUS_RXFCG_BIT_MASK | SYS_STATUS_RXPRD_BIT_MASK | \
        SYS_STATUS_RXSFDD_BIT_MASK | SYS_STATUS_RXPHD_BIT_MASK | SYS_STATUS_CIADONE_BIT_MASK)

/* All TX events mask. */
#define SYS_STATUS_ALL_TX      (SYS_STATUS_AAT_BIT_MASK | SYS_STATUS_TXFRB_BIT_MASK | SYS_STATUS_TXPRS_BIT_MASK | \
        SYS_STATUS_TXPHS_BIT_MASK | SYS_STATUS_TXFRS_BIT_MASK )

#define SYS_STATUS_RXOK         (SYS_STATUS_RXFCG_BIT_MASK | SYS_STATUS_CIA_DONE_BIT_MASK)

#define AES_ERRORS             (AES_STS_AUTH_ERR_BIT_MASK|AES_STS_TRANS_ERR_BIT_MASK|AES_STS_MEM_CONF_BIT_MASK)

#define MAX_OFFSET_ALLOWED      (0xFFF)
#define MIN_INDERECT_ADDR       (0x1000)

#define BUF0_RX_FINFO               0x180000    //part of min set
#define BUF0_RX_TIME                0x180004    //part of min set (RX time ~ RX_TIME_O)
#define BUF0_RX_TIME1               0x180008    //part of min set
#define BUF0_CIA_DIAG_0             0x18000C    //part of min set
#define BUF0_TDOA                   0x180010    //part of min set
#define BUF0_PDOA                   0x180014    //part of min set
#define BUF0_RES1                   0x180018    //part of min set (---)
#define BUF0_IP_DIAG_12             0x18001C    //part of min set
#define BUF0_IP_TS                  0x180020    //part of mid set
#define BUF0_RES2                   0x180024    //part of mid set
#define BUF0_STS_TS                 0x180028    //part of mid set
#define BUF0_STS_STAT               0x18002C    //part of mid set
#define BUF0_STS1_TS                0x180030    //part of mid set
#define BUF0_STS1_STAT              0x180034    //part of mid set
#define BUF0_CIA_DIAG_1             0x180038    //part of max set
#define BUF0_IP_DIAG_0              0x18003C    //part of max set
#define BUF0_IP_DIAG_1              0x180040    //part of max set
#define BUF0_IP_DIAG_2              0x180044    //...
#define BUF0_IP_DIAG_3              0x180048
#define BUF0_IP_DIAG_4              0x18004C
#define BUF0_IP_DIAG_5              0x180050
#define BUF0_IP_DIAG_6              0x180054
#define BUF0_IP_DIAG_7              0x180058
#define BUF0_IP_DIAG_8              0x18005C
#define BUF0_IP_DIAG_9              0x180060
#define BUF0_IP_DIAG_10             0x180064
#define BUF0_IP_DIAG_11             0x180068
#define BUF0_STS_DIAG_0             0x18006C
#define BUF0_STS_DIAG_1             0x180070
#define BUF0_STS_DIAG_2             0x180074
#define BUF0_STS_DIAG_3             0x180078
#define BUF0_STS_DIAG_4             0x18007C
#define BUF0_STS_DIAG_5             0x180080
#define BUF0_STS_DIAG_6             0x180084
#define BUF0_STS_DIAG_7             0x180088
#define BUF0_STS_DIAG_8             0x18008C
#define BUF0_STS_DIAG_9             0x180090
#define BUF0_STS_DIAG_10            0x180094
#define BUF0_STS_DIAG_11            0x180098
#define BUF0_STS_DIAG_12            0x18009C
#define BUF0_STS_DIAG_13            0x1800A0
#define BUF0_STS_DIAG_14            0x1800A4
#define BUF0_STS_DIAG_15            0x1800A8
#define BUF0_STS_DIAG_16            0x1800AC
#define BUF0_STS_DIAG_17            0x1800B0
#define BUF0_STS1_DIAG_0            0x1800B4
#define BUF0_STS1_DIAG_1            0x1800B8
#define BUF0_STS1_DIAG_2            0x1800BC
#define BUF0_STS1_DIAG_3            0x1800C0
#define BUF0_STS1_DIAG_4            0x1800C4
#define BUF0_STS1_DIAG_5            0x1800C8
#define BUF0_STS1_DIAG_6            0x1800CC
#define BUF0_STS1_DIAG_7            0x1800D0
#define BUF0_STS1_DIAG_8            0x1800D4
#define BUF0_STS1_DIAG_9            0x1800D8
#define BUF0_STS1_DIAG_10           0x1800DC
#define BUF0_STS1_DIAG_11           0x1800E0
#define BUF0_STS1_DIAG_12           0x1800E4

#define BUF1_RX_FINFO               0x1800E8    //part of min set
#define BUF1_RX_TIME                0x1800EC    //part of min set (RX time ~ RX_TIME_O)
#define BUF1_RX_TIME1               0x1800F0    //part of min set
#define BUF1_CIA_DIAG_0             0x1800F4    //part of min set
#define BUF1_TDOA                   0x1800F8    //part of min set
#define BUF1_PDOA                   0x1800FC    //part of min set
#define BUF1_RES1                   0x180100    //part of min set (---)
#define BUF1_IP_DIAG_12             0x180104    //part of min set
#define BUF1_IP_TS                  0x180108    //part of mid set
#define BUF1_RES2                   0x18010C    //part of mid set
#define BUF1_STS_TS                 0x180110    //part of mid set
#define BUF1_RES3                   0x180114    //part of mid set
#define BUF1_STS1_TS                0x180118    //part of mid set
#define BUF1_RES4                   0x18011C    //part of mid set
#define BUF1_CIA_DIAG_1             0x180120    //part of max set
#define BUF1_IP_DIAG_0              0x180124    //part of max set
#define BUF1_IP_DIAG_1              0x180128    //part of max set
#define BUF1_IP_DIAG_2              0x18012C    //...
#define BUF1_IP_DIAG_3              0x180130
#define BUF1_IP_DIAG_4              0x180134
#define BUF1_IP_DIAG_5              0x180138
#define BUF1_IP_DIAG_6              0x18013C
#define BUF1_IP_DIAG_7              0x180140
#define BUF1_IP_DIAG_8              0x180144
#define BUF1_IP_DIAG_9              0x180148
#define BUF1_IP_DIAG_10             0x18014C
#define BUF1_IP_DIAG_11             0x180150
#define BUF1_STS_DIAG_0             0x180154
#define BUF1_STS_DIAG_1             0x180158
#define BUF1_STS_DIAG_2             0x18015C
#define BUF1_STS_DIAG_3             0x180160
#define BUF1_STS_DIAG_4             0x180164
#define BUF1_STS_DIAG_5             0x180168
#define BUF1_STS_DIAG_6             0x18016C
#define BUF1_STS_DIAG_7             0x180170
#define BUF1_STS_DIAG_8             0x180174
#define BUF1_STS_DIAG_9             0x180178
#define BUF1_STS_DIAG_10            0x18017C
#define BUF1_STS_DIAG_11            0x180180
#define BUF1_STS_DIAG_12            0x180184
#define BUF1_STS_DIAG_13            0x180188
#define BUF1_STS_DIAG_14            0x18018C
#define BUF1_STS_DIAG_15            0x180190
#define BUF1_STS_DIAG_16            0x180194
#define BUF1_STS_DIAG_17            0x180198
#define BUF1_STS1_DIAG_0            0x18019C
#define BUF1_STS1_DIAG_1            0x1801A0
#define BUF1_STS1_DIAG_2            0x1801A4
#define BUF1_STS1_DIAG_3            0x1801A8
#define BUF1_STS1_DIAG_4            0x1801AC
#define BUF1_STS1_DIAG_5            0x1801B0
#define BUF1_STS1_DIAG_6            0x1801B4
#define BUF1_STS1_DIAG_7            0x1801B8
#define BUF1_STS1_DIAG_8            0x1801BC
#define BUF1_STS1_DIAG_9            0x1801C0
#define BUF1_STS1_DIAG_10           0x1801C4
#define BUF1_STS1_DIAG_11           0x1801C8
#define BUF1_STS1_DIAG_12           0x1801CC


#ifdef __cplusplus
}
#endif

#endif
