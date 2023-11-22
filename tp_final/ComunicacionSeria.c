#include <stdio.h>
#include <wiringPi.h>
#include <wirinfPiSerial.h>

void ModoRemoto();
void ModoLocal();
int main void(){
int selMod;
WiringPiSetup();
printf("En que modo deseas trabajar\n0:Modo Remoto\n1: Modo Local");
scanf("%d",&selMod);
if(selMod)
  modoRemoto();
else
  ModoLocal();
return 0;
}
void ModoRemoto(){
int serial_port;
int luces,vel;
serial_port = serialOpen("/dev/serial0",9600);
luces = menu();

  
}
