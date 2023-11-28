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
	printf("Modo Esclavo - El control esta dado de manera remota\n");
	    

	while(c ==-1){ //LEE SERIAL SI CORRESPONDE
    	c = recive();}
	printf("recivido: %c\n",c);
    	switch (c){ //case para juego de luces o salir
					case 's':
					case 'S':
					case 'e':
					case 'E': //salir menu 
						printf("Saliendo del menu principal \n");
						w=0;
						break;
					default: 
						if ( control_leds_remote(c)){ //llama a control leds si algo falla este debuelve 1 si todo esta ok 0 
							printf("\nUps!! esa secuencia no es ejecutable, intenta nuevamente\n\n");
                            send('1');}
						else{
                            send('0');
                            clean_consol();}
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
						if(c>47 && c<57){
							send(c);
							menu_control_remoto();
						}
						else{
							printf("opcion no valida");
						}
						
						clean_consol();
		}
    }

    return 0;
}

int menu_control_remoto(){
	int flag=1;
	char c;
        while(flag){
		clean_consol();
		printf("(f) salir | (p) pausa | (flecha arriba) aumentar tiempo | (flecha abajo) reducir tiempo\n");
		
        
		if(!condition_end()){ //salir juego de luces
			send('F');
			//flag=0;
		}
        
        switch (up_dw()){ //case para juego de luces 
					case 10: printf("Aumentando velocidad juego de luces\n");
                             send('A');
                            break;
                    case -10: printf("Disminuye velocidad juego de luces\n");
                              send('B');
                            break;
        }


        switch (recive()){ //case para juego de luces o salir
					case 1: printf("La secuencia de luces no existe");
                            flag=0;
                            break;
                    case 0: printf("La secuencia de luces finalizo correctamente\n");
                            flag=0;
                            break;
        }



	}
}
