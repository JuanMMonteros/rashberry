#include <stdio.h>
#include <wiringPi.h>
#define M 1000

void jump(int vel, volatile int vel_flecha, volatile int salida){
	while(salida!=1){
		int k=7;
		for(int i=0; i<8; i++){
			if(i!=4){
				digitalWrite(i,1);
				delayMicroseconds((vel+(vel_flecha))*M);
				digitalWrite(i,0);
			}
			if(salida==1)
				return;
			digitalWrite(k,1);
			delayMicroseconds((vel+(vel_flecha))*M);
			digitalWrite(k,0);
			k--;
			if(salida==1)
				return;
		}
	}
}
	
void bounce(int vel, volatile int vel_flecha, volatile int salida){
	while(salida!=1){
		for (int i=0; i<8; i++){
			for(int j=(8-i);j>0; j--){
				digitalWrite((j-1),1);
				delayMicroseconds((vel+(vel_flecha))*M);
				digitalWrite((j-1),0);
				if(salida==1)
					return;
			}
			for(int k=0; k<(7-i);k++){
				digitalWrite(k,1);
				delayMicroseconds((vel+(vel_flecha))*M);
				digitalWrite(k,0);
				if(salida==1)
					return;
			}
		}
	}
}
	


