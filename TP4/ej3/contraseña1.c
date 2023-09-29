#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 6 // Incluye el carácter nulo '\0'

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char correctPassword[MAX_PASSWORD_LENGTH] = "12345"; // Cambia esto a tu contraseña correcta
    char c;
    int i = 0;
    int attempts = 3; // Número de intentos permitidos

    struct termios term_orig;

    // Configura la estructura termios para deshabilitar el modo canónico
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term_orig = term;
    term.c_lflag &= ~(ECHO | ICANON);
    term.c_cc[VMIN] = 1;  // Lee un carácter a la vez
    term.c_cc[VTIME] = 0; // Sin tiempo de espera

    while (attempts > 0) {
        tcsetattr(STDIN_FILENO, TCSANOW, &term); // Configura el modo sin eco
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

        tcsetattr(STDIN_FILENO, TCSANOW, &term_orig); // Restaura el modo de entrada original
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
            }
        }
    }

    return 0;
}


