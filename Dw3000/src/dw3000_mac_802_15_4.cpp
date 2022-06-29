/*! ----------------------------------------------------------------------------
 * @file    mac_802_15_4.c
 * @brief   Functions that handle 802.15.4 frame
 *
 * @attention
 *
 * Copyright 2013-2019(c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */
#include <string.h>
#include "dw3000_device_api.h"
#include "dw3000_mac_802_15_4.h"


/*Set the pan id src + dst and src and dst addresses*/
void mac_frame_set_pan_ids_and_addresses_802_15_4(mac_frame_802_15_4_format_t *mac_frame_ptr, uint16_t dest_pan_id,
        uint64_t dest_addr/*,uint16_t src_pan_id*/, uint64_t src_addr)
{
    /*Doing this kind of assignment to support big/little Endian*/
    uint8_t   cnt;

    for (cnt=0;cnt<sizeof(uint64_t);cnt++)//EXTENDED_ADDR
    {
        MAC_FRAME_SRC_ADDR_802_15_4(mac_frame_ptr,cnt)=(uint8_t)(src_addr);
        src_addr>>=8;
        MAC_FRAME_DEST_ADDR_ID_802_15_4(mac_frame_ptr,cnt)=(uint8_t)(dest_addr);
        dest_addr>>=8;
    }

    MAC_FRAME_DEST_PAN_ID_802_15_4(mac_frame_ptr,0)=(uint8_t)dest_pan_id;
    MAC_FRAME_DEST_PAN_ID_802_15_4(mac_frame_ptr,1)=(uint8_t)(dest_pan_id>>8);

    //SRC_PAN_ID_802_15_4(0)=(uint8_t)src_pan_id;
    //SRC_PAN_ID_802_15_4(1)=(uint8_t)(src_pan_id>>8);
}


/*Set the first 2 bytes of the MAC frame - Frame control*/
void mac_frame_init_mac_frame_ctrl(mac_frame_802_15_4_format_t *mac_frame_ptr)
{
    /*
     * Frame control[0]= Data, protected, no more data, no ACK, PEND ID for dest (no for source)
     * Frame control[1]=Has seq num, no IE, dest addr extended, frame ver 2 (IEEE Std 802.15.4), source extended
     */
    MAC_FRAME_FRAME_CTRL_802_15_4(mac_frame_ptr,0)=(MAC_FRAME_TYPE_802_15_4_DATA<<MAC_FRAME_TYPE_SHIFT_VALUE)|(MAC_SEC_EN_PROTECTED<<MAC_FRAME_SECURITY_ENABLED_SHIFT_VALUE)|
            (MAC_PEND_FRAME_NO_MORE_DATA<<MAC_FRAME_FRAME_PENDING_SHIFT_VALUE)|(MAC_AR_NO_ACK<<MAC_FRAME_AR_SHIFT_VALUE)|
            (MAC_PEND_ID_COMPRESS_DEST_EXIST_SOURCE_NOT<<MAC_FRAME_PAN_ID_SHIFT_VALUE);
    MAC_FRAME_FRAME_CTRL_802_15_4(mac_frame_ptr,1)=(MAC_SEQ_NUM_SUPP_PRESENT<<MAC_FRAME_SEQ_NUM_SUPPRESS_SHIFT_VALUE)|(MAC_SEQ_NUM_SUPP_PRESENT<<MAC_FRAME_IE_PRESET_SHIFT_VALUE)|
            (MAC_DEST_ADDR_MODE_EXT_ADDR_64_BITS<<MAC_FRAME_DEST_ADDR_MODE_SHIFT_VALUE)|(DATA_FRAME_VERSION<<MAC_FRAME_FRAME_VER_SHIFT_VALUE)|
            (MAC_SRC_ADDR_MODE_EXT_ADDR_64_BITS<<MAC_FRAME_SRC_ADDR_MODE_SHIFT_VALUE);
}

/* This function updates the MAC frame sequence number */
void mac_frame_update_sequence_number(mac_frame_802_15_4_format_t *mac_frame_ptr,uint8_t seq_num)
{
    MAC_FRAME_SEQ_NUM_802_15_4(mac_frame_ptr)=seq_num;
}

/* Set the security control in the Auxiliary security header */
/* Security control -  Security level MIC 16(data conf OFF, data Auth Yes), key determine from key index, has frame cnt, frame cnt gen nonce */
void mac_frame_set_AUX_security_control(mac_frame_802_15_4_format_t *mac_frame_ptr)
{
    MAC_FRAME_AUX_SECURITY_CTRL_802_15_4(mac_frame_ptr)=(AUX_SEC_LEVEL_DATA_CONF_ON_MIC_16<<AUX_SECURITY_LEVEL_SHIFT_VALUE)|
            (AUX_KEY_IDEN_MODE_KEY_INDEX<<AUX_KEY_IDENTIFIER_MODE_SHIFT_VALUE)|
            (AUX_FRAME_CNT_SUPPRESS_OFF<<AUX_FRAME_CNT_SUPPRESSION_SHIFT_VALUE)|(AUX_ASN_IN_NOUNCE_FRAME_CNT_GEN_NONCE<<AUX_ASN_IN_NONCE);
}

