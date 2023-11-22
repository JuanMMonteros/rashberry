#include <wiringPi.h>
int leds[8]={4,5,6,26,27,28,29,25};
int main(){
wiringPiSetup();
for(int i=0;i<8;i++){
pinMode(leds[i],OUTPUT);}
for(int=0;i<8;i++){
digitalWrite(leds[i],1);}
return 0;
}
