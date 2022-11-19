/*Escreva um programa para ler 10 palavras. Para cada palavra lida escrever a primeira e a
última letra. Considere que cada palavra possui no máximo 30 caracteres.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	int i=0,fim;
	char palavra[30];
	
	while(i<10){
		printf("Digite a palavra %d: ",i+1);	
		scanf("%s",palavra);
		fim = strlen(palavra);
		printf("Primeiro caractere: %c. \núltimo caractere: %c.\n\n",palavra[0],palavra[fim-1]); //-1 pelo \0
	i++;
	}
	return 0;
}
