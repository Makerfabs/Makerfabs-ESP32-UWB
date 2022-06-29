/*! ----------------------------------------------------------------------------
 * @file    mac_802_15_4.h
 * @brief   Functions that handle 802.15.4 frame
 *
 * @attention
 *
 * Copyright 2013-2019(c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */

#ifndef _802_15_4_
#define _802_15_4_

#ifdef __cplusplus
//extern "C" {
#endif

#include "dw3000_regs.h"
#include "dw3000_device_api.h"
#include "dw3000_shared_defines.h"

#define NUM_OF_KEY_OPTIONS  3

/*  802_15_4 general MAC frame format
 *
 *  Octets:     1/2             0/1         0/2             0/2/8       0/2         0/2/8       Variable        Variable    Variable        2/4
 *              Frame control   Seq number  Dest PAN ID     Dest Addr   Src PAN ID  Src Addr    Aux Sec Header  IEs         Frame Payload   FCS
 */


/*Auxiliary security header bytes
 *
 * Octets:  1               0/4         0/1/5/9
 *          Security ctrl   Frame count Key identifier
 */

/*Auxiliary security header - Security ctrl byte
 *
 * Bits:    0-2                 3-4                     5                       6               7
 *          Security level      Key identifier mode     Frame count suppression ASN in Nonce    Reserved
 */

/* Auxiliary security header bytes */
typedef struct
{
    uint8_t   security_ctrl;    /* as defined above */
    uint8_t   frame_counter[4]; /* In the SS-TWR AES example, we are using a 4 byte counter */
    uint8_t   key_indentifier;  /* as defined above used to identify which key is used*/
}aux_security_t;

#define EXTENDED_ADDR   8

/* MAC - MHR data fields. These field sizes are set for the sample frames of the SS-TWR AES demo
 * the demo uses data type frames with 2 byte frame control, seq number, dest PAN ID, 64-bit source
 * and destination addresses and the aux security header fields */
typedef struct
{
    uint8_t               frame_ctrl[2];
    uint8_t               sequence_num;
    uint8_t               dest_pan_id[2];
    uint8_t               dest_addr[EXTENDED_ADDR];
    uint8_t               src_addr[EXTENDED_ADDR];
    aux_security_t      aux_security;               /* As defined above */
    /*IE fields not in use*/
}mhr_802_15_4_t;


/* Aux security header byte 1, bits 0-2 */
typedef enum
{
    AUX_SEC_LEVEL_DATA_CONF_OFF_MIC_0=0, /* Sec attribute None,    data conf off, data auth No,  MIC length 0  */
    AUX_SEC_LEVEL_DATA_CONF_OFF_MIC_4,   /* Sec attribute mic 32,  data conf off, data auth Yes, MIC length 4  */
    AUX_SEC_LEVEL_DATA_CONF_OFF_MIC_8,   /* Sec attribute mic 64,  data conf off, data auth Yes, MIC length 8  */
    AUX_SEC_LEVEL_DATA_CONF_OFF_MIC_16,  /* Sec attribute mic 128, data conf off, data auth Yes, MIC length 16 */
    AUX_SEC_LEVEL_RESERVED,              /* Reserved */
    AUX_SEC_LEVEL_DATA_CONF_ON_MIC_4,    /* Sec attribute mic 32,  data conf on, data auth Yes, MIC length 4   */
    AUX_SEC_LEVEL_DATA_CONF_ON_MIC_8,    /* Sec attribute mic 64,  data conf on, data auth Yes, MIC length 8   */
    AUX_SEC_LEVEL_DATA_CONF_ON_MIC_16    /* Sec attribute mic 128, data conf on, data auth Yes, MIC length 16  */
}aux_security_level_e;


/* Aux security header byte 1, bits 3-4 */
typedef enum
{
    AUX_KEY_IDEN_MODE_ORIGINATOR_RECIPIENT=0,
    AUX_KEY_IDEN_MODE_KEY_INDEX,
    AUX_KEY_IDEN_MODE_4_OCTET_KEY_SOUCE_AND_INDEX,
    AUX_KEY_IDEN_MODE_8_OCTET_KEY_SOUCE_AND_INDEX
}aux_key_indentifier_mode_e;

/* Aux security header byte 1, bit 5 */
typedef enum
{
    AUX_FRAME_CNT_SUPPRESS_OFF=0,   /* Frame counter is carried */
    AUX_FRAME_CNT_SUPPRESS_ON       /* Frame counter is not carried */
}aux_frame_cnt_suppress_e;

/* Aux security header byte 1, bit 6 */
typedef enum
{
    AUX_ASN_IN_NOUNCE_FRAME_CNT_GEN_NONCE=0,
    AUX_ASN_IN_NOUNCE_FRAME_CNT_NOT_GEN_NONCE
}aux_asn_in_nonce_e;

#define AUX_SECURITY_LEVEL_SHIFT_VALUE          0
#define AUX_KEY_IDENTIFIER_MODE_SHIFT_VALUE     3
#define AUX_FRAME_CNT_SUPPRESSION_SHIFT_VALUE   5
#define AUX_ASN_IN_NONCE                        6

