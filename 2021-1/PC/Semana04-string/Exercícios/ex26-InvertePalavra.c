/*26. Escreva um programa para ler 10 palavras 
(considere que cada palavra possui no máximo 30 caracteres). 
Copiar para outra string cada palavra informada de forma que ela fique com os
caracteres na ordem inversa. Escrever a string com a palavra invertida.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main () {
	int i=0,j=0,tam;
	char palavra[30],invertida[30];
		
	while(j<5){
		printf("Digite a palavra %d: ",j+1);	
		fgets(palavra, 30, stdin);
		
		tam = strlen(palavra);
		
		for(i=0;i<=tam;i++){
				invertida[i] = palavra[tam-i];
			}

	for(i=0;i<=tam;i++){printf("%c",invertida[i]);}
	printf("\n");
	j++;
	}
	return 0;
}
