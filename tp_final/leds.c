#include <wiringPi.h>
int leds[8]={16,18,22,32,36,38,40,37};
int main(){
wiringPiSetup();
for(int i=0;i<8;i++){
pinMode(leds[i],OUTPUT);}
for(int=0;i<8;i++){
digitalWrite(leds[i],1);}
return 0;
}
