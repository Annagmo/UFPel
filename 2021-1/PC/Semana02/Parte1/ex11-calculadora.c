#include <stdio.h>
#include <stdlib.h>

int main () {
	int num1,num2,opcao;
	printf("Bem Vindo a calculadora LPX3000");
	
	printf("\n\nDigite o primeiro numero: ");
	scanf("%d",&num1);
	printf("Digite o segundo numero: ");
	scanf("%d",&num2);
	
	printf("\n________________________");
	printf("\n|Opções:                |");
	printf("\n|       1: soma         |");
	printf("\n|       2: subtração    |");
	printf("\n|       3: multiplicação|");
	printf("\n|       4: divisão      |");
	printf("\n|_______________________|");

	printf("\n\nDigite a opção: ");
	scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
		printf("A soma de %d e %d é: %d",num1,num2,num1 + num2);
		break;
		case 2:
		printf("A subtração de %d e %d é: %d",num1,num2,num1 - num2);
		break;
		case 3:
		printf("A multiplicação de %d e %d é: %d",num1,num2,num1 * num2);
		break;
		case 4:
		printf("A divisão de %d e %d é: %.1f",num1,num2,num1/(num2+ 0.0));
		break;
	}
	return 0;
}
