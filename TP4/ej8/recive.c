#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",11200);
int caracter;
serialFlush(serial_port);
delay(10);
  while(1){
    caracter=serialGetchar(serial_port);
    if(caracter != -1){
      serialFlush(serial_port);
      printf("%d\n",caracter);
    }
  }
serialClose(serial_port);
 return 0;
}
