#include <wiringPi.h>
int leds[8]={23,24,25,12,16,20,21,16}
int main(){
wiringPiSetup();
for(int i=0;i<8;i++){
pinMode(leds[i],OUTPUT);}
for(int=0;i<8;i++){
digitalWrite(leds[i],1);}
return 0;
}
