#include <stdio.h>
#include <termios.h>
#include <wiringSerial.h>
#include <wiringPi.h>
#include <unistd.h>
 int main(){
struct termios * term_old,term_new;
wiringPiSetup();
int serial_port;

serial_port = serialOpen("/dev/serial0",9600);
char a='a';
serialFlush(seral_port);
serialPuts(serial_port,&a);
 return 0;
}