/* Set the key identifier value, in our case it is one byte - key index */
void mac_frame_set_AUX_key_identifier(mac_frame_802_15_4_format_t *mac_frame_ptr, uint8_t key_index)
{
    MAC_FRAME_AUX_KEY_IDENTIFY_802_15_4(mac_frame_ptr)=key_index;/*First keys set*/
}

/* Update the frame counter in the MAC frame - AUX security - Frame counter */
void mac_frame_update_aux_frame_cnt(mac_frame_802_15_4_format_t *mac_frame_802_15_4_format_ptr,uint32_t frame_cnt)
{
    uint8_t cnt;

    for (cnt=0;cnt<AUX_FRAME_CNT_SIZE;cnt++)
    {
        MAC_FRAME_AUX_FRAME_CNT_802_15_4(mac_frame_802_15_4_format_ptr,cnt)=(uint8_t)(frame_cnt);
        frame_cnt>>=8;
    }
}

/* Get the key identifier value, in our case it is one byte - key index */
uint8_t mac_frame_get_AUX_key_identifier(mac_frame_802_15_4_format_t *mac_frame_ptr)
{
    return MAC_FRAME_AUX_KEY_IDENTIFY_802_15_4(mac_frame_ptr);
}

/* Get the frame counter in the MAC frame - AUX security - Frame counter */
uint32_t mac_frame_get_aux_frame_cnt(mac_frame_802_15_4_format_t *mac_frame_ptr)
{
    int8_t    cnt;
    uint32_t  frame_cnt=0;

    for (cnt=0;cnt<AUX_FRAME_CNT_SIZE;cnt++)
    {
        frame_cnt|=(uint32_t)MAC_FRAME_AUX_FRAME_CNT_802_15_4(mac_frame_ptr,cnt)<<(cnt*8);
    }
    return frame_cnt;
}

/* This function will fill the buffer with the nonce-IV values.
 * In SS-TWR AES example as specified by IEEE802.15.4 the nonce is of 13-bytes and is made up of Source Address (8), Frame Counter (4) and Nonce Security Level (1)
 *
 * */
void mac_frame_get_nonce(mac_frame_802_15_4_format_t *mac_frame_ptr, uint8_t *aes_iv)
{
    //Copy Source Address (8)
    memcpy(&aes_iv[0], MAC_FRAME_SRC_ADDR_PTR_802_15_4(mac_frame_ptr), 8);

    //Copy Frame Counter
    memcpy(&aes_iv[8], MAC_FRAME_AUX_FRAME_CNT_PTR_802_15_4(mac_frame_ptr), 4);

    //Copy Nonce Security Level
    aes_iv[12] = MAC_FRAME_AUX_SECURITY_CTRL_802_15_4(mac_frame_ptr) & 0x7;
}

/* Return the MIC length from the AUX - Security control bits 0-2
 * the value of 4 is reserved and will return an error if set
 * */
uint8_t mac_frame_get_aux_mic_size(mac_frame_802_15_4_format_t *mac_frame_ptr)
{
    uint8_t   value;

    value=MAC_FRAME_AUX_SECURITY_CTRL_802_15_4(mac_frame_ptr)&0x7;
    if (value==0)
        return 0;
    else if ((value == 1)||(value == 5))
        return 4;
    else if ((value == 2)||(value == 6))
        return 8;
    else if ((value == 3)||(value == 7))
        return 16;
    else
        return MIC_ERROR; //error (value 4 is reserved and should not be set)
}

/* @fn      rx_aes_802_15_4
 * @brief   Decrypts received frame, the frame type needs to match the structure defined in mac_802_15_4.h - mac_frame_802_15_4_format_t.
 *          Note, the register key AES128 should be set before 1st call to this function.
 * @param   mac_frame_ptr - frame pointer
 * @param   frame_length  - length of data that was received in bytes
 * @param   aes_job       - holds the parameters for decryption,
 *          max_payload   - max allow size,
 *          aes_key_ptr   - pointer for keys,
 *          exp_src_addr  - expected src addr,
 *          exp_dst_addr  - expected dest addr
 *
 * @return aes_results_e
 * */
