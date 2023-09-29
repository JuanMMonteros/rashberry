#include "easyPIO.h"
#include <stdio.h>
void main(void){
int a, b;
int vec[3]={23,24,25};

pioInit();
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
pinMode(12,OUTPUT);
pinMode(16,OUTPUT);
pinMode(20,OUTPUT);
pinMode(21,OUTPUT);
pinMode(26,OUTPUT);

digitalWrite(23,1);
digitalWrite(24,1);
digitalWrite(25,1);
digitalWrite(12,1);
digitalWrite(16,1);
digitalWrite(20,1);
digitalWrite(21,1);
digitalWrite(26,1);
sleep(10);
digitalWrite(23,0);
digitalWrite(24,0);
digitalWrite(25,0);
digitalWrite(12,0);
digitalWrite(16,0);
digitalWrite(20,0);
digitalWrite(21,0);
digitalWrite(26,0);
} 
