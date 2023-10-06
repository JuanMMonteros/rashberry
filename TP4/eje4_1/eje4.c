#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// Define los pines de entrada y salida
#define INPUT_PIN 2   // Cambia estos números según tus pines GPIO
#define OUTPUT_PIN 3  // Cambia estos números según tus pines GPIO

int main() {
    // Inicializa WiringPi
    if (wiringPiSetup() == -1) {
        fprintf(stderr, "Error al inicializar WiringPi.\n");
        exit(1);
    }

    // Configura los pines como entrada y salida
    pinMode(INPUT_PIN, INPUT);
    pinMode(OUTPUT_PIN, OUTPUT);

    printf("Presiona cualquier tecla para salir...\n");

    while (1) {
        int inputValue = digitalRead(INPUT_PIN); // Lee el valor del pin de entrada
        digitalWrite(OUTPUT_PIN, inputValue);   // Escribe el valor leído en el pin de salida
    }

    return 0;
}

