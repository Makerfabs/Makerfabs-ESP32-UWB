#ifndef _SHARE_FUNC_
#define _SHARE_FUNC_

#ifdef __cplusplus
//extern "C" {
#endif

#include "dw3000.h"
#include "dw3000_types.h"
#include "dw3000_regs.h"
#include "dw3000_shared_defines.h"
#include "dw3000_config_options.h"

extern dwt_config_t config_options;

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
void check_for_status_errors(uint32_t reg, uint32_t * errors);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn get_rx_delay_time_txpreamble()
 *
 * @brief This function is used to get a value to increase the delay timer by dependent on the current TX preamble length set.
 *
 * @param None
 *
 * @return delay_time - a uint32_t value indicating the required increase needed to delay the time by.
 */
uint32_t get_rx_delay_time_txpreamble(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn get_rx_delay_time_data_rate()
 *
 * @brief This function is used to get a value to increase the delay timer by dependent on the current data rate set.
 *
 * @param None
 *
 * @return delay_time - a uint32_t value indicating the required increase needed to delay the time by.
 */
uint32_t get_rx_delay_time_data_rate(void);

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
void set_delayed_rx_time(uint32_t delay, dwt_config_t *config_options);

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
void set_resp_rx_timeout(uint32_t delay, dwt_config_t *config_options);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn resync_sts()
 *
 * @brief Resync the current device's STS value the given value
 *
 * @param newCount - The 32 bit value to set the STS to.
 *
 * @return None
 */
void resync_sts(uint32_t newCount);

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
void resp_msg_get_ts(uint8_t *ts_field, uint32_t *ts);
uint64_t get_tx_timestamp_u64(void);
uint64_t get_rx_timestamp_u64(void);
void final_msg_get_ts(const uint8_t *ts_field, uint32_t *ts);
void final_msg_set_ts(uint8_t *ts_field, uint64_t ts);
void resp_msg_set_ts(uint8_t *ts_field, const uint64_t ts);



#ifdef __cplusplus
//}
#endif


#endif
