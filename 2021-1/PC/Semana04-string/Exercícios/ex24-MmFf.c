/*24. Escreva um programa para ler uma quantidade indeterminada de dupla de dados.
O primeiro elemento da dupla é um dos seguintes caracteres: 'M','m', 'F' ou 'f' 
(não é necessário validar). O segundo é uma palavra de até 30 caracteres 
(considere que ela pode conter hífen). Converta cada palavra lida para maiúscula ou
minúscula conforme o primeiro caractere (da dupla) informado seja 'M' (Maiúscula) ou
'm' (Minúscula). Imprimir cada palavra após a conversão. O programa termina 
quando o primeiro caractere informado (da dupla) for 'F' ou 'f'.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


 
int main()
{

	char *p1;
	char dupla[31];
	int continuar=1;
	char *token1,*token2;
	do {

		printf("Digite o critério e a palavra separados por ';' : ");
		fgets (dupla, 30, stdin);
		token1 = strtok(dupla, ";");
		token2 = strtok(NULL, " ");
		
		p1 = token2;
		
		if(token1[0] == 'M'){
			while (*p1){
				*p1 = toupper(*p1);
				printf("%c", *p1++); 
				}
			}
		else{printf("%s",token2);}
		if(token1[0] == 'f' || token1[0] == 'F'){continuar=0;}

	} while (continuar==1);
	return 0;
}

