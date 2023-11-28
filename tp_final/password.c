#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "my_header.h"

#define MAX_PASSWORD_LENGTH 6 // Incluye el carácter nulo '\0'

int password() {
    char password[MAX_PASSWORD_LENGTH];
    char correctPassword[MAX_PASSWORD_LENGTH] = "12345"; // Cambia esto a tu contraseña correcta
    char c;
    int i = 0;
    int attempts = 3; // Número de intentos permitidos

   

    while (attempts > 0) {
        printf("Ingrese su contraseña de 5 dígitos: ");
        i = 0;

        while (1) {
            c = getchar();

            if (c == '\n') {
                password[i] = '\0';
                break;
            } else if (c == 127 && i > 0) { // Tecla Backspace (borrar)
                putchar('\b');  // Retrocede un caracter
                putchar(' ');   // Borra el caracter
                putchar('\b');  // Retrocede otro caracter
                i--;
            } else if (i < MAX_PASSWORD_LENGTH - 1) {
                password[i] = c;
                putchar('*');
                i++;
            }
        }

        printf("\n");

        if (strcmp(password, correctPassword) == 0) {
            printf("Bienvenido al Sistema.\n");
            break; // Contraseña correcta, salimos del bucle
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Contraseña no válida. Te quedan %d intentos.\n", attempts);
            } else {
                printf("Contraseña no válida. Se han agotado los intentos.\n");
                return 0;
            }
        }
    }

    return 1;
}
