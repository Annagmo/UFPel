/*Escreva um programa para ler 2 valores (considere que não serão lidos valores iguais) e
escreve-los em ordem crescente.*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int num, num2;
		printf("Digite um número: ");
		scanf("%d",&num);
		printf("Digite um número: ");
		scanf("%d",&num2);
		
		if(num>num2){printf("ordem crescente: %d %d",num2,num);}
		else printf("ordem crescente: %d %d",num,num2);
			
	
	
return 0;	
}
