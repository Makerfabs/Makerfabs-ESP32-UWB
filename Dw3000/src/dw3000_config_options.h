/*! ----------------------------------------------------------------------------
 * @file    config_options.h
 * @brief   Configuration options are selected here.
 *
 * @attention
 *
 * Copyright 2019(c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */

#include "dw3000_device_api.h"

#ifndef EXAMPLES_CONFIG_OPTIONS_H_
#define EXAMPLES_CONFIG_OPTIONS_H_

/* Index values for errors in array */
#define CRC_ERR_IDX 0
#define RSE_ERR_IDX 1
#define PHE_ERR_IDX 2
#define SFDTO_ERR_IDX 3
#define PTO_ERR_IDX 4
#define RTO_ERR_IDX 5
#define SPICRC_ERR_IDX 6
#define TXTO_ERR_IDX 7
#define ARFE_ERR_IDX 8
#define TS_MISMATCH_ERR_IDX 9
#define BAD_FRAME_ERR_IDX 10
#define PREAMBLE_COUNT_ERR_IDX 11
#define CP_QUAL_ERR_IDX 12
#define STS_PREAMBLE_ERR 13
#define STS_PEAK_GROWTH_RATE_ERR 14
#define STS_ADC_COUNT_ERR 15
#define STS_SFD_COUNT_ERR 16
#define STS_LATE_FIRST_PATH_ERR 17
#define STS_LATE_COARSE_EST_ERR 18
#define STS_COARSE_EST_EMPTY_ERR 19
#define STS_HIGH_NOISE_THREASH_ERR 20
#define STS_NON_TRIANGLE_ERR 21
#define STS_LOG_REG_FAILED_ERR 22

/*
 * Number of ranges to attempt in test
 */
#define RANGE_COUNT 200

/* Compensation value for CPU
 * The time taken to receive the poll frame, check for errors,
 * calculate length, read content, get poll timestamp,
 * calculate response timestamp and send delayed response with timestamp will
 * be different for each device.
 * Adjusting this value lower and lower until dwt_starttx() starts returning
 * DWT_ERROR status allows the user to tweak their system to calculate the
 * shortest turn-around time for messages.
 */
#define CPU_COMP 400

/*
 * SPI Rate Configuration Settings
 */
#define CONFIG_SPI_FAST_RATE
//#define CONFIG_SPI_SLOW_RATE

/*
 * Changing threshold to 5ns for DW3000 B0 red board devices.
 * ~10% of ranging attempts have a larger than usual difference between Ipatov and STS.
 * A larger threshold allows for better coverage with this coverage.
 * This should be fixed for DW3000 C0 devices.
 */
#define TS_MISMATCH_THRESHOLD 5*64       /* 64 = 1 ns --> 5 ns */

/*
 * Please note that a PRF of 16 MHz and a STS PRF of 64 MHz will not be supported for the DW3000.
 */

/* Configuration option 01.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_01

/* Configuration option 02.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_02

/* Configuration option 03.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_03

/* Configuration option 04.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_04

/* Configuration option 05.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_05

/* Configuration option 06.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_06

/* Configuration option 07.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_07

/* Configuration option 08.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_08

/* Configuration option 09.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_09

/* Configuration option 10.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_10

/* Configuration option 11.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_11

/* Configuration option 12.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_12

/* Configuration option 13.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_13

/* Configuration option 14.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_14

/* Configuration option 15.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_15

/* Configuration option 16.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_16

/* Configuration option 17.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_17

/* Configuration option 18.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_18

/* Configuration option 19.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_19

/* Configuration option 20.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_20

/* Configuration option 21.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 850k, STS Length 64
 */
//#define CONFIG_OPTION_21

/* Configuration option 22.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_22

/* Configuration option 23.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_23

/* Configuration option 24.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_24

/* Configuration option 25.
 * Channel 5, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_25

/* Configuration option 26.
 * Channel 9, PRF 64M, Preamble Length 64, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_26

/* Configuration option 27.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_27

/* Configuration option 28.
 * Channel 9, PRF 64M, Preamble Length 128, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_28

/* Configuration option 29.
 * Channel 5, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_29

/* Configuration option 30.
 * Channel 9, PRF 64M, Preamble Length 512, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_30

/* Configuration option 31.
 * Channel 5, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_31

/* Configuration option 32.
 * Channel 9, PRF 64M, Preamble Length 1024, PAC 8, Preamble code 10, Data Rate 6.8M, STS Length 64
 */
//#define CONFIG_OPTION_32

/* Configuration option 33.
 * Channel 5, PRF 64M, Preamble Length 128, PAC 8, Preamble code 9, Data Rate 6.8M, STS Length 128
 */
#define CONFIG_OPTION_33

extern char dist_str[16];

#endif /* EXAMPLES_CONFIG_OPTIONS_H_ */
