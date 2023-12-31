#include <stdio.h>
#include "easyPIO.h"
#include <unistd.h>

void auto_fan();

#define delay  500

int pin[9]={23,24,25,12,16,20,21,26,17};

void main() {
	
	
	pioInit();
	pinMode(pin[0],OUTPUT);
	pinMode(pin[1],OUTPUT);
	pinMode(pin[2],OUTPUT);
	pinMode(pin[3],OUTPUT);
	pinMode(pin[4],OUTPUT);
	pinMode(pin[5],OUTPUT);
	pinMode(pin[6],OUTPUT);
	pinMode(pin[7],OUTPUT);
	pinMode(pin[8],INPUT);
	
	auto_fan();
}

void auto_fan(){
	do{
		for(int i=0; i<=6; i++){
			if (digitalRead(pin[8]))
				break;
			digitalWrite(pin[i],1);
			usleep(delay*1000);
			digitalWrite(pin[i],0);
		}
		for(int j=7; j>=1; j--){
			if (digitalRead(pin[8]))
                                break;
			digitalWrite(pin[j],1);
			usleep(delay*1000);
			digitalWrite(pin[j],0);
		}
	}while(digitalRead(pin[8])==0);
}
