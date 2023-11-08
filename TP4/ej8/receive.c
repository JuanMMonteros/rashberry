#include <stdio.h>
#include "easyPIO.h"

int main(){
char * str;
pioInit();
uartInit(9600);
getStrSerial(str);
printf("%s\n,str");
return 0;}
