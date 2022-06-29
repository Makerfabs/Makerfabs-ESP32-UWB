/*! ----------------------------------------------------------------------------
 * @file    config_options.c
 * @brief   Configuration options are defined here.
 *
 * @attention
 *
 * Copyright 2019 - 2020 (c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */

#include "dw3000_config_options.h"

/* String used to display measured distance on LCD screen (16 characters maximum). */
char dist_str[16] = {0};

/*
 * TX Power Configuration Settings
 */
/* Values for the PG_DELAY and TX_POWER registers reflect the bandwidth and power of the spectrum at the current
 * temperature. These values can be calibrated prior to taking reference measurements. */
dwt_txconfig_t txconfig_options =
{
    0x34,           /* PG delay. */
    0xfdfdfdfd,      /* TX power. */
    0x0             /*PG count*/
};

dwt_txconfig_t txconfig_options_ch9 =
{
    0x34,           /* PG delay. */
    0xfefefefe,     /* TX power. */
    0x0             /*PG count*/
};

/*
 * Configuration options for the following parameters:
 * Channel: 5, 9
 * PRF: 64
 * Preamble Length: 64, 128, 512, 1024
 * Preamble Code: 3/4 for 16MHz PRf, 9/10/11/12 for 64MHz PRF
 * Data Rate: 0.85, 6.8
 * STS: Length 64
 */

#ifdef CONFIG_OPTION_01
/* Configuration option 01.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_02
/* Configuration option 02.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_03
/* Configuration option 03.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_04
/* Configuration option 04.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_05
/* Configuration option 05.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_06
/* Configuration option 06.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_07
/* Configuration option 07.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_08
/* Configuration option 08.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_09
/* Configuration option 09.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_10
/* Configuration option 10.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_11
/* Configuration option 11.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_12
/* Configuration option 12.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_13
/* Configuration option 13.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_14
/* Configuration option 14.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_15
/* Configuration option 15.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_16
/* Configuration option 16.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_850K,        /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_17
/* Configuration option 17.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_18
/* Configuration option 18.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_19
/* Configuration option 19.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_20
/* Configuration option 20.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_21
/* Configuration option 21.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_22
/* Configuration option 22.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_23
/* Configuration option 23.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_24
/* Configuration option 24.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_25
/* Configuration option 25.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_26
/* Configuration option 26.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_64,        /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (64 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_27
/* Configuration option 27.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_28
/* Configuration option 28.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_29
/* Configuration option 29.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_30
/* Configuration option 30.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_512,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (512 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_31
/* Configuration option 31.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0         /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_32
/* Configuration option 32.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
dwt_config_t config_options = {
    9,                  /* Channel number. */
    DWT_PLEN_1024,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    10,                  /* TX preamble code. Used in TX only. */
    10,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (1024 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,      /* Mode 1 STS enabled */
    DWT_STS_LEN_64,      /* STS length*/
    DWT_PDOA_M0          /* PDOA mode off */
};
#endif

#ifdef CONFIG_OPTION_33
/* Configuration option 33.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 128
 */
dwt_config_t config_options = {
    5,                  /* Channel number. */
    DWT_PLEN_128,      /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_1,     /* Mode 1 STS enabled */
    DWT_STS_LEN_128,    /* (STS length  in blocks of 8) - 1*/
    DWT_PDOA_M0         /* PDOA mode off */
};

/* Configuration option SP3.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 128, STS Mode 3
 */
dwt_config_t config_option_sp3 = {
    5,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_ND,    /* Mode 3 STS (no data) enabled */
    DWT_STS_LEN_128,    /* (STS length  in blocks of 8) - 1*/
    DWT_PDOA_M0         /* PDOA mode off */
};

/* Configuration option SP0.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, No STS
 */
dwt_config_t config_option_sp0 = {
    5,                  /* Channel number. */
    DWT_PLEN_128,       /* Preamble length. Used in TX only. */
    DWT_PAC8,           /* Preamble acquisition chunk size. Used in RX only. */
    9,                  /* TX preamble code. Used in TX only. */
    9,                  /* RX preamble code. Used in RX only. */
    3,                  /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,         /* Data rate. */
    DWT_PHRMODE_STD,    /* PHY header mode. */
    DWT_PHRRATE_STD,    /* PHY header rate. */
    (128 + 1 + 8 - 8),  /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_OFF,   /* STS Off */
    DWT_STS_LEN_128,    /* Ignore value when STS is disabled */
    DWT_PDOA_M0         /* PDOA mode off */
};

#endif
