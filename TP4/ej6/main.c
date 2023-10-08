#include <stdio.h>
#include "easyPIO.h"

// Estructura para representar el campo de bits de 8 LEDs
struct LedField {
    unsigned char led1 : 1;
    unsigned char led2 : 1;
    unsigned char led3 : 1;
    unsigned char led4 : 1;
    unsigned char led5 : 1;
    unsigned char led6 : 1;
    unsigned char led7 : 1;
    unsigned char led8 : 1;
    unsigned int delay;
};

// Función para imprimir el estado de los LEDs por consola
void imprimirEstadoLEDs(struct LedField leds) {
    leds.led1 ? printf("[O]") : printf("[x]") ;
    leds.led2 ? printf("[O]") : printf("[x]") ;
    leds.led3 ? printf("[O]") : printf("[x]") ;
    leds.led4 ? printf("[O]") : printf("[x]") ;
    leds.led5 ? printf("[O]") : printf("[x]") ;
    leds.led6 ? printf("[O]") : printf("[x]") ;
    leds.led7 ? printf("[O]") : printf("[x]") ;
    leds.led8 ? printf("[O]") : printf("[x]") ;
    printf("\n");
}

// Función para imprimir el estado de los LEDs por GPIO
void GPIOEstadoLEDs(struct LedField leds) {
	digitalWrite(23,leds.led1);
	digitalWrite(24,leds.led2);
	digitalWrite(25,leds.led3);
	digitalWrite(12,leds.led4);
	digitalWrite(16,leds.led5);
	digitalWrite(20,leds.led6);
	digitalWrite(21,leds.led7);
	digitalWrite(26,leds.led8);
	sleep(delay);
}

// Función para apagar todos los LEDs por GPIO
void LEDsOFF() {
	digitalWrite(23,0);
	digitalWrite(24,0);
	digitalWrite(25,0);
	digitalWrite(12,0);
	digitalWrite(16,0);
	digitalWrite(20,0);
	digitalWrite(21,0);
	digitalWrite(26,0);
}

//funcion que produce bucle de juego de luces 
void bucleLEDs (struct LedField[] leds,int bucle){
	for (int i = 0; i < bucle; ++i)
	{
		// Llamar a la función para imprimir el estado de los LEDs por consola
	    imprimirEstadoLEDs(leds[i]);
		// Llamar a la función para imprimir el estado de los LEDs por GPIO  
	    GPIOEstadoLEDs(leds[i]);
	    if ( conditionEND() )
	    	break;
	}
}


// consulata la condicion para terminar el bucle
int conditionEND(){
	return 0;
}

int main() {

	pioInit();
	pinMode(23,OUTPUT);
	pinMode(24,OUTPUT);
	pinMode(25,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(16,OUTPUT);
	pinMode(20,OUTPUT);
	pinMode(21,OUTPUT);
	pinMode(26,OUTPUT);

    // Crear un campo de bits de 8 LEDs
    struct LedField leds;

    // Simular el estado de los LEDs (0 para apagado, 1 para encendido)
    leds.led1 = 1;
    leds.led2 = 0;
    leds.led3 = 1;
    leds.led4 = 0;
    leds.led5 = 1;
    leds.led6 = 0;
    leds.led7 = 1;
    leds.led8 = 0;
    leds.delay = 10;

    // Llamar a la función para imprimir el estado de los LEDs  
    imprimirEstadoLEDs(leds);

    // Llamar a la función para imprimir el estado de los LEDs por GPIO
    GPIOEstadoLEDs(leds);

    // Llamar a la función para apagar los LEDs antes de salir
    LEDsOFF();
    return 0;
}