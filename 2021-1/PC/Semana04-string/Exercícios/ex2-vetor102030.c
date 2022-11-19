/*2. Preencher um vetor A de 10 elementos(índices de 0 a 9) com os números inteiros 10, 20, 30,
40, 50, ..., 100. Escrever o vetor A após o seu total preenchimento.*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int X[10],i;
	
	X[0]=10;
	for (i=0;i<10;i++){X[i]=X[i-1]+10;}
	for (i=0;i<10;i++){printf("%d\n",X[i]);}
	
	return 0;
}
