/*
 * UART.h
 *
 * Created: 9/10/2021 12:32:28 PM
 *  Author: Emin Eminof
 */ 

#ifndef UART_H_
#define UART_H_

#include "dw3000.h"

void UART_init(void);
void UART_putc(char data);
void UART_puts(char* s);

void test_run_info(unsigned char * s);

#endif /* UART_H_ */
