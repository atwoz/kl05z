/*
 * UART.h
 *
 *  Created on: Mar 14, 2013
 *      Author: Arteko
 */

#include "UART.h"

void init_UART()
{	
	/* Seleccionamos el reloj de la UART como el MCGIRCLK */
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(3);
	
	/* Habilitamos el reloj de la UART */
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	
	/* Deshabilitamos el open drain */
	SIM_SOPT5 &=  ~SIM_SOPT5_UART0ODE_MASK;
	
	/* La entrada del UART es la default */
	SIM_SOPT5 &= ~SIM_SOPT5_UART0RXSRC_MASK;
	
	/* La salida del UART es la default */
	SIM_SOPT5 &= ~SIM_SOPT5_UART0TXSRC_MASK;
	
	/* Para inicializar la confifuración de la UART es necesarios desactivar primero
	 * el registro UART0_C2 */
	UART0_C2 = 0;
	//UART0_C2 &= ~ (UART0_C2_TE_MASK| UART0_C2_RE_MASK);
	
	#if UART_MODE == INTERRUPT_MODE
	enable_irq(12); 
	set_irq_priority(12, 3);
	#endif
	UART0_BDH = 0x00;
	UART0_BDL = 0x01;
	
	UART0_C4 = UART0_C4_OSR(15);
	UART0_C1 = 0x00;
	UART0_C3 = 0x00;
	UART0_MA1 = 0x00;
	UART0_MA1 = 0x00;
	UART0_S1 |= 0x1F;
	UART0_S2 |= 0xC0;
	UART0_C5 = 0x00;
		
	
	
	#if UART_MODE == INTERRUPT_MODE
	UART0_C2 = UART0_C2_RIE_MASK;
	#endif
	
	UART0_C2 |= (UART0_C2_TE_MASK| UART0_C2_RE_MASK);
	
	#if UART_MODE == INTERRUPT_MODE
	asm("CPSIE i");
	#endif
	
	char c = 'a';
	int i;
	
	Led_On(BLUE);
	
	while (1)
	{
	#if UART_MODE == POLLING_MODE
		
	for (i = 0; i < 200000; ++i);
	
	UART0_D = c++;
	while(!(UART0_S1&UART0_S1_TC_MASK));
	
	Led_Neg(BLUE);
	
	if( c == 'z')
		c = 'a';
	#endif
	}
}



	
