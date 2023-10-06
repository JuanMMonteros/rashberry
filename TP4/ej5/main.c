#include <stdio.h>
#include <easypio.h>
#include <unistd.h>

void auto_fan();

int main() {
	int pin[];
	
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	pinMode(pin[],OUTPUT);
	
	pinMode(pin[],INPUT);
	
	auto_fan();
	
	return 0;
}

void auto_fan(){
	while(digitalRead(pin[])==0){
		for(i=0, i<=6, i++){
			digitalWrite(pin[i],1);
			sleep(1);
			digitalWrite(pin[i],0);
		}
		for(j=7, j<=1, j++){
			digitalWrite(pin[j],1);
			sleep(1);
			digitalWrite(pin[j],0);
		}
	}
}
