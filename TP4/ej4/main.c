#include "easyPIO.h"
#include <stdio.h>

int main(void){

pioInit();
//entradas
pinmode(29,INPUT);
pinmode(31,INPUT);
pinmode(33,INPUT);
pinmode(35,INPUT);
//salidas
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(12,OUTPUT);
pinMode(16,OUTPUT);
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(26,OUTPUT);

digitalWrite(23, digitalRead(29));
digitalWrite(24, digitalRead(31));
digitalWrite(25, digitalRead(33));
digitalWrite(12, digitalRead(35));


}
