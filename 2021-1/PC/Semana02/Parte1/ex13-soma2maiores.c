/*13. Escreva um programa para ler 3 valores e escrever a soma dos 2 maiores. Considere que o
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
		if(num2>num3){printf("Os maiores números são: %d e %d, a soma é: %d",num1,num2,num1+num2);}
		else printf("Os maiores números são: %d e %d, a soma é: %d",num1,num3,num1+num3);
	}
	else if(num2>num1 && num2>num3){
		if(num1>num3){printf("Os maiores números são: %d e %d, a soma é: %d",num2,num1,num1+num2);}
		else printf("Os maiores números são: %d e %d, a soma é: %d",num2,num3,num2+num3);
		}
	else if(num3>num2 && num3>num1){
		if(num2>num1){printf("Os maiores números são: %d e %d, a soma é: %d",num3,num2,num2+num3);}
		else printf("Os maiores números são: %d e %d, a soma é: %d",num3,num1,num1+num3);
		}
	return 0;
}


