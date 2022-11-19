/*Escreva um programa para ler 3 valores e escrever o maior deles. Considere que o usuário
não informará valores iguais.*/
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

	if(num1>num2){
		if(num1>num3){
			printf("O maior número é: %d",num1);
			}
		else{printf("O maior número é: %d",num3);}
	}
	else if(num2>num1){
		if(num2>num3){
			printf("O maior número é: %d",num2);
			}
		else{printf("O maior número é: %d",num3);}
	}
	else if(num3>num2){
		if(num3>num1){
			printf("O maior número é: %d",num3);
			}
		else{printf("O maior número é: %d",num1);}
	}

	return 0;
}

