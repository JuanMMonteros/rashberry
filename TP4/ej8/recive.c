#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
char caracter;
caracter=serialGetchar(serial_port);
printf("%c",caracter);
serialFlush(serial_port);
serialClose(serial_port);
 return 0;
}
