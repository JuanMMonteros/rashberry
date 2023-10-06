#include "easyPIO.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Configura la terminal en modo no canónico
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Configura la entrada estándar para ser no bloqueante
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    // Restaura la configuración original de la terminal y la entrada estándar
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main(void){
pioInit();
//entradas
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(13,INPUT);
pinMode(19,INPUT);
pinMode(17,INPUT);
//salidas
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(12,OUTPUT);
pinMode(16,OUTPUT);
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(26,OUTPUT);


char a = 0;
do{
digitalWrite(25, digitalRead(5));
digitalWrite(12, digitalRead(6));
digitalWrite(16, digitalRead(13));
digitalWrite(20, digitalRead(19));
a=kbhit();
}while(!a);

return 0;
}
