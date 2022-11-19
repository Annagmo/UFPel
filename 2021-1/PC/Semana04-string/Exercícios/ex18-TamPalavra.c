/*18. Escreva um programa para ler 10 palavras. Para cada palavra lida escrever a quantidade de
caracteres existentes na palavra. Considere que cada palavra possui no máximo 30
caracteres.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	int i=0;
	char palavra[30];
	
	while(i<10){
		printf("Digite a palavra %d: ",i+1);	
		scanf("%s",palavra);
		printf("A palavra tem %ld caracteres.\n\n",strlen(palavra));
	i++;
	}
	return 0;
}
