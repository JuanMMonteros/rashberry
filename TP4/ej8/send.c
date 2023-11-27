#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
serialFlush(serial_port);
deley(10);
char caracter ='A';
for(int i=0;i<24;i++){
serialPutchar(serial_port,caracter);
delay(10);
}
serialClose(serial_port);
 return 0;
}
