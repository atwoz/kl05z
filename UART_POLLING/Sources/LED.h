#ifndef LED_H_
#define LED_H_

#include "derivative.h"

#define RED 1
#define BLUE 2
#define GREEN 3

/**
 * Inicialización del PIN que corresponde al color de LED seleccionado.
 * Esta biblioteca es aplicable tanto al micro KL05Z como al KL25Z.
 */
void init_LED(int color);

/**
 * Función que enciende el LED del color indicado como parámetro.
 */
void Led_On(int color);

/**
 * Función que niega el valor (On/Off) del LED indicado como parámetro.
 */
void Led_Neg(int color);


#endif /* LED_H_ */
