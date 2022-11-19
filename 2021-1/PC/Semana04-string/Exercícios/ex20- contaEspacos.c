/*20. Escreva um programa para ler uma quantidade indeterminada de frases (considere que cada
frase possui no máximo 70 caracteres). Para cada frase imprima a quantidade de espaços em
branco que ela contém. O programa se encerra quando for digitada uma frase que não
contém espaços em branco.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	int i=0,j=0,tam,contaEspaco,continuar;
	char palavra[70];
	

	while(continuar!=0){
		contaEspaco=0;
		continuar=0;
		printf("Digite a palavra %d: ",j+1);	
		fgets(palavra, 30, stdin); 
		tam = strlen(palavra);
		for(i=0;i<tam;i++){if(palavra[i]==' '){contaEspaco++;continuar=1;}}
		printf("%d espaços\n",contaEspaco);	
	j++;
	}
	return 0;
}

