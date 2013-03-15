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
	//UART0_C2 = 0;
	UART0_C2 &= ~ (UART0_C2_TE_MASK| UART0_C2_RE_MASK);
	
	#if UART_MODE == INTERRUPT_MODE
	enable_irq(12); 
	set_irq_priority(12, 3);
	#endif
	
	/* Se le asigna el baudaje ala uart0, calculado mediante la formula
	 * baudclock / ((OSR+1) × BR); donde baudclock = Frequencia del reloj, 
	 * OSR = cantidad de muestras al receptor(15 en este caso), BR = baudaje que se requiere(250,000 en este caso)
	 */
	UART0_BDL = UART0_BDL_SBR(1);
	
    /*Se le asignamos el valor del el numero de muestras que se le haran al receptor (15)*/
	UART0_C4 = UART0_C4_OSR(15);
	
	
	#if UART_MODE == INTERRUPT_MODE
	/*Registro de control de la uart en el cual se habilita la interrupcion del receptor */
	UART0_C2 = UART0_C2_RIE_MASK;
	#endif
	
	/*Registro de control de la uart en el cual se habilita el transmisor y el receptor */
	UART0_C2 |= (UART0_C2_TE_MASK| UART0_C2_RE_MASK);
	
	#if UART_MODE == INTERRUPT_MODE
	/*Secuencia para entrar en modo interrupcion*/
	asm("CPSIE i");
	#endif
	
	char c = 'a';
	int i;
	
	Led_On(BLUE);
	
	while (1)
	{
	#if UART_MODE == POLLING_MODE
		
	for (i = 0; i < 200000; ++i);
	/*Registro por el cual se escribe lo que se va a enviar de la uart*/
	UART0_D = c++;
	/*Mientras la bandera de transmicion completa se activa*/
	while(!(UART0_S1&UART0_S1_TC_MASK));
	
	Led_Neg(BLUE);
	
	if( c == 'z')
		c = 'a';
	#endif
	}
}



	
