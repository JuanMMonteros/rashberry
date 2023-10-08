#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "easyPIO.H"
// Define los pines GPIO para las luces
#define LIGHT_PIN_1 2
#define LIGHT_PIN_2 3
#define LIGHT_PIN_3 4

// Definición de los campos de bits para representar un paso en la secuencia
typedef struct {
    unsigned int encender_1 : 1;
    unsigned int encender_2 : 1;
    unsigned int encender_3 : 1;
    unsigned int duracion : 29; // Para representar la duración en microsegundos
} Paso;

// Función para verificar si se ha presionado una tecla
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main() {
    // Configura los pines GPIO como salidas para las luces (reemplaza esto por tu configuración)
    // ...

	
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


    printf("Presiona cualquier tecla para detener la secuencia...\n");

    Paso secuencia[] = {
        {1, 0, 0, 250000},  // Enciende la luz 1 durante 0.25 segundos
        {0, 0, 0, 250000},  // Apaga la luz 1 durante 0.25 segundos
        {1, 0, 0, 250000},  // Enciende la luz 1 durante 0.25 segundos
        {0, 0, 0, 250000},  // Apaga la luz 1 durante 0.25 segundos
        // Agrega más pasos según sea necesario para la secuencia completa
    };

    while (!kbhit()) {
        for (int i = 0; i < sizeof(secuencia) / sizeof(secuencia[0]); i++) {
            // Enciende o apaga las luces según los campos de bits
            if (secuencia[i].encender_1) {
                // Enciende la luz 1 (reemplaza esto por tu código específico)
                printf("Encendiendo luz 1 en el paso %d\n", i + 1);
            } else {
                // Apaga la luz 1 (reemplaza esto por tu código específico)
                printf("Apagando luz 1 en el paso %d\n", i + 1);
            }
            usleep(secuencia[i].duracion);

            // Puedes repetir el proceso para encender o apagar las otras luces (encender_2 y encender_3)
        }
    }

    // Limpieza: Apaga todas las luces
    // ...

    return 0;
}