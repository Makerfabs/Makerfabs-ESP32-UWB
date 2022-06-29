/*! ----------------------------------------------------------------------------
 * @file    shared_defines.h
 * @brief   Global definitions are found here
 *
 * @attention
 *
 * Copyright 2013-2020 (c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */

#ifndef _SHARE_DEF_
#define _SHARE_DEF_


#ifdef __cplusplus
extern "C" {
#endif

#define SPEED_OF_LIGHT (299702547)
#define FRAME_LEN_MAX      (127)
#define FRAME_LEN_MAX_EX   (1023)

#define RXFLEN_MASK    0x0000007FUL    /* Receive Frame Length (0 to 127) */
#define RXFL_MASK_1023 0x000003FFUL    /* Receive Frame Length Extension (0 to 1023) */

#define RESP_MSG_TS_LEN 4
#define FINAL_MSG_TS_LEN 4

/* UWB microsecond (uus) to device time unit (dtu, around 15.65 ps) conversion factor.
 * 1 uus = 512 / 499.2 µs and 1 µs = 499.2 * 128 dtu. */
#define UUS_TO_DWT_TIME 63898



#define TX_CHANGEABLE_DATA              (10)/*Can change the length of TX data by this size*/
#define MINIMAL_DATA_LENGTH             (11)/*The TX length will be at least the buffer below*/
#define SIMPLE_TX_DATA_SIZE             (MINIMAL_DATA_LENGTH+TX_CHANGEABLE_DATA)
#define TX_LENGTH_BYTE_POS              (2)/*This byte index represent the total length of the TX data*/



typedef enum
{
    DBL_BUFF_ERR_TYPE_UNKNOWN=-1,/*Unknown yet*/
  DBL_BUFF_ERR_TYPE_OK,/*No error*/
  DBL_BUFF_ERR_TYPE_TIMEOUT,/*Timeout*/
  DBL_BUFF_ERR_TYPE_ERROR,/*Error*/
  DBL_BUFF_ERR_TYPE_GOT_UNNEEDED_DATA,
}dbl_buff_error_type_e;

typedef enum
{
    AES_RES_OK=0,
    AES_RES_ERROR_LENGTH=-1,
    AES_RES_ERROR=-2,
    AES_RES_ERROR_FRAME=-3,
    AES_RES_ERROR_IGNORE_FRAME=-4
}aes_results_e;



#ifdef __cplusplus
}
#endif


#endif
