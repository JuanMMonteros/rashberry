#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

int main() {
    struct termios old_term, new_term;
    tcgetattr(STDIN_FILENO, &old_term);
    new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO); // Deshabilita el modo canónico y eco
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

    fd_set rfds;
    struct timeval tv;
    int retval;

    while (1) {
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
                printf("Tecla presionada: %c\n", c);
                // Realiza acciones necesarias con 'c'
            }
        } else {
            // No se presionó ninguna tecla
            printf("nada che");
            // Realiza otras tareas
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old_term); // Restaura la configuración del terminal
    return 0;
}
