/*
 * port.h
 *
 * Created: 9/10/2021 1:20:00 PM
 *  Author: Emin Eminof
 */ 

#ifndef PORT_H_
#define PORT_H_

#include "dw3000.h"

#define DDR_SPI DDRB
#define DD_SCK DDB5
#define DD_MISO DDB4
#define DD_MOSI DDB3
#define DD_SS 4

#define DEFAULT_IRQ 34
#define DEFAULT_RST 27
#define DEFAULT_SS 4

//#define DDR_PORTD DDRD
#define DD_RESET_PIN 27

#ifndef FALSE
#define FALSE  0
#endif

#ifndef TRUE
#define TRUE  1
#endif

// PMSC
#define PMSC 0x36
#define PMSC_CTRL0_SUB 0x00
#define PMSC_CTRL1_SUB 0x04
#define PMSC_LEDC_SUB 0x28
#define LEN_PMSC_CTRL0 4
#define LEN_PMSC_CTRL1 4
#define LEN_PMSC_LEDC 4
#define GPDCE_BIT 18
#define KHZCLKEN_BIT 23
#define BLNKEN 8

#define ATXSLP_BIT 11
#define ARXSLP_BIT 12

// used for SPI ready w/o actual writes
#define JUNK 0x00

// no sub-address for register write
#define NO_SUB 0xFF

#define WRITE      0x80
#define WRITE_SUB  0xC0
#define READ       0x00
#define READ_SUB   0x40
#define RW_SUB_EXT 0x80

// device control register
#define SYS_CTRL 0x0D
#define LEN_SYS_CTRL 4
#define SFCST_BIT 0
#define TXSTRT_BIT 1
#define TXDLYS_BIT 2
#define TRXOFF_BIT 6
#define WAIT4RESP_BIT 7
#define RXENAB_BIT 8
#define RXDLYS_BIT 9

// device configuration register
#define SYS_CFG 0x04
#define LEN_SYS_CFG 4
#define FFEN_BIT 0
#define FFBC_BIT 1
#define FFAB_BIT 2
#define FFAD_BIT 3
#define FFAA_BIT 4
#define FFAM_BIT 5
#define FFAR_BIT 6
#define DIS_DRXB_BIT 12
#define DIS_STXP_BIT 18
#define HIRQ_POL_BIT 9
#define RXAUTR_BIT 29
#define PHR_MODE_SUB 16
#define LEN_PHR_MODE_SUB 2
#define RXM110K_BIT 22

// system event status register
#define SYS_STATUS 0x0F
#define LEN_SYS_STATUS 5
#define CPLOCK_BIT 1
#define AAT_BIT 3
#define TXFRB_BIT 4
#define TXPRS_BIT 5
#define TXPHS_BIT 6
#define TXFRS_BIT 7
#define LDEDONE_BIT 10
#define RXPHE_BIT 12
#define RXDFR_BIT 13
#define RXFCG_BIT 14
#define RXFCE_BIT 15
#define RXRFSL_BIT 16
#define RXRFTO_BIT 17
#define RXPTO_BIT 21
#define RXSFDTO_BIT 26
#define LDEERR_BIT 18
#define RFPLL_LL_BIT 24
#define CLKPLL_LL_BIT 25

// transmit control
#define TX_FCTRL 0x08
#define LEN_TX_FCTRL 5

// channel control
#define CHAN_CTRL 0x1F
#define LEN_CHAN_CTRL 4
#define DWSFD_BIT 17
#define TNSSFD_BIT 20
#define RNSSFD_BIT 21

// system event mask register
// NOTE: uses the bit definitions of SYS_STATUS (below 32)
#define SYS_MASK 0x0E
#define LEN_SYS_MASK 4
  
  /* clocks available. */
#define AUTO_CLOCK 0x00
#define XTI_CLOCK  0x01
#define PLL_CLOCK  0x02

// OTP control (for LDE micro code loading only)
#define OTP_IF 0x2D
#define OTP_ADDR_SUB 0x04
#define OTP_CTRL_SUB 0x06
#define OTP_RDAT_SUB 0x0A
#define LEN_OTP_ADDR 2
#define LEN_OTP_CTRL 2
#define LEN_OTP_RDAT 4

// enum to determine RX or TX mode of device
#define IDLE_MODE 0x00
#define RX_MODE 0x01
#define TX_MODE 0x02

// PAN identifier, short address register
#define PANADR 0x03
#define LEN_PANADR 4

void readBytes(byte cmd, uint16_t offset, byte data[], uint16_t n);
void readSystemEventStatusRegister();
void readSystemConfigurationRegister();
void writeSystemConfigurationRegister();
void readNetworkIdAndDeviceAddress();
void writeNetworkIdAndDeviceAddress();
void readSystemEventMaskRegister();
void writeSystemEventMaskRegister();
void readChannelControlRegister();
void writeChannelControlRegister();
void readTransmitFrameControlRegister();
void writeTransmitFrameControlRegister();
void setDoubleBuffering(boolean val);
void setBit(byte data[], uint16_t n, uint16_t bit, boolean val);
boolean getBit(byte data[], uint16_t n, uint16_t bit);
void writeValueToBytes(byte data[], int32_t val, uint16_t n);
void writeBytes(byte cmd, uint16_t offset, byte data[], uint16_t data_size);
void writeByte(byte cmd, uint16_t offset, byte data);
void reset();
void softReset();
void idle();
void spiBegin(uint8_t irq, uint8_t rst);
void spiSelect(uint8_t ss);
void enableClock(byte clock);
int writetospi(uint16_t headerLength,  uint8_t *headerBuffer, uint16_t bodyLength, uint8_t *bodyBuffer);
int readfromspi(uint16_t headerLength, uint8_t *headerBuffer, uint16_t readLength, uint8_t *readBuffer);

void Sleep(uint32_t d);
void enableDebounceClock();
void wakeup_device_with_io();

void port_set_dw_ic_spi_fastrate(uint8_t irq = DEFAULT_IRQ, uint8_t rst = DEFAULT_RST, uint8_t ss = DEFAULT_SS);

uint32_t port_GetEXT_IRQStatus(void);
uint32_t port_CheckEXT_IRQ(void);
void port_DisableEXT_IRQ(void);
void port_EnableEXT_IRQ(void);

/* DW IC IRQ (EXTI15_10_IRQ) handler type. */
typedef void (*port_dwic_isr_t)(void);

/*! ------------------------------------------------------------------------------------------------------------------
 * @fn port_set_DWIC_isr()
 *
 * @brief This function is used to install the handling function for DW1000 IRQ.
 *
 * NOTE:
 *   - As EXTI9_5_IRQHandler does not check that port_deca_isr is not null, the user application must ensure that a
 *     proper handler is set by calling this function before any DW1000 IRQ occurs!
 *   - This function makes sure the DW1000 IRQ line is deactivated while the handler is installed.
 *
 * @param deca_isr function pointer to DW1000 interrupt handler to install
 *
 * @return none
 */
void port_set_dwic_isr(port_dwic_isr_t isr);

#if 0
void sleepms(uint32_t x);
int sleepus(uint32_t x);
void deca_sleep(uint8_t time_ms);
void deca_usleep(uint8_t time_us);
void open_spi(void);
void close_spi(void);


void port_set_dw_ic_spi_slowrate(void);
void port_set_dw_ic_spi_fastrate(void);
void reset_DWIC(void);
int spi_tranceiver (uint8_t *data);
#endif

#endif /* PORT_H_ */
