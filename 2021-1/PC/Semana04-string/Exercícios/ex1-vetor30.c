/*Preencher um vetor X de 10 elementos(índices de 0 a 9) com o valor inteiro 30. Escrever o
vetor X, após seu total preenchimento.*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int X[10],i;
	
	for (i=0;i<10;i++){X[i]=30;}
	for (i=0;i<10;i++){printf("%d\n",X[i]);}
	
	return 0;
}
