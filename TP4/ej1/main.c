#include <stdio.h>
void menu();
extern int operacion(int op,int num1, int num2);
int main(void){
	int num1,num2,op,result;
	printf("ingrese el numero 1: ");
	scanf("%d",&num1);
	printf("ingrese el numero 2: ");
	scanf("%d",&num2);
	menu();
	printf("ingrese el numero operacion: ");
	scanf("%d",&op);
	result = operacion(op,num1,num2);
	printf("\n El resultado es %d\n", result);
	return 0;
	}
	
void menu(){
	printf("0 suma\n 1 resta\n 2 and\n 3 or \n");
	}
