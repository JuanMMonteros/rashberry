#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main()
{
    int serial_port;
    char dat;

    if ((serial_port = serialOpen("/dev/serial0", 9600)) < 0)
    {
        fprintf(stderr, "No pudo abrirse el dispositivo serie: %s\n", strerror(errno));
        return 1;
    }

    if (wiringPiSetup() == -1)
    {
        fprintf(stdout, "No pudo comenzar wiringPi: %s\n", strerror(errno));
        return 1;
    }

    printf("------- Envía un carácter a la Raspberry Pi -------\n");
    printf("Escribe un carácter y presiona Enter. Ctrl+C para salir.\n");

    while (1)
    {
        char input;
        if (scanf(" %c", &input) == 1)
        {
            serialPutchar(serial_port, input);
        }
    }

    return 0;
}
