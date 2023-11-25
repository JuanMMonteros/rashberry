#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include "my_header.h"



int sync(){
  int fd= serialOpen("/dev/serial0",9600);
  char test='T';
  char resive;
  serialPutchar(fd,test);
  resive=serialGetchar(fd);
  if(test==resive){
  
  serialFlush(fd);
  printf("Anda Gods\n");
  return 0;
  }else{
     serialFlush(fd);
    printf("el Caracter Recivido fue %c ",resive);
  } 

  return 1;
}
  

