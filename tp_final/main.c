#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "my_header.h"



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
	
	if( password() ){ //contraseña nesesaria para ejecutar programa
		printf("Funcionamiento local (l) o remoto (r): ");
		switch ( getchar() ){ //case para modo en remoto o local
			case 'l':
			case 'L': //programa en local
				control_leds(8);
				break;
			case 'r':
			case 'R': //programa en remoto
				switch ( getchar() ){ //case para modo remoto maestro o esclavo
					case 'm':
					case 'M': //modo maestro
						printf("Dispositivo en modo maestro \n");
						break;
					case 's':
					case 'S':
					case 'e':
					case 'E': //modo esclavo
						printf("Dispositivo en modo esclavo \n");
						break;
					default: 
						printf("Opcion no valida programa terminado \n");
						break;
				}
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
