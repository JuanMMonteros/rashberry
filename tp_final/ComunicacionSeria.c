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
  fflush (fd) ;
  printf("Error\n");
  return 0;
  }else 
  return 1;
}
  

