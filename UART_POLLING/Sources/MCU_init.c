/*
 * MCU_init.c
 *
 *  Created on: Mar 14, 2013
 *      Author: erick
 */
#include "MCU_init.h"

void init()
{
	/** Inicialización de los puertos */
	ini_ports();
	
	#ifdef MCU_MKL25Z4
	/** Inicialización del pin CLKOUT (sólo tiene efecto en el KL25Z */
	ini_Clkout();
	#endif
	
	/** Inicialización del Multipurpose Clock Generator **/
	init_MCG();
		
	init_LED(BLUE);
	init_LED(RED);
	init_LED(GREEN);
	
	init_UART();	
	
}
