/*Ler um vetor X de 10 elementos. Crie um vetor Y da seguinte forma. Os elementos de
ordem par de Y (elementos com índice 0,2,4,6,8) receberão os respectivos elementos de X
multiplicados por 2. Os elementos de ordem ímpar de Y (elementos com índices 1,3,5,7,9)
receberão os respectivos elementos de X multiplicados por 3. Escrever o vetor Y.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int X[10],Y[10],i;
	
	for (i=0;i<10;i++){
		printf("Digite um valor para o vetor X:");
		scanf("%d",&X[i]);
	}
		
	for (i=0;i<10;i++){
		if(i%2==0){Y[i] = X[i]*2;}
		else{Y[i] = X[i]*3;}
	}
	printf("Vetor Y:");
	for (i=0;i<10;i++){printf("%d ",Y[i]);}
	
	return 0;
}
