/*27. Escreva um programa para ler um caractere e uma a frase 
(considere que ela possui no máximo 70 caracteres). 
Retire da string que contém a frase todos os caracteres iguais ao
informado. Escrever a string que contém a frase após a retirada dos caracteres.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

	char frase[70],caractere,retirada[70];
	int i,j=0,tam;

	printf("Digite o caractere: ");
	caractere = getchar();
	getchar();
	printf("Digite a frase: ");
	fgets (frase, 70, stdin);
		
	tam = strlen(frase);
	
	for(i=0;i<=tam+1;i++){
		if(caractere != frase[i]){retirada[j] = frase[i];j++;}
	}

	for(i=0;i<=tam;i++){printf("%c",retirada[i]);}
	printf("%c",caractere);
	return 0;
}
