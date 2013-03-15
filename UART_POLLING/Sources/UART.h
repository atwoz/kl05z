#ifndef UART_H_
#define UART_H_

#define POLLING_MODE 1
#define INTERRUPT_MODE 2
#define UART_MODE POLLING_MODE

/*
extern void uart0_isr(void);
#undef VECTOR_028
#define VECTOR_028 uart0_isr
*/

#include "derivative.h"
#include "LED.h"

void init_UART();

#endif /* UART_H_ */