#define AUX_FRAME_CNT_SIZE                      4


/* This is the frame type - bits 0-2 that reside in the first byte of frame control */
typedef enum
{
    MAC_FRAME_TYPE_802_15_4_BEACON=0,
    MAC_FRAME_TYPE_802_15_4_DATA,
    MAC_FRAME_TYPE_802_15_4_ACK,
    MAC_FRAME_TYPE_802_15_4_MAC_CMD,
    MAC_FRAME_TYPE_802_15_4_RESERVED,
    MAC_FRAME_TYPE_802_15_4_MULTI,
    MAC_FRAME_TYPE_802_15_4_FRAGMENT,
    MAC_FRAME_TYPE_802_15_4_EXTENDED
}mac_frame_type_802_15_4_e;


/* This is the frame security enabled - bit 3 that reside in the first byte of frame control */
typedef enum
{
    MAC_SEC_EN_UN_PROTECTED=0,
    MAC_SEC_EN_PROTECTED
}mac_security_en_802_15_4_e;

/* This is the frame pending - bit 4 that reside in the first byte of frame control */
typedef enum
{
    MAC_PEND_FRAME_NO_MORE_DATA=0,
    MAC_PEND_FRAME_MORE_DATA
}mac_pend_frame_802_15_4_e;

/* This is the frame AR - bit 5 that reside in the first byte of frame control */
typedef enum
{
    MAC_AR_NO_ACK=0,
    MAC_AR_ACK
}mac_AR_802_15_4_e;

/* This is the frame PAN ID compress - bit 6 that reside in the first byte of frame control */
typedef enum
{
    MAC_PEND_ID_COMPRESS_DEST_EXIST_SOURCE_NOT=0,
    MAC_PEND_ID_COMPRESS_NO
}mac_pand_id_compress_802_15_4_e;

/* This is the Seq num suppress - bit 0 that reside in the second byte of frame control */
typedef enum
{
    MAC_SEQ_NUM_SUPP_PRESENT=0,
    MAC_SEQ_NUM_SUPP_NOT_PRESENT
}mac_seq_num_suppress_802_15_4_e;

/* This is the IE present - bit 1 that reside in the second byte of frame control */
typedef enum
{
    MAC_IE_PRESENT_NO=0,
    MAC_IE_PRESENT_YES
}mac_ie_present_802_15_4_e;


/* This is the dest addr mode - bits 2,3 that reside in the second byte of frame control */
typedef enum
{
    MAC_DEST_ADDR_MODE_NO_PEND_AND_ADDR=0,
    MAC_DEST_ADDR_MODE_RESERVED,
    MAC_DEST_ADDR_MODE_SHORT_ADDR_16_BITS,
    MAC_DEST_ADDR_MODE_EXT_ADDR_64_BITS
}mac_dest_addr_mode_802_15_4_e;


/* This is the frame version - bits 4,5 that reside in the second byte of frame control */
#define DATA_FRAME_VERSION      2 /* IEEE Std 802.15.4 */

/* This is the dest src mode - bits 6,7 that reside in the second byte of frame control */
typedef enum
{
    MAC_SRC_ADDR_MODE_NO_PEND_AND_ADDR=0,
    MAC_SRC_ADDR_MODE_RESERVED,
    MAC_SRC_ADDR_MODE_SHORT_ADDR_16_BITS,
    MAC_SRC_ADDR_MODE_EXT_ADDR_64_BITS
}mac_src_addr_mode_802_15_4_e;



/* Shift values to frame control byte 0 */
#define MAC_FRAME_TYPE_SHIFT_VALUE                  0
#define MAC_FRAME_SECURITY_ENABLED_SHIFT_VALUE      3
#define MAC_FRAME_FRAME_PENDING_SHIFT_VALUE         4
#define MAC_FRAME_AR_SHIFT_VALUE                    5
#define MAC_FRAME_PAN_ID_SHIFT_VALUE                6

/* Shift values to frame control byte 1 */
#define MAC_FRAME_SEQ_NUM_SUPPRESS_SHIFT_VALUE      0
#define MAC_FRAME_IE_PRESET_SHIFT_VALUE             1
#define MAC_FRAME_DEST_ADDR_MODE_SHIFT_VALUE        2
#define MAC_FRAME_FRAME_VER_SHIFT_VALUE             4
#define MAC_FRAME_SRC_ADDR_MODE_SHIFT_VALUE         6

#define SECURITY_ENABLE_BIT_MASK                    0x8

/* This is the structure of the MAC frame. The structure defined here applies for the SS-TWR AES example frames
 * the mhr_802_15_4_t defines a data frame with: with 2 byte frame control, seq number, dest PAN ID, 64-bit source
 * and destination addresses and the aux security header fields
 */
