#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include "my_header.h"



int sync(){
  int fd= serialOpen("/dev/serial0",9600);
  char test='T';
  serialPutchar(fd,test);
  if(test==serialGetchar (fd)){
  fflush (fd) ;
  return 0;
  }else 
  return 1;
}
  

