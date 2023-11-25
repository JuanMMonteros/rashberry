#include <stdio.h>
#include <stdlib.h>

#include "my_header.h"


int menu_remoto() {
    printf("Prueba de comunicacion\n");
    if(sync()!=0){
        printf("Error de comunicacion\n");
        return 1;
    }
    printf("Comunicacion Exitosa\n");
    return 0;
}