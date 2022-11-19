/*Escreva um programa para ler o ano de nascimento de uma pessoa e escrever uma
mensagem que diga se ela poderá ou não votar este ano (não é necessário considerar o mês
em que ela nasceu).*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int ano;
		printf("Digite seu ano de nascimento: ");
		scanf("%d",&ano);
		
		if((2021-ano)>16){printf("Pode votar.");}
		else printf("Não pode votar.");
			
	
	
return 0;	
}