aes_results_e rx_aes_802_15_4(mac_frame_802_15_4_format_t *mac_frame_ptr, uint16_t frame_length, dwt_aes_job_t *aes_job, uint16_t max_payload,
        dwt_aes_key_t *aes_key_ptr, uint64_t exp_src_addr, uint64_t exp_dst_addr, dwt_aes_config_t  *aes_config)
{
    uint8_t             nonce[13];
    int8_t              status;
    int16_t             payload_len;
    uint64_t            src_addr,dst_addr;
    security_state_e    security_state;

    /* the length of frame needs to be at least == header */
    if ((frame_length-FCS_LEN) >= aes_job->header_len)
    {
        /* Get the MAC unencrypted data (MHR) */
        dwt_readrxdata((uint8_t *)MHR_802_15_4_PTR(mac_frame_ptr), aes_job->header_len, 0);

        /* Place a breakpoint here to see an unencrypted header */

        get_src_and_dst_frame_addr(mac_frame_ptr,&src_addr,&dst_addr);
        security_state = get_security_state(mac_frame_ptr);
        //Check if we got a secure frame with the right destination and source addresses
        if ((security_state != SECURITY_STATE_SECURE)||(exp_src_addr != src_addr)||(exp_dst_addr != dst_addr))
            return AES_RES_ERROR_IGNORE_FRAME; // This is not for us

        /* next get the MIC size */
        aes_job->mic_size = mac_frame_get_aux_mic_size(mac_frame_ptr);
        if(aes_job->mic_size == MIC_ERROR)
            return AES_RES_ERROR_FRAME;

        payload_len = frame_length - (aes_job->header_len + aes_job->mic_size + FCS_LEN); /* to get unencrypted payload length subtract MIC, FCS and MHR lengths */
        /* Check if payload_len is valid */
        if ((payload_len < 0) || (payload_len > max_payload))
            return AES_RES_ERROR_FRAME;

        /* next get the nonce (SS-TWR AES example uses 13-byte nonce*/
        mac_frame_get_nonce(mac_frame_ptr, nonce);

        /* Fill AES job to decrypt the received packet */
        aes_job->nonce       = nonce;
        aes_job->payload_len = payload_len;
        aes_job->header      = NULL;            /* not used for decryption*/
        aes_config->mic      = dwt_mic_size_from_bytes(aes_job->mic_size);
        //aes_config->aes_core_type=AES_core_type_CCM;
        dwt_configure_aes(aes_config);

        /* program the correct 128-bit key into DW3000 AES block*/
        dwt_set_keyreg_128(&aes_key_ptr[MAC_FRAME_AUX_KEY_IDENTIFY_802_15_4(mac_frame_ptr)-1]);

        /* perform the decryption job, the unencrypted payload will be stored in aes_job->payload */
        status = dwt_do_aes(aes_job,aes_config->aes_core_type);

        /* "status" represents a last read of AES_STS_ID register.
        * See DW3000 User Manual for details.
        * */
        if (status<0)
        {//Problem with Header/Payload length or mode selection
            return AES_RES_ERROR_LENGTH;
        }
        else
        {
            if (status & AES_ERRORS)
            {//One of the error status bits were raised
                return AES_RES_ERROR;
            }
            else
            {
                return AES_RES_OK;
            }
        }
    }
    else
    {
        return AES_RES_ERROR_FRAME;
    }
}

/* @fn      get_security_state
 * @brief   This function checks if the security bit is set in the frame header corresponding security_state_e value.
 *
 * @param   frame pointer
 * @return  security_state_e according to the state
*/
security_state_e get_security_state(mac_frame_802_15_4_format_t *mac_frame_ptr)
{
    if(MAC_FRAME_FRAME_CTRL_802_15_4(mac_frame_ptr,0) & SECURITY_ENABLE_BIT_MASK)
        return SECURITY_STATE_SECURE;//Protected
    else
        return SECURITY_STATE_NOT_SECURE;//Not protected
}


/* @fn      get_src_and_dst_frame_addr
 * @brief   Copy the source and destination data from the frame header into given destination and source buffers.
 *
 * @param   mac_frame_ptr - pointer to MAC frame
 * @param   src           - pointer to 64-bit integer where the src address will be stored
 * @param   dst           - pointer to 64-bit integer where the dst address will be stored
 * @return  None
*/
void get_src_and_dst_frame_addr(mac_frame_802_15_4_format_t *mac_frame_ptr, uint64_t *src, uint64_t *dst)
{
    uint8_t   cnt1, *src_ptr, *dst_ptr;

    *src=*dst=0;
    src_ptr=&MAC_FRAME_SRC_ADDR_802_15_4(mac_frame_ptr,0);
    dst_ptr=&MAC_FRAME_DEST_ADDR_ID_802_15_4(mac_frame_ptr,0);

    for (cnt1=0;cnt1<sizeof(uint64_t);cnt1++)
    {
        *src |= (uint64_t)(src_ptr[cnt1])<<(8*cnt1);
        *dst |= (uint64_t)(dst_ptr[cnt1])<<(8*cnt1);
    }
}

