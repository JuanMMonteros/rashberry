#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
if((serial_port = serialOpen("/dev/serial0",9600)<0))
return 0;
serialFlush(serial_port);
unsigned char caracter =65;
serialPutchar(serial_port,caracter);
 return 0;
}
