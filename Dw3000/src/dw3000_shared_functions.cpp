/*! ----------------------------------------------------------------------------
 * @file    shared_functions.h
 * @brief   Global functions are found here
 *
 * @attention
 *
 * Copyright 2013-2020 (c) Decawave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 */

#include "dw3000_shared_functions.h"

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn check_for_status_errors()
 *
 * @brief This function is used to get a value to increase the delay timer by dependent on the current TX preamble length set.
 *
 * @param reg: uint32_t value representing the current status register value.
 * @param errors: pointer to a uint32_t buffer that contains the sum of different errors logged during program operation.
 *
 * @return none
 */
void check_for_status_errors(uint32_t reg, uint32_t * errors)
{
    uint16_t stsStatus = 0;

    if (!(reg & SYS_STATUS_RXFCG_BIT_MASK))
    {
        errors[BAD_FRAME_ERR_IDX] += 1;
    }

    if (reg & SYS_STATUS_RXFSL_BIT_MASK)
    {
        errors[RSE_ERR_IDX] += 1;
    }

    if (reg & SYS_STATUS_RXPHE_BIT_MASK)
    {
        errors[PHE_ERR_IDX] += 1;
    }

    if (reg & SYS_STATUS_RXPTO_BIT_MASK)
    {
        errors[PTO_ERR_IDX] += 1;
    }

    if (reg & SYS_STATUS_ARFE_BIT_MASK)
    {
        errors[ARFE_ERR_IDX] += 1;
    }

    if ((reg & SYS_STATUS_RXFR_BIT_MASK) && !(reg & SYS_STATUS_RXFCG_BIT_MASK))
    {
        errors[CRC_ERR_IDX] += 1;
    }

    if ((reg & SYS_STATUS_RXFTO_BIT_MASK) || (reg & SYS_STATUS_ALL_RX_TO))
    {
        errors[RTO_ERR_IDX] += 1;
    }

    if (reg & SYS_STATUS_RXSTO_BIT_MASK)
    {
        errors[SFDTO_ERR_IDX] += 1;
    }

    if (reg & SYS_STATUS_CPERR_BIT_MASK)
    {
        // There is a general STS error
        errors[STS_PREAMBLE_ERR] += 1;

        // Get the status for a more detailed error reading of what went wrong with the STS
        dwt_readstsstatus(&stsStatus, 0);
        if (stsStatus & 0x100)
        {
            // Peak growth rate warning
            errors[STS_PEAK_GROWTH_RATE_ERR] += 1;
        }
        if (stsStatus & 0x080)
        {
            // ADC count warning
            errors[STS_ADC_COUNT_ERR] += 1;
        }
        if (stsStatus & 0x040)
        {
            // SFD count warning
            errors[STS_SFD_COUNT_ERR] += 1;
        }
        if (stsStatus & 0x020)
        {
            // Late first path estimation
            errors[STS_LATE_FIRST_PATH_ERR] += 1;
        }
        if (stsStatus & 0x010)
        {
            // Late coarse estimation
            errors[STS_LATE_COARSE_EST_ERR] += 1;
        }
        if (stsStatus & 0x008)
        {
            // Coarse estimation empty
            errors[STS_COARSE_EST_EMPTY_ERR] += 1;
        }
        if (stsStatus & 0x004)
        {
            // High noise threshold
            errors[STS_HIGH_NOISE_THREASH_ERR] += 1;
        }
        if (stsStatus & 0x002)
        {
            // Non-triangle
            errors[STS_NON_TRIANGLE_ERR] += 1;
        }
        if (stsStatus & 0x001)
        {
            // Logistic regression failed
            errors[STS_LOG_REG_FAILED_ERR] += 1;
        }
    }
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn get_rx_delay_time_txpreamble()
 *
 * @brief This function is used to get a value to increase the delay timer by dependent on the current TX preamble length set.
 *
 * @param None
 *
 * @return delay_time - a uint32_t value indicating the required increase needed to delay the time by.
 */
uint32_t get_rx_delay_time_txpreamble(void)
{
    uint32_t delay_time = 0;
    /* Standard delay values for preamble lengths of 32, 64, 72 & 128 should be adequate.
     * Additional time delay will be needed for larger preamble lengths.
     * Delay required is dependent on the preamble length as it increases the frame length. */
    switch (config_options.txPreambLength)
    {
    case DWT_PLEN_256:
        delay_time += 128; /* 256 - 128 */
        break;
    case DWT_PLEN_512:
        delay_time += 384; /* 512 - 128 */
        break;
    case DWT_PLEN_1024:
        delay_time += 896; /* 1024 - 128 */
        break;
    case DWT_PLEN_1536:
        delay_time += 1408; /* 1536 - 128 */
        break;
    case DWT_PLEN_2048:
        delay_time += 1920; /* 2048 - 128 */
        break;
    case DWT_PLEN_4096:
        delay_time += 3968; /* 4096 - 128 */
        break;
    case DWT_PLEN_32:
    case DWT_PLEN_64:
    case DWT_PLEN_72:
    case DWT_PLEN_128:
    default:
        break;
    }

    return delay_time;
}
/*! ------------------------------------------------------------------------------------------------------------------
 * @fn get_rx_delay_time_data_rate()
 *
 * @brief This function is used to get a value to increase the delay timer by dependent on the current data rate set.
 *
 * @param None
 *
 * @return delay_time - a uint32_t value indicating the required increase needed to delay the time by.
 */
uint32_t get_rx_delay_time_data_rate(void)
{
    uint32_t delay_time = 0;
    /*
     * If data rate is set to 850k (slower rate),
     * increase the delay time
     */
    switch (config_options.dataRate)
    {
    case DWT_BR_850K:
        delay_time += 200;
        break;
    case DWT_BR_6M8:
    default:
        break;
    }

    return delay_time;
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn set_delayed_rx_time()
 *
 * @brief This function is used to set the delayed RX time before running dwt_rxenable()
 *
 * @param delay - This is a defined delay value (usually POLL_TX_TO_RESP_RX_DLY_UUS)
 * @param config_options - pointer to dwt_config_t configuration structure that is in use at the time this function
 *                         is called.
 *
 * @return None
 */
void set_delayed_rx_time(uint32_t delay, dwt_config_t *config_options)
{
    uint32_t delay_time = delay;

    switch (config_options->txPreambLength)
    {
    case DWT_PLEN_32:
        delay_time -= 32;
        break;
    case DWT_PLEN_64:
        delay_time -= 64;
        break;
    case DWT_PLEN_72:
        delay_time -= 72;
        break;
    case DWT_PLEN_128:
        delay_time -= 128;
        break;
    case DWT_PLEN_256:
        delay_time -= 256;
        break;
    case DWT_PLEN_512:
        delay_time -= 512;
        break;
    case DWT_PLEN_1024:
        delay_time -= 1024;
        break;
    case DWT_PLEN_1536:
        delay_time -= 1536;
        break;
    case DWT_PLEN_2048:
    case DWT_PLEN_4096:
        delay_time -= 2048;
        break;
    default:
        break;
    }

    /* Length of the STS effects the size of the frame also.
     * This means the delay required is greater for larger STS lengths. */
    delay_time += ((1<<(config_options->stsLength+2))*8);

    dwt_setdelayedtrxtime((uint32_t)((delay_time * UUS_TO_DWT_TIME) >> 8));
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn set_resp_rx_timeout()
 *
 * @brief This function is used to set the RX timeout value
 *
 * @param delay - This is a defined delay value (usually RESP_RX_TIMEOUT_UUS)
 * @param config_options - pointer to dwt_config_t configuration structure that is in use at the time this function
 *                         is called.
 *
 * @return None
 */
void set_resp_rx_timeout(uint32_t delay, dwt_config_t *config_options)
{
    /*
     * The program will need to adjust the timeout value depending on the size of the frame
     * Different sized frames require different time delays.
     */
    uint32_t delay_time = delay + get_rx_delay_time_data_rate() + get_rx_delay_time_txpreamble() + 500;

    /* Length of the STS effects the size of the frame also.
     * This means the delay required is greater for larger STS lengths. */
    switch (config_options->stsLength)
    {
    case DWT_STS_LEN_256:
    case DWT_STS_LEN_512:
    case DWT_STS_LEN_1024:
    case DWT_STS_LEN_2048:
        delay_time += ((1<<(config_options->stsLength+2))*8);
        break;
    case DWT_STS_LEN_32:
    case DWT_STS_LEN_64:
    case DWT_STS_LEN_128:
    default:
        break;
    }

    dwt_setrxtimeout(delay_time);
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn resync_sts()
 *
 * @brief This function is used to resync the counter values used by the STS.
 *        The counter value is sent over via the TX device during a "poll" message.
 *        This counter value is used to make the RX device align with the same counter value
 *        so that the STS aligns again.
 *
 * @param newCount - The 32 bit value to set the STS to.
 *
 * @return None
 */
void resync_sts(uint32_t newCount)
{
    // New IV value to use is the original IV0 value plus the count value sent over from the RX,
    // plus half the STS length. This is because the TX device would have read it's current
    // STS count value and then transmitted it. By transmitting, it would have increased it's
    // STS count value by half of the configured STS length.
    // It is important to note that the STS counter will increment by 32 whenever there is a
    // receiver or SFD timeout. This value is consistent regardless of the STS preamble length
    // that is set.
    uint32_t iv_value = newCount;

    iv_value += ((1<<(config_options.stsLength+2))*8)/2;

    /* Write the new STS count value to the appropriate register and reload the value into the counter */
    dwt_write32bitreg(STS_IV0_ID, iv_value);
    dwt_configurestsloadiv();
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn resp_msg_get_ts()
 *
 * @brief Read a given timestamp value from the response message. In the timestamp fields of the response message, the
 *        least significant byte is at the lower address.
 *
 * @param  ts_field  pointer on the first byte of the timestamp field to get
 *         ts  timestamp value
 *
 * @return none
 */
void resp_msg_get_ts(uint8_t *ts_field, uint32_t *ts)
{
    int i;
    *ts = 0;
    for (i = 0; i < RESP_MSG_TS_LEN; i++)
    {
        *ts += (uint32_t)ts_field[i] << (i * 8);
    }
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn get_tx_timestamp_u64()
 *
 * @brief Get the TX time-stamp in a 64-bit variable.
 *        /!\ This function assumes that length of time-stamps is 40 bits, for both TX and RX!
 *
 * @param  none
 *
 * @return  64-bit value of the read time-stamp.
 */
uint64_t get_tx_timestamp_u64(void)
{
    uint8_t ts_tab[5];
    uint64_t ts = 0;
    int8_t i;
    dwt_readtxtimestamp(ts_tab);
    for (i = 4; i >= 0; i--)
    {
        ts <<= 8;
        ts |= ts_tab[i];
    }
    return ts;
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn get_rx_timestamp_u64()
 *
 * @brief Get the RX time-stamp in a 64-bit variable.
 *        /!\ This function assumes that length of time-stamps is 40 bits, for both TX and RX!
 *
 * @param  none
 *
 * @return  64-bit value of the read time-stamp.
 */
uint64_t get_rx_timestamp_u64(void)
{
    uint8_t ts_tab[5];
    uint64_t ts = 0;
    int8_t i;
    dwt_readrxtimestamp(ts_tab);
    for (i = 4; i >= 0; i--)
    {
        ts <<= 8;
        ts |= ts_tab[i];
    }
    return ts;
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn final_msg_get_ts()
 *
 * @brief Read a given timestamp value from the final message. In the timestamp fields of the final message, the least
 *        significant byte is at the lower address.
 *
 * @param  ts_field  pointer on the first byte of the timestamp field to read
 *         ts  timestamp value
 *
 * @return none
 */
void final_msg_get_ts(const uint8_t *ts_field, uint32_t *ts)
{
    uint8_t i;
    *ts = 0;
    for (i = 0; i < FINAL_MSG_TS_LEN; i++)
    {
        *ts += ((uint32_t)ts_field[i] << (i * 8));
    }
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn final_msg_set_ts()
 *
 * @brief Fill a given timestamp field in the final message with the given value. In the timestamp fields of the final
 *        message, the least significant byte is at the lower address.
 *
 * @param  ts_field  pointer on the first byte of the timestamp field to fill
 *         ts  timestamp value
 *
 * @return none
 */
void final_msg_set_ts(uint8_t *ts_field, uint64_t ts)
{
    uint8_t i;
    for (i = 0; i < FINAL_MSG_TS_LEN; i++)
    {
        ts_field[i] = (uint8_t)ts;
        ts >>= 8;
    }
}

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn resp_msg_set_ts()
 *
 * @brief Fill a given timestamp field in the response message with the given value. In the timestamp fields of the
 *        response message, the least significant byte is at the lower address.
 *
 * @param  ts_field  pointer on the first byte of the timestamp field to fill
 *         ts  timestamp value
 *
 * @return none
 */
void resp_msg_set_ts(uint8_t *ts_field, const uint64_t ts)
{
    uint8_t i;
    for (i = 0; i < RESP_MSG_TS_LEN; i++)
    {
        ts_field[i] = (uint8_t)(ts >> (i * 8));
    }
}
