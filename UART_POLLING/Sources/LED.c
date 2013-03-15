/*
 * LED.h
 *
 *  Created on: Mar 13, 2013
 *      Author: Arteko
 */
#include "LED.h"

#ifdef MCU_MKL25Z4

/** Configuración de LEDs para el KL25Z **/

void init_LED(int color) 
{
	switch(color)
	{
		case GREEN:
			  /* Configure pin as output */
			  GPIOB_PDDR |= GPIO_PDDR_PDD(1<<19);                                                   
		
			  /* Set initialization value */
			  GPIOB_PDOR &= (uint32_t)~(GPIO_PDOR_PDO(1<<19));                                                   
		
			  /* Initialization of Port Control register */
			  /* 31–25  Reserved  0000000
			   * 24 Interrupt Status Flag 0
			   * 23–20 Reserved 0000
			   * 19–16 Interrupt Configuration 0000
			   * 15–11 Reserved 00000
			   * 10-8 Pin Mux Control 001 ( 000 Analógico, 001 Digital)
			   * 7 Reserved 0
			   * 6 Drive Strength Enable 0 (Solo aplicable en alto a los pines PTB0, PTB1, PTA12 y PTA13) 
			   * 							These pins can be used to drive LED or power MOSFET directly.
			   * 5 Reserved 0
			   * 4 Passive Filter Enable 0	(RESET_b and PTB5 only)
			   * 3 Reserved 0
			   * 2 Slew Rate Enable 0 (Fast slew rate 0, Slow slew rate 1) 
			   * 					  (Representa la incapacidad de un amplificador para seguir variaciones
			   * 					  rápidas de la señal de entrada.)
			   * 1 Pull Enable 1	(0 not enable, 1 enabled)
			   * 					(All the pins are hard wired to be pullup except for SWD_CLK)
			   * 0 Pull Select 1  (0 pulldown, 1 pullup)				   
			   */
			  
			  PORTB_PCR19 = (PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|PORT_PCR_MUX(1));//;x0103;    
		break;
		case RED:
			  /* Configure pin as output */
			  GPIOB_PDDR |= GPIO_PDDR_PDD(1<<18);                                                   
		
			  /* Set initialization value */
			  GPIOB_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(1<<18));                                                   			
							 
			  /* Initialization of Port Control register */		 
			  PORTB_PCR18 =  (PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|PORT_PCR_MUX(1));   
		break;
		case BLUE:
			 /* Configure pin as output */
			  /* GPIOB_PDDR |= 0100|0000|0000
			   * */
			  GPIOD_PDDR |= GPIO_PDDR_PDD(1<<1);                                                   
		
			  /* Set initialization value */
			  /* GPIOB_PDOR: PDO&=~0x0400 */
			  GPIOD_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(1<<1));                                                   
		
			  /* Initialization of Port Control register */
			  /* PORTB_PCR9: ISF=0,MUX=1 */
			  PORTD_PCR1 =  (PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|PORT_PCR_MUX(1));  
		break;
	}
	Led_Off(color);
}

void Led_On(int color)
{
	switch(color)
	{
		case RED:	  /* Set Led on    */
			  GPIOB_PSOR |= (uint32_t)~(GPIO_PDOR_PDO(1<<19));
		break;
		case GREEN:   /* Set Led on   */
			  GPIOB_PSOR |= (uint32_t)~(GPIO_PDOR_PDO(1<<18));
		break;
		case BLUE:	  /* Set Led on    */
			  GPIOD_PSOR |= (uint32_t)~(GPIO_PDOR_PDO(1<<1));
		break;
				
	}
}


void Led_Off(int color)
{
	switch(color)
	{
		case RED:	  /* Set Led off   */
			  GPIOB_PSOR |= (uint32_t)(GPIO_PDOR_PDO(1<<19));
		break;
		case GREEN:   /* Set Led off   */
			  GPIOB_PSOR |= (uint32_t)(GPIO_PDOR_PDO(1<<18));
		break;
		case BLUE:	  /* Set Led off    */
			  GPIOD_PSOR |= (uint32_t)(GPIO_PDOR_PDO(1<<1));
		break;
				
	}
}


void Led_Neg(int color)
{
	switch(color)
	{
		case RED:	  
			  GPIOB_PTOR |= (uint32_t)(GPIO_PTOR_PTTO(1<<19));
		break;
		case GREEN:   
			  GPIOB_PTOR |= (uint32_t)(GPIO_PTOR_PTTO(1<<18));
		break;
		case BLUE:	  
			  GPIOD_PTOR |= (uint32_t)(GPIO_PTOR_PTTO(1<<1));
		break;
	}
}
#endif

