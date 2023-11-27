#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
char caracter;
  while(1){
   //delay(10);
    caracter=serialGetchar(serial_port);
    if((int)caracter != -1){
      //serialFlush(serial_port);
      printf("%d\n",(int)caracter);
    }
  }
serialClose(serial_port);
 return 0;
}
