#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
int fd;
char recive(){
  char caracter=-1;
  int n=serialDataAvail(fd);
   if(n>0){
     do{
     caracter=serialGetchar(fd);
      n--;
     }while(!(caracter>32&&caracter<128)&& n);
     if(caracter>32&&caracter<128){
       return caracter;
       serialFlush(fd);}
     else 
       caracter = -1;
   }
  return caracter;
 }
 int main(){
wiringPiSetup();
fd = serialOpen("/dev/serial0",9600);
char c=-1;
  while(1){
    c=recive();
   if(c==-1)
      printf("%c\n",c);
  }
 return 0;
}
