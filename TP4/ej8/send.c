#include <stdio.h>
#include <EasyPio4.h>
 int main(){
char * str="Hola Mundo";
pioInit();
uardInit(9600);
 putStrSeria(str);
 return 0;
}