#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//#include <unistd.h>

#include "my_header.h"

extern char inttochar (int); //funcion de ensamblador que combierte numeros del 0 al 9 en chars 

int time=0; //variable global tiempo

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
    printf(" delay=%dmS \n",(leds.delay + time) );
}

// Función para imprimir el estado de los LEDs por GPIO
void GPIOEstadoLEDs(struct LedField leds) {
	digitalWrite(4,leds.led1);
	digitalWrite(5,leds.led2);
	digitalWrite(6,leds.led3);
	digitalWrite(26,leds.led4);
	digitalWrite(27,leds.led5);
	digitalWrite(28,leds.led6);
	digitalWrite(29,leds.led7);
	digitalWrite(25,leds.led8);
	delay(leds.delay + time );
}

// Función para apagar todos los LEDs por GPIO
void LEDsOFF() {
	digitalWrite(4,0);
	digitalWrite(5,0);
	digitalWrite(6,0);
	digitalWrite(26,0);
	digitalWrite(27,0);
	digitalWrite(28,0);
	digitalWrite(29,0);
	digitalWrite(25,0);
}



//funcion que produce bucle de juego de luces 
void bucleLEDs (struct LedField *leds,int bucle){
	int w=1;
        while(w){
		for (int i = 0; i < bucle; ++i){
			//ajuste tiempo para los delays
			time += up_dw();
			if(time<0)       //limita a numeros positivos
				time=0;

			printf("(f) finalizar |(p) pausa | flechas tiempo    ");
                	// Llamar a la función para imprimir el estado de los LEDs por consola
            		imprimirEstadoLEDs(leds[i]);
                	// Llamar a la función para imprimir el estado de los LEDs por GPIO  
            		GPIOEstadoLEDs(leds[i]);
	    		if( condition_end() ){   //sale del bucle
				w=0;
				break;
			}
                }
         }
}

//estado correcto de pines GPIO
void pinINIT(){
    wiringPiSetup();
        pinMode(4,OUTPUT);
        pinMode(5,OUTPUT);
        pinMode(6,OUTPUT);
        pinMode(26,OUTPUT);
        pinMode(27,OUTPUT);
        pinMode(28,OUTPUT);
        pinMode(29,OUTPUT);
        pinMode(25,OUTPUT);
}


int control_leds_file(int number){

    char file_name [6]="1.txt";
    file_name[0]= inttochar(number);

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

    bucleLEDs (leds,numElementos);

    // Libera la memoria utilizada para el vector
    free(leds);

    // Llamar a la función para apagar los LEDs antes de salir
    LEDsOFF();


    return 0;
}

int control_leds(int number){
	 pinINIT();
     time = adc_load();
	switch(number){
		case 1:jump(20);
			break;
		case 2:bounce(20);
			break;
		default: return control_leds_file(number);
	}
	// Llamar a la función para apagar los LEDs antes de salir
	LEDsOFF();
	return 0;
}
