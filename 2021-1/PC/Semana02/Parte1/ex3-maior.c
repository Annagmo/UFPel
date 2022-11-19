/*Escreva um programa para ler 2 valores (considere que não serão informados valores iguais)
e escrever o maior deles.*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int num, num2;
		printf("Digite um número: ");
		scanf("%d",&num);
		printf("Digite um número: ");
		scanf("%d",&num2);
		
		if(num>num2){printf("O número %d é maior que %d",num,num2);}
		else printf("O número %d é maior que %d",num2,num);
			
	
	
return 0;	
}
