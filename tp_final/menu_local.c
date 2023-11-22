#include <stdio.h>
#include <stdlib.h>

#include "my_header.h"


int menu_local() {
    int w = 1;
    int c;
    while(w==1){
	printf("Menu principal modo local\n");
    	printf("Ingrese numero de la secuencia de luces o exit (e) para salir:\n");
    	c = read_keyboard();
    	switch (c){ //case para juego de luces o salir
					case 's':
					case 'S':
					case 'e':
					case 'E': //salir menu 
						printf("Saliendo del menu principal \n");
						w=0;
						break;
					default: 
						if ( control_leds( (int)c - 48 ) ) //llama a control leds si algo falla este debuelve 1 si todo esta ok 0 
							printf("\nUps!! esa secuencia no es ejecutable, intenta nuevamente\n\n");
						else
							clean_consol();
						break;
		}
    }

    return 0;
}


void clean_consol(){
	for (int i = 0; i < 50; ++i)
		printf("\n");
}
