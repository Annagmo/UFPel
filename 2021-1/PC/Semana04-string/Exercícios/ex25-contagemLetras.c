/*Escreva um programa para ler 10 palavras 
(considere que cada palavra possui no máximo 30 caracteres). 
Contar e escrever a frequência de cada caractere presente nestas palavras.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main () {
	int i=0,j=0,k=0,tam;
	char palavra[30],alfabeto[] = "abcdefghijklmnopqrstuvwxyz",contagem[27];
	
	for(i=0;i<27;i++){contagem[i]=0;}
		
	while(j<5){
		printf("Digite a palavra %d: ",k+1);	
		fgets(palavra, 30, stdin);
		
		tam = strlen(palavra);
		for(j=0;j<27;j++){
			for(i=0;i<tam;i++){
				if(palavra[i]==alfabeto[j]){contagem[j]++;}
			}
		}
	for(i=0;i<26;i++){printf("%c:%d\n",alfabeto[i],contagem[i]);}
	k++;
	}
	return 0;
}