#ifdef MCU_MKL05Z4
/** Configuración de LEDs para el KL05Z **/

void init_LED(int color) 
{
	switch(color)
	{
		case GREEN:
			  /* Configure pin as output */
			  GPIOB_PDDR |= GPIO_PDDR_PDD(1<<8);                                                   
		
			  /* Set initialization value */
			  GPIOB_PDOR &= (uint32_t)~(GPIO_PDOR_PDO(1<<8));                                                   
		
			  /* Initialization of Port Control register */
			  /* 31–25  Reserved  0000000
			   * 24 Interrupt Status Flag 0
			   * 23–20 Reserved 0000
			   * 19–16 Interrupt Configuration 0000
			   * 15–11 Reserved 00000
			   * 10-8 Pin Mux Control 001 ( 000 Analógico, 001 Digital)
			   * 7 Reserved 0
			   * 6 Drive Strength Enable 0 (Solo aplicable en alto a los pines PTB0, PTB1, PTA12 y PTA13) 
			   * 							These pins can be used to drive LED or power MOSFET directly.
			   * 5 Reserved 0
			   * 4 Passive Filter Enable 0	(RESET_b and PTB5 only)
			   * 3 Reserved 0
			   * 2 Slew Rate Enable 0 (Fast slew rate 0, Slow slew rate 1) 
			   * 					  (Representa la incapacidad de un amplificador para seguir variaciones
			   * 					  rápidas de la señal de entrada.)
			   * 1 Pull Enable 1	(0 not enable, 1 enabled)
			   * 					(All the pins are hard wired to be pullup except for SWD_CLK)
			   * 0 Pull Select 1  (0 pulldown, 1 pullup)				   
			   */
			  
			  PORTB_PCR8 = (PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|PORT_PCR_MUX(1));//;x0103;    
		break;
		case RED:
			  /* Configure pin as output */
			  GPIOB_PDDR |= GPIO_PDDR_PDD(1<<9);                                                   
		
			  /* Set initialization value */
			  GPIOB_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(1<<9));                                                   			
							 
			  /* Initialization of Port Control register */
			  /* PORTB_PCR9: ISF=0,MUX=1 */					 
			  PORTB_PCR9 =  (PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|PORT_PCR_MUX(1));   
		break;
		case BLUE:
			 /* Configure pin as output */
			  GPIOB_PDDR |= GPIO_PDDR_PDD(1<<10);                                                   
		
			  /* Set initialization value */
			  GPIOB_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(1<<10));                                                   
		
			  /* Initialization of Port Control register */
			  /* PORTB_PCR9: ISF=0,MUX=1 */
			  PORTB_PCR10 =  (PORT_PCR_PS_MASK|PORT_PCR_PE_MASK|PORT_PCR_MUX(1));  
		break;
	}
}

void Led_On(int color)
{
	switch(color)
	{
		case RED:	 
			  GPIOB_PSOR |= (uint32_t)~(GPIO_PDOR_PDO(1<<8));
		break;
		case GREEN:   
			  GPIOB_PSOR |= (uint32_t)~(GPIO_PDOR_PDO(1<<9));
		break;
		case BLUE:	  
			  GPIOB_PSOR |= (uint32_t)~(GPIO_PDOR_PDO(1<<10));
		break;
				
	}
}


void Led_Off(int color)
{
	switch(color)
	{
		case RED:	  
			  GPIOB_PSOR |= (uint32_t)(GPIO_PDOR_PDO(1<<8));
		break;
		case GREEN:   
			  GPIOB_PSOR |= (uint32_t)(GPIO_PDOR_PDO(1<<9));
		break;
		case BLUE:	  
			  GPIOB_PSOR |= (uint32_t)(GPIO_PDOR_PDO(1<<10));
		break;
				
	}
}


void Led_Neg(int color)
{
	switch(color)
	{
		case RED:	 
			  GPIOB_PTOR |= (uint32_t)(GPIO_PTOR_PTTO(1<<8));
		break;
		case GREEN:  
			  GPIOB_PTOR |= (uint32_t)(GPIO_PTOR_PTTO(1<<9));
		break;
		case BLUE:	  
			  GPIOB_PTOR |= (uint32_t)(GPIO_PTOR_PTTO(1<<10));
		break;
	}
}
#endif


