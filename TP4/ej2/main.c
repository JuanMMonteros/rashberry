#include <stdio.h>

extern void retardo(unsigned long int a);

int main() {
    printf("Mensaje 1\n");
    retardo(1000000000); // Retardo de 1 segundo aproximadamente
    
    printf("Mensaje 2\n");
    retardo(500000000); // Retardo de 0.5 segundos aproximadamente
    
    printf("Mensaje 3\n");
    retardo(2000000000); // Retardo de 2 segundos aproximadamente
    
    return 0;
}
