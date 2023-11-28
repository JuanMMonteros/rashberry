#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include "my_header.h"

int fd;
char status;

void serialInit(){
  fd= serialOpen("/dev/serial0",9600);
  serialFlush(fd);
}
 void send(char caracter){
  serialPutchar(fd,caracter);
 }

 char recive(){
  char caracter=serialGetchar(fd);
 }
 


void refresh (){
  status = recive();
}


int condition_end_remote(){
    switch( status ){
        case 'f': 
        case 'F': return 1; //condicion salir juego luces
        default: return 0;
    }
}

//detecta flechas arriba o abajo para cambiar tiempo
int up_dw_remote(){
            switch( status ){
                case 'A': return 10;//up
                case 'B': return -10; //Dw
                default: return 0;
            }
    return 0;
}
