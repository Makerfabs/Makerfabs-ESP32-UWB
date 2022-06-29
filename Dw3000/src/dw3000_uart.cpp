/*
 * UART.c
 *
 * Created: 9/10/2021 12:32:14 PM
 *  Author: Emin Eminof
 */ 
#include "dw3000_uart.h"


void UART_init(void)
{
  Serial.begin(115200);
}

void UART_putc(char data)
{
  Serial.print(data);
}

void UART_puts(char* s)
{
  Serial.print(s);
}

void test_run_info(unsigned char * s)
{
    UART_puts((char *)s);
    UART_puts("\r\n");
}
