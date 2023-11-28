#include <stdio.h>
#include <stdlib.h>

#include "my_header.h"


int menu_remoto() {
	printf("Bienvenido al mode Remoto");
	maestro();
	return 0;
}
    
int esclavo(){
     int w = 1;
    char c=-1;
    while(w==1){
	printf("Menu Exclavo\n");
	while(c ==-1 || c>200){
    	c = recive();}
    	switch (c){ //case para juego de luces o salir
					case 's':
					case 'S':
					case 'e':
					case 'E': //salir menu 
						printf("Saliendo del menu principal \n");
						w=0;
						break;
					default: 
						if ( control_leds_remote(c)) //llama a control leds si algo falla este debuelve 1 si todo esta ok 0 
							printf("\nUps!! esa secuencia no es ejecutable, intenta nuevamente\n\n");
						else
							clean_consol();
						break;
		}
    }
}


int maestro(){
     int w = 1;
    int c;
    while(w==1){
	printf("Menu Maestro\n");
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
						if(c>47&&c<57){
						send(c);}
						else{
							printf("opcion no valida");
						}
						
						clean_consol();
						}
						w=0;
						break;
		}
    }

    return 0;
}

