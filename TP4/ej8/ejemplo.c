#include <wiringSerial.h>
#include <stdio.h>

int main() {
    int serial_port;
    char serial_data;

    if ((serial_port = serialOpen("/dev/ttyS0", 9600)) < 0) {
        fprintf(stderr, "Error al abrir el puerto serial\n");
        return 1;
    }

    serialPuts(serial_port, "Hola desde Raspberry Pi 4\n");

    while (1) {
        if (serialDataAvail(serial_port)) {
            serial_data = serialGetchar(serial_port);
            printf("Carácter recibido: %c\n", serial_data);
        }
        serialFlush(serial_port);
    }

    return 0;
}
