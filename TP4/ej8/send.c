#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
unsigned char caracter;
  serialFlush(serial_port);
while(1){
 caracter = getchr();
 delay(100);
 serialPutchar(serial_port,caracter);
}
serialClose(serial_port);
 return 0;
}
