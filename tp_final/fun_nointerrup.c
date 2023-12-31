#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

#include "my_header.h"

//esta funcion lee un caracter sin espera activa
char key_ni() {
    fd_set rfds;
    struct timeval tv;
    int retval;

        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);

        tv.tv_sec = 0;
        tv.tv_usec = 0;

        retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
        if (retval == -1) {
            perror("select()");
        } else if (retval) {
            if (FD_ISSET(STDIN_FILENO, &rfds)) {
                char c;
                read(STDIN_FILENO, &c, 1);
               //printf("Tecla presionada: %c\n", c);
                return c;
            }
        } else {
            // No se presionó ninguna tecla
            return 0;
        }
    

}


int condition_end(){
    //printf("  presione (f) finalizar | flechas tiempo    ");
    switch( key_ni()){
        case 'f': 
        case 'F': return 1; //condicion salir juego luces
        case 'p': 
        case 'P': printf("\nprecione cualquier tecla para continuar \n"); //condicion pausa
                  getchar();//espera a tecla precionada si o si
                  printf("Programa continuado \n");
        default: return 0;
    }
}

//detecta flechas arriba o abajo
int up_dw(){
        if(key_ni()=='['){
            switch( key_ni() ){
                case 'A': return 10;//up
                case 'B': return -10; //Dw
                default: return 0;
            }
        }
    return 0;
}


