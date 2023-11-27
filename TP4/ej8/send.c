#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
unsigned char caracter ='A';
  serialFlush(serial_port);
while(1){
 delay(100);
serialPuts(serial_port,(char *)caracter);}
serialClose(serial_port);
 return 0;
}
