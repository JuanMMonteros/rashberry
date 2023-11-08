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
int caracter[20];
for(int i=0;;i++){
if(caracter[i]!='\0'){
caracter[i]=serialGetchar(serial_port);
printf("%c",caracter[i]);}
else {
printf("\n");
i=20;
}
}
 return 0;
}
