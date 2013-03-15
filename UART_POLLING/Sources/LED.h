#ifndef LED_H_
#define LED_H_

#include "derivative.h"

#define RED 1
#define BLUE 2
#define GREEN 3

/**
 * Inicializaci�n del PIN que corresponde al color de LED seleccionado.
 * Esta biblioteca es aplicable tanto al micro KL05Z como al KL25Z.
 */
void init_LED(int color);

/**
 * Funci�n que enciende el LED del color indicado como par�metro.
 */
void Led_On(int color);

/**
 * Funci�n que niega el valor (On/Off) del LED indicado como par�metro.
 */
void Led_Neg(int color);


#endif /* LED_H_ */
