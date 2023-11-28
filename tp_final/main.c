#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "my_header.h"

char read_keyboard();


int main() {
struct termios term_orig;

    // Configura la estructura termios para deshabilitar el modo canónico
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term_orig = term;
    term.c_lflag &= ~(ECHO | ICANON);
    term.c_cc[VMIN] = 1;  // Lee un carácter a la vez
    term.c_cc[VTIME] = 0; // Sin tiempo de espera

    tcsetattr(STDIN_FILENO, TCSANOW, &term); // Configura el modo sin eco
	//programas aqui abajo
	sync();
	while(!read_keyboard()){
	char remote_mode=recive();
		if(remote_mode=='P')
			esclavo();
	}
	
	clean_consol();  //limpia la consola
	if( password() ){ //contraseña nesesaria para ejecutar programa
		printf("Funcionamiento local (l) o remoto (r): ");
		switch ( read_keyboard() ){ //case para modo en remoto o local
			case 'l':
			case 'L': //programa en local
				clean_consol();  //limpia la consola
				menu_local();    //llama al menu de modo local
				break;
			case 'r':
			case 'R': //programa en remoto
			    clean_consol();  //limpia la consola
				send('P');
				menu_remoto();
				printf("Funcionamiento maestro (m) esclavo (e): ");
				
				break;
			default: 
				printf("Opcion no valida programa terminado \n");
				break;
		}
	}
		
	

    //antes de salir retorna modo de consola
    tcsetattr(STDIN_FILENO, TCSANOW, &term_orig); // Restaura el modo de entrada original
    printf("\n");
    return 0;
}

//funcion que lee tecla del teclado la imprime y salta de linea 
char read_keyboard(){
	char c;
	c =  getchar();
	printf("%c \n",c);
	return c;
}
