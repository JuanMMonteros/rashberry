#include <stdio.h>
#include <wiringPi.h>
#define M 1

#include "my_header.h"

void act_time();
void text_remote(int vel,char *name );

int timec=0; //variable global tiempo

void jump_remote(int vel){
	timec = adc_load(); //carga timeb con el valor del adc para iniciar
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		int k=7;
		for(int i=0; i<8; i++){
			if(i!=4){
				act_time_remote();
				text_remote(vel,"jump");
				
				digitalWrite(led[i],1);
				delay((vel+timec)*M);
				digitalWrite(led[i],0);
			}
			if(condition_end_remote() )
				return;
			digitalWrite(led[k],1);
			delay((vel+timec)*M);
			digitalWrite(led[k],0);
			k--;
			if(condition_end_remote() )
				return;
		}
	}
}
	
void bounce_remote(int vel){
	timec = adc_load(); //carga timeb con el valor del adc para iniciar
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		for (int i=0; i<8; i++){
			for(int j=(8-i);j>0; j--){
				act_time_remote();
				text_remote(vel,"bounce");
				
				digitalWrite((led[j]-1),1);
				delay((vel+timec)*M);
				digitalWrite((led[j]-1),0);
				if(condition_end_remote() )
					return;
			}
			for(int k=0; k<(7-i);k++){
				act_time_remote();
				text_remote(vel,"bounce");
				
				digitalWrite(led[k],1);
				delay((vel+timec)*M);
				digitalWrite(led[k],0);
				if(condition_end_remote() )
					return;
			}
		}
	}
}


void act_time_remote(){
	refresh (); //lee remoto y actualiza
	//ajuste tiempo para los delays
	timec += up_dw_remote();
	if(timec<0)       //limita a numeros positivos
		timec=0;
}


void text_remote(int vel,char *name ){
	static int tem;  //genera un retardo no activo para evitar parpadeos en consola
	if( tem>20 | timec>30 ){ //si los dileys son largos el retardo desaparese
		tem = 0;
		clean_consol();
		printf("Juego de luces por algoritmo - %s \n",name);
		printf("Control remoto\n");
		printf("delay = %d mS\n",(vel+timec));
	}
	tem++;
}


