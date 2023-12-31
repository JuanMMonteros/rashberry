#include <stdio.h>
#include <wiringPi.h>
#define M 1

#include "my_header.h"

void act_time();
void text(int vel,char *name);

int timeb=0; //variable global tiempo

void jump(int vel){
	timeb = adc_load(); //carga timeb con el valor del adc para iniciar
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		int k=7;
		for(int i=0; i<8; i++){
			if(i!=4){
				act_time();
				text(vel,"jump");
				
				digitalWrite(led[i],1);
				delay((vel+timeb)*M);
				digitalWrite(led[i],0);
			}
			if(condition_end() )
				return;
			digitalWrite(led[k],1);
			delay((vel+timeb)*M);
			digitalWrite(led[k],0);
			k--;
			if(condition_end() )
				return;
		}
	}
}
	
void bounce(int vel){
	timeb = adc_load(); //carga timeb con el valor del adc para iniciar
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		for (int i=0; i<8; i++){
			for(int j=(8-i);j>0; j--){
				act_time();
				text(vel,"bounce");
				
				digitalWrite((led[j]-1),1);
				delay((vel+timeb)*M);
				digitalWrite((led[j]-1),0);
				if(condition_end() )
					return;
			}
			for(int k=0; k<(7-i);k++){
				act_time();
				text(vel,"bounce");
				
				digitalWrite(led[k],1);
				delay((vel+timeb)*M);
				digitalWrite(led[k],0);
				if(condition_end() )
					return;
			}
		}
	}
}


void act_time(){
	//ajuste tiempo para los delays
	timeb += up_dw();
	if(timeb<0)       //limita a numeros positivos
		timeb=0;
}


void text(int vel,char *name ){
	static int tem;  //genera un retardo no activo para evitar parpadeos en consola
	if( tem>20 | timeb>30 ){ //si los dileys son largos el retardo desaparese
		tem = 0;
		clean_consol();
		printf("Juego de luces por algoritmo - %s \n",name);
		printf("(f) salir | (p) pausa | (flecha arriba) aumentar tiempo | (flecha abajo) reducir tiempo\n");
		printf("delay = %d mS\n",(vel+timeb));
	}
	tem++;
}


