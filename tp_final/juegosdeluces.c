#include <stdio.h>
#include <wiringPi.h>
#define M 1

#include "my_header.h"

void act_time();

int timeb=0; //variable global tiempo

void jump(int vel){
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		int k=7;
		for(int i=0; i<8; i++){
			if(i!=4){
				act_time();
				
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
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		for (int i=0; i<8; i++){
			for(int j=(8-i);j>0; j--){
				act_time();
				
				digitalWrite((led[j]-1),1);
				delay((vel+(vel_flecha))*M);
				digitalWrite((led[j]-1),0);
				if(condition_end() )
					return;
			}
			for(int k=0; k<(7-i);k++){
				act_time();
				
				digitalWrite(led[k],1);
				delay((vel+(vel_flecha))*M);
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
	


