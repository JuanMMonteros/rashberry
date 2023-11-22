#include <stdio.h>
#include <stdlib.h>
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
	usleep(leds.delay * 1000);
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

// consulata la condicion para terminar el bucle
int conditionEND(){
        return digitalRead(17);
}


//funcion que produce bucle de juego de luces 
void bucleLEDs (struct LedField *leds,int bucle){
        while(!conditionEND()){
		for (int i = 0; i < bucle; ++i){
                	// Llamar a la función para imprimir el estado de los LEDs por consola
            		imprimirEstadoLEDs(leds[i]);
                	// Llamar a la función para imprimir el estado de los LEDs por GPIO  
            		GPIOEstadoLEDs(leds[i]);
	    		if( conditionEND() )
			break;
                }
         }
}

//estado correcto de pines GPIO
void pinINIT(){
        pioInit();
        pinMode(23,OUTPUT);
        pinMode(24,OUTPUT);
        pinMode(25,OUTPUT);
        pinMode(12,OUTPUT);
        pinMode(16,OUTPUT);
        pinMode(20,OUTPUT);
        pinMode(21,OUTPUT);
        pinMode(26,OUTPUT);
	pinMode(17,INPUT);
}


int main(){

    int juego = 8;
    char file_name [6]="1.txt";
    file_name[0]=juego;

       // Abre el archivo en modo lectura
    FILE *archivo = fopen(file_name, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return 1;
    }

    // Determina cuántas líneas hay en el archivo (cada línea representa un elemento)
    int numElementos = 0;
    char ch=0;
	while((ch=fgetc(archivo)) != 255){  //255=EOF
		if(ch=='\n')
			numElementos++;
	}    
    
    // Vuelve al inicio del archivo
    fseek(archivo, 0, SEEK_SET);

    // Crea un vector para almacenar los elementos
    struct LedField *leds = (struct LedField *)malloc(numElementos * sizeof(struct LedField));
    if (leds == NULL) {
        printf("Error al asignar memoria para el vector");
        fclose(archivo);
        return 1;
    }

    // Variables temporales para leer los valores
    unsigned char led[8];
    unsigned int delay;

    // Lee los datos desde el archivo y carga en el vector
    for (int i = 0; i < numElementos; i++) {
        if (fscanf(archivo, "%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %u",
                   &led[0], &led[1], &led[2], &led[3],
                   &led[4], &led[5], &led[6], &led[7],
                   &delay) != 9) {
            printf("Error al leer los datos del archivo");
            free(leds);
            fclose(archivo);
            return 1;
        }

        // Asigna los valores leídos a la estructura correspondiente en el vector
        leds[i].led1 = led[0];
        leds[i].led2 = led[1];
        leds[i].led3 = led[2];
        leds[i].led4 = led[3];
        leds[i].led5 = led[4];
        leds[i].led6 = led[5];
        leds[i].led7 = led[6];
        leds[i].led8 = led[7];
        leds[i].delay = delay;
    }

    // Cierra el archivo
    fclose(archivo);

    // Ahora el vector "leds" contiene los datos leídos desde el archivo

    // Realizar operaciones con los datos aquí
    pinINIT();
    bucleLEDs (leds,numElementos);

    // Libera la memoria utilizada para el vector
    free(leds);

    // Llamar a la función para apagar los LEDs antes de salir
    LEDsOFF();
    return 0;
}
