/*Ler um vetor A de 10 elementos e um valor V. Conte e escreva quantas vezes o valor V
ocorre no vetor A.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int A[10],i,V,contador=0;
	
	for (i=0;i<10;i++){
		printf("Digite um valor para o vetor A: ");
		scanf("%d",&A[i]);
	}
	
	printf("Digite um valor V: ");
	scanf("%d",&V);
	
	for (i=0;i<10;i++){if(A[i]==V){contador++;}}
	
	printf("O valor V esteve em A: %d vezes",contador);
	
	return 0;
}
