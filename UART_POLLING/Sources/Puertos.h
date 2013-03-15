/*
 * Puertos.h
 *
 *  Created on: Mar 14, 2013
 *      Author: Arteko
 */

#ifndef PUERTOS_H_
#define PUERTOS_H_

#include "derivative.h"

/* Habilitamos los relojes de los puertos A, B,C y D para que sus pines
 * sean funcionales.
 * Notas:
 * En el puerto B se encuentran dos LEDs. Led rojo (PTB18), Led verde (PTB19) y
 * en el D el Led azul (PTD1). (Esto es para el KL25Z)
 * El puerto C se utilizar� para poder medir la frecuencia obtenida al modificar
 * los par�metros del Multipurpose Clock Generator (MCG), ya que la se�al CLKOUT
 * puede ser medida en el pin 3 del puerto C (PTC3). (Esto aplica para el KL25Z,
 * el KL05 no tiene esta opci�n, o no en todas sus presentaciones).
 */
void ini_ports();

#ifdef MCU_MKL25Z4
void ini_Clkout();
#endif

#endif /* PUERTOS_H_ */
