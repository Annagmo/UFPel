/*Ler 2 vetores X e Y de 10 elementos cada um (ocupando as posições de 0 a 9 em cada
vetor). Intercalar os elementos desses 2 vetores formando assim, um novo vetor R de 20
elementos, onde nas posições pares de R (0,2,4,6,8,...) estejam os elementos de X e nas
posições ímpares (1,3,5,7,9,...) os elementos de Y. Após a geração completa do vetor R,
escreva-o.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int X[10],Y[10],R[20],i,j=0,k=0;
	
	for (i=0;i<10;i++){
		printf("Digite um valor para a posição %d do vetor X:",i+1);
		scanf("%d",&X[i]);
	}
	printf("\n");
	for (i=0;i<10;i++){
		printf("Digite um valor para a posição %d do vetor Y:",i+1);
		scanf("%d",&Y[i]);
	}
	
	for (i=0;i<20;i++){
		if(i%2==0){R[i]=X[j];j++;}
		else{R[i]=Y[k];k++;}
		}
		
	printf("\nVetor R: ");
	for (i=0;i<20;i++){printf("%d ",R[i]);}
	return 0;
}
