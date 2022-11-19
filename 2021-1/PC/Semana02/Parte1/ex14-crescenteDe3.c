/*14. Escreva um programa para ler 3 valores e escrevê-los em ordem crescente. Considere que o
usuário não informará valores iguais.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	int num1,num2,num3;
	
	printf("Digite o primeiro numero: ");
	scanf("%d",&num1);
	printf("Digite o segundo numero: ");
	scanf("%d",&num2);
	printf("Digite o terceiro numero: ");
	scanf("%d",&num3);

	if(num1>num2 && num1>num3){
		if(num2>num3){printf("ordem crescente: %d < %d < %d",num3,num2,num1);}
		else printf("ordem crescente: %d < %d < %d",num2,num3,num1);
	}
	else if(num2>num1 && num2>num3){
		if(num1>num3){printf("ordem crescente: %d < %d < %d",num3,num1,num2);}
		else printf("ordem crescente: %d < %d < %d",num1,num3,num2);
		}
	else if(num3>num2 && num3>num1){
		if(num2>num1){printf("ordem crescente: %d < %d < %d",num1,num2,num3);}
		else printf("ordem crescente: %d < %d < %d",num2,num1,num3);
		}
	return 0;
}



