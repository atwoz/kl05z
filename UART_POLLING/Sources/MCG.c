
#include "MCG.h"

/**	La configuraci�n del MCG se realiza en los registros MCG_Cx.
  * En este ejemplo configuraremos el micro para trabajar usando el oscilador
  * interno que tiene de 4MHz. Sin embargo, es importante recordar que la 
  * frecuencia del micro puede obtenerse a trav�s de tres m�todos. La primera
  * es usando directamente el oscilador interno lento (32 kHz), usando el osc.
  * interno r�pido (4MHz)  y que apartir de este podemos obtener frecuencias
  * m�s bajas al dividirlo, y la �ltima opci�n es usar el m�dulo FLL, el cual 
  * puede generar el reloj de otras maneras, como es multiplicando la frec. de
  * 32 kHz por distintos factores definidos, o podemos usar un oscilador externo
  * al micro como referencia.
  */
void init_MCG()
{
	/* Primero seleccionamos la referencia interna y habilitamos la se�al MCGIRCLK, ya 
	 * que esta es usada por otros m�dulos como es la UART0 
	 */
 	MCG_C1 = (MCG_C1_CLKS(1)|MCG_C1_IRCLKEN_MASK);
 	
 	/* Especificamos que el reloj de 4MHz se queda as� (no se divide para obtener una
   	 * frecuencia m�s baja).
   	 */
   	MCG_SC &= MCG_SC_FCRDIV(0);
   	
 	/* Seleccionamos el oscilador interno de 4 MHz. */
   	MCG_C2 |= MCG_C2_IRCS_MASK;
   	
   	/* Establecemos que el reloj seleccionado (System clock)(en este caso el de 4MHz) se
   	 *  divide por 1 (es decir, queda intacto, ya que podr�a dividirse a�n m�s.*/
   	SIM_CLKDIV1 = 0;
}