typedef struct
{
    mhr_802_15_4_t      mhr_802_15_4;   /* MHR structure */
    uint8_t               *payload_ptr;   /* Pointer to the payload */
    /*FCS will be added when transmitting this data*/
}mac_frame_802_15_4_format_t;


typedef enum
{
    SECURITY_STATE_SECURE=0,
    SECURITY_STATE_NOT_SECURE
}security_state_e;

#define MAC_FRAME_HEADER_SIZE(mac_frame_ptr)    sizeof((mac_frame_ptr)->mhr_802_15_4)
#define MHR_802_15_4_PTR(mac_frame_ptr)         &((mac_frame_ptr)->mhr_802_15_4)
#define PAYLOAD_PTR_802_15_4(mac_frame_ptr)     (mac_frame_ptr)->payload_ptr

#define MAC_FRAME_FRAME_CTRL_802_15_4(mac_frame_ptr,index)      (mac_frame_ptr)->mhr_802_15_4.frame_ctrl[index]
#define MAC_FRAME_SEQ_NUM_802_15_4(mac_frame_ptr)               (mac_frame_ptr)->mhr_802_15_4.sequence_num
#define MAC_FRAME_DEST_PAN_ID_802_15_4(mac_frame_ptr,index)     (mac_frame_ptr)->mhr_802_15_4.dest_pan_id[index]
#define MAC_FRAME_DEST_ADDR_ID_802_15_4(mac_frame_ptr,index)    (mac_frame_ptr)->mhr_802_15_4.dest_addr[index]
//#define MAC_FRAME_SRC_PAN_ID_802_15_4(index)  MAC_frame_802_15_4_format.MHR_802_15_4.src_pan_id[index]
#define MAC_FRAME_SRC_ADDR_802_15_4(mac_frame_ptr,index)        (mac_frame_ptr)->mhr_802_15_4.src_addr[index]
#define MAC_FRAME_SRC_ADDR_PTR_802_15_4(mac_frame_ptr)          (mac_frame_ptr)->mhr_802_15_4.src_addr

#define MAC_FRAME_AUX_SECURITY_CTRL_802_15_4(mac_frame_ptr)         (mac_frame_ptr)->mhr_802_15_4.aux_security.security_ctrl
#define MAC_FRAME_AUX_FRAME_CNT_802_15_4(mac_frame_ptr,index)       (mac_frame_ptr)->mhr_802_15_4.aux_security.frame_counter[index]
#define MAC_FRAME_AUX_FRAME_CNT_PTR_802_15_4(mac_frame_ptr)         (mac_frame_ptr)->mhr_802_15_4.aux_security.frame_counter
#define MAC_FRAME_AUX_FRAME_GET_CNT_802_15_4_PTR(mac_frame_ptr)     (uint8_t *)(&(mac_frame_ptr)->mhr_802_15_4.aux_security.frame_counter)
#define MAC_FRAME_AUX_KEY_IDENTIFY_802_15_4(mac_frame_ptr)          (mac_frame_ptr)->mhr_802_15_4.aux_security.key_indentifier

void mac_frame_init_mac_frame_ctrl(mac_frame_802_15_4_format_t  *mac_frame_ptr);
void mac_frame_set_pan_ids_and_addresses_802_15_4(mac_frame_802_15_4_format_t   *mac_frame_ptr,uint16_t dest_pan_id,uint64_t dest_addr/*,uint16_t src_pan_id*/,uint64_t src_addr);
void mac_frame_update_sequence_number(mac_frame_802_15_4_format_t *mac_frame_ptr,uint8_t seq_num);
void mac_frame_update_aux_frame_cnt(mac_frame_802_15_4_format_t *mac_frame_ptr,uint32_t frame_cnt);
void mac_frame_set_aux_key_identifier(mac_frame_802_15_4_format_t *mac_frame_ptr,uint8_t key_index);
uint8_t mac_frame_get_aux_key_identifier(mac_frame_802_15_4_format_t *mac_frame_ptr);
uint32_t mac_frame_get_aux_frame_cnt(mac_frame_802_15_4_format_t *mac_frame_ptr);
void mac_frame_get_nonce(mac_frame_802_15_4_format_t *mac_frame_ptr, uint8_t* aes_iv);
void mac_frame_set_aux_security_control(mac_frame_802_15_4_format_t *mac_frame_ptr);
uint8_t mac_frame_get_aux_mic_size(mac_frame_802_15_4_format_t *mac_frame_ptr);
aes_results_e rx_aes_802_15_4(mac_frame_802_15_4_format_t   *mac_frame_ptr,uint16_t frame_length,dwt_aes_job_t *aes_job,uint16_t max_payload,
        dwt_aes_key_t *aes_key_ptr,uint64_t exp_src_addr,uint64_t exp_dst_addr,dwt_aes_config_t *aes_config);
security_state_e get_security_state(mac_frame_802_15_4_format_t *mac_frame_ptr);
void get_src_and_dst_frame_addr(mac_frame_802_15_4_format_t *mac_frame_ptr,uint64_t *src, uint64_t *dst);



#ifdef __cplusplus
//}
#endif


#endif
