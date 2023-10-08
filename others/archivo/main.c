#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura LedField
struct LedField {
    unsigned char led1 : 1;
    unsigned char led2 : 1;
    unsigned char led3 : 1;
    unsigned char led4 : 1;
    unsigned char led5 : 1;
    unsigned char led6 : 1;
    unsigned char led7 : 1;
    unsigned char led8 : 1;
    unsigned int delay;
};

int main() {
    // Abre el archivo en modo lectura
    FILE *archivo = fopen("leds.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return 1;
    }

    // Determina cuántas líneas hay en el archivo (cada línea representa un elemento)
    int numElementos = 0;
    char ch=0;
	while((ch=fgetc(archivo)) != 255){  //255=EOF
		if(ch=='\n')
			numElementos++;
	}    
    
    // Vuelve al inicio del archivo
    fseek(archivo, 0, SEEK_SET);

    // Crea un vector para almacenar los elementos
    struct LedField *leds = (struct LedField *)malloc(numElementos * sizeof(struct LedField));
    if (leds == NULL) {
        printf("Error al asignar memoria para el vector");
        fclose(archivo);
        return 1;
    }

    // Variables temporales para leer los valores
    unsigned char led[8];
    unsigned int delay;

    // Lee los datos desde el archivo y carga en el vector
    for (int i = 0; i < numElementos; i++) {
        if (fscanf(archivo, "%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %u",
                   &led[0], &led[1], &led[2], &led[3],
                   &led[4], &led[5], &led[6], &led[7],
                   &delay) != 9) {
            printf("Error al leer los datos del archivo");
            free(leds);
            fclose(archivo);
            return 1;
        }

        // Asigna los valores leídos a la estructura correspondiente en el vector
        leds[i].led1 = led[0];
        leds[i].led2 = led[1];
        leds[i].led3 = led[2];
        leds[i].led4 = led[3];
        leds[i].led5 = led[4];
        leds[i].led6 = led[5];
        leds[i].led7 = led[6];
        leds[i].led8 = led[7];
        leds[i].delay = delay;

        // Para verificar la lectura, puedes imprimir los valores leídos
        printf("Elemento %d: led1=%d, led2=%d, led3=%d, led4=%d, led5=%d, led6=%d, led7=%d, led8=%d, delay=%u\n",
               i, leds[i].led1, leds[i].led2, leds[i].led3, leds[i].led4,
               leds[i].led5, leds[i].led6, leds[i].led7, leds[i].led8, leds[i].delay);
    }

    // Cierra el archivo
    fclose(archivo);

    // Ahora el vector "leds" contiene los datos leídos desde el archivo

    // Puedes realizar operaciones con los datos aquí

    // Libera la memoria utilizada para el vector
    free(leds);

    return 0;
}
