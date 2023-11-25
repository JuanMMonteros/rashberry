#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
 int main(){
wiringPiSetup();
int serial_port;
serial_port = serialOpen("/dev/serial0",9600);
fflush(serial_port);
int * caracter ="Hola Mundo";

for(int i=0;i<20;i++){
serialPutchar(serial_port,caracter[i]);
serialFlush(serial_port);
delay(10);
}
 return 0;
}
