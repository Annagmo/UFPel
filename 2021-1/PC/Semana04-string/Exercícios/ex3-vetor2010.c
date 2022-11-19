/*Preencher um vetor B de 10 elementos com 10 se o índice do elemento for ímpar, e 20 se for
par. Escrever o vetor B após o seu total preenchimento.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int B[10],i;
	
	for (i=0;i<10;i++){
		if(i%2==0){
		B[i]=20;}
		else{B[i]=10;}
	}
	for (i=0;i<10;i++){printf("%d\n",B[i]);}
	
	return 0;
}
