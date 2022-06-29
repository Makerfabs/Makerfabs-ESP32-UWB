#include "dw3000.h"

#define APP_NAME "READ DEV ID\r\n"

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4; // spi select pin


void setup() {
  UART_init();
  UART_puts((char *)APP_NAME);

  /* Configure SPI rate, DW3000 supports up to 38 MHz */
  /* Reset DW IC */
  spiBegin(PIN_IRQ, PIN_RST);
  spiSelect(PIN_SS);

  delay(2); // Time needed for DW3000 to start up (transition from INIT_RC to IDLE_RC, or could wait for SPIRDY event)

  /* Reads and validate device ID returns DWT_ERROR if it does not match expected else DWT_SUCCESS */
  if (dwt_check_dev_id() == DWT_SUCCESS)
  {
      UART_puts((char *)"DEV ID OK");
  }
  else
  {
      UART_puts((char *)"DEV ID FAILED");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
