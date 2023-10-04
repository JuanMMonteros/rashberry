#include "easyPIO.h"
#include <stdio.h>

int main(void){

pioInit();
//entradas
pinmode(5,INPUT);
pinmode(6,INPUT);
pinmode(13,INPUT);
pinmode(19,INPUT);
//salidas
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(12,OUTPUT);
pinMode(16,OUTPUT);
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(26,OUTPUT);

digitalWrite(23, digitalRead(5));
digitalWrite(24, digitalRead(6));
digitalWrite(25, digitalRead(13));
digitalWrite(12, digitalRead(19));


}
