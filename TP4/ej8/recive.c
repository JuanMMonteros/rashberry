#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;

serial_port = serialOpen("/dev/serial0",9600);
seriaFlush(serial_port);
char caracter;
caracter=serialGetchar(serial_port);
printf("%c",caracter);
serialFlush();
 return 0;
}
