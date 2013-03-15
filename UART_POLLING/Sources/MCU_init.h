/*
 * MCU_init.h
 *
 *  Created on: Mar 14, 2013
 *      Author: erick
 */

#ifndef MCU_INIT_H_
#define MCU_INIT_H_

#include "LED.h"
#include "MCG.h"
#include "UART.h"
#include "Puertos.h"

 /* Esta funci�n realiza una serie de pasos para configurar al microcontrolador.
 * Esta funci�n fue desarrollada para hacer ajustes al MCG, a la inicializaci�n
 * de puertos, de LEDs, y de la UART.
 */
void init();

#endif /* MCU_INIT_H_ */
