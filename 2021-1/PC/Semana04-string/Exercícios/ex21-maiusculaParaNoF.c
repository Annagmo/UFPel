/*21. Escreva um programa para ler uma quantidade indeterminada de palavras (considere que
cada palavra possui no máximo 30 caracteres e contém apenas letras minúsculas). Converta
todas as letras de cada palavra lida para maiúsculas. Imprimir cada palavra após a
conversão. O programa se encerra quando for digitada uma palavra que começa pela letra 'f'.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i;
	char *p1, c, s[80],primeiro;
	int continuar=1;
	do {
		p1 = s;
		i = 0;
		while ((c = getchar()) != '\n') {
			s[i] = c;
			if(i==0){primeiro=s[0];}
			i++;
		}
		s[i] = '\0';
		while (*p1){
			*p1 = toupper(*p1);
			printf("%c", *p1++); 
		}
		printf("\n\n");
		if(primeiro == 'f'){continuar=0;}

	} while (continuar==1);
	return 0;
}

