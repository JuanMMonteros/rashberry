#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>


int condition_end() {
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
                printf("Tecla presionada: %c\n", c);
                return 1;
            }
        } else {
            // No se presionó ninguna tecla
            return 0;
        }
    

}
