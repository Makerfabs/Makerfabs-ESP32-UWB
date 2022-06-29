/*! ---------------------------------------------------------------------------
 * @file    deca_regs.h
 * @brief   DW3000 Register Definitions
 *          This file supports Assembly and C development for DW3000 enabled devices
 *
 * @author  Decawave Software
 * @attention
 * Copyright 2019 - 2020 (c) Decawave Ltd, Dublin, Ireland.
 * All rights reserved.
 */

#ifndef __DECA_REGS_H
#define __DECA_REGS_H                         1

#ifdef __cplusplus
extern "C" {
#endif

#include "dw3000_vals.h"

/******************************************************************************
* @brief Bit definitions for register DEV_ID
**/
#define DEV_ID_ID                            0x0                  
#define DEV_ID_LEN                           (4U)                
#define DEV_ID_MASK                          0xFFFFFFFFUL        
#define DEV_ID_RIDTAG_BIT_OFFSET             (16U)               
#define DEV_ID_RIDTAG_BIT_LEN                (16U)               
#define DEV_ID_RIDTAG_BIT_MASK               0xffff0000UL         
#define DEV_ID_MODEL_BIT_OFFSET              (8U)                
#define DEV_ID_MODEL_BIT_LEN                 (8U)                
#define DEV_ID_MODEL_BIT_MASK                0xff00U              
#define DEV_ID_VER_BIT_OFFSET                (4U)                
#define DEV_ID_VER_BIT_LEN                   (4U)                
#define DEV_ID_VER_BIT_MASK                  0xf0U                
#define DEV_ID_REV_BIT_OFFSET                (0U)                
#define DEV_ID_REV_BIT_LEN                   (4U)                
#define DEV_ID_REV_BIT_MASK                  0xfU                 

/******************************************************************************
* @brief Bit definitions for register EUI_64_LO
**/
#define EUI_64_LO_ID                         0x4                  
#define EUI_64_LO_LEN                        (4U)                
#define EUI_64_LO_MASK                       0xFFFFFFFFUL        
#define EUI_64_LO_EUI_64_BIT_OFFSET          (0U)                
#define EUI_64_LO_EUI_64_BIT_LEN             (32U)               
#define EUI_64_LO_EUI_64_BIT_MASK            0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register EUI_64_HI
**/
#define EUI_64_HI_ID                         0x8                  
#define EUI_64_HI_LEN                        (4U)                
#define EUI_64_HI_MASK                       0xFFFFFFFFUL        
#define EUI_64_HI_EUI_64_BIT_OFFSET          (0U)                
#define EUI_64_HI_EUI_64_BIT_LEN             (32U)               
#define EUI_64_HI_EUI_64_BIT_MASK            0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register PANADR
**/
#define PANADR_ID                            0xc                  
#define PANADR_LEN                           (4U)                
#define PANADR_MASK                          0xFFFFFFFFUL        
#define PANADR_PAN_ID_BIT_OFFSET             (16U)               
#define PANADR_PAN_ID_BIT_LEN                (16U)               
#define PANADR_PAN_ID_BIT_MASK               0xffff0000UL         
#define PANADR_SHORTADDR_BIT_OFFSET          (0U)                
#define PANADR_SHORTADDR_BIT_LEN             (16U)               
#define PANADR_SHORTADDR_BIT_MASK            0xffffU              

/******************************************************************************
* @brief Bit definitions for register SYS_CFG
**/
#define SYS_CFG_ID                           0x10                 
#define SYS_CFG_LEN                          (4U)                
#define SYS_CFG_MASK                         0xFFFFFFFFUL        
#define SYS_CFG_FAST_AAT_EN_BIT_OFFSET       (18U)               
#define SYS_CFG_FAST_AAT_EN_BIT_LEN          (1U)                
#define SYS_CFG_FAST_AAT_EN_BIT_MASK         0x40000UL            
#define SYS_CFG_PDOA_MODE_BIT_OFFSET         (16U)               
#define SYS_CFG_PDOA_MODE_BIT_LEN            (2U)                
#define SYS_CFG_PDOA_MODE_BIT_MASK           0x30000UL            
#define SYS_CFG_CP_SDC_BIT_OFFSET            (15U)               
#define SYS_CFG_CP_SDC_BIT_LEN               (1U)                
#define SYS_CFG_CP_SDC_BIT_MASK              0x8000U              
#define SYS_CFG_CP_SPC_BIT_OFFSET            (12U)               
#define SYS_CFG_CP_SPC_BIT_LEN               (2U)                
#define SYS_CFG_CP_SPC_BIT_MASK              0x3000U              
#define SYS_CFG_AUTO_ACK_BIT_OFFSET          (11U)               
#define SYS_CFG_AUTO_ACK_BIT_LEN             (1U)                
#define SYS_CFG_AUTO_ACK_BIT_MASK            0x800U               
#define SYS_CFG_RXAUTR_BIT_OFFSET            (10U)               
#define SYS_CFG_RXAUTR_BIT_LEN               (1U)                
#define SYS_CFG_RXAUTR_BIT_MASK              0x400U               
#define SYS_CFG_RXWTOE_BIT_OFFSET            (9U)                
#define SYS_CFG_RXWTOE_BIT_LEN               (1U)                
#define SYS_CFG_RXWTOE_BIT_MASK              0x200U               
#define SYS_CFG_CIA_STS_BIT_OFFSET           (8U)                
#define SYS_CFG_CIA_STS_BIT_LEN              (1U)                
#define SYS_CFG_CIA_STS_BIT_MASK             0x100U               
#define SYS_CFG_CIA_IPATOV_BIT_OFFSET        (7U)                
#define SYS_CFG_CIA_IPATOV_BIT_LEN           (1U)                
#define SYS_CFG_CIA_IPATOV_BIT_MASK          0x80U                
#define SYS_CFG_SPI_CRC_BIT_OFFSET           (6U)                
#define SYS_CFG_SPI_CRC_BIT_LEN              (1U)                
#define SYS_CFG_SPI_CRC_BIT_MASK             0x40U                
#define SYS_CFG_PHR_6M8_BIT_OFFSET           (5U)                
#define SYS_CFG_PHR_6M8_BIT_LEN              (1U)                
#define SYS_CFG_PHR_6M8_BIT_MASK             0x20U                
#define SYS_CFG_PHR_MODE_BIT_OFFSET          (4U)                
#define SYS_CFG_PHR_MODE_BIT_LEN             (1U)                
#define SYS_CFG_PHR_MODE_BIT_MASK            0x10U                
#define SYS_CFG_DIS_DRXB_BIT_OFFSET          (3U)                
#define SYS_CFG_DIS_DRXB_BIT_LEN             (1U)                
#define SYS_CFG_DIS_DRXB_BIT_MASK            0x8U                 
#define SYS_CFG_DIS_FCE_BIT_OFFSET           (2U)                
#define SYS_CFG_DIS_FCE_BIT_LEN              (1U)                
#define SYS_CFG_DIS_FCE_BIT_MASK             0x4U                 
#define SYS_CFG_DIS_FCS_TX_BIT_OFFSET        (1U)                
#define SYS_CFG_DIS_FCS_TX_BIT_LEN           (1U)                
#define SYS_CFG_DIS_FCS_TX_BIT_MASK          0x2U                 
#define SYS_CFG_FFEN_BIT_OFFSET              (0U)                
#define SYS_CFG_FFEN_BIT_LEN                 (1U)                
#define SYS_CFG_FFEN_BIT_MASK                0x1U                 

/******************************************************************************
* @brief Bit definitions for register ADR_FILT_CFG
**/
#define ADR_FILT_CFG_ID                      0x14                 
#define ADR_FILT_CFG_LEN                     (4U)                
#define ADR_FILT_CFG_MASK                    0xFFFFFFFFUL        
#define ADR_FILT_CFG_LSADRAPE_BIT_OFFSET     (15U)               
#define ADR_FILT_CFG_LSADRAPE_BIT_LEN        (1U)                
#define ADR_FILT_CFG_LSADRAPE_BIT_MASK       0x8000U              
#define ADR_FILT_CFG_SSADRAPE_BIT_OFFSET     (14U)               
#define ADR_FILT_CFG_SSADRAPE_BIT_LEN        (1U)                
#define ADR_FILT_CFG_SSADRAPE_BIT_MASK       0x4000U              
#define ADR_FILT_CFG_LE3_PEND_BIT_OFFSET     (13U)               
#define ADR_FILT_CFG_LE3_PEND_BIT_LEN        (1U)                
#define ADR_FILT_CFG_LE3_PEND_BIT_MASK       0x2000U              
#define ADR_FILT_CFG_LE2_PEND_BIT_OFFSET     (12U)               
#define ADR_FILT_CFG_LE2_PEND_BIT_LEN        (1U)                
#define ADR_FILT_CFG_LE2_PEND_BIT_MASK       0x1000U              
#define ADR_FILT_CFG_LE1_PEND_BIT_OFFSET     (11U)               
#define ADR_FILT_CFG_LE1_PEND_BIT_LEN        (1U)                
#define ADR_FILT_CFG_LE1_PEND_BIT_MASK       0x800U               
#define ADR_FILT_CFG_LE0_PEND_BIT_OFFSET     (10U)               
#define ADR_FILT_CFG_LE0_PEND_BIT_LEN        (1U)                
#define ADR_FILT_CFG_LE0_PEND_BIT_MASK       0x400U               
#define ADR_FILT_CFG_FFIB_BIT_OFFSET         (9U)                
#define ADR_FILT_CFG_FFIB_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFIB_BIT_MASK           0x200U               
#define ADR_FILT_CFG_FFBC_BIT_OFFSET         (8U)                
#define ADR_FILT_CFG_FFBC_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFBC_BIT_MASK           0x100U               
#define ADR_FILT_CFG_FFAE_BIT_OFFSET         (7U)                
#define ADR_FILT_CFG_FFAE_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAE_BIT_MASK           0x80U                
#define ADR_FILT_CFG_FFAF_BIT_OFFSET         (6U)                
#define ADR_FILT_CFG_FFAF_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAF_BIT_MASK           0x40U                
#define ADR_FILT_CFG_FFAMULTI_BIT_OFFSET     (5U)                
#define ADR_FILT_CFG_FFAMULTI_BIT_LEN        (1U)                
#define ADR_FILT_CFG_FFAMULTI_BIT_MASK       0x20U                
#define ADR_FILT_CFG_FFAR_BIT_OFFSET         (4U)                
#define ADR_FILT_CFG_FFAR_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAR_BIT_MASK           0x10U                
#define ADR_FILT_CFG_FFAM_BIT_OFFSET         (3U)                
#define ADR_FILT_CFG_FFAM_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAM_BIT_MASK           0x8U                 
#define ADR_FILT_CFG_FFAA_BIT_OFFSET         (2U)                
#define ADR_FILT_CFG_FFAA_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAA_BIT_MASK           0x4U                 
#define ADR_FILT_CFG_FFAD_BIT_OFFSET         (1U)                
#define ADR_FILT_CFG_FFAD_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAD_BIT_MASK           0x2U                 
#define ADR_FILT_CFG_FFAB_BIT_OFFSET         (0U)                
#define ADR_FILT_CFG_FFAB_BIT_LEN            (1U)                
#define ADR_FILT_CFG_FFAB_BIT_MASK           0x1U                 

/******************************************************************************
* @brief Bit definitions for register SPICRC_CFG
**/
#define SPICRC_CFG_ID                        0x18                 
#define SPICRC_CFG_LEN                       (4U)                
#define SPICRC_CFG_MASK                      0xFFFFFFFFUL        
#define SPICRC_CFG_SPI_RD_CRC_BIT_OFFSET     (0U)                
#define SPICRC_CFG_SPI_RD_CRC_BIT_LEN        (8U)                
#define SPICRC_CFG_SPI_RD_CRC_BIT_MASK       0xffU                

/******************************************************************************
* @brief Bit definitions for register SYS_TIME
**/
#define SYS_TIME_ID                          0x1c                 
#define SYS_TIME_LEN                         (4U)                
#define SYS_TIME_MASK                        0xFFFFFFFFUL        
#define SYS_TIME_SYS_TIME_BIT_OFFSET         (1U)                
#define SYS_TIME_SYS_TIME_BIT_LEN            (31U)               
#define SYS_TIME_SYS_TIME_BIT_MASK           0xfffffffeUL         

/******************************************************************************
* @brief Bit definitions for register TX_FCTRL
**/
#define TX_FCTRL_ID                          0x24                 
#define TX_FCTRL_LEN                         (4U)                
#define TX_FCTRL_MASK                        0xFFFFFFFFUL        
#define TX_FCTRL_TXB_OFFSET_BIT_OFFSET       (16U)               
#define TX_FCTRL_TXB_OFFSET_BIT_LEN          (10U)               
#define TX_FCTRL_TXB_OFFSET_BIT_MASK         0x3ff0000UL          
#define TX_FCTRL_TXPSR_BIT_OFFSET         (12U)               
#define TX_FCTRL_TXPSR_BIT_LEN            (4U)                
#define TX_FCTRL_TXPSR_BIT_MASK           0xf000U              
#define TX_FCTRL_TR_BIT_OFFSET               (11U)               
#define TX_FCTRL_TR_BIT_LEN                  (1U)                
#define TX_FCTRL_TR_BIT_MASK                 0x800U               
#define TX_FCTRL_TXBR_BIT_OFFSET             (10U)               
#define TX_FCTRL_TXBR_BIT_LEN                (1U)                
#define TX_FCTRL_TXBR_BIT_MASK               0x400U               
#define TX_FCTRL_TXFLEN_BIT_OFFSET           (0U)                
#define TX_FCTRL_TXFLEN_BIT_LEN              (10U)               
#define TX_FCTRL_TXFLEN_BIT_MASK             0x3ffU               

/******************************************************************************
* @brief Bit definitions for register TX_FCTRL_HI
**/
#define TX_FCTRL_HI_ID                       0x28                 
#define TX_FCTRL_HI_LEN                      (4U)                
#define TX_FCTRL_HI_MASK                     0xFFFFFFFFUL        
#define TX_FCTRL_HI_FINE_PLEN_BIT_OFFSET     (8U)                
#define TX_FCTRL_HI_FINE_PLEN_BIT_LEN        (8U)                
#define TX_FCTRL_HI_FINE_PLEN_BIT_MASK       0xff00U              

/******************************************************************************
* @brief Bit definitions for register DX_TIME
**/
#define DX_TIME_ID                           0x2c                 
#define DX_TIME_LEN                          (4U)                
#define DX_TIME_MASK                         0xFFFFFFFFUL        
#define DX_TIME_DX_TIME_BIT_OFFSET           (1U)                
#define DX_TIME_DX_TIME_BIT_LEN              (31U)               
#define DX_TIME_DX_TIME_BIT_MASK             0xfffffffeUL         

/******************************************************************************
* @brief Bit definitions for register DREF_TIME
**/
#define DREF_TIME_ID                         0x30                 
#define DREF_TIME_LEN                        (4U)                
#define DREF_TIME_MASK                       0xFFFFFFFFUL        
#define DREF_TIME_DREF_BIT_OFFSET            (1U)                
#define DREF_TIME_DREF_BIT_LEN               (31U)               
#define DREF_TIME_DREF_BIT_MASK              0xfffffffeUL         

/******************************************************************************
* @brief Bit definitions for register RX_FWTO
**/
#define RX_FWTO_ID                           0x34                 
#define RX_FWTO_LEN                          (4U)                
#define RX_FWTO_MASK                         0xFFFFFFFFUL        
#define RX_FWTO_FWTO_BIT_OFFSET              (0U)                
#define RX_FWTO_FWTO_BIT_LEN                 (20U)               
#define RX_FWTO_FWTO_BIT_MASK                0xfffffUL            

/******************************************************************************
* @brief Bit definitions for register SYS_ENABLE_LO
**/
#define SYS_ENABLE_LO_ID                     0x3c                 
#define SYS_ENABLE_LO_LEN                    (4U)                
#define SYS_ENABLE_LO_MASK                   0xFFFFFFFFUL        
#define SYS_ENABLE_LO_ARFE_ENABLE_BIT_OFFSET (29U)               
#define SYS_ENABLE_LO_ARFE_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_LO_ARFE_ENABLE_BIT_MASK   0x20000000UL         
#define SYS_ENABLE_LO_CPERR_ENABLE_BIT_OFFSET (28U)               
#define SYS_ENABLE_LO_CPERR_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_CPERR_ENABLE_BIT_MASK  0x10000000UL         
#define SYS_ENABLE_LO_HPDWARN_ENABLE_BIT_OFFSET (27U)               
#define SYS_ENABLE_LO_HPDWARN_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_LO_HPDWARN_ENABLE_BIT_MASK 0x8000000UL          
#define SYS_ENABLE_LO_RXSTO_ENABLE_BIT_OFFSET (26U)               
#define SYS_ENABLE_LO_RXSTO_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXSTO_ENABLE_BIT_MASK  0x4000000UL          
#define SYS_ENABLE_LO_PLL_HILO_ENABLE_BIT_OFFSET (25U)               
#define SYS_ENABLE_LO_PLL_HILO_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_LO_PLL_HILO_ENABLE_BIT_MASK 0x2000000UL          
#define SYS_ENABLE_LO_RCINIT_ENABLE_BIT_OFFSET (24U)               
#define SYS_ENABLE_LO_RCINIT_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_LO_RCINIT_ENABLE_BIT_MASK 0x1000000UL          
#define SYS_ENABLE_LO_SPIRDY_ENABLE_BIT_OFFSET (23U)               
#define SYS_ENABLE_LO_SPIRDY_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_LO_SPIRDY_ENABLE_BIT_MASK 0x800000UL           
#define SYS_ENABLE_LO_RXPTO_ENABLE_BIT_OFFSET (21U)               
#define SYS_ENABLE_LO_RXPTO_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXPTO_ENABLE_BIT_MASK  0x200000UL           
#define SYS_ENABLE_LO_RXOVRR_ENABLE_BIT_OFFSET (20U)               
#define SYS_ENABLE_LO_RXOVRR_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_LO_RXOVRR_ENABLE_BIT_MASK 0x100000UL           
#define SYS_ENABLE_LO_VWARN_ENABLE_BIT_OFFSET (19U)               
#define SYS_ENABLE_LO_VWARN_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_VWARN_ENABLE_BIT_MASK  0x80000UL            
#define SYS_ENABLE_LO_CIAERR_ENABLE_BIT_OFFSET (18U)               
#define SYS_ENABLE_LO_CIAERR_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_LO_CIAERR_ENABLE_BIT_MASK 0x40000UL            
#define SYS_ENABLE_LO_RXFTO_ENABLE_BIT_OFFSET (17U)               
#define SYS_ENABLE_LO_RXFTO_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXFTO_ENABLE_BIT_MASK  0x20000UL            
#define SYS_ENABLE_LO_RXFSL_ENABLE_BIT_OFFSET (16U)               
#define SYS_ENABLE_LO_RXFSL_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXFSL_ENABLE_BIT_MASK  0x10000UL            
#define SYS_ENABLE_LO_RXFCE_ENABLE_BIT_OFFSET (15U)               
#define SYS_ENABLE_LO_RXFCE_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXFCE_ENABLE_BIT_MASK  0x8000U              
#define SYS_ENABLE_LO_RXFCG_ENABLE_BIT_OFFSET (14U)               
#define SYS_ENABLE_LO_RXFCG_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXFCG_ENABLE_BIT_MASK  0x4000U              
#define SYS_ENABLE_LO_RXFR_ENABLE_BIT_OFFSET (13U)               
#define SYS_ENABLE_LO_RXFR_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_LO_RXFR_ENABLE_BIT_MASK   0x2000U              
#define SYS_ENABLE_LO_RXPHE_ENABLE_BIT_OFFSET (12U)               
#define SYS_ENABLE_LO_RXPHE_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXPHE_ENABLE_BIT_MASK  0x1000U              
#define SYS_ENABLE_LO_RXPHD_ENABLE_BIT_OFFSET (11U)               
#define SYS_ENABLE_LO_RXPHD_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXPHD_ENABLE_BIT_MASK  0x800U               
#define SYS_ENABLE_LO_CIADONE_ENABLE_BIT_OFFSET (10U)               
#define SYS_ENABLE_LO_CIADONE_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_LO_CIADONE_ENABLE_BIT_MASK 0x400U               
#define SYS_ENABLE_LO_RXSFDD_ENABLE_BIT_OFFSET (9U)                
#define SYS_ENABLE_LO_RXSFDD_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_LO_RXSFDD_ENABLE_BIT_MASK 0x200U               
#define SYS_ENABLE_LO_RXPRD_ENABLE_BIT_OFFSET (8U)                
#define SYS_ENABLE_LO_RXPRD_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_RXPRD_ENABLE_BIT_MASK  0x100U               
#define SYS_ENABLE_LO_TXFRS_ENABLE_BIT_OFFSET (7U)                
#define SYS_ENABLE_LO_TXFRS_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_TXFRS_ENABLE_BIT_MASK  0x80U                
#define SYS_ENABLE_LO_TXPHS_ENABLE_BIT_OFFSET (6U)                
#define SYS_ENABLE_LO_TXPHS_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_TXPHS_ENABLE_BIT_MASK  0x40U                
#define SYS_ENABLE_LO_TXPRS_ENABLE_BIT_OFFSET (5U)                
#define SYS_ENABLE_LO_TXPRS_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_TXPRS_ENABLE_BIT_MASK  0x20U                
#define SYS_ENABLE_LO_TXFRB_ENABLE_BIT_OFFSET (4U)                
#define SYS_ENABLE_LO_TXFRB_ENABLE_BIT_LEN   (1U)                
#define SYS_ENABLE_LO_TXFRB_ENABLE_BIT_MASK  0x10U                
#define SYS_ENABLE_LO_AAT_ENABLE_BIT_OFFSET  (3U)                
#define SYS_ENABLE_LO_AAT_ENABLE_BIT_LEN     (1U)                
#define SYS_ENABLE_LO_AAT_ENABLE_BIT_MASK    0x8U                 
#define SYS_ENABLE_LO_SPICRCE_ENABLE_BIT_OFFSET (2U)                
#define SYS_ENABLE_LO_SPICRCE_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_LO_SPICRCE_ENABLE_BIT_MASK    0x4U                 
#define SYS_ENABLE_LO_CP_LOCK_ENABLE_BIT_OFFSET (1U)                
#define SYS_ENABLE_LO_CP_LOCK_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_LO_CP_LOCK_ENABLE_BIT_MASK   0x2U                 

/******************************************************************************
* @brief Bit definitions for register SYS_ENABLE_HI
**/
#define SYS_ENABLE_HI_ID                     0x40                 
#define SYS_ENABLE_HI_LEN                    (4U)                
#define SYS_ENABLE_HI_MASK                   0xFFFFFFFFUL        
#define SYS_ENABLE_HI_CCA_FAIL_ENABLE_BIT_OFFSET (12U)               
#define SYS_ENABLE_HI_CCA_FAIL_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_HI_CCA_FAIL_ENABLE_BIT_MASK 0x1000U              
#define SYS_ENABLE_HI_SPIERR_ENABLE_BIT_OFFSET (11U)               
#define SYS_ENABLE_HI_SPIERR_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_HI_SPIERR_ENABLE_BIT_MASK    0x800U               
#define SYS_ENABLE_HI_SPI_UNF_ENABLE_BIT_OFFSET (10U)               
#define SYS_ENABLE_HI_SPI_UNF_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_HI_SPI_UNF_ENABLE_BIT_MASK    0x400U               
#define SYS_ENABLE_HI_SPI_OVF_ENABLE_BIT_OFFSET (9U)                
#define SYS_ENABLE_HI_SPI_OVF_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_HI_SPI_OVF_ENABLE_BIT_MASK    0x200U               
#define SYS_ENABLE_HI_CMD_ERR_ENABLE_BIT_OFFSET (8U)                
#define SYS_ENABLE_HI_CMD_ERR_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_HI_CMD_ERR_ENABLE_BIT_MASK 0x100U               
#define SYS_ENABLE_HI_AES_ERR_ENABLE_BIT_OFFSET (7U)                
#define SYS_ENABLE_HI_AES_ERR_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_HI_AES_ERR_ENABLE_BIT_MASK 0x80U                
#define SYS_ENABLE_HI_AES_DONE_ENABLE_BIT_OFFSET (6U)                
#define SYS_ENABLE_HI_AES_DONE_ENABLE_BIT_LEN (1U)                
#define SYS_ENABLE_HI_AES_DONE_ENABLE_BIT_MASK 0x40U                
#define SYS_ENABLE_HI_GPIOIRQ_ENABLE_BIT_OFFSET (5U)                
#define SYS_ENABLE_HI_GPIOIRQ_ENABLE_BIT_LEN    (1U)                
#define SYS_ENABLE_HI_GPIOIRQ_ENABLE_BIT_MASK   0x20U                
#define SYS_ENABLE_HI_VT_DET_ENABLE_BIT_OFFSET (4U)                
#define SYS_ENABLE_HI_VT_DET_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_HI_VT_DET_ENABLE_BIT_MASK 0x10U                
#define SYS_ENABLE_HI_RXPREJ_ENABLE_BIT_OFFSET (1U)                
#define SYS_ENABLE_HI_RXPREJ_ENABLE_BIT_LEN  (1U)                
#define SYS_ENABLE_HI_RXPREJ_ENABLE_BIT_MASK 0x2U                 
                 

/******************************************************************************
* @brief Bit definitions for register SYS_STATUS
**/
#define SYS_STATUS_ID                        0x44                 
#define SYS_STATUS_LEN                       (4U)                
#define SYS_STATUS_MASK                      0xFFFFFFFFUL        
#define SYS_STATUS_ARFE_BIT_OFFSET           (29U)               
#define SYS_STATUS_ARFE_BIT_LEN              (1U)                
#define SYS_STATUS_ARFE_BIT_MASK             0x20000000UL         
#define SYS_STATUS_CPERR_BIT_OFFSET          (28U)               
#define SYS_STATUS_CPERR_BIT_LEN             (1U)                
#define SYS_STATUS_CPERR_BIT_MASK            0x10000000UL         
#define SYS_STATUS_HPDWARN_BIT_OFFSET        (27U)               
#define SYS_STATUS_HPDWARN_BIT_LEN           (1U)                
#define SYS_STATUS_HPDWARN_BIT_MASK          0x8000000UL          
#define SYS_STATUS_RXSTO_BIT_OFFSET          (26U)               
#define SYS_STATUS_RXSTO_BIT_LEN             (1U)                
#define SYS_STATUS_RXSTO_BIT_MASK            0x4000000UL          
#define SYS_STATUS_PLL_HILO_BIT_OFFSET       (25U)               
#define SYS_STATUS_PLL_HILO_BIT_LEN          (1U)                
#define SYS_STATUS_PLL_HILO_BIT_MASK         0x2000000UL          
#define SYS_STATUS_RCINIT_BIT_OFFSET         (24U)               
#define SYS_STATUS_RCINIT_BIT_LEN            (1U)                
#define SYS_STATUS_RCINIT_BIT_MASK           0x1000000UL          
#define SYS_STATUS_SPIRDY_BIT_OFFSET         (23U)               
#define SYS_STATUS_SPIRDY_BIT_LEN            (1U)                
#define SYS_STATUS_SPIRDY_BIT_MASK           0x800000UL                    
#define SYS_STATUS_RXPTO_BIT_OFFSET          (21U)               
#define SYS_STATUS_RXPTO_BIT_LEN             (1U)                
#define SYS_STATUS_RXPTO_BIT_MASK            0x200000UL           
#define SYS_STATUS_RXOVRR_BIT_OFFSET         (20U)               
#define SYS_STATUS_RXOVRR_BIT_LEN            (1U)                
#define SYS_STATUS_RXOVRR_BIT_MASK           0x100000UL           
#define SYS_STATUS_VWARN_BIT_OFFSET          (19U)               
#define SYS_STATUS_VWARN_BIT_LEN             (1U)                
#define SYS_STATUS_VWARN_BIT_MASK            0x80000UL            
#define SYS_STATUS_CIAERR_BIT_OFFSET         (18U)               
#define SYS_STATUS_CIAERR_BIT_LEN            (1U)                
#define SYS_STATUS_CIAERR_BIT_MASK           0x40000UL            
#define SYS_STATUS_RXFTO_BIT_OFFSET          (17U)               
#define SYS_STATUS_RXFTO_BIT_LEN             (1U)                
#define SYS_STATUS_RXFTO_BIT_MASK            0x20000UL            
#define SYS_STATUS_RXFSL_BIT_OFFSET          (16U)               
#define SYS_STATUS_RXFSL_BIT_LEN             (1U)                
#define SYS_STATUS_RXFSL_BIT_MASK            0x10000UL            
#define SYS_STATUS_RXFCE_BIT_OFFSET          (15U)               
#define SYS_STATUS_RXFCE_BIT_LEN             (1U)                
#define SYS_STATUS_RXFCE_BIT_MASK            0x8000U              
#define SYS_STATUS_RXFCG_BIT_OFFSET          (14U)               
#define SYS_STATUS_RXFCG_BIT_LEN             (1U)                
#define SYS_STATUS_RXFCG_BIT_MASK            0x4000U              
#define SYS_STATUS_RXFR_BIT_OFFSET           (13U)               
#define SYS_STATUS_RXFR_BIT_LEN              (1U)                
#define SYS_STATUS_RXFR_BIT_MASK             0x2000U              
#define SYS_STATUS_RXPHE_BIT_OFFSET          (12U)               
#define SYS_STATUS_RXPHE_BIT_LEN             (1U)                
#define SYS_STATUS_RXPHE_BIT_MASK            0x1000U              
#define SYS_STATUS_RXPHD_BIT_OFFSET          (11U)               
#define SYS_STATUS_RXPHD_BIT_LEN             (1U)                
#define SYS_STATUS_RXPHD_BIT_MASK            0x800U               
#define SYS_STATUS_CIADONE_BIT_OFFSET       (10U)               
#define SYS_STATUS_CIADONE_BIT_LEN          (1U)                
#define SYS_STATUS_CIADONE_BIT_MASK         0x400U               
#define SYS_STATUS_RXSFDD_BIT_OFFSET         (9U)                
#define SYS_STATUS_RXSFDD_BIT_LEN            (1U)                
#define SYS_STATUS_RXSFDD_BIT_MASK           0x200U               
#define SYS_STATUS_RXPRD_BIT_OFFSET          (8U)                
#define SYS_STATUS_RXPRD_BIT_LEN             (1U)                
#define SYS_STATUS_RXPRD_BIT_MASK            0x100U               
#define SYS_STATUS_TXFRS_BIT_OFFSET          (7U)                
#define SYS_STATUS_TXFRS_BIT_LEN             (1U)                
#define SYS_STATUS_TXFRS_BIT_MASK            0x80U                
#define SYS_STATUS_TXPHS_BIT_OFFSET          (6U)                
#define SYS_STATUS_TXPHS_BIT_LEN             (1U)                
#define SYS_STATUS_TXPHS_BIT_MASK            0x40U                
#define SYS_STATUS_TXPRS_BIT_OFFSET          (5U)                
#define SYS_STATUS_TXPRS_BIT_LEN             (1U)                
#define SYS_STATUS_TXPRS_BIT_MASK            0x20U                
#define SYS_STATUS_TXFRB_BIT_OFFSET          (4U)                
#define SYS_STATUS_TXFRB_BIT_LEN             (1U)                
#define SYS_STATUS_TXFRB_BIT_MASK            0x10U                
#define SYS_STATUS_AAT_BIT_OFFSET            (3U)                
#define SYS_STATUS_AAT_BIT_LEN               (1U)                
#define SYS_STATUS_AAT_BIT_MASK              0x8U                 
#define SYS_STATUS_SPICRCE_BIT_OFFSET      (2U)                
#define SYS_STATUS_SPICRCE_BIT_LEN         (1U)                
#define SYS_STATUS_SPICRCE_BIT_MASK        0x4U                 
#define SYS_STATUS_CP_LOCK_BIT_OFFSET   (1U)                
#define SYS_STATUS_CP_LOCK_BIT_LEN      (1U)                
#define SYS_STATUS_CP_LOCK_BIT_MASK     0x2U                 
#define SYS_STATUS_IRQS_BIT_OFFSET           (0U)                
#define SYS_STATUS_IRQS_BIT_LEN              (1U)                
#define SYS_STATUS_IRQS_BIT_MASK             0x1U                 

/******************************************************************************
* @brief Bit definitions for register SYS_STATUS_HI
**/
#define SYS_STATUS_HI_ID                     0x48                 
#define SYS_STATUS_HI_LEN                    (4U)                
#define SYS_STATUS_HI_MASK                   0xFFFFFFFFUL        
#define SYS_STATUS_HI_CCA_FAIL_BIT_OFFSET    (12U)               
#define SYS_STATUS_HI_CCA_FAIL_BIT_LEN       (1U)                
#define SYS_STATUS_HI_CCA_FAIL_BIT_MASK      0x1000U              
#define SYS_STATUS_HI_SPIERR_BIT_OFFSET (11U)               
#define SYS_STATUS_HI_SPIERR_BIT_LEN  (1U)                
#define SYS_STATUS_HI_SPIERR_BIT_MASK 0x800U               
#define SYS_STATUS_HI_SPI_UNF_BIT_OFFSET     (10U)               
#define SYS_STATUS_HI_SPI_UNF_BIT_LEN        (1U)                
#define SYS_STATUS_HI_SPI_UNF_BIT_MASK       0x400U               
#define SYS_STATUS_HI_SPI_OVF_BIT_OFFSET     (9U)                
#define SYS_STATUS_HI_SPI_OVF_BIT_LEN        (1U)                
#define SYS_STATUS_HI_SPI_OVF_BIT_MASK       0x200U               
#define SYS_STATUS_HI_CMD_ERR_BIT_OFFSET     (8U)                
#define SYS_STATUS_HI_CMD_ERR_BIT_LEN        (1U)                
#define SYS_STATUS_HI_CMD_ERR_BIT_MASK       0x100U               
#define SYS_STATUS_HI_AES_ERR_BIT_OFFSET     (7U)                
#define SYS_STATUS_HI_AES_ERR_BIT_LEN        (1U)                
#define SYS_STATUS_HI_AES_ERR_BIT_MASK       0x80U                
#define SYS_STATUS_HI_AES_DONE_BIT_OFFSET    (6U)                
#define SYS_STATUS_HI_AES_DONE_BIT_LEN       (1U)                
#define SYS_STATUS_HI_AES_DONE_BIT_MASK      0x40U                
#define SYS_STATUS_HI_GPIO_IRQ_BIT_OFFSET        (5U)                
#define SYS_STATUS_HI_GPIO_IRQ_BIT_LEN           (1U)                
#define SYS_STATUS_HI_GPIO_IRQ_BIT_MASK          0x20U                
#define SYS_STATUS_HI_VT_DET_BIT_OFFSET      (4U)                
#define SYS_STATUS_HI_VT_DET_BIT_LEN         (1U)                
#define SYS_STATUS_HI_VT_DET_BIT_MASK        0x10U                
#define SYS_STATUS_HI_RXPREJ_BIT_OFFSET      (1U)                
#define SYS_STATUS_HI_RXPREJ_BIT_LEN         (1U)                
#define SYS_STATUS_HI_RXPREJ_BIT_MASK        0x2U                 
              

/******************************************************************************
* @brief Bit definitions for register RX_FINFO
**/
#define RX_FINFO_ID                          0x4c                 
#define RX_FINFO_LEN                         (4U)                
#define RX_FINFO_MASK                        0xFFFFFFFFUL        
#define RX_FINFO_RXPACC_BIT_OFFSET           (20U)               
#define RX_FINFO_RXPACC_BIT_LEN              (12U)               
#define RX_FINFO_RXPACC_BIT_MASK             0xfff00000UL         
#define RX_FINFO_RXPSR_BIT_OFFSET            (18U)               
#define RX_FINFO_RXPSR_BIT_LEN               (2U)                
#define RX_FINFO_RXPSR_BIT_MASK              0xc0000UL            
#define RX_FINFO_RXPRF_BIT_OFFSET            (16U)               
#define RX_FINFO_RXPRF_BIT_LEN               (2U)                
#define RX_FINFO_RXPRF_BIT_MASK              0x30000UL            
#define RX_FINFO_RNG_BIT_OFFSET              (15U)               
#define RX_FINFO_RNG_BIT_LEN                 (1U)                
#define RX_FINFO_RNG_BIT_MASK                0x8000U              
#define RX_FINFO_RXBR_BIT_OFFSET             (13U)               
#define RX_FINFO_RXBR_BIT_LEN                (1U)                
#define RX_FINFO_RXBR_BIT_MASK               0x2000U              
#define RX_FINFO_RXNSPL_BIT_OFFSET           (11U)               
#define RX_FINFO_RXNSPL_BIT_LEN              (2U)                
#define RX_FINFO_RXNSPL_BIT_MASK             0x1800U              
#define RX_FINFO_RXFLEN_BIT_OFFSET           (0U)                
#define RX_FINFO_RXFLEN_BIT_LEN              (10U)               
#define RX_FINFO_RXFLEN_BIT_MASK             0x3ffU               





/******************************************************************************
* @brief Bit definitions for register RX_TIME_0
**/
#define RX_TIME_0_ID                         0x64                 
#define RX_TIME_0_LEN                        (4U)                
#define RX_TIME_0_MASK                       0xFFFFFFFFUL        



/******************************************************************************
* @brief Bit definitions for register RX_TIME_RAW
**/
#define RX_TIME_RAW_ID                         0x70                 
#define RX_TIME_RAW_LEN                        (4U)                
#define RX_TIME_RAW_MASK                       0xFFFFFFFFUL        
#define RX_TIME_RX_RAWST_BIT_OFFSET (0U)                
#define RX_TIME_RX_RAWST_BIT_LEN (32U)               
#define RX_TIME_RX_RAWST_BIT_MASK 0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register TX_TIME_LO
**/
#define TX_TIME_LO_ID                        0x74                 
#define TX_TIME_LO_LEN                       (4U)                
#define TX_TIME_LO_MASK                      0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register TX_TIME_RAW
**/
#define TX_TIME_RAW_ID                         0x10000              
#define TX_TIME_RAW_LEN                        (4U)                
#define TX_TIME_RAW_MASK                       0xFFFFFFFFUL        
#define TX_TIME_TX_RAWST_BIT_OFFSET (0U)                
#define TX_TIME_TX_RAWST_BIT_LEN (32U)               
#define TX_TIME_TX_RAWST_BIT_MASK 0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register TX_ANTD
**/
#define TX_ANTD_ID                           0x10004              
#define TX_ANTD_LEN                          (4U)                
#define TX_ANTD_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register ACK_RESP
**/
#define ACK_RESP_ID                          0x10008              
#define ACK_RESP_LEN                         (4U)                
#define ACK_RESP_MASK                        0xFFFFFFFFUL        
#define ACK_RESP_W4R_TIM_BIT_OFFSET    (0U)                
#define ACK_RESP_W4R_TIM_BIT_LEN       (20U)               
#define ACK_RESP_W4R_TIM_BIT_MASK      0xfffffUL            

/******************************************************************************
* @brief Bit definitions for register TX_POWER
**/
#define TX_POWER_ID                          0x1000c              
#define TX_POWER_LEN                         (4U)                
#define TX_POWER_MASK                        0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register CHAN_CTRL
**/
#define CHAN_CTRL_ID                         0x10014              
#define CHAN_CTRL_LEN                        (4U)                
#define CHAN_CTRL_MASK                       0xFFFFFFFFUL        
#define CHAN_CTRL_RX_PCODE_BIT_OFFSET        (8U)                
#define CHAN_CTRL_RX_PCODE_BIT_LEN           (5U)                
#define CHAN_CTRL_RX_PCODE_BIT_MASK          0x1f00U              
#define CHAN_CTRL_TX_PCODE_BIT_OFFSET        (3U)                
#define CHAN_CTRL_TX_PCODE_BIT_LEN           (5U)                
#define CHAN_CTRL_TX_PCODE_BIT_MASK          0xf8U                
#define CHAN_CTRL_SFD_TYPE_BIT_OFFSET        (1U)                
#define CHAN_CTRL_SFD_TYPE_BIT_LEN           (2U)                
#define CHAN_CTRL_SFD_TYPE_BIT_MASK          0x6U                 
#define CHAN_CTRL_RF_CHAN_BIT_OFFSET         (0U)                
#define CHAN_CTRL_RF_CHAN_BIT_LEN            (1U)                
#define CHAN_CTRL_RF_CHAN_BIT_MASK           0x1U                 

/******************************************************************************
* @brief Bit definitions for register LE_PEND_01
**/
#define LE_PEND_01_ID                        0x10018              
#define LE_PEND_01_LEN                       (4U)                
#define LE_PEND_01_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register LE_PEND_23
**/
#define LE_PEND_23_ID                        0x1001c              
#define LE_PEND_23_LEN                       (4U)                
#define LE_PEND_23_MASK                      0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register RDB_STATUS
**/
#define RDB_STATUS_ID                        0x10024              
#define RDB_STATUS_LEN                       (4U)                
#define RDB_STATUS_MASK                      0xFFFFFFFFUL        
#define RDB_STATUS_CP_ERR1_BIT_OFFSET        (7U)                
#define RDB_STATUS_CP_ERR1_BIT_LEN           (1U)                
#define RDB_STATUS_CP_ERR1_BIT_MASK          0x80U                
#define RDB_STATUS_CIADONE1_BIT_OFFSET       (6U)                
#define RDB_STATUS_CIADONE1_BIT_LEN          (1U)                
#define RDB_STATUS_CIADONE1_BIT_MASK         0x40U                
#define RDB_STATUS_RXFR1_BIT_OFFSET          (5U)                
#define RDB_STATUS_RXFR1_BIT_LEN             (1U)                
#define RDB_STATUS_RXFR1_BIT_MASK            0x20U                
#define RDB_STATUS_RXFCG1_BIT_OFFSET         (4U)                
#define RDB_STATUS_RXFCG1_BIT_LEN            (1U)                
#define RDB_STATUS_RXFCG1_BIT_MASK           0x10U                
#define RDB_STATUS_CP_ERR0_BIT_OFFSET        (3U)                
#define RDB_STATUS_CP_ERR0_BIT_LEN           (1U)                
#define RDB_STATUS_CP_ERR0_BIT_MASK          0x8U                 
#define RDB_STATUS_CIADONE0_BIT_OFFSET       (2U)                
#define RDB_STATUS_CIADONE0_BIT_LEN          (1U)                
#define RDB_STATUS_CIADONE0_BIT_MASK         0x4U                 
#define RDB_STATUS_RXFR0_BIT_OFFSET          (1U)                
#define RDB_STATUS_RXFR0_BIT_LEN             (1U)                
#define RDB_STATUS_RXFR0_BIT_MASK            0x2U                 
#define RDB_STATUS_RXFCG0_BIT_OFFSET         (0U)                
#define RDB_STATUS_RXFCG0_BIT_LEN            (1U)                
#define RDB_STATUS_RXFCG0_BIT_MASK           0x1U                 

/******************************************************************************
* @brief Bit definitions for register RDB_DIAG_MODE
**/
#define RDB_DIAG_MODE_ID                     0x10028              
#define RDB_DIAG_MODE_LEN                    (4U)                
#define RDB_DIAG_MODE_MASK                   0xFFFFFFFFUL        
#define RDB_DIAG_MODE_RDB_DMODE_BIT_OFFSET (0U)                
#define RDB_DIAG_MODE_RDB_DMODE_BIT_LEN  (3U)                
#define RDB_DIAG_MODE_RDB_DMODE_BIT_MASK 0x7U                 


/******************************************************************************
* @brief Bit definitions for register AES_CFG
**/
#define AES_CFG_ID                           0x10030              
#define AES_CFG_LEN                          (4U)                
#define AES_CFG_MASK                         0xFFFFFFFFUL        
#define AES_CFG_KEY_OTP_BIT_OFFSET       (12U)               
#define AES_CFG_KEY_OTP_BIT_LEN          (1U)                
#define AES_CFG_KEY_OTP_BIT_MASK         0x1000U              
#define AES_CFG_CORE_SEL_BIT_OFFSET      (11U)               
#define AES_CFG_CORE_SEL_BIT_LEN         (1U)                
#define AES_CFG_CORE_SEL_BIT_MASK        0x800U               
#define AES_CFG_TAG_SIZE_BIT_OFFSET      (8U)                
#define AES_CFG_TAG_SIZE_BIT_LEN         (3U)                
#define AES_CFG_TAG_SIZE_BIT_MASK        0x700U               
#define AES_CFG_KEY_SRC_BIT_OFFSET       (7U)                
#define AES_CFG_KEY_SRC_BIT_LEN          (1U)                
#define AES_CFG_KEY_SRC_BIT_MASK         0x80U                
#define AES_CFG_KEY_LOAD_BIT_OFFSET      (6U)                
#define AES_CFG_KEY_LOAD_BIT_LEN         (1U)                
#define AES_CFG_KEY_LOAD_BIT_MASK        0x40U                
#define AES_CFG_KEY_ADDR_BIT_OFFSET      (3U)                
#define AES_CFG_KEY_ADDR_BIT_LEN         (3U)                
#define AES_CFG_KEY_ADDR_BIT_MASK        0x38U                
#define AES_CFG_KEY_SIZE_BIT_OFFSET      (1U)                
#define AES_CFG_KEY_SIZE_BIT_LEN         (2U)                
#define AES_CFG_KEY_SIZE_BIT_MASK        0x6U                 
#define AES_CFG_MODE_BIT_OFFSET          (0U)                
#define AES_CFG_MODE_BIT_LEN             (1U)                
#define AES_CFG_MODE_BIT_MASK            0x1U                 

/******************************************************************************
* @brief Bit definitions for register AES_IV0
**/
#define AES_IV0_ID                           0x10034              
#define AES_IV0_LEN                          (4U)                
#define AES_IV0_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register AES_IV1
**/
#define AES_IV1_ID                           0x10038              
#define AES_IV1_LEN                          (4U)                
#define AES_IV1_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register AES_IV2
**/
#define AES_IV2_ID                           0x1003c              
#define AES_IV2_LEN                          (4U)                
#define AES_IV2_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register AES_IV3
**/
#define AES_IV3_ID                           0x10040              
#define AES_IV3_LEN                          (4U)                
#define AES_IV3_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DMA_CFG0
**/
#define DMA_CFG0_ID                          0x10044              
#define DMA_CFG0_LEN                         (4U)                
#define DMA_CFG0_MASK                        0xFFFFFFFFUL        
#define DMA_CFG0_CP_END_SEL_BIT_OFFSET   (26U)               
#define DMA_CFG0_CP_END_SEL_BIT_LEN      (1U)                
#define DMA_CFG0_CP_END_SEL_BIT_MASK     0x4000000UL          
#define DMA_CFG0_DST_ADDR_BIT_OFFSET     (16U)               
#define DMA_CFG0_DST_ADDR_BIT_LEN        (10U)               
#define DMA_CFG0_DST_ADDR_BIT_MASK       0x3ff0000UL          
#define DMA_CFG0_DST_PORT_BIT_OFFSET     (13U)               
#define DMA_CFG0_DST_PORT_BIT_LEN        (3U)                
#define DMA_CFG0_DST_PORT_BIT_MASK       0xe000U              
#define DMA_CFG0_SRC_ADDR_BIT_OFFSET     (3U)                
#define DMA_CFG0_SRC_ADDR_BIT_LEN        (10U)               
#define DMA_CFG0_SRC_ADDR_BIT_MASK       0x1ff8U              
#define DMA_CFG0_SRC_PORT_BIT_OFFSET     (0U)                
#define DMA_CFG0_SRC_PORT_BIT_LEN        (3U)                
#define DMA_CFG0_SRC_PORT_BIT_MASK       0x7U                 

/******************************************************************************
* @brief Bit definitions for register DMA_CFG1
**/
#define DMA_CFG1_ID                          0x10048              
#define DMA_CFG1_LEN                         (4U)                
#define DMA_CFG1_MASK                        0xFFFFFFFFUL        
#define DMA_CFG1_PYLD_SIZE_BIT_OFFSET    (7U)                
#define DMA_CFG1_PYLD_SIZE_BIT_LEN       (10U)               
#define DMA_CFG1_PYLD_SIZE_BIT_MASK      0x1ff80UL            
#define DMA_CFG1_HDR_SIZE_BIT_OFFSET     (0U)                
#define DMA_CFG1_HDR_SIZE_BIT_LEN        (7U)                
#define DMA_CFG1_HDR_SIZE_BIT_MASK       0x7fU                

/******************************************************************************
* @brief Bit definitions for register AES_START
**/
#define AES_START_ID                         0x1004c              
#define AES_START_LEN                        (4U)                
#define AES_START_MASK                       0xFFFFFFFFUL        
#define AES_START_AES_START_BIT_OFFSET       (0U)                
#define AES_START_AES_START_BIT_LEN          (1U)                
#define AES_START_AES_START_BIT_MASK         0x1U                 

/******************************************************************************
* @brief Bit definitions for register AES_STS
**/
#define AES_STS_ID                           0x10050              
#define AES_STS_LEN                          (4U)                
#define AES_STS_MASK                         0xFFFFFFFFUL        
#define AES_STS_RAM_FULL_BIT_OFFSET          (5U)
#define AES_STS_RAM_FULL_BIT_LEN             (1U)
#define AES_STS_RAM_FULL_BIT_MASK            0x20U
#define AES_STS_RAM_EMPTY_BIT_OFFSET         (4U)
#define AES_STS_RAM_EMPTY_BIT_LEN            (1U)
#define AES_STS_RAM_EMPTY_BIT_MASK           0x10U
#define AES_STS_MEM_CONF_BIT_OFFSET          (3U)
#define AES_STS_MEM_CONF_BIT_LEN             (1U)
#define AES_STS_MEM_CONF_BIT_MASK            0x8U
#define AES_STS_TRANS_ERR_BIT_OFFSET         (2U)
#define AES_STS_TRANS_ERR_BIT_LEN            (1U)
#define AES_STS_TRANS_ERR_BIT_MASK           0x4U
#define AES_STS_AUTH_ERR_BIT_OFFSET          (1U)
#define AES_STS_AUTH_ERR_BIT_LEN             (1U)
#define AES_STS_AUTH_ERR_BIT_MASK            0x2U
#define AES_STS_AES_DONE_BIT_OFFSET          (0U)                
#define AES_STS_AES_DONE_BIT_LEN             (1U)                
#define AES_STS_AES_DONE_BIT_MASK            0x1U                 

/******************************************************************************
* @brief Bit definitions for register AES_KEY0
**/
#define AES_KEY0_ID                          0x10054              
#define AES_KEY0_LEN                         (4U)                
#define AES_KEY0_MASK                        0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register AES_KEY1
**/
#define AES_KEY1_ID                          0x10058              
#define AES_KEY1_LEN                         (4U)                
#define AES_KEY1_MASK                        0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register AES_KEY2
**/
#define AES_KEY2_ID                          0x1005c              
#define AES_KEY2_LEN                         (4U)                
#define AES_KEY2_MASK                        0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register AES_KEY3
**/
#define AES_KEY3_ID                          0x10060              
#define AES_KEY3_LEN                         (4U)                
#define AES_KEY3_MASK                        0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_CFG0
**/
#define STS_CFG0_ID                           0x20000              
#define STS_CFG0_LEN                          (4U)                
#define STS_CFG0_MASK                         0xFFFFFFFFUL        
#define STS_CFG0_CPS_LEN_BIT_OFFSET         (0U)                
#define STS_CFG0_CPS_LEN_BIT_LEN            (8U)                
#define STS_CFG0_CPS_LEN_BIT_MASK           0xffU                

/******************************************************************************
* @brief Bit definitions for register STS_CTRL
**/
#define STS_CTRL_ID                           0x20004              
#define STS_CTRL_LEN                          (4U)                
#define STS_CTRL_MASK                         0xFFFFFFFFUL        
#define STS_CTRL_RST_LAST_BIT_OFFSET (1U)                
#define STS_CTRL_RST_LAST_BIT_LEN (1U)                
#define STS_CTRL_RST_LAST_BIT_MASK 0x2U                 
#define STS_CTRL_LOAD_IV_BIT_OFFSET        (0U)                
#define STS_CTRL_LOAD_IV_BIT_LEN           (1U)                
#define STS_CTRL_LOAD_IV_BIT_MASK          0x1U                 

/******************************************************************************
* @brief Bit definitions for register STS_STS
**/
#define STS_STS_ID                            0x20008              
#define STS_STS_LEN                           (4U)                
#define STS_STS_MASK                          0xFFFFFFFFUL        
#define STS_STS_ACC_QUAL_BIT_OFFSET           (0U)                
#define STS_STS_ACC_QUAL_BIT_LEN              (12U)               
#define STS_STS_ACC_QUAL_BIT_MASK             0xfffU               

/******************************************************************************
* @brief Bit definitions for register STS_KEY0
**/
#define STS_KEY0_ID                           0x2000c              
#define STS_KEY0_LEN                          (4U)                
#define STS_KEY0_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_KEY1
**/
#define STS_KEY1_ID                           0x20010              
#define STS_KEY1_LEN                          (4U)                
#define STS_KEY1_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_KEY2
**/
#define STS_KEY2_ID                           0x20014              
#define STS_KEY2_LEN                          (4U)                
#define STS_KEY2_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_KEY3
**/
#define STS_KEY3_ID                           0x20018              
#define STS_KEY3_LEN                          (4U)                
#define STS_KEY3_MASK                         0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_IV0
**/
#define STS_IV0_ID                            0x2001c              
#define STS_IV0_LEN                           (4U)                
#define STS_IV0_MASK                          0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_IV1
**/
#define STS_IV1_ID                            0x20020              
#define STS_IV1_LEN                           (4U)                
#define STS_IV1_MASK                          0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_IV2
**/
#define STS_IV2_ID                            0x20024              
#define STS_IV2_LEN                           (4U)                
#define STS_IV2_MASK                          0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_IV3
**/
#define STS_IV3_ID                            0x20028              
#define STS_IV3_LEN                           (4U)                
#define STS_IV3_MASK                          0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register LCSS_MARGIN
**/
#define LCSS_MARGIN_ID                       0x20034              

/******************************************************************************
* @brief Bit definitions for register DGC_CFG
**/
#define DGC_CFG_ID                           0x30018              
#define DGC_CFG_LEN                          (4U)                
#define DGC_CFG_MASK                         0xFFFFFFFFUL    
#define DGC_CFG_THR_64_BIT_OFFSET            (9U)                
#define DGC_CFG_THR_64_BIT_LEN               (6U)                
#define DGC_CFG_THR_64_BIT_MASK              0x7e00U  
#define DGC_CFG_RX_TUNE_EN_BIT_OFFSET        (0U)                
#define DGC_CFG_RX_TUNE_EN_BIT_LEN           (1U)                
#define DGC_CFG_RX_TUNE_EN_BIT_MASK          0x1U                 

/******************************************************************************
* @brief Bit definitions for register DGC_CFG0
**/
#define DGC_CFG0_ID              0x3001c              
#define DGC_CFG0_LEN             (4U)                
#define DGC_CFG0_MASK            0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_CFG1
**/
#define DGC_CFG1_ID             0x30020              
#define DGC_CFG1_LEN            (4U)                
#define DGC_CFG1_MASK           0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_0_CFG
**/
#define DGC_LUT_0_CFG_ID                 0x30038              
#define DGC_LUT_0_CFG_LEN                (4U)                
#define DGC_LUT_0_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_1_CFG
**/
#define DGC_LUT_1_CFG_ID                 0x3003c              
#define DGC_LUT_1_CFG_LEN                (4U)                
#define DGC_LUT_1_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_2_CFG
**/
#define DGC_LUT_2_CFG_ID                 0x30040              
#define DGC_LUT_2_CFG_LEN                (4U)                
#define DGC_LUT_2_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_3_CFG
**/
#define DGC_LUT_3_CFG_ID                 0x30044              
#define DGC_LUT_3_CFG_LEN                (4U)                
#define DGC_LUT_3_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_4_CFG
**/
#define DGC_LUT_4_CFG_ID                 0x30048              
#define DGC_LUT_4_CFG_LEN                (4U)                
#define DGC_LUT_4_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_5_CFG
**/
#define DGC_LUT_5_CFG_ID                 0x3004c              
#define DGC_LUT_5_CFG_LEN                (4U)                
#define DGC_LUT_5_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register DGC_LUT_6_CFG
**/
#define DGC_LUT_6_CFG_ID                 0x30050              
#define DGC_LUT_6_CFG_LEN                (4U)                
#define DGC_LUT_6_CFG_MASK               0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register EC_CTRL
**/
#define EC_CTRL_ID                           0x40000              
#define EC_CTRL_LEN                          (4U)                
#define EC_CTRL_MASK                         0xFFFFFFFFUL        
#define EC_CTRL_OSTR_MODE_BIT_OFFSET         (11U)               
#define EC_CTRL_OSTR_MODE_BIT_LEN            (1U)                
#define EC_CTRL_OSTR_MODE_BIT_MASK           0x800U               
#define EC_CTRL_OSTS_WAIT_BIT_OFFSET         (3U)                
#define EC_CTRL_OSTS_WAIT_BIT_LEN            (8U)                
#define EC_CTRL_OSTS_WAIT_BIT_MASK           0x7f8U               

/******************************************************************************
* @brief Bit definitions for register RX_CAL_CFG
**/
#define RX_CAL_CFG_ID                       0x4000c              
#define RX_CAL_CFG_LEN                      (4U)                
#define RX_CAL_CFG_MASK                     0xFFFFFFFFUL        
#define RX_CAL_CFG_COMP_DLY_BIT_OFFSET      (16U)               
#define RX_CAL_CFG_COMP_DLY_BIT_LEN         (4U)                
#define RX_CAL_CFG_COMP_DLY_BIT_MASK        0xf0000UL            
#define RX_CAL_CFG_CAL_EN_BIT_OFFSET        (4U)                
#define RX_CAL_CFG_CAL_EN_BIT_LEN           (1U)                
#define RX_CAL_CFG_CAL_EN_BIT_MASK          0x10U                
#define RX_CAL_CFG_CAL_MODE_BIT_OFFSET      (0U)                
#define RX_CAL_CFG_CAL_MODE_BIT_LEN         (2U)                
#define RX_CAL_CFG_CAL_MODE_BIT_MASK        0x3U                 


/******************************************************************************
* @brief Bit definitions for register RX_CAL_RESI
**/
#define RX_CAL_RESI_ID                       0x40014              
#define RX_CAL_RESI_LEN                      (4U)                
#define RX_CAL_RESI_MASK                     0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register RX_CAL_RESQ
**/
#define RX_CAL_RESQ_ID                       0x4001c              
#define RX_CAL_RESQ_LEN                      (4U)                
#define RX_CAL_RESQ_MASK                     0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register RX_CAL_STS
**/
#define RX_CAL_STS_ID                       0x40020              
#define RX_CAL_STS_LEN                      (4U)                
#define RX_CAL_STS_MASK                     0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register GPIO_MODE
**/
#define GPIO_MODE_ID                         0x50000              
#define GPIO_MODE_LEN                        (4U)                
#define GPIO_MODE_MASK                       0xFFFFFFFFUL        
#define GPIO_MODE_MSGP8_MODE_BIT_OFFSET      (24U)               
#define GPIO_MODE_MSGP8_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP8_MODE_BIT_MASK        0x7000000UL          
#define GPIO_MODE_MSGP7_MODE_BIT_OFFSET      (21U)               
#define GPIO_MODE_MSGP7_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP7_MODE_BIT_MASK        0xe00000UL           
#define GPIO_MODE_MSGP6_MODE_BIT_OFFSET      (18U)               
#define GPIO_MODE_MSGP6_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP6_MODE_BIT_MASK        0x1c0000UL           
#define GPIO_MODE_MSGP5_MODE_BIT_OFFSET      (15U)               
#define GPIO_MODE_MSGP5_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP5_MODE_BIT_MASK        0x38000UL            
#define GPIO_MODE_MSGP4_MODE_BIT_OFFSET      (12U)               
#define GPIO_MODE_MSGP4_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP4_MODE_BIT_MASK        0x7000U              
#define GPIO_MODE_MSGP3_MODE_BIT_OFFSET      (9U)                
#define GPIO_MODE_MSGP3_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP3_MODE_BIT_MASK        0xe00U               
#define GPIO_MODE_MSGP2_MODE_BIT_OFFSET      (6U)                
#define GPIO_MODE_MSGP2_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP2_MODE_BIT_MASK        0x1c0U               
#define GPIO_MODE_MSGP1_MODE_BIT_OFFSET      (3U)                
#define GPIO_MODE_MSGP1_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP1_MODE_BIT_MASK        0x38U                
#define GPIO_MODE_MSGP0_MODE_BIT_OFFSET      (0U)                
#define GPIO_MODE_MSGP0_MODE_BIT_LEN         (3U)                
#define GPIO_MODE_MSGP0_MODE_BIT_MASK        0x7U                 


/******************************************************************************
* @brief Bit definitions for register GPIO_DIR
**/
#define GPIO_DIR_ID                          0x50008              
#define GPIO_DIR_LEN                         (4U)                
#define GPIO_DIR_MASK                        0xFFFFFFFFUL        
#define GPIO_DIR_GDP8_BIT_OFFSET        (8U)                
#define GPIO_DIR_GDP8_BIT_LEN           (1U)                
#define GPIO_DIR_GDP8_BIT_MASK          0x100U               
#define GPIO_DIR_GDP7_BIT_OFFSET        (7U)                
#define GPIO_DIR_GDP7_BIT_LEN           (1U)                
#define GPIO_DIR_GDP7_BIT_MASK          0x80U                
#define GPIO_DIR_GDP6_BIT_OFFSET        (6U)                
#define GPIO_DIR_GDP6_BIT_LEN           (1U)                
#define GPIO_DIR_GDP6_BIT_MASK          0x40U                
#define GPIO_DIR_GDP5_BIT_OFFSET        (5U)                
#define GPIO_DIR_GDP5_BIT_LEN           (1U)                
#define GPIO_DIR_GDP5_BIT_MASK          0x20U                
#define GPIO_DIR_GDP4_BIT_OFFSET        (4U)                
#define GPIO_DIR_GDP4_BIT_LEN           (1U)                
#define GPIO_DIR_GDP4_BIT_MASK          0x10U                
#define GPIO_DIR_GDP3_BIT_OFFSET        (3U)                
#define GPIO_DIR_GDP3_BIT_LEN           (1U)                
#define GPIO_DIR_GDP3_BIT_MASK          0x8U                 
#define GPIO_DIR_GDP2_BIT_OFFSET        (2U)                
#define GPIO_DIR_GDP2_BIT_LEN           (1U)                
#define GPIO_DIR_GDP2_BIT_MASK          0x4U                 
#define GPIO_DIR_GDP1_BIT_OFFSET        (1U)                
#define GPIO_DIR_GDP1_BIT_LEN           (1U)                
#define GPIO_DIR_GDP1_BIT_MASK          0x2U                 
#define GPIO_DIR_GDP0_BIT_OFFSET        (0U)                
#define GPIO_DIR_GDP0_BIT_LEN           (1U)                
#define GPIO_DIR_GDP0_BIT_MASK          0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_OUT
**/
#define GPIO_OUT_ID                          0x5000c              
#define GPIO_OUT_LEN                         (4U)                
#define GPIO_OUT_MASK                        0xFFFFFFFFUL        
#define GPIO_OUT_GOP8_BIT_OFFSET        (8U)                
#define GPIO_OUT_GOP8_BIT_LEN           (1U)                
#define GPIO_OUT_GOP8_BIT_MASK          0x100U               
#define GPIO_OUT_GOP7_BIT_OFFSET        (7U)                
#define GPIO_OUT_GOP7_BIT_LEN           (1U)                
#define GPIO_OUT_GOP7_BIT_MASK          0x80U                
#define GPIO_OUT_GOP6_BIT_OFFSET        (6U)                
#define GPIO_OUT_GOP6_BIT_LEN           (1U)                
#define GPIO_OUT_GOP6_BIT_MASK          0x40U                
#define GPIO_OUT_GOP5_BIT_OFFSET        (5U)                
#define GPIO_OUT_GOP5_BIT_LEN           (1U)                
#define GPIO_OUT_GOP5_BIT_MASK          0x20U                
#define GPIO_OUT_GOP4_BIT_OFFSET        (4U)                
#define GPIO_OUT_GOP4_BIT_LEN           (1U)                
#define GPIO_OUT_GOP4_BIT_MASK          0x10U                
#define GPIO_OUT_GOP3_BIT_OFFSET        (3U)                
#define GPIO_OUT_GOP3_BIT_LEN           (1U)                
#define GPIO_OUT_GOP3_BIT_MASK          0x8U                 
#define GPIO_OUT_GOP2_BIT_OFFSET        (2U)                
#define GPIO_OUT_GOP2_BIT_LEN           (1U)                
#define GPIO_OUT_GOP2_BIT_MASK          0x4U                 
#define GPIO_OUT_GOP1_BIT_OFFSET        (1U)                
#define GPIO_OUT_GOP1_BIT_LEN           (1U)                
#define GPIO_OUT_GOP1_BIT_MASK          0x2U                 
#define GPIO_OUT_GOP0_BIT_OFFSET        (0U)                
#define GPIO_OUT_GOP0_BIT_LEN           (1U)                
#define GPIO_OUT_GOP0_BIT_MASK          0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_IRQE
**/
#define GPIO_IRQE_ID                       0x50010              
#define GPIO_IRQE_LEN                      (4U)                
#define GPIO_IRQE_MASK                     0xFFFFFFFFUL        
#define GPIO_IRQE_GIRQE8_BIT_OFFSET  (8U)                
#define GPIO_IRQE_GIRQE8_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE8_BIT_MASK    0x100U               
#define GPIO_IRQE_GIRQE7_BIT_OFFSET  (7U)                
#define GPIO_IRQE_GIRQE7_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE7_BIT_MASK    0x80U                
#define GPIO_IRQE_GIRQE6_BIT_OFFSET  (6U)                
#define GPIO_IRQE_GIRQE6_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE6_BIT_MASK    0x40U                
#define GPIO_IRQE_GIRQE5_BIT_OFFSET  (5U)                
#define GPIO_IRQE_GIRQE5_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE5_BIT_MASK    0x20U                
#define GPIO_IRQE_GIRQE4_BIT_OFFSET  (4U)                
#define GPIO_IRQE_GIRQE4_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE4_BIT_MASK    0x10U                
#define GPIO_IRQE_GIRQE3_BIT_OFFSET  (3U)                
#define GPIO_IRQE_GIRQE3_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE3_BIT_MASK    0x8U                 
#define GPIO_IRQE_GIRQE2_BIT_OFFSET  (2U)                
#define GPIO_IRQE_GIRQE2_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE2_BIT_MASK    0x4U                 
#define GPIO_IRQE_GIRQE1_BIT_OFFSET  (1U)                
#define GPIO_IRQE_GIRQE1_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE1_BIT_MASK    0x2U                 
#define GPIO_IRQE_GIRQE0_BIT_OFFSET  (0U)                
#define GPIO_IRQE_GIRQE0_BIT_LEN     (1U)                
#define GPIO_IRQE_GIRQE0_BIT_MASK    0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_ISTS
**/
#define GPIO_ISTS_ID                   0x50014              
#define GPIO_ISTS_LEN                  (4U)                
#define GPIO_ISTS_MASK                 0xFFFFFFFFUL        
#define GPIO_ISTS_GISTS8_BIT_OFFSET (8U)                
#define GPIO_ISTS_GISTS8_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS8_BIT_MASK 0x100U               
#define GPIO_ISTS_GISTS7_BIT_OFFSET (7U)                
#define GPIO_ISTS_GISTS7_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS7_BIT_MASK 0x80U                
#define GPIO_ISTS_GISTS6_BIT_OFFSET (6U)                
#define GPIO_ISTS_GISTS6_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS6_BIT_MASK 0x40U                
#define GPIO_ISTS_GISTS5_BIT_OFFSET (5U)                
#define GPIO_ISTS_GISTS5_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS5_BIT_MASK 0x20U                
#define GPIO_ISTS_GISTS4_BIT_OFFSET (4U)                
#define GPIO_ISTS_GISTS4_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS4_BIT_MASK 0x10U                
#define GPIO_ISTS_GISTS3_BIT_OFFSET (3U)                
#define GPIO_ISTS_GISTS3_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS3_BIT_MASK 0x8U                 
#define GPIO_ISTS_GISTS2_BIT_OFFSET (2U)                
#define GPIO_ISTS_GISTS2_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS2_BIT_MASK 0x4U                 
#define GPIO_ISTS_GISTS1_BIT_OFFSET (1U)                
#define GPIO_ISTS_GISTS1_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS1_BIT_MASK 0x2U                 
#define GPIO_ISTS_GISTS0_BIT_OFFSET (0U)                
#define GPIO_ISTS_GISTS0_BIT_LEN (1U)                
#define GPIO_ISTS_GISTS0_BIT_MASK 0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_ISEN
**/
#define GPIO_ISEN_ID                     0x50018              
#define GPIO_ISEN_LEN                    (4U)                
#define GPIO_ISEN_MASK                   0xFFFFFFFFUL        
#define GPIO_ISEN_GISEN8_BIT_OFFSET (8U)                
#define GPIO_ISEN_GISEN8_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN8_BIT_MASK 0x100U               
#define GPIO_ISEN_GISEN7_BIT_OFFSET (7U)                
#define GPIO_ISEN_GISEN7_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN7_BIT_MASK 0x80U                
#define GPIO_ISEN_GISEN6_BIT_OFFSET (6U)                
#define GPIO_ISEN_GISEN6_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN6_BIT_MASK 0x40U                
#define GPIO_ISEN_GISEN5_BIT_OFFSET (5U)                
#define GPIO_ISEN_GISEN5_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN5_BIT_MASK 0x20U                
#define GPIO_ISEN_GISEN4_BIT_OFFSET (4U)                
#define GPIO_ISEN_GISEN4_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN4_BIT_MASK 0x10U                
#define GPIO_ISEN_GISEN3_BIT_OFFSET (3U)                
#define GPIO_ISEN_GISEN3_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN3_BIT_MASK 0x8U                 
#define GPIO_ISEN_GISEN2_BIT_OFFSET (2U)                
#define GPIO_ISEN_GISEN2_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN2_BIT_MASK 0x4U                 
#define GPIO_ISEN_GISEN1_BIT_OFFSET (1U)                
#define GPIO_ISEN_GISEN1_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN1_BIT_MASK 0x2U                 
#define GPIO_ISEN_GISEN0_BIT_OFFSET (0U)                
#define GPIO_ISEN_GISEN0_BIT_LEN (1U)                
#define GPIO_ISEN_GISEN0_BIT_MASK 0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_IMODE
**/
#define GPIO_IMODE_ID                     0x5001c              
#define GPIO_IMODE_LEN                    (4U)                
#define GPIO_IMODE_MASK                   0xFFFFFFFFUL        
#define GPIO_IMODE_GIMOD8_BIT_OFFSET (8U)                
#define GPIO_IMODE_GIMOD8_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD8_BIT_MASK 0x100U               
#define GPIO_IMODE_GIMOD7_BIT_OFFSET (7U)                
#define GPIO_IMODE_GIMOD7_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD7_BIT_MASK 0x80U                
#define GPIO_IMODE_GIMOD6_BIT_OFFSET (6U)                
#define GPIO_IMODE_GIMOD6_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD6_BIT_MASK 0x40U                
#define GPIO_IMODE_GIMOD5_BIT_OFFSET (5U)                
#define GPIO_IMODE_GIMOD5_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD5_BIT_MASK 0x20U                
#define GPIO_IMODE_GIMOD4_BIT_OFFSET (4U)                
#define GPIO_IMODE_GIMOD4_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD4_BIT_MASK 0x10U                
#define GPIO_IMODE_GIMOD3_BIT_OFFSET (3U)                
#define GPIO_IMODE_GIMOD3_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD3_BIT_MASK 0x8U                 
#define GPIO_IMODE_GIMOD2_BIT_OFFSET (2U)                
#define GPIO_IMODE_GIMOD2_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD2_BIT_MASK 0x4U                 
#define GPIO_IMODE_GIMOD1_BIT_OFFSET (1U)                
#define GPIO_IMODE_GIMOD1_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD1_BIT_MASK 0x2U                 
#define GPIO_IMODE_GIMOD0_BIT_OFFSET (0U)                
#define GPIO_IMODE_GIMOD0_BIT_LEN (1U)                
#define GPIO_IMODE_GIMOD0_BIT_MASK 0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_IBES
**/
#define GPIO_IBES_ID                    0x50020              
#define GPIO_IBES_LEN                   (4U)                
#define GPIO_IBES_MASK                  0xFFFFFFFFUL        
#define GPIO_IBES_GIBES8_BIT_OFFSET (8U)                
#define GPIO_IBES_GIBES8_BIT_LEN (1U)                
#define GPIO_IBES_GIBES8_BIT_MASK 0x100U               
#define GPIO_IBES_GIBES7_BIT_OFFSET (7U)                
#define GPIO_IBES_GIBES7_BIT_LEN (1U)                
#define GPIO_IBES_GIBES7_BIT_MASK 0x80U                
#define GPIO_IBES_GIBES6_BIT_OFFSET (6U)                
#define GPIO_IBES_GIBES6_BIT_LEN (1U)                
#define GPIO_IBES_GIBES6_BIT_MASK 0x40U                
#define GPIO_IBES_GIBES5_BIT_OFFSET (5U)                
#define GPIO_IBES_GIBES5_BIT_LEN (1U)                
#define GPIO_IBES_GIBES5_BIT_MASK 0x20U                
#define GPIO_IBES_GIBES4_BIT_OFFSET (4U)                
#define GPIO_IBES_GIBES4_BIT_LEN (1U)                
#define GPIO_IBES_GIBES4_BIT_MASK 0x10U                
#define GPIO_IBES_GIBES3_BIT_OFFSET (3U)                
#define GPIO_IBES_GIBES3_BIT_LEN (1U)                
#define GPIO_IBES_GIBES3_BIT_MASK 0x8U                 
#define GPIO_IBES_GIBES2_BIT_OFFSET (2U)                
#define GPIO_IBES_GIBES2_BIT_LEN (1U)                
#define GPIO_IBES_GIBES2_BIT_MASK 0x4U                 
#define GPIO_IBES_GIBES1_BIT_OFFSET (1U)                
#define GPIO_IBES_GIBES1_BIT_LEN (1U)                
#define GPIO_IBES_GIBES1_BIT_MASK 0x2U                 
#define GPIO_IBES_GIBES0_BIT_OFFSET (0U)                
#define GPIO_IBES_GIBES0_BIT_LEN (1U)                
#define GPIO_IBES_GIBES0_BIT_MASK 0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_ICLR
**/
#define GPIO_ICLR_ID                      0x50024              
#define GPIO_ICLR_LEN                     (4U)                
#define GPIO_ICLR_MASK                    0xFFFFFFFFUL        
#define GPIO_ICLR_GICLR8_BIT_OFFSET (8U)                
#define GPIO_ICLR_GICLR8_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR8_BIT_MASK  0x100U               
#define GPIO_ICLR_GICLR7_BIT_OFFSET (7U)                
#define GPIO_ICLR_GICLR7_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR7_BIT_MASK  0x80U                
#define GPIO_ICLR_GICLR6_BIT_OFFSET (6U)                
#define GPIO_ICLR_GICLR6_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR6_BIT_MASK  0x40U                
#define GPIO_ICLR_GICLR5_BIT_OFFSET (5U)                
#define GPIO_ICLR_GICLR5_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR5_BIT_MASK  0x20U                
#define GPIO_ICLR_GICLR4_BIT_OFFSET (4U)                
#define GPIO_ICLR_GICLR4_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR4_BIT_MASK  0x10U                
#define GPIO_ICLR_GICLR3_BIT_OFFSET (3U)                
#define GPIO_ICLR_GICLR3_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR3_BIT_MASK  0x8U                 
#define GPIO_ICLR_GICLR2_BIT_OFFSET (2U)                
#define GPIO_ICLR_GICLR2_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR2_BIT_MASK  0x4U                 
#define GPIO_ICLR_GICLR1_BIT_OFFSET (1U)                
#define GPIO_ICLR_GICLR1_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR1_BIT_MASK  0x2U                 
#define GPIO_ICLR_GICLR0_BIT_OFFSET (0U)                
#define GPIO_ICLR_GICLR0_BIT_LEN   (1U)                
#define GPIO_ICLR_GICLR0_BIT_MASK  0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_IDBE
**/
#define GPIO_IDBE_ID                      0x50028              
#define GPIO_IDBE_LEN                     (4U)                
#define GPIO_IDBE_EN_MASK                    0xFFFFFFFFUL        
#define GPIO_IDBE_GIDBE8_BIT_OFFSET (8U)                
#define GPIO_IDBE_GIDBE8_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE8_BIT_MASK  0x100U               
#define GPIO_IDBE_GIDBE7_BIT_OFFSET (7U)                
#define GPIO_IDBE_GIDBE7_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE7_BIT_MASK  0x80U                
#define GPIO_IDBE_GIDBE6_BIT_OFFSET (6U)                
#define GPIO_IDBE_GIDBE6_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE6_BIT_MASK  0x40U                
#define GPIO_IDBE_GIDBE5_BIT_OFFSET (5U)                
#define GPIO_IDBE_GIDBE5_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE5_BIT_MASK  0x20U                
#define GPIO_IDBE_GIDBE4_BIT_OFFSET (4U)                
#define GPIO_IDBE_GIDBE4_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE4_BIT_MASK  0x10U                
#define GPIO_IDBE_GIDBE3_BIT_OFFSET (3U)                
#define GPIO_IDBE_GIDBE3_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE3_BIT_MASK  0x8U                 
#define GPIO_IDBE_GIDBE2_BIT_OFFSET (2U)                
#define GPIO_IDBE_GIDBE2_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE2_BIT_MASK  0x4U                 
#define GPIO_IDBE_GIDBE1_BIT_OFFSET (1U)                
#define GPIO_IDBE_GIDBE1_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE1_BIT_MASK  0x2U                 
#define GPIO_IDBE_GIDBE0_BIT_OFFSET (0U)                
#define GPIO_IDBE_GIDBE0_BIT_LEN   (1U)                
#define GPIO_IDBE_GIDBE0_BIT_MASK  0x1U                 

/******************************************************************************
* @brief Bit definitions for register GPIO_RAW
**/
#define GPIO_RAW_ID                     0x5002c              
#define GPIO_RAW_LEN                    (4U)                
#define GPIO_RAW_MASK                   0xFFFFFFFFUL        
#define GPIO_RAW_GRAWP8_BIT_OFFSET (8U)                
#define GPIO_RAW_GRAWP8_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP8_BIT_MASK 0x100U               
#define GPIO_RAW_GRAWP7_BIT_OFFSET (7U)                
#define GPIO_RAW_GRAWP7_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP7_BIT_MASK 0x80U                
#define GPIO_RAW_GRAWP6_BIT_OFFSET (6U)                
#define GPIO_RAW_GRAWP6_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP6_BIT_MASK 0x40U                
#define GPIO_RAW_GRAWP5_BIT_OFFSET (5U)                
#define GPIO_RAW_GRAWP5_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP5_BIT_MASK 0x20U                
#define GPIO_RAW_GRAWP4_BIT_OFFSET (4U)                
#define GPIO_RAW_GRAWP4_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP4_BIT_MASK 0x10U                
#define GPIO_RAW_GRAWP3_BIT_OFFSET (3U)                
#define GPIO_RAW_GRAWP3_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP3_BIT_MASK 0x8U                 
#define GPIO_RAW_GRAWP2_BIT_OFFSET (2U)                
#define GPIO_RAW_GRAWP2_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP2_BIT_MASK 0x4U                 
#define GPIO_RAW_GRAWP1_BIT_OFFSET (1U)                
#define GPIO_RAW_GRAWP1_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP1_BIT_MASK 0x2U                 
#define GPIO_RAW_GRAWP0_BIT_OFFSET (0U)                
#define GPIO_RAW_GRAWP0_BIT_LEN  (1U)                
#define GPIO_RAW_GRAWP0_BIT_MASK 0x1U                 

/******************************************************************************
* @brief Bit definitions for register DTUNE0
**/
#define DTUNE0_ID                            0x60000              
#define DTUNE0_LEN                           (4U)                
#define DTUNE0_MASK                          0xFFFFFFFFUL        
#define DTUNE0_RX_SFD_TOC_BIT_OFFSET         (16U)               
#define DTUNE0_RX_SFD_TOC_BIT_LEN            (16U)               
#define DTUNE0_RX_SFD_TOC_BIT_MASK           0xffff0000UL         
#define DTUNE0_PRE_PAC_SYM_BIT_OFFSET        (0U)                
#define DTUNE0_PRE_PAC_SYM_BIT_LEN           (2U)                
#define DTUNE0_PRE_PAC_SYM_BIT_MASK          0x3U                 

/******************************************************************************
* @brief Bit definitions for register DTUNE1
**/
#define DTUNE1_ID                            0x60004              
#define DTUNE1_LEN                           (4U)                
#define DTUNE1_MASK                          0xFFFFFFFFUL        
#define DTUNE1_PRE_TOC_BIT_OFFSET            (0U)                
#define DTUNE1_PRE_TOC_BIT_LEN               (16U)               
#define DTUNE1_PRE_TOC_BIT_MASK              0xffffU              


/******************************************************************************
* @brief Bit definitions for register DTUNE3
**/
#define DTUNE3_ID                            0x6000c              
#define DTUNE3_LEN                           (4U)                
#define DTUNE3_MASK                          0xFFFFFFFFUL        








/******************************************************************************
* @brief Bit definitions for register DRX_DIAG3
**/
#define DRX_DIAG3_ID                         0x60029              /*  */
#define DRX_DIAG3_LEN                        (4U)                
#define DRX_DIAG3_MASK                       0xFFFFFFFFUL        
#define DRX_DIAG3_CAR_INT_BIT_OFFSET         (0U)                
#define DRX_DIAG3_CAR_INT_BIT_LEN            (21U)               
#define DRX_DIAG3_CAR_INT_BIT_MASK           0x1fffffUL           





/******************************************************************************
* @brief Bit definitions for register RF_ENABLE
**/
#define RF_ENABLE_ID                            0x70000              
#define RF_ENABLE_LEN                           (4U)                
#define RF_ENABLE_MASK                          0xFFFFFFFFUL        
#define RF_ENABLE_TX_SW_EN_BIT_OFFSET           (25U)               
#define RF_ENABLE_TX_SW_EN_BIT_LEN              (1U)                
#define RF_ENABLE_TX_SW_EN_BIT_MASK             0x2000000UL          
#define RF_ENABLE_TX_CH5_BIT_OFFSET             (13U)               
#define RF_ENABLE_TX_CH5_BIT_LEN                (1U)                
#define RF_ENABLE_TX_CH5_BIT_MASK               0x2000U              
#define RF_ENABLE_TX_EN_BIT_OFFSET              (12U)               
#define RF_ENABLE_TX_EN_BIT_LEN                 (1U)                
#define RF_ENABLE_TX_EN_BIT_MASK                0x1000U              
#define RF_ENABLE_TX_EN_BUF_BIT_OFFSET          (11U)               
#define RF_ENABLE_TX_EN_BUF_BIT_LEN             (1U)                
#define RF_ENABLE_TX_EN_BUF_BIT_MASK            0x800U               
#define RF_ENABLE_TX_BIAS_EN_BIT_OFFSET         (10U)               
#define RF_ENABLE_TX_BIAS_EN_BIT_LEN            (1U)                
#define RF_ENABLE_TX_BIAS_EN_BIT_MASK           0x400U               

/******************************************************************************
* @brief Bit definitions for register RF_CTRL_MASK
**/
#define RF_CTRL_MASK_ID                      0x70004              
#define RF_CTRL_MASK_LEN                     (4U)                
#define RF_CTRL_MASK_MASK                    0xFFFFFFFFUL        



/******************************************************************************
* @brief Bit definitions for register RX_CTRL_HI
**/
#define RX_CTRL_HI_ID                        0x70010              
#define RX_CTRL_HI_LEN                       (4U)                
#define RX_CTRL_HI_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register RF_SWITCH
**/
#define RF_SWITCH_CTRL_ID                         0x70014              
#define RF_SWITCH_CTRL_LEN                        (4U)                
#define RF_SWITCH_CTRL_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register TX_CTRL_LO
**/
#define TX_CTRL_LO_ID                        0x70018              
#define TX_CTRL_LO_LEN                       (4U)                
#define TX_CTRL_LO_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register TX_CTRL_HI
**/
#define TX_CTRL_HI_ID                        0x7001c              
#define TX_CTRL_HI_LEN                       (4U)                
#define TX_CTRL_HI_MASK                      0xFFFFFFFFUL        
#define TX_CTRL_HI_TX_PG_DELAY_BIT_OFFSET    (0U)                
#define TX_CTRL_HI_TX_PG_DELAY_BIT_LEN       (6U)                
#define TX_CTRL_HI_TX_PG_DELAY_BIT_MASK      0x3fU                


/******************************************************************************
* @brief Bit definitions for register TX_TEST
**/
#define TX_TEST_ID                           0x70028              
#define TX_TEST_LEN                          (4U)                
#define TX_TEST_MASK                         0xFFFFFFFFUL        
#define TX_TEST_TX_ENTEST_CH1_BIT_OFFSET     (3U)                
#define TX_TEST_TX_ENTEST_CH1_BIT_LEN        (1U)                
#define TX_TEST_TX_ENTEST_CH1_BIT_MASK       0x8U                 
#define TX_TEST_TX_ENTEST_CH2_BIT_OFFSET     (2U)                
#define TX_TEST_TX_ENTEST_CH2_BIT_LEN        (1U)                
#define TX_TEST_TX_ENTEST_CH2_BIT_MASK       0x4U                 
#define TX_TEST_TX_ENTEST_CH3_BIT_OFFSET     (1U)                
#define TX_TEST_TX_ENTEST_CH3_BIT_LEN        (1U)                
#define TX_TEST_TX_ENTEST_CH3_BIT_MASK       0x2U                 
#define TX_TEST_TX_ENTEST_CH4_BIT_OFFSET     (0U)                
#define TX_TEST_TX_ENTEST_CH4_BIT_LEN        (1U)                
#define TX_TEST_TX_ENTEST_CH4_BIT_MASK       0x1U                 



/******************************************************************************
* @brief Bit definitions for register SAR_TEST
**/
#define SAR_TEST_ID                          0x70034              
#define SAR_TEST_LEN                         (4U)                
#define SAR_TEST_MASK                        0xFFFFFFFFUL        
#define SAR_TEST_SAR_RDEN_BIT_OFFSET    (2U)                
#define SAR_TEST_SAR_RDEN_BIT_LEN       (1U)                
#define SAR_TEST_SAR_RDEN_BIT_MASK      0x4U                 


/******************************************************************************
* @brief Bit definitions for register LDO_TUNE_LO
**/
#define LDO_TUNE_LO_ID                       0x70040              
#define LDO_TUNE_LO_LEN                      (4U)                
#define LDO_TUNE_LO_MASK                     0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register LDO_TUNE_HI
**/
#define LDO_TUNE_HI_ID                       0x70044              
#define LDO_TUNE_HI_LEN                      (4U)                
#define LDO_TUNE_HI_MASK                     0xFFFFFFFFUL        
#define LDO_TUNE_HI_LDO_HVAUX_TUNE_BIT_OFFSET (12U)               
#define LDO_TUNE_HI_LDO_HVAUX_TUNE_BIT_LEN   (4U)                
#define LDO_TUNE_HI_LDO_HVAUX_TUNE_BIT_MASK  0xf000U              

/******************************************************************************
* @brief Bit definitions for register LDO_CTRL
**/
#define LDO_CTRL_ID                          0x70048              
#define LDO_CTRL_LEN                         (4U)                
#define LDO_CTRL_MASK                        0xFFFFFFFFUL        
#define LDO_CTRL_LDO_VDDHVTX_VREF_BIT_OFFSET (27U)               
#define LDO_CTRL_LDO_VDDHVTX_VREF_BIT_LEN    (1U)                
#define LDO_CTRL_LDO_VDDHVTX_VREF_BIT_MASK   0x8000000UL          
#define LDO_CTRL_LDO_VDDTX2_VREF_BIT_OFFSET  (22U)               
#define LDO_CTRL_LDO_VDDTX2_VREF_BIT_LEN     (1U)                
#define LDO_CTRL_LDO_VDDTX2_VREF_BIT_MASK    0x400000UL           
#define LDO_CTRL_LDO_VDDTX1_VREF_BIT_OFFSET  (21U)               
#define LDO_CTRL_LDO_VDDTX1_VREF_BIT_LEN     (1U)                
#define LDO_CTRL_LDO_VDDTX1_VREF_BIT_MASK    0x200000UL           
#define LDO_CTRL_LDO_VDDHVTX_EN_BIT_OFFSET   (11U)               
#define LDO_CTRL_LDO_VDDHVTX_EN_BIT_LEN      (1U)                
#define LDO_CTRL_LDO_VDDHVTX_EN_BIT_MASK     0x800U               
#define LDO_CTRL_LDO_VDDIF2_EN_BIT_OFFSET    (8U)                
#define LDO_CTRL_LDO_VDDIF2_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDIF2_EN_BIT_MASK      0x100U               
#define LDO_CTRL_LDO_VDDTX2_EN_BIT_OFFSET    (6U)                
#define LDO_CTRL_LDO_VDDTX2_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDTX2_EN_BIT_MASK      0x40U                
#define LDO_CTRL_LDO_VDDTX1_EN_BIT_OFFSET    (5U)                
#define LDO_CTRL_LDO_VDDTX1_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDTX1_EN_BIT_MASK      0x20U                
#define LDO_CTRL_LDO_VDDPLL_EN_BIT_OFFSET    (4U)                
#define LDO_CTRL_LDO_VDDPLL_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDPLL_EN_BIT_MASK      0x10U                
#define LDO_CTRL_LDO_VDDMS3_EN_BIT_OFFSET    (2U)                
#define LDO_CTRL_LDO_VDDMS3_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDMS3_EN_BIT_MASK      0x4U                 
#define LDO_CTRL_LDO_VDDMS2_EN_BIT_OFFSET    (1U)                
#define LDO_CTRL_LDO_VDDMS2_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDMS2_EN_BIT_MASK      0x2U                 
#define LDO_CTRL_LDO_VDDMS1_EN_BIT_OFFSET    (0U)                
#define LDO_CTRL_LDO_VDDMS1_EN_BIT_LEN       (1U)                
#define LDO_CTRL_LDO_VDDMS1_EN_BIT_MASK      0x1U                 


/******************************************************************************
* @brief Bit definitions for register LDO_RLOAD
**/
#define LDO_RLOAD_ID                         0x70050              
#define LDO_RLOAD_LEN                        (4U)                
#define LDO_RLOAD_MASK                       0xFFFFFFFFUL        



/******************************************************************************
* @brief Bit definitions for register SAR_CTRL
**/
#define SAR_CTRL_ID                          0x80000              
#define SAR_CTRL_LEN                         (4U)                
#define SAR_CTRL_MASK                        0xFFFFFFFFUL        
#define SAR_CTRL_SAR_START_BIT_OFFSET        (0U)                
#define SAR_CTRL_SAR_START_BIT_LEN           (1U)                
#define SAR_CTRL_SAR_START_BIT_MASK          0x1U                 

/******************************************************************************
* @brief Bit definitions for register SAR_STATUS
**/
#define SAR_STATUS_ID                        0x80004              
#define SAR_STATUS_LEN                       (4U)                
#define SAR_STATUS_MASK                      0xFFFFFFFFUL        
#define SAR_STATUS_SAR_DONE_BIT_OFFSET  (0U)                
#define SAR_STATUS_SAR_DONE_BIT_LEN     (1U)                
#define SAR_STATUS_SAR_DONE_BIT_MASK    0x1U                 

/******************************************************************************
* @brief Bit definitions for register SAR_READING
**/
#define SAR_READING_ID                       0x80008              
#define SAR_READING_LEN                      (4U)                
#define SAR_READING_MASK                     0xFFFFFFFFUL        
#define SAR_READING_SAR_READING_TEMP_BIT_OFFSET (8U)                
#define SAR_READING_SAR_READING_TEMP_BIT_LEN (8U)                
#define SAR_READING_SAR_READING_TEMP_BIT_MASK 0xff00U              
#define SAR_READING_SAR_READING_VBAT_BIT_OFFSET (0U)                
#define SAR_READING_SAR_READING_VBAT_BIT_LEN (8U)                
#define SAR_READING_SAR_READING_VBAT_BIT_MASK 0xffU                

/******************************************************************************
* @brief Bit definitions for register SAR_WAKE_RD

**/
#define SAR_WAKE_RD_ID                      0x8000c              
#define SAR_WAKE_RD_LEN                     (4U)                
#define SAR_WAKE_RD_MASK                    0xFFFFFFFFUL        
#define SAR_WAKE_RD_SAR_LAST_TEMP_BIT_OFFSET (8U)                
#define SAR_WAKE_RD_SAR_LAST_TEMP_BIT_LEN   (8U)                
#define SAR_WAKE_RD_SAR_LAST_TEMP_BIT_MASK  0xff00U              
#define SAR_WAKE_RD_SAR_LAST_VBAT_BIT_OFFSET (0U)                
#define SAR_WAKE_RD_SAR_LAST_VBAT_BIT_LEN   (8U)                
#define SAR_WAKE_RD_SAR_LAST_VBAT_BIT_MASK  0xffU                

/******************************************************************************
* @brief Bit definitions for register PGC_CTRL
**/
#define PGC_CTRL_ID                          0x80010              
#define PGC_CTRL_LEN                         (4U)                
#define PGC_CTRL_MASK                        0xFFFFFFFFUL        
#define PGC_CTRL_PGC_AUTO_CAL_BIT_OFFSET     (1U)                
#define PGC_CTRL_PGC_AUTO_CAL_BIT_LEN        (1U)                
#define PGC_CTRL_PGC_AUTO_CAL_BIT_MASK       0x2U                 
#define PGC_CTRL_PGC_START_BIT_OFFSET        (0U)                
#define PGC_CTRL_PGC_START_BIT_LEN           (1U)                
#define PGC_CTRL_PGC_START_BIT_MASK          0x1U                 

/******************************************************************************
* @brief Bit definitions for register PGC_STATUS
**/
#define PGC_STATUS_ID                        0x80014              
#define PGC_STATUS_LEN                       (4U)                
#define PGC_STATUS_MASK                      0xFFFFFFFFUL        
#define PGC_STATUS_AUTOCAL_DONE_BIT_OFFSET   (12U)               
#define PGC_STATUS_AUTOCAL_DONE_BIT_LEN      (1U)                
#define PGC_STATUS_AUTOCAL_DONE_BIT_MASK     0x1000U              
#define PGC_STATUS_PG_DELAY_COUNT_BIT_OFFSET (0U)                
#define PGC_STATUS_PG_DELAY_COUNT_BIT_LEN    (12U)               
#define PGC_STATUS_PG_DELAY_COUNT_BIT_MASK   0xfffU               

/******************************************************************************
* @brief Bit definitions for register PG_TEST
**/
#define PG_TEST_ID                           0x80018              
#define PG_TEST_LEN                          (4U)                
#define PG_TEST_MASK                         0xFFFFFFFFUL        
#define PG_TEST_TX_TEST_CH4_BIT_OFFSET       (12U)               
#define PG_TEST_TX_TEST_CH4_BIT_LEN          (4U)                
#define PG_TEST_TX_TEST_CH4_BIT_MASK         0xf000U              
#define PG_TEST_TX_TEST_CH3_BIT_OFFSET       (8U)                
#define PG_TEST_TX_TEST_CH3_BIT_LEN          (4U)                
#define PG_TEST_TX_TEST_CH3_BIT_MASK         0xf00U               
#define PG_TEST_TX_TEST_CH2_BIT_OFFSET       (4U)                
#define PG_TEST_TX_TEST_CH2_BIT_LEN          (4U)                
#define PG_TEST_TX_TEST_CH2_BIT_MASK         0xf0U                
#define PG_TEST_TX_TEST_CH1_BIT_OFFSET       (0U)                
#define PG_TEST_TX_TEST_CH1_BIT_LEN          (4U)                
#define PG_TEST_TX_TEST_CH1_BIT_MASK         0xfU                 

/******************************************************************************
* @brief Bit definitions for register PG_CAL_TARGET
**/
#define PG_CAL_TARGET_ID                     0x8001c              
#define PG_CAL_TARGET_LEN                    (4U)                
#define PG_CAL_TARGET_MASK                   0xFFFFFFFFUL        
#define PG_CAL_TARGET_TARGET_BIT_OFFSET      (0U)                
#define PG_CAL_TARGET_TARGET_BIT_LEN         (12U)               
#define PG_CAL_TARGET_TARGET_BIT_MASK        0xfffU               





/******************************************************************************
* @brief Bit definitions for register PLL_CFG
**/
#define PLL_CFG_ID                           0x90000              
#define PLL_CFG_LEN                          (4U)                
#define PLL_CFG_MASK                         0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register PLL_CAL
**/
#define PLL_CAL_ID                           0x90008              
#define PLL_CAL_LEN                          (4U)                
#define PLL_CAL_MASK                         0xFFFFFFFFUL        



/******************************************************************************
* @brief Bit definitions for register XTAL
**/
#define XTAL_ID                              0x90014              
#define XTAL_LEN                             (4U)                
#define XTAL_MASK                            0xFFFFFFFFUL        
#define XTAL_XTAL_TRIM_BIT_OFFSET            (0U)                
#define XTAL_XTAL_TRIM_BIT_LEN               (7U)                
#define XTAL_XTAL_TRIM_BIT_MASK              0x7fU                


/******************************************************************************
* @brief Bit definitions for register AON_DIG_CFG
**/
#define AON_DIG_CFG_ID                       0xa0000         
#define AON_DIG_CFG_LEN                      (4U)                
#define AON_DIG_CFG_MASK                     0xFFFFFFFFUL      
#define AON_DIG_CFG_ONWAKE_GO2RX_BIT_OFFSET  (9U)                
#define AON_DIG_CFG_ONWAKE_GO2RX_BIT_LEN     (1U)                
#define AON_DIG_CFG_ONWAKE_GO2RX_BIT_MASK    0x200U               
#define AON_DIG_CFG_ONWAKE_GO2IDLE_BIT_OFFSET (8U)                
#define AON_DIG_CFG_ONWAKE_GO2IDLE_BIT_LEN   (1U)                
#define AON_DIG_CFG_ONWAKE_GO2IDLE_BIT_MASK  0x100U                              
#define AON_DIG_CFG_ONWAKE_RUN_SAR_BIT_OFFSET (1U)                
#define AON_DIG_CFG_ONWAKE_RUN_SAR_BIT_LEN   (1U)                
#define AON_DIG_CFG_ONWAKE_RUN_SAR_BIT_MASK  0x2U                 
#define AON_DIG_CFG_ONWAKE_AON_DLD_BIT_OFFSET (0U)                
#define AON_DIG_CFG_ONWAKE_AON_DLD_BIT_LEN   (1U)                
#define AON_DIG_CFG_ONWAKE_AON_DLD_BIT_MASK  0x1U                 

/******************************************************************************
* @brief Bit definitions for register AON_CTRL
**/
#define AON_CTRL_ID                          0xa0004              
#define AON_CTRL_LEN                         (4U)                
#define AON_CTRL_MASK                        0xFFFFFFFFUL        
#define AON_CTRL_DCA_ENAB_BIT_OFFSET      (7U)                
#define AON_CTRL_DCA_ENAB_BIT_LEN         (1U)                
#define AON_CTRL_DCA_ENAB_BIT_MASK        0x80U                              
#define AON_CTRL_DCA_WRITE_HI_EN_BIT_OFFSET    (5U)                
#define AON_CTRL_DCA_WRITE_HI_EN_BIT_LEN       (1U)                
#define AON_CTRL_DCA_WRITE_HI_EN_BIT_MASK      0x20U                
#define AON_CTRL_DCA_WRITE_EN_BIT_OFFSET     (4U)                
#define AON_CTRL_DCA_WRITE_EN_BIT_LEN        (1U)                
#define AON_CTRL_DCA_WRITE_EN_BIT_MASK       0x10U                
#define AON_CTRL_DCA_READ_EN_BIT_OFFSET      (3U)                
#define AON_CTRL_DCA_READ_EN_BIT_LEN         (1U)                
#define AON_CTRL_DCA_READ_EN_BIT_MASK        0x8U                 
#define AON_CTRL_CONFIG_UPLOAD_BIT_OFFSET    (2U)                
#define AON_CTRL_CONFIG_UPLOAD_BIT_LEN       (1U)                
#define AON_CTRL_CONFIG_UPLOAD_BIT_MASK      0x4U                 
#define AON_CTRL_ARRAY_SAVE_BIT_OFFSET     (1U)                
#define AON_CTRL_ARRAY_SAVE_BIT_LEN        (1U)                
#define AON_CTRL_ARRAY_SAVE_BIT_MASK       0x2U                 
#define AON_CTRL_ARRAY_RESTORE_BIT_OFFSET   (0U)                
#define AON_CTRL_ARRAY_RESTORE_BIT_LEN      (1U)                
#define AON_CTRL_ARRAY_RESTORE_BIT_MASK     0x1U                 

/******************************************************************************
* @brief Bit definitions for register AON_RDATA
**/
#define AON_RDATA_ID                         0xa0008              
#define AON_RDATA_LEN                        (4U)                
#define AON_RDATA_MASK                       0xFFFFFFFFUL        
#define AON_RDATA_RDATA_BIT_OFFSET           (0U)                
#define AON_RDATA_RDATA_BIT_LEN              (8U)                
#define AON_RDATA_RDATA_BIT_MASK             0xffU                

/******************************************************************************
* @brief Bit definitions for register AON_ADDR
**/
#define AON_ADDR_ID                          0xa000c              
#define AON_ADDR_LEN                         (4U)                
#define AON_ADDR_MASK                        0xFFFFFFFFUL        
#define AON_ADDR_ADDR_BIT_OFFSET             (0U)                
#define AON_ADDR_ADDR_BIT_LEN                (9U)                
#define AON_ADDR_ADDR_BIT_MASK               0x1ffU               

/******************************************************************************
* @brief Bit definitions for register AON_WDATA
**/
#define AON_WDATA_ID                         0xa0010              
#define AON_WDATA_LEN                        (4U)                
#define AON_WDATA_MASK                       0xFFFFFFFFUL        
#define AON_WDATA_WDATA_BIT_OFFSET           (0U)                
#define AON_WDATA_WDATA_BIT_LEN              (8U)                
#define AON_WDATA_WDATA_BIT_MASK             0xffU                

/******************************************************************************
* @brief Bit definitions for register ANA_CFG
**/
#define ANA_CFG_ID                           0xa0014              
#define ANA_CFG_LEN                          (4U)                
#define ANA_CFG_MASK                         0xFFFFFFFFUL                       
#define ANA_CFG_PRES_SLEEP_BIT_OFFSET    (5U)                
#define ANA_CFG_PRES_SLEEP_BIT_LEN       (1U)                
#define ANA_CFG_PRES_SLEEP_BIT_MASK      0x20U                
#define ANA_CFG_WAKE_WUP_BIT_OFFSET        (4U)                
#define ANA_CFG_WAKE_WUP_BIT_LEN           (1U)                
#define ANA_CFG_WAKE_WUP_BIT_MASK          0x10U                
#define ANA_CFG_WAKE_CSN_BIT_OFFSET        (3U)                
#define ANA_CFG_WAKE_CSN_BIT_LEN           (1U)                
#define ANA_CFG_WAKE_CSN_BIT_MASK          0x8U                 
#define ANA_CFG_BROUT_EN_BIT_OFFSET     (2U)                
#define ANA_CFG_BROUT_EN_BIT_LEN        (1U)                
#define ANA_CFG_BROUT_EN_BIT_MASK       0x4U                 
#define ANA_CFG_WAKE_CNT_BIT_OFFSET      (1U)                
#define ANA_CFG_WAKE_CNT_BIT_LEN         (1U)                
#define ANA_CFG_WAKE_CNT_BIT_MASK        0x2U                 
#define ANA_CFG_SLEEP_EN_BIT_OFFSET          (0U)                
#define ANA_CFG_SLEEP_EN_BIT_LEN             (1U)                
#define ANA_CFG_SLEEP_EN_BIT_MASK            0x1U                 

/******************************************************************************
* @brief Bit definitions for register OTP_WDATA
**/
#define OTP_WDATA_ID                         0xb0000              
#define OTP_WDATA_LEN                        (4U)                
#define OTP_WDATA_MASK                       0xFFFFFFFFUL        
#define OTP_WDATA_OTP_WDATA_BIT_OFFSET       (0U)                
#define OTP_WDATA_OTP_WDATA_BIT_LEN          (32U)               
#define OTP_WDATA_OTP_WDATA_BIT_MASK         0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register OTP_ADDR
**/
#define OTP_ADDR_ID                          0xb0004              
#define OTP_ADDR_LEN                         (4U)                
#define OTP_ADDR_MASK                        0xFFFFFFFFUL        
#define OTP_ADDR_OTP_ADDR_BIT_OFFSET         (0U)                
#define OTP_ADDR_OTP_ADDR_BIT_LEN            (11U)               
#define OTP_ADDR_OTP_ADDR_BIT_MASK           0x7ffU               

/******************************************************************************
* @brief Bit definitions for register OTP_CFG
**/
#define OTP_CFG_ID                           0xb0008              
#define OTP_CFG_LEN                          (4U)                
#define OTP_CFG_MASK                         0xFFFFFFFFUL        
#define OTP_CFG_DGC_SEL_BIT_OFFSET           (13U)               
#define OTP_CFG_DGC_SEL_BIT_LEN              (1U)                
#define OTP_CFG_DGC_SEL_BIT_MASK             0x2000U              
#define OTP_CFG_OPS_ID_BIT_OFFSET           (11U)               
#define OTP_CFG_OPS_ID_BIT_LEN              (2U)                
#define OTP_CFG_OPS_ID_BIT_MASK             0x1800U              
#define OTP_CFG_OPS_KICK_BIT_OFFSET         (10U)               
#define OTP_CFG_OPS_KICK_BIT_LEN            (1U)                
#define OTP_CFG_OPS_KICK_BIT_MASK           0x400U                             
#define OTP_CFG_BIAS_KICK_BIT_OFFSET         (8U)                
#define OTP_CFG_BIAS_KICK_BIT_LEN            (1U)                
#define OTP_CFG_BIAS_KICK_BIT_MASK           0x100U               
#define OTP_CFG_LDO_KICK_BIT_OFFSET          (7U)                
#define OTP_CFG_LDO_KICK_BIT_LEN             (1U)                
#define OTP_CFG_LDO_KICK_BIT_MASK            0x80U                
#define OTP_CFG_DGC_KICK_BIT_OFFSET          (6U)                
#define OTP_CFG_DGC_KICK_BIT_LEN             (1U)                
#define OTP_CFG_DGC_KICK_BIT_MASK            0x40U                                         
#define OTP_CFG_OTP_WRITE_MR_BIT_OFFSET      (3U)                
#define OTP_CFG_OTP_WRITE_MR_BIT_LEN         (1U)                
#define OTP_CFG_OTP_WRITE_MR_BIT_MASK        0x8U                 
#define OTP_CFG_OTP_WRITE_BIT_OFFSET         (2U)                
#define OTP_CFG_OTP_WRITE_BIT_LEN            (1U)                
#define OTP_CFG_OTP_WRITE_BIT_MASK           0x4U                 
#define OTP_CFG_OTP_READ_BIT_OFFSET          (1U)                
#define OTP_CFG_OTP_READ_BIT_LEN             (1U)                
#define OTP_CFG_OTP_READ_BIT_MASK            0x2U                 
#define OTP_CFG_OTP_MAN_CTR_EN_BIT_OFFSET    (0U)                
#define OTP_CFG_OTP_MAN_CTR_EN_BIT_LEN       (1U)                
#define OTP_CFG_OTP_MAN_CTR_EN_BIT_MASK      0x1U                 

/******************************************************************************
* @brief Bit definitions for register OTP_STATUS
**/
#define OTP_STATUS_ID                        0xb000c              
#define OTP_STATUS_LEN                       (4U)                
#define OTP_STATUS_MASK                      0xFFFFFFFFUL        
#define OTP_STATUS_OTP_VPP_OK_BIT_OFFSET     (1U)                
#define OTP_STATUS_OTP_VPP_OK_BIT_LEN        (1U)                
#define OTP_STATUS_OTP_VPP_OK_BIT_MASK       0x2U                 
#define OTP_STATUS_OTP_PROG_DONE_BIT_OFFSET  (0U)                
#define OTP_STATUS_OTP_PROG_DONE_BIT_LEN     (1U)                
#define OTP_STATUS_OTP_PROG_DONE_BIT_MASK    0x1U                 

/******************************************************************************
* @brief Bit definitions for register OTP_RDATA
**/
#define OTP_RDATA_ID                         0xb0010              
#define OTP_RDATA_LEN                        (4U)                
#define OTP_RDATA_MASK                       0xFFFFFFFFUL        
#define OTP_RDATA_OTP_RDATA_BIT_OFFSET       (0U)                
#define OTP_RDATA_OTP_RDATA_BIT_LEN          (32U)               
#define OTP_RDATA_OTP_RDATA_BIT_MASK         0xffffffffUL         


/******************************************************************************
* @brief Bit definitions for register IP_TOA_LO
**/
#define IP_TOA_LO_ID                         0xc0000              
#define IP_TOA_LO_LEN                        (4U)                
#define IP_TOA_LO_MASK                       0xFFFFFFFFUL        
#define IP_TOA_LO_IP_TOA_BIT_OFFSET          (0U)                
#define IP_TOA_LO_IP_TOA_BIT_LEN             (32U)               
#define IP_TOA_LO_IP_TOA_BIT_MASK            0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register IP_TOA_HI
**/
#define IP_TOA_HI_ID                         0xc0004              
#define IP_TOA_HI_LEN                        (4U)                
#define IP_TOA_HI_MASK                       0xFFFFFFFFUL        
#define IP_TOA_HI_IP_TOAST_BIT_OFFSET          (24U)               
#define IP_TOA_HI_IP_TOAST_BIT_LEN             (8U)                
#define IP_TOA_HI_IP_TOAST_BIT_MASK            0xff000000UL         
#define IP_TOA_HI_IP_POA_BIT_OFFSET             (8U)                
#define IP_TOA_HI_IP_POA_BIT_LEN                (14U)               
#define IP_TOA_HI_IP_POA_BIT_MASK               0x3fff00UL           
#define IP_TOA_HI_IP_TOA_BIT_OFFSET          (0U)                
#define IP_TOA_HI_IP_TOA_BIT_LEN             (8U)                
#define IP_TOA_HI_IP_TOA_BIT_MASK            0xffU                

/******************************************************************************
* @brief Bit definitions for register STS_TOA_LO
**/
#define STS_TOA_LO_ID                        0xc0008              
#define STS_TOA_LO_LEN                       (4U)                
#define STS_TOA_LO_MASK                      0xFFFFFFFFUL        
#define STS_TOA_LO_STS_TOA_BIT_OFFSET         (0U)                
#define STS_TOA_LO_STS_TOA_BIT_LEN            (32U)               
#define STS_TOA_LO_STS_TOA_BIT_MASK           0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register STS_TOA_HI
**/
#define STS_TOA_HI_ID                        0xc000c              
#define STS_TOA_HI_LEN                       (4U)                
#define STS_TOA_HI_MASK                      0xFFFFFFFFUL        
#define STS_TOA_HI_STS_TOAST_BIT_OFFSET         (23U)               
#define STS_TOA_HI_STS_TOAST_BIT_LEN            (9U)                
#define STS_TOA_HI_STS_TOAST_BIT_MASK           0xff800000UL         
#define STS_TOA_HI_STS_POA_BIT_OFFSET            (8U)                
#define STS_TOA_HI_STS_POA_BIT_LEN               (14U)               
#define STS_TOA_HI_STS_POA_BIT_MASK              0x3fff00UL           
#define STS_TOA_HI_STS_TOA_BIT_OFFSET          (0U)                
#define STS_TOA_HI_STS_TOA_BIT_LEN             (8U)                
#define STS_TOA_HI_STS_TOA_BIT_MASK            0xffU                

/******************************************************************************
* @brief Bit definitions for register STS1_TOA_LO
**/
#define STS1_TOA_LO_ID                        0xc0010              
#define STS1_TOA_LO_LEN                       (4U)                
#define STS1_TOA_LO_MASK                      0xFFFFFFFFUL        
#define STS1_TOA_LO_STS1_TOA_BIT_OFFSET         (0U)                
#define STS1_TOA_LO_STS1_TOA_BIT_LEN            (32U)               
#define STS1_TOA_LO_STS1_TOA_BIT_MASK           0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register STS1_TOA_HI
**/
#define STS1_TOA_HI_ID                        0xc0014              
#define STS1_TOA_HI_LEN                       (4U)                
#define STS1_TOA_HI_MASK                      0xFFFFFFFFUL        
#define STS1_TOA_HI_STS1_TOAST_BIT_OFFSET         (23U)               
#define STS1_TOA_HI_STS1_TOAST_BIT_LEN            (9U)                
#define STS1_TOA_HI_STS1_TOAST_BIT_MASK           0xff800000UL         
#define STS1_TOA_HI_STS1_POA_BIT_OFFSET            (8U)                
#define STS1_TOA_HI_STS1_POA_BIT_LEN               (14U)               
#define STS1_TOA_HI_STS1_POA_BIT_MASK              0x3fff00UL           
#define STS1_TOA_HI_STS1_TOA_BIT_OFFSET          (0U)                
#define STS1_TOA_HI_STS1_TOA_BIT_LEN             (8U)                
#define STS1_TOA_HI_STS1_TOA_BIT_MASK            0xffU                

/******************************************************************************
* @brief Bit definitions for register CIA_TDOA_0
**/
#define CIA_TDOA_0_ID                        0xc0018              
#define CIA_TDOA_0_LEN                       (4U)                
#define CIA_TDOA_0_MASK                      0xFFFFFFFFUL        
#define CIA_TDOA_0_TDOA_BIT_OFFSET        (0U)                
#define CIA_TDOA_0_TDOA_BIT_LEN           (32U)               
#define CIA_TDOA_0_TDOA_BIT_MASK          0xffffffffUL         

/******************************************************************************
* @brief Bit definitions for register CIA_TDOA_1_PDOA
**/
#define CIA_TDOA_1_PDOA_ID                   0xc001c              
#define CIA_TDOA_1_PDOA_LEN                  (4U)                
#define CIA_TDOA_1_PDOA_MASK                 0xFFFFFFFFUL        
#define CIA_TDOA_1_PDOA_FP_TH_MD_BIT_OFFSET (30U)               
#define CIA_TDOA_1_PDOA_FP_TH_MD_BIT_LEN    (1U)                
#define CIA_TDOA_1_PDOA_FP_TH_MD_BIT_MASK   0x40000000UL         
#define CIA_TDOA_1_PDOA_PDOA_BIT_OFFSET   (16U)               
#define CIA_TDOA_1_PDOA_PDOA_BIT_LEN      (14U)               
#define CIA_TDOA_1_PDOA_PDOA_BIT_MASK     0x3fff0000UL         
#define CIA_TDOA_1_PDOA_TDOA_BIT_OFFSET   (0U)                
#define CIA_TDOA_1_PDOA_TDOA_BIT_LEN      (9U)                
#define CIA_TDOA_1_PDOA_TDOA_BIT_MASK     0x1ffU               

/******************************************************************************
* @brief Bit definitions for register CIA_DIAG_0
**/
#define CIA_DIAG_0_ID                        0xc0020              
#define CIA_DIAG_0_LEN                       (4U)                
#define CIA_DIAG_0_MASK                      0xFFFFFFFFUL        
#define CIA_DIAG_0_COE_PPM_BIT_OFFSET     (0U)                
#define CIA_DIAG_0_COE_PPM_BIT_LEN        (13U)               
#define CIA_DIAG_0_COE_PPM_BIT_MASK       0x1fffU              

/******************************************************************************
* @brief Bit definitions for register CIA_DIAG_1
**/
#define CIA_DIAG_1_ID                        0xc0024              
#define CIA_DIAG_1_LEN                       (4U)                
#define CIA_DIAG_1_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_0
**/
#define IP_DIAG_0_ID                         0xc0028              
#define IP_DIAG_0_LEN                        (4U)                
#define IP_DIAG_0_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_1
**/
#define IP_DIAG_1_ID                         0xc002c              
#define IP_DIAG_1_LEN                        (4U)                
#define IP_DIAG_1_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_2
**/
#define IP_DIAG_2_ID                         0xc0030              
#define IP_DIAG_2_LEN                        (4U)                
#define IP_DIAG_2_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_3
**/
#define IP_DIAG_3_ID                         0xc0034              
#define IP_DIAG_3_LEN                        (4U)                
#define IP_DIAG_3_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_4
**/
#define IP_DIAG_4_ID                         0xc0038              
#define IP_DIAG_4_LEN                        (4U)                
#define IP_DIAG_4_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_5
**/
#define IP_DIAG_5_ID                         0xc003c              
#define IP_DIAG_5_LEN                        (4U)                
#define IP_DIAG_5_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_6
**/
#define IP_DIAG_6_ID                         0xc0040              
#define IP_DIAG_6_LEN                        (4U)                
#define IP_DIAG_6_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_7
**/
#define IP_DIAG_7_ID                         0xc0044              
#define IP_DIAG_7_LEN                        (4U)                
#define IP_DIAG_7_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_8
**/
#define IP_DIAG_8_ID                         0xc0048              
#define IP_DIAG_8_LEN                        (4U)                
#define IP_DIAG_8_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_9
**/
#define IP_DIAG_9_ID                         0xc004c              
#define IP_DIAG_9_LEN                        (4U)                
#define IP_DIAG_9_MASK                       0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_10
**/
#define IP_DIAG_10_ID                        0xc0050              
#define IP_DIAG_10_LEN                       (4U)                
#define IP_DIAG_10_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_11
**/
#define IP_DIAG_11_ID                        0xc0054              
#define IP_DIAG_11_LEN                       (4U)                
#define IP_DIAG_11_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register IP_DIAG_12
**/
#define IP_DIAG_12_ID                        0xc0058              
#define IP_DIAG_12_LEN                       (4U)                
#define IP_DIAG_12_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_0
**/
#define STS_DIAG_0_ID                        0xc005c              
#define STS_DIAG_0_LEN                       (4U)                
#define STS_DIAG_0_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_1
**/
#define STS_DIAG_1_ID                        0xc0060              
#define STS_DIAG_1_LEN                       (4U)                
#define STS_DIAG_1_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_2
**/
#define STS_DIAG_2_ID                        0xc0064              
#define STS_DIAG_2_LEN                       (4U)                
#define STS_DIAG_2_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_3
**/
#define STS_DIAG_3_ID                        0xc0068              
#define STS_DIAG_3_LEN                       (4U)                
#define STS_DIAG_3_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_4
**/
#define STS_DIAG_4_ID                        0xd0000              
#define STS_DIAG_4_LEN                       (4U)                
#define STS_DIAG_4_MASK                      0xFFFFFFFFUL        



/******************************************************************************
* @brief Bit definitions for register STS_DIAG_5
**/
#define STS_DIAG_5_ID                        0xd0004              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_6
**/
#define STS_DIAG_6_ID                        0xd0008              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_7
**/
#define STS_DIAG_7_ID                        0xd000c              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_8
**/
#define STS_DIAG_8_ID                        0xd0010              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_9
**/
#define STS_DIAG_9_ID                        0xd0014              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_10
**/
#define STS_DIAG_10_ID                       0xd0018              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_11
**/
#define STS_DIAG_11_ID                       0xd001c              

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_12
**/
#define STS_DIAG_12_ID                       0xd0020              
#define STS_DIAG_12_LEN                      (4U)                
#define STS_DIAG_12_MASK                     0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_13
**/
#define STS_DIAG_13_ID                       0xd0024    

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_14
**/
#define STS_DIAG_14_ID                       0xd0028    

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_15
**/
#define STS_DIAG_15_ID                       0xd002C    

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_16
**/
#define STS_DIAG_16_ID                       0xd0030    

/******************************************************************************
* @brief Bit definitions for register STS_DIAG_17
**/
#define STS_DIAG_17_ID                       0xd0034    

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_0
**/
#define STS1_DIAG_0_ID                        0xd0038              
#define STS1_DIAG_0_LEN                       (4U)                
#define STS1_DIAG_0_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_1
**/
#define STS1_DIAG_1_ID                        0xd003c              
#define STS1_DIAG_1_LEN                       (4U)                
#define STS1_DIAG_1_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_2
**/
#define STS1_DIAG_2_ID                        0xd0040              
#define STS1_DIAG_2_LEN                       (4U)                
#define STS1_DIAG_2_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_3
**/
#define STS1_DIAG_3_ID                        0xd0044              
#define STS1_DIAG_3_LEN                       (4U)                
#define STS1_DIAG_3_MASK                      0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_4
**/
#define STS1_DIAG_4_ID                        0xd0048              
#define STS1_DIAG_4_LEN                       (4U)                
#define STS1_DIAG_4_MASK                      0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_5
**/
#define STS1_DIAG_5_ID                        0xd004c              

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_6
**/
#define STS1_DIAG_6_ID                        0xd0050              

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_7
**/
#define STS1_DIAG_7_ID                        0xd0054              

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_8
**/
#define STS1_DIAG_8_ID                        0xd0058              
#define STS1_DIAG_8_LEN                       (4U)                
#define STS1_DIAG_8_MASK                      0xFFFFFFFFUL        


/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_9
**/
#define STS1_DIAG_9_ID                        0xd005c              

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_10
**/
#define STS1_DIAG_10_ID                       0xd0060              

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_11
**/
#define STS1_DIAG_11_ID                       0xd0064              

/******************************************************************************
* @brief Bit definitions for register STS1_DIAG_12
**/
#define STS1_DIAG_12_ID                       0xd0068              
#define STS1_DIAG_12_LEN                      (4U)                
#define STS1_DIAG_12_MASK                     0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register CIA_CONF
**/
#define CIA_CONF_ID                  0xe0000              
#define CIA_CONF_LEN                 (4U)                
#define CIA_CONF_MASK                0xFFFFFFFFUL        
#define CIA_CONF_MINDIAG_BIT_OFFSET  (20U)               
#define CIA_CONF_MINDIAG_BIT_LEN     (1U)                
#define CIA_CONF_MINDIAG_BIT_MASK    0x100000UL                          
#define CIA_CONF_RXANTD_BIT_OFFSET (0U)                
#define CIA_CONF_RXANTD_BIT_LEN (16U)               
#define CIA_CONF_RXANTD_BIT_MASK 0xffffU              

/******************************************************************************
* @brief Bit definitions for register FP_CONF
**/
#define FP_CONF_ID               0xe0004              
#define FP_CONF_LEN              (4U)                
#define FP_CONF_MASK             0xFFFFFFFFUL                            
#define FP_CONF_TC_RXDLY_EN_BIT_OFFSET (20U)               
#define FP_CONF_TC_RXDLY_EN_BIT_LEN (1U)                
#define FP_CONF_TC_RXDLY_EN_BIT_MASK 0x100000UL                     
#define FP_CONF_CAL_TEMP_BIT_OFFSET (11U)               
#define FP_CONF_CAL_TEMP_BIT_LEN (8U)                
#define FP_CONF_CAL_TEMP_BIT_MASK 0x7f800UL            
#define FP_CONF_FP_AGREED_TH_BIT_OFFSET (8U)                
#define FP_CONF_FP_AGREED_TH_BIT_LEN (3U)                
#define FP_CONF_FP_AGREED_TH_BIT_MASK 0x700U               
               

/******************************************************************************
* @brief Bit definitions for register IP_CONFIG_LO
**/
#define IP_CONFIG_LO_ID                      0xe000c              
#define IP_CONFIG_LO_LEN                     (2U)                
#define IP_CONFIG_LO_MASK                    0xFFFFU                            
#define IP_CONFIG_LO_IP_PMULT_BIT_OFFSET (5U)                
#define IP_CONFIG_LO_IP_PMULT_BIT_LEN  (2U)                
#define IP_CONFIG_LO_IP_PMULT_BIT_MASK 0x60U                
#define IP_CONFIG_LO_IP_NTM_BIT_OFFSET (0U)                
#define IP_CONFIG_LO_IP_NTM_BIT_LEN (5U)                
#define IP_CONFIG_LO_IP_NTM_BIT_MASK 0x1fU                

/******************************************************************************
* @brief Bit definitions for register IP_CONFIG_HI
**/
#define IP_CONFIG_HI_ID                      0xe000e              /*  { aliased = true}  */
#define IP_CONFIG_HI_LEN                     (4U)
#define IP_CONFIG_HI_MASK                    0xFFFFFFFFUL
#define IP_CONFIG_HI_IP_RTM_BIT_OFFSET (0U)
#define IP_CONFIG_HI_IP_RTM_BIT_LEN (5U)
#define IP_CONFIG_HI_IP_RTM_BIT_MASK 0x1fU

/******************************************************************************
* @brief Bit definitions for register STS_CONFIG_LO
**/
#define STS_CONFIG_LO_ID                      0xe0012              /*  { aliased = true}  */
#define STS_CONFIG_LO_LEN                     (4U)
#define STS_CONFIG_LO_MASK                    0xFFFFFFFFUL
#define STS_CONFIG_LO_STS_MAN_TH_BIT_OFFSET (16U)
#define STS_CONFIG_LO_STS_MAN_TH_BIT_LEN (7U)
#define STS_CONFIG_LO_STS_MAN_TH_BIT_MASK 0x7f0000UL
#define STS_CONFIG_LO_STS_PMULT_BIT_OFFSET (5U)
#define STS_CONFIG_LO_STS_PMULT_BIT_LEN  (2U)
#define STS_CONFIG_LO_STS_PMULT_BIT_MASK 0x60U
#define STS_CONFIG_LO_STS_NTM_BIT_OFFSET (0U)
#define STS_CONFIG_LO_STS_NTM_BIT_LEN (5U)
#define STS_CONFIG_LO_STS_NTM_BIT_MASK 0x1fU

/******************************************************************************
* @brief Bit definitions for register STS_CONFIG_HI
**/
#define STS_CONFIG_HI_ID                      0xe0016              /*  { aliased = true}  */
#define STS_CONFIG_HI_LEN                     (4U)
#define STS_CONFIG_HI_MASK                    0xFFFFFFFFUL
#define STS_CONFIG_HI_STS_PGR_EN_BIT_OFFSET (31U)
#define STS_CONFIG_HI_STS_PGR_EN_BIT_LEN  (1U)
#define STS_CONFIG_HI_STS_PGR_EN_BIT_MASK 0x80000000UL
#define STS_CONFIG_HI_STS_SS_EN_BIT_OFFSET (30U)
#define STS_CONFIG_HI_STS_SS_EN_BIT_LEN    (1U)
#define STS_CONFIG_HI_STS_SS_EN_BIT_MASK   0x40000000UL
#define STS_CONFIG_HI_STS_CQ_EN_BIT_OFFSET (29U)
#define STS_CONFIG_HI_STS_CQ_EN_BIT_LEN    (1U)
#define STS_CONFIG_HI_STS_CQ_EN_BIT_MASK   0x20000000UL
#define STS_CONFIG_HI_FP_AGREED_EN_BIT_OFFSET (28U)
#define STS_CONFIG_HI_FP_AGREED_EN_BIT_LEN    (1U)
#define STS_CONFIG_HI_FP_AGREED_EN_BIT_MASK   0x10000000UL

/******************************************************************************
* @brief Bit definitions for register CIA_ADJUST
**/
#define CIA_ADJUST_ID            0xe001a              /* {aliased=true} */
#define CIA_ADJUST_LEN           (4U)
#define CIA_ADJUST_MASK          0xFFFFFFFFUL
#define CIA_ADJUST_PDOA_ADJ_OFFSET_BIT_OFFSET (0U)
#define CIA_ADJUST_PDOA_ADJ_OFFSET_BIT_LEN (14U)
#define CIA_ADJUST_PDOA_ADJ_OFFSET_BIT_MASK 0x3fffU

/******************************************************************************
* @brief Bit definitions for register PGF_DELAY_COMP_LO
**/
#define PGF_DELAY_COMP_LO_ID                 0xe001e              /* {aliased=true} */

/******************************************************************************
* @brief Bit definitions for register PGF_DELAY_COMP_HI
**/
#define PGF_DELAY_COMP_HI_ID                 0xe0022              /* {aliased=true} */

/******************************************************************************
* @brief Bit definitions for register EVENT_CTRL
**/
#define EVC_CTRL_ID                        0xf0000              
#define EVC_CTRL_LEN                       (4U)                
#define EVC_CTRL_MASK                      0xFFFFFFFFUL        
#define EVC_CTRL_EVC_CLR_BIT_OFFSET (1U)                
#define EVC_CTRL_EVC_CLR_BIT_LEN   (1U)                
#define EVC_CTRL_EVC_CLR_BIT_MASK  0x2U                 
#define EVC_CTRL_EVC_EN_BIT_OFFSET (0U)                
#define EVC_CTRL_EVC_EN_BIT_LEN    (1U)                
#define EVC_CTRL_EVC_EN_BIT_MASK   0x1U                 

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT0
**/
#define EVC_COUNT0_ID                      0xf0004              
#define EVC_COUNT0_LEN                     (4U)                
#define EVC_COUNT0_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT0_EVC_RSE_BIT_OFFSET  (16U)               
#define EVC_COUNT0_EVC_RSE_BIT_LEN     (12U)               
#define EVC_COUNT0_EVC_RSE_BIT_MASK    0xfff0000UL          
#define EVC_COUNT0_EVC_PHE_BIT_OFFSET  (0U)                
#define EVC_COUNT0_EVC_PHE_BIT_LEN     (12U)               
#define EVC_COUNT0_EVC_PHE_BIT_MASK    0xfffU               

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT1
**/
#define EVC_COUNT1_ID                      0xf0008              
#define EVC_COUNT1_LEN                     (4U)                
#define EVC_COUNT1_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT1_EVC_FCE_BIT_OFFSET  (16U)               
#define EVC_COUNT1_EVC_FCE_BIT_LEN     (12U)               
#define EVC_COUNT1_EVC_FCE_BIT_MASK    0xfff0000UL          
#define EVC_COUNT1_EVC_FCG_BIT_OFFSET  (0U)                
#define EVC_COUNT1_EVC_FCG_BIT_LEN     (12U)               
#define EVC_COUNT1_EVC_FCG_BIT_MASK    0xfffU               

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT2
**/
#define EVC_COUNT2_ID                      0xf000c              
#define EVC_COUNT2_LEN                     (4U)                
#define EVC_COUNT2_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT2_EVC_OVR_BIT_OFFSET (16U)               
#define EVC_COUNT2_EVC_OVR_BIT_LEN    (8U)                
#define EVC_COUNT2_EVC_OVR_BIT_MASK   0xff0000UL           
#define EVC_COUNT2_EVC_FFR_BIT_OFFSET   (0U)                
#define EVC_COUNT2_EVC_FFR_BIT_LEN      (8U)                
#define EVC_COUNT2_EVC_FFR_BIT_MASK     0xffU                

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT3
**/
#define EVC_COUNT3_ID                      0xf0010              
#define EVC_COUNT3_LEN                     (4U)                
#define EVC_COUNT3_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT3_EVC_PTO_BIT_OFFSET  (16U)               
#define EVC_COUNT3_EVC_PTO_BIT_LEN     (12U)               
#define EVC_COUNT3_EVC_PTO_BIT_MASK    0xfff0000UL          
#define EVC_COUNT3_EVC_STO_BIT_OFFSET  (0U)                
#define EVC_COUNT3_EVC_STO_BIT_LEN     (12U)               
#define EVC_COUNT3_EVC_STO_BIT_MASK    0xfffU               

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT4
**/
#define EVC_COUNT4_ID                      0xf0014              
#define EVC_COUNT4_LEN                     (4U)                
#define EVC_COUNT4_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT4_EVC_TXFS_BIT_OFFSET  (16U)               
#define EVC_COUNT4_EVC_TXFS_BIT_LEN     (12U)               
#define EVC_COUNT4_EVC_TXFS_BIT_MASK    0xfff0000UL          
#define EVC_COUNT4_EVC_FWTO_BIT_OFFSET   (0U)                
#define EVC_COUNT4_EVC_FWTO_BIT_LEN      (8U)                
#define EVC_COUNT4_EVC_FWTO_BIT_MASK     0xffU                

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT5
**/
#define EVC_COUNT5_ID                      0xf0018              
#define EVC_COUNT5_LEN                     (4U)                
#define EVC_COUNT5_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT5_EVC_SWCE_BIT_OFFSET (16U)               
#define EVC_COUNT5_EVC_SWCE_BIT_LEN    (8U)                
#define EVC_COUNT5_EVC_SWCE_BIT_MASK   0xff0000UL           
#define EVC_COUNT5_EVC_HPW_BIT_OFFSET (0U)                
#define EVC_COUNT5_EVC_HPW_BIT_LEN    (8U)                
#define EVC_COUNT5_EVC_HPW_BIT_MASK   0xffU                

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT6
**/
#define EVC_COUNT6_ID                      0xf001c              
#define EVC_COUNT6_LEN                     (4U)                
#define EVC_COUNT6_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT6_EVC_PREJ_BIT_OFFSET (0U)                
#define EVC_COUNT6_EVC_PREJ_BIT_LEN    (12U)               
#define EVC_COUNT6_EVC_PREJ_BIT_MASK   0xfffU               
            


/******************************************************************************
* @brief Bit definitions for register TEST_CTRL0
**/
#define TEST_CTRL0_ID                        0xf0024              
#define TEST_CTRL0_LEN                       (4U)                
#define TEST_CTRL0_MASK                      0xFFFFFFFFUL        
#define TEST_CTRL0_CIA_RUN_BIT_OFFSET    (26U)               
#define TEST_CTRL0_CIA_RUN_BIT_LEN       (1U)                
#define TEST_CTRL0_CIA_RUN_BIT_MASK      0x4000000UL          
#define TEST_CTRL0_CIA_WDEN_BIT_OFFSET    (24U)               
#define TEST_CTRL0_CIA_WDEN_BIT_LEN       (1U)                
#define TEST_CTRL0_CIA_WDEN_BIT_MASK      0x1000000UL          
#define TEST_CTRL0_HIRQ_POL_BIT_OFFSET       (21U)               
#define TEST_CTRL0_HIRQ_POL_BIT_LEN          (1U)                
#define TEST_CTRL0_HIRQ_POL_BIT_MASK         0x200000UL           
#define TEST_CTRL0_TX_PSTM_BIT_OFFSET          (4U)                
#define TEST_CTRL0_TX_PSTM_BIT_LEN             (1U)                
#define TEST_CTRL0_TX_PSTM_BIT_MASK            0x10U                

/******************************************************************************
* @brief Bit definitions for register EVC_COUNT7
**/
#define EVC_COUNT7_ID                      0xf0028              
#define EVC_COUNT7_LEN                     (4U)                
#define EVC_COUNT7_MASK                    0xFFFFFFFFUL        
#define EVC_COUNT7_EVC_VWARN_BIT_OFFSET  (16U)               
#define EVC_COUNT7_EVC_VWARN_BIT_LEN     (8U)                
#define EVC_COUNT7_EVC_VWARN_BIT_MASK    0xff0000UL           
#define EVC_COUNT7_EVC_CPQE_BIT_OFFSET  (0U)                
#define EVC_COUNT7_EVC_CPQE_BIT_LEN     (8U)                
#define EVC_COUNT7_EVC_CPQE_BIT_MASK    0xffU                

/******************************************************************************
* @brief Bit definitions for register SPI_MODE
**/
#define SPI_MODE_ID                          0xf002c              
#define SPI_MODE_LEN                         (4U)                
#define SPI_MODE_MASK                        0xFFFFFFFFUL        
#define SPI_MODE_SPI_MODE_BIT_OFFSET         (0U)                
#define SPI_MODE_SPI_MODE_BIT_LEN            (2U)                
#define SPI_MODE_SPI_MODE_BIT_MASK           0x3U                 

/******************************************************************************
* @brief Bit definitions for register SYS_STATE_LO
**/
#define SYS_STATE_LO_ID                      0xf0030              
#define SYS_STATE_LO_LEN                     (4U)                
#define SYS_STATE_LO_MASK                    0xFFFFFFFFUL        



/******************************************************************************
* @brief Bit definitions for register FCMD_STATUS
**/
#define FCMD_STATUS_ID                       0xf003c              
#define FCMD_STATUS_LEN                      (4U)                
#define FCMD_STATUS_MASK                     0xFFFFFFFFUL        
#define FCMD_STATUS_FCMD_STATUS_BIT_OFFSET   (0U)                
#define FCMD_STATUS_FCMD_STATUS_BIT_LEN      (5U)                
#define FCMD_STATUS_FCMD_STATUS_BIT_MASK     0x1fU                

/******************************************************************************
* @brief Bit definitions for register CTR_DBG
**/
#define CTR_DBG_ID                           0xf0048   
#define CTR_DBG_LEN                          (4U)
#define CTR_DBG_MASK                         0xFFFFFFFFUL
#define CTR_DBG_CTR_DBG_BIT_OFFSET           (0U)
#define CTR_DBG_CTR_DBG_BIT_LEN              (32U)
#define CTR_DBG_CTR_DBG_BIT_MASK             0xffffffffUL

/******************************************************************************
* @brief Bit definitions for register SOFT_RST
**/
#define SOFT_RST_ID                          0x110000             
#define SOFT_RST_LEN                         (4U)                
#define SOFT_RST_MASK                        0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register CLK_CTRL
**/
#define CLK_CTRL_ID                          0x110004             
#define CLK_CTRL_LEN                         (4U)                
#define CLK_CTRL_MASK                        0xFFFFFFFFUL                          
#define CLK_CTRL_LP_CLK_EN_BIT_OFFSET        (23U)               
#define CLK_CTRL_LP_CLK_EN_BIT_LEN           (1U)                
#define CLK_CTRL_LP_CLK_EN_BIT_MASK          0x800000UL                             
#define CLK_CTRL_GPIO_DRST_N_BIT_OFFSET  (19U)               
#define CLK_CTRL_GPIO_DRST_N_BIT_LEN     (1U)                
#define CLK_CTRL_GPIO_DRST_N_BIT_MASK    0x80000UL            
#define CLK_CTRL_GPIO_DCLK_EN_BIT_OFFSET (18U)               
#define CLK_CTRL_GPIO_DCLK_EN_BIT_LEN    (1U)                
#define CLK_CTRL_GPIO_DCLK_EN_BIT_MASK   0x40000UL            
#define CLK_CTRL_GPIO_CLK_EN_BIT_OFFSET      (16U)               
#define CLK_CTRL_GPIO_CLK_EN_BIT_LEN         (1U)                
#define CLK_CTRL_GPIO_CLK_EN_BIT_MASK        0x10000UL            
#define CLK_CTRL_ACC_MCLK_EN_BIT_OFFSET   (15U)               
#define CLK_CTRL_ACC_MCLK_EN_BIT_LEN      (1U)                
#define CLK_CTRL_ACC_MCLK_EN_BIT_MASK     0x8000U                         
#define CLK_CTRL_TX_BUF_CLK_ON_BIT_OFFSET    (12U)               
#define CLK_CTRL_TX_BUF_CLK_ON_BIT_LEN       (1U)                
#define CLK_CTRL_TX_BUF_CLK_ON_BIT_MASK      0x1000U              
#define CLK_CTRL_RX_BUF_CLK_ON_BIT_OFFSET    (11U)               
#define CLK_CTRL_RX_BUF_CLK_ON_BIT_LEN       (1U)                
#define CLK_CTRL_RX_BUF_CLK_ON_BIT_MASK      0x800U               
#define CLK_CTRL_SAR_CLK_EN_BIT_OFFSET (10U)               
#define CLK_CTRL_SAR_CLK_EN_BIT_LEN    (1U)                
#define CLK_CTRL_SAR_CLK_EN_BIT_MASK   0x400U               
#define CLK_CTRL_OTP_CLK_EN_BIT_OFFSET (9U)                
#define CLK_CTRL_OTP_CLK_EN_BIT_LEN    (1U)                
#define CLK_CTRL_OTP_CLK_EN_BIT_MASK   0x200U               
#define CLK_CTRL_CIA_CLK_EN_BIT_OFFSET (8U)                
#define CLK_CTRL_CIA_CLK_EN_BIT_LEN   (1U)                
#define CLK_CTRL_CIA_CLK_EN_BIT_MASK  0x100U                            
#define CLK_CTRL_ACC_CLK_EN_BIT_OFFSET    (6U)                
#define CLK_CTRL_ACC_CLK_EN_BIT_LEN       (1U)                
#define CLK_CTRL_ACC_CLK_EN_BIT_MASK      0x40U                
#define CLK_CTRL_TX_CLK_SEL_BIT_OFFSET       (4U)                
#define CLK_CTRL_TX_CLK_SEL_BIT_LEN          (2U)                
#define CLK_CTRL_TX_CLK_SEL_BIT_MASK         0x30U                
#define CLK_CTRL_RX_CLK_SEL_BIT_OFFSET       (2U)                
#define CLK_CTRL_RX_CLK_SEL_BIT_LEN          (2U)                
#define CLK_CTRL_RX_CLK_SEL_BIT_MASK         0xcU                 
#define CLK_CTRL_SYS_CLK_SEL_BIT_OFFSET      (0U)                
#define CLK_CTRL_SYS_CLK_SEL_BIT_LEN         (2U)                
#define CLK_CTRL_SYS_CLK_SEL_BIT_MASK        0x3U                 

/******************************************************************************
* @brief Bit definitions for register SEQ_CTRL
**/
#define SEQ_CTRL_ID                          0x110008             
#define SEQ_CTRL_LEN                         (4U)                
#define SEQ_CTRL_MASK                        0xFFFFFFFFUL        
#define SEQ_CTRL_LP_CLK_DIV_BIT_OFFSET       (26U)               
#define SEQ_CTRL_LP_CLK_DIV_BIT_LEN          (6U)                
#define SEQ_CTRL_LP_CLK_DIV_BIT_MASK         0xfc000000UL                            
#define SEQ_CTRL_FORCE2INIT_BIT_OFFSET       (23U)               
#define SEQ_CTRL_FORCE2INIT_BIT_LEN          (1U)                
#define SEQ_CTRL_FORCE2INIT_BIT_MASK         0x800000UL           
#define SEQ_CTRL_CIA_SEQ_EN_BIT_OFFSET       (17U)               
#define SEQ_CTRL_CIA_SEQ_EN_BIT_LEN          (1U)                
#define SEQ_CTRL_CIA_SEQ_EN_BIT_MASK         0x20000UL                       
#define SEQ_CTRL_PLL_SYNC_MODE_BIT_OFFSET    (15U)               
#define SEQ_CTRL_PLL_SYNC_MODE_BIT_LEN       (1U)                
#define SEQ_CTRL_PLL_SYNC_MODE_BIT_MASK      0x8000U                          
#define SEQ_CTRL_ARX2SLP_BIT_OFFSET      (12U)               
#define SEQ_CTRL_ARX2SLP_BIT_LEN         (1U)                
#define SEQ_CTRL_ARX2SLP_BIT_MASK        0x1000U              
#define SEQ_CTRL_ATX2SLP_BIT_OFFSET      (11U)               
#define SEQ_CTRL_ATX2SLP_BIT_LEN         (1U)                
#define SEQ_CTRL_ATX2SLP_BIT_MASK        0x800U                            
#define SEQ_CTRL_AINIT2IDLE_BIT_OFFSET   (8U)                
#define SEQ_CTRL_AINIT2IDLE_BIT_LEN      (1U)                
#define SEQ_CTRL_AINIT2IDLE_BIT_MASK     0x100U               
               
               
                          

/******************************************************************************
* @brief Bit definitions for register PWR_UP_TIMES_LO
**/
#define PWR_UP_TIMES_LO_ID                   0x110010             
#define PWR_UP_TIMES_LO_LEN                  (4U)                
#define PWR_UP_TIMES_LO_MASK                 0xFFFFFFFFUL        
#define PWR_UP_TIMES_TXFINESEQ_BIT_OFFSET    (0U)                
#define PWR_UP_TIMES_TXFINESEQ_BIT_LEN       (32U)                
#define PWR_UP_TIMES_TXFINESEQ_BIT_MASK      0xFFFFFFFFUL              


/******************************************************************************
* @brief Bit definitions for register LED_CTRL
**/
#define LED_CTRL_ID                          0x110016             /*  */
#define LED_CTRL_LEN                         (4U)                
#define LED_CTRL_MASK                        0xFFFFFFFFUL        
#define LED_CTRL_FORCE_TRIGGER_BIT_OFFSET    (16U)               
#define LED_CTRL_FORCE_TRIGGER_BIT_LEN       (4U)                
#define LED_CTRL_FORCE_TRIGGER_BIT_MASK      0xf0000UL            
#define LED_CTRL_BLINK_EN_BIT_OFFSET         (8U)                
#define LED_CTRL_BLINK_EN_BIT_LEN            (1U)                
#define LED_CTRL_BLINK_EN_BIT_MASK           0x100U               

/******************************************************************************
* @brief Bit definitions for register RX_SNIFF
**/
#define RX_SNIFF_ID                            0x11001a             /*  { aliased = true}  */
#define RX_SNIFF_LEN                           (4U)                
#define RX_SNIFF_MASK                          0xFFFFFFFFUL        
#define RX_SNIFF_SNIFF_OFF_BIT_OFFSET            (8U)                
#define RX_SNIFF_SNIFF_OFF_BIT_LEN               (8U)                
#define RX_SNIFF_SNIFF_OFF_BIT_MASK              0xff00U              
#define RX_SNIFF_SNIFF_ON_BIT_OFFSET             (0U)                
#define RX_SNIFF_SNIFF_ON_BIT_LEN                (4U)                
#define RX_SNIFF_SNIFF_ON_BIT_MASK               0xfU                 


/******************************************************************************
* @brief Bit definitions for register BIAS_CTRL
**/
#define BIAS_CTRL_ID                         0x11001f             /*  */
#define BIAS_CTRL_LEN                        (4U)                
#define BIAS_CTRL_MASK                       0xFFFFFFFFUL        
#define BIAS_CTRL_BIAS_OFFSET (0U)                
#define BIAS_CTRL_BIAS_LEN   (5U)                
#define BIAS_CTRL_BIAS_MASK  0x1fU                

/******************************************************************************
* @brief Bit definitions for register FINT_STAT
**/
#define FINT_STAT_ID                         0x1F0000             
#define FINT_STAT_LEN                        (4U)                
#define FINT_STAT_MASK                       0xFFFFFFFFUL        
#define FINT_STAT_SYS_PANIC_BIT_MASK         0x80U                
#define FINT_STAT_SYS_EVENT_BIT_MASK         0x40U                
#define FINT_STAT_RXTO_BIT_MASK              0x20U                
#define FINT_STAT_RXERR_BIT_MASK             0x10U                
#define FINT_STAT_RXOK_BIT_MASK              0x8U                 
#define FINT_STAT_RXTSERR_BIT_MASK           0x4U                 
#define FINT_STAT_CCA_FAIL_AAT_BIT_MASK      0x2U                 
#define FINT_STAT_TXOK_BIT_MASK              0x1U 

/******************************************************************************
* @brief Bit definitions for register INDIRECT_ADDR_A
**/
#define INDIRECT_ADDR_A_ID                   0x1f0004             
#define INDIRECT_ADDR_A_LEN                  (4U)                
#define INDIRECT_ADDR_A_MASK                 0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register ADDR_OFFSET_A
**/
#define ADDR_OFFSET_A_ID                     0x1f0008             
#define ADDR_OFFSET_A_LEN                    (4U)                
#define ADDR_OFFSET_A_MASK                   0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register INDIRECT_ADDR_B
**/
#define INDIRECT_ADDR_B_ID                   0x1f000c             
#define INDIRECT_ADDR_B_LEN                  (4U)                
#define INDIRECT_ADDR_B_MASK                 0xFFFFFFFFUL        

/******************************************************************************
* @brief Bit definitions for register ADDR_OFFSET_B
**/
#define ADDR_OFFSET_B_ID                     0x1f0010             
#define ADDR_OFFSET_B_LEN                    (4U)                
#define ADDR_OFFSET_B_MASK                   0xFFFFFFFFUL        

#ifdef __cplusplus
}
#endif
#endif /* __DECA_REGS_H */
