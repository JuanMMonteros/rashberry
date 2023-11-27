#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include "my_header.h"

int fd;
char status;

int sync(){
  fd= serialOpen("/dev/serial0",9600);
  char test='T';
  char recive;
  serialPutchar(fd,test);
  recive=serialGetchar(fd);
  if(test==recive){
  serialFlush(fd);
  printf("Anda Gods\n");
  return 0;
  }else{
     serialFlush(fd);
    printf("el Caracter Recivido fue %c ",recive);
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
password[i]=recive();}
serialFlush(fd);
}

void refresh (){
  Status = recive();
}


int condition_end_remote(){
    switch( Status ){
        case 'f': 
        case 'F': return 1; //condicion salir juego luces
        default: return 0;
    }
}

//detecta flechas arriba o abajo para cambiar tiempo
int up_dw_remote(){
            switch( Status ){
                case 'A': return 10;//up
                case 'B': return -10; //Dw
                default: return 0;
            }
    return 0;
}
