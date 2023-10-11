#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <ncurses.h> /* libncurses5-dev */

/*
PCF8591PG.c

Instalar curses:

sudo apt-get install libncurses5-dev

Compilar:

gcc -o PCF8591PG PCF8591PG.c -lcurses -lpigpio -lpthread

Run:

sudo ./PCF8591
*/

/*
Connect Pi 3V3 - VCC, Ground - Ground, SDA - SDA, SCL - SCL.
*/

#define PCF8591_I2C_ADDR 0x48

int main(int argc, char *argv[]) {
    int i;
    int r;
    int handle;
    unsigned char command;
    unsigned char value[4];
    unsigned char str[8];
    char *filename = (char*)"/dev/i2c-1";

    int j;
    int key;

    if (gpioInitialise() < 0) return 1;

    initscr();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    printw("PCF8591, any key to quit.");

    mvaddstr(10, 0, "LDR");
    mvaddstr(12, 0, "Infrarojo");
    mvaddstr(14, 0, "Temperature");
    mvaddstr(16, 0, "Pote");

    refresh();

    handle = i2cOpen(1, PCF8591_I2C_ADDR, 0);

    while (1) {
        for (i = 0; i < 4; i++) {
            command = 0x40 | ((i + 1) & 0x03); // habilita la salida | selecciona el canal de lectura i

            i2cWriteDevice(handle, &command, 1); // escribe la palabra de control

            usleep(20000);

            value[i] = i2cReadByte(handle); // lee los datos de la entrada seleccionada

            sprintf(str, "%3d", value[i]); // imprime en pantalla el valor leído
            mvaddstr(10 + i + i, 12, str);
            value[i] = value[i] / 4;
            move(10 + i + i, 16);

            for (j = 0; j < 64; j++)
                if (j < value[i]) addch('*');
                else addch(' ');
        }

        refresh();

        key = getch();

        if (key != -1) break;
    }

    endwin();

    i2cClose(handle);

    gpioTerminate();

    return (0);
}
