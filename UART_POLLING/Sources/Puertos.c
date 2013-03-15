/*
 * Puertos.c
 *
 *  Created on: Mar 14, 2013
 *      Author: Arteko
 */
#include "Puertos.h"


void ini_ports()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	/* Habilitamos las interrupciones en los pines de la UART A2(Tx) y A1(Rx). */
	PORTB_PCR2 |= (PORT_PCR_ISF_MASK|PORT_PCR_MUX(2));
	PORTB_PCR1 |= (PORT_PCR_ISF_MASK|PORT_PCR_MUX(2));
	
	/** El KL05Z no tiene puertos C y D */
	#ifdef MCU_MKL25Z4
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	#endif
}

#ifdef MCU_MKL25Z4
void ini_Clkout()
{	
 	//Habilitamos la funcion alterna FB_CLKOUT  en el pin
	PORTC_PCR3 = ( PORT_PCR_MUX(0x5));
	    
    //Seleccionamos CLKOUT en el SIM SOPT2
    SIM_SOPT2 = SIM_SOPT2_CLKOUTSEL(2);
   
}
#endif
