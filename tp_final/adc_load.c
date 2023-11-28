#include <wiringPi.h>
#include <pcf8591.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

#include "my_header.h"

int adc_init = 1;

int adc_load(void) {
    int val;
    if (adc_init !=0){
        pcf8591Setup(BASE, Address);
        adc_init = 0;
    }
        val = analogRead(A3);
        return val;
}
