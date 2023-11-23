#include <stdio.h>
#include <wiringPi.h>
#define M 1

#include "my_header.h"


void jump(int vel,  int vel_flecha){
	int led[8]={4,5,6,26,27,28,29,25};
	while(1){
		int k=7;
		for(int i=0; i<8; i++){
			if(i!=4){
				digitalWrite(led[i],1);
				delay((vel+(vel_flecha))*M);
				digitalWrite(led[i],0);
			}
			if(condition_end() )
				return;
			digitalWrite(led[k],1);
			delay((vel+(vel_flecha))*M);
			digitalWrite(led[k],0);
			k--;
			if(condition_end() )
				return;
		}
	}
}
	
void bounce(int vel, volatile int vel_flecha, volatile int salida){
	int led[8]={4,5,6,26,27,28,29,25};
	while(salida!=1){
		for (int i=0; i<8; i++){
			for(int j=(8-i);j>0; j--){
				digitalWrite((led[j]-1),1);
				delay((vel+(vel_flecha))*M);
				digitalWrite((led[j]-1),0);
				if(salida==1)
					return;
			}
			for(int k=0; k<(7-i);k++){
				digitalWrite(led[k],1);
				delay((vel+(vel_flecha))*M);
				digitalWrite(led[k],0);
				if(salida==1)
					return;
			}
		}
	}
}
	


