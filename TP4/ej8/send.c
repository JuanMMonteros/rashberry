#include <stdio.h>
#include <termios.h>
#include <wiringSerial.h>
#include <wiringPi.h>
#include <unistd.h>
 int main(){
struct termios * term_old,term_new;
wiringPiSetup();
int serial_port;

serial_port = serialOpen("/dev/tty0",9600);
tcgetattr(serial_port,term_old);
term_old->c_cflag |= CS8;
tcsetattr(serial_port,TCSANOW,term_old);
 return 0;
}
