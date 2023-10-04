#include "easyPIO.h"
#include <stdio.h>

int main(void){

pioInit();
//entradas
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(13,INPUT);
pinMode(19,INPUT);
//salidas
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(12,OUTPUT);
pinMode(16,OUTPUT);
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(26,OUTPUT);

digitalWrite(25, digitalRead(5));
digitalWrite(12, digitalRead(6));
digitalWrite(16, digitalRead(13));
digitalWrite(20, digitalRead(19));


}
