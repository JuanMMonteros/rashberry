#include <stdio.h>
#include <easyPio.h>

int main(){
char * str;
pioInit();
uardInit(9600);
getStrSeria(str);
printf("%s\n,str");
return 0;}