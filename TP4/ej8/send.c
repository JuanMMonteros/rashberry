#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
serialFlush(serial_port);
unsigned char caracter =65;
serialPutchar(serial_port,caracter);
 return 0;
}
