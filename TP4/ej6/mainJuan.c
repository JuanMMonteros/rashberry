#include <stdio.h>
#include "EasyPio4.h"
#include <unistd.h>

// Define una estructura que contiene campos de bits para cada bit en un char
struct Byte {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
}typedef Byte;

union dato {
    char carga;
    Byte byte;
}typedef dato;

int pin[9]={23,24,25,12,16,20,21,26,17};



struct ListaLuces{
    dato luces;
    int delay } typedef ListaLuces;
    
    void inicioLuces(){
    pioInit();
	pinMode(pin[0],OUTPUT);
	pinMode(pin[1],OUTPUT);
	pinMode(pin[2],OUTPUT);
	pinMode(pin[3],OUTPUT);
	pinMode(pin[4],OUTPUT);
	pinMode(pin[5],OUTPUT);
	pinMode(pin[6],OUTPUT);
	pinMode(pin[7],OUTPUT);
	pinMode(pin[8],INPUT);
        }
    void carga (dato luz){
        digitalWrite(pin[0],luz.byte.bit0);
        digitalWrite(pin[1],luz.byte.bit1);
        digitalWrite(pin[2],luz.byte.bit2);
        digitalWrite(pin[3],luz.byte.bit3);
        digitalWrite(pin[4],luz.byte.bit4);
        digitalWrite(pin[5],luz.byte.bit5);
        digitalWrite(pin[6],luz.byte.bit6);
        digitalWrite(pin[7],luz.byte.bit7);
        }
int main (){
	inicioLuces();
    dato luz[8]={1,2,4,8,16,32,64,128};
    while(1){
        for(int i=0;i<8;i++){
            carga(luz[i]);
            usleep(1000*500);
            }
        }
	}
