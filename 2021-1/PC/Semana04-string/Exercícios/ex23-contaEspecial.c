/*Escreva um programa para ler 5 nomes (e sobrenomes) de pessoas (considere que cada
nome possui no máximo 70 letras e contém apenas letras minúsculas). Converter apenas a
inicial de cada nome para maiúscula. Imprimir cada nome após a conversão.*/
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
		palavra[0]= toupper(palavra[0]);
		for(i=1;i<tam;i++){
			if (i == 0 || palavra[i - 1] == ' '){
            	palavra[i] = toupper(palavra[i]);
            	}
        	else{
            	palavra[i] = palavra[i];
			}
		}
		for(i=0;i<tam;i++){printf("%c",palavra[i]);	}
	j++;
	}
	return 0;
}

