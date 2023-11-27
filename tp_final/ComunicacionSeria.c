#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include "my_header.h"

int fd;

int sync(){
  fd= serialOpen("/dev/serial0",9600);
  char test='T';
  char resive;
  serialPutchar(fd,test);
  recive=serialGetchar(fd);
  if(test==recive){
  serialFlush(fd);
  printf("Anda Gods\n");
  return 0;
  }else{
     serialFlush(fd);
    printf("el Caracter Recivido fue %c ",resive);
  } 

  return 1;
}
 void send(char caracter){
  serialPutchar(fd,caracter);
 }

 char recive(){
  char caracter=serialGetchar(fd);
 }
 
 void sendKey(){
char *password="12345";
serialFlush(fd);
for (int i=0;i<5;i++){
send(password[i]);
delay(10);}
 }
char * reciveKey(){
char password[5];
for(int i=0;i<5;i++){
password[i]=resive();}
serialFlush(fd);
}

