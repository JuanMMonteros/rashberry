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
	if( password() ){
        	control_leds(8);
	}

	//antes de salir retorna modo de consola
    tcsetattr(STDIN_FILENO, TCSANOW, &term_orig); // Restaura el modo de entrada original

    return 0;
}
