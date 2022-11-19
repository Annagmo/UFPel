/*Escreva um algoritmo para ler um número inteiro (considere que serão lidos apenas valores
positivos e inteiros) e escrever se é par ou ímpar.*/

#include <stdlib.h>
#include <stdio.h>
int main(){
	int num;
		printf("Digite um número: ");
		scanf("%d",&num);
		
		if(num%2==0){printf("O número é par.");}
		else printf("O número é impar.");
			
	
	
return 0;	
}
