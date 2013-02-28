#MCG (Multipurpose Clock Generator)

##TODO
Poner ejemplo de la configuración del oscilador interno y externo, explicando como configurar el fll y el pll y como obtener diferentes frecuencias. 

Crear un archivo eko_mcg.c y eko_mcg.h.

eko_mcg.c
<table>
    <tr>
        <td><strong>Función</strong></td>
        <td><strong>Descripción</strong></td>
    </tr>
    <tr>
        <td>configMCG()</td>
        <td>Configura el oscilador con los #defines que estan en el header.</td>
    </tr>
    <tr>
        <td></td>
        <td></td>
    </tr>
</table>

eko_mcg.h
<table>
    <tr>
        <td><strong>#define</strong></td>
        <td><strong>Descripción</strong></td>
    </tr>
    <tr>
        <td>EKO_CORE_FOSC</td>
        <td>Frecuencia del oscilador</td>
    </tr>
    <tr>
        <td>EKO_BUS_FOSC</td>
        <td>Frecuencia del Bus</td>
    </tr>
    <tr>
        <td>EKO_USE_FLL</td>
        <td>Usar FLL</td>
    </tr>
    <tr>
        <td>EKO_USE_PLL</td>
        <td>Usar PLL (para el KL25)</td>
    </tr>
    <tr>
        <td>EKO_USE_INT_OSC</td>
        <td>Usar el oscilador interno si es verdadero</td>
    </tr>
    <tr>
        <td>EKO_USE_INT_OSC</td>
        <td>Usar el oscilador interno si es verdadero</td>
    </tr>
    <tr>
        <td>EKO_LOW_POWER_OSC</td>
        <td>Modo de bajo poder para el MCG</td>
    </tr>
</table>

NOTA: Estos solo son algunos ejemplos, en realidad debería de haber más **#defines** para abarcar toda la configuración posible. 

