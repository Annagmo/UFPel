/*Escreva um programa para ler 5 frases (considere que cada frase possui no máximo 70
caracteres). Converter todas as letras minúsculas existentes na frase (somente as letras
minúsculas) para maiúsculas. Imprimir cada frase após a conversão.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main () {
	int i=0,j=0,tam;
	char palavra[30];
	
	while(j<5){
		printf("Digite a palavra %d: ",j+1);	
		fgets(palavra, 30, stdin);
		
		tam = strlen(palavra);
		for(i=0;i<tam;i++)(palavra[i]= toupper(palavra[i]));
		
		for(i=0;i<tam;i++){printf("%c",palavra[i]);	}
	j++;
	}
	return 0;
}

