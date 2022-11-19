/*11. Ler 2 vetores, R de 5 elementos e S de 10 elementos. Gere um vetor X que possua os
elementos comuns a R e a S. Considere que no mesmo vetor não haverá números repetidos.
Escrever o vetor X.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int X[5],R[5],S[10],i,j,k=0;
	
	for (i=0;i<10;i++){
		printf("Digite um valor para a posição %d do vetor S:",i+1);
		scanf("%d",&S[i]);
		X[i]=0;
	}
	printf("\n");
	for (i=0;i<5;i++){
		printf("Digite um valor para a posição %d do vetor R:",i+1);
		scanf("%d",&R[i]);
	}
	
	for (i=0;i<10;i++){
		for(j=0;j<5;j++){
			if(R[j]==S[i]){X[k]=R[j];k++;}
			}
		}
	printf("\nVetor X: ");
	for (i=0;i<5;i++){
		if(X[i]!=0){printf("%d ",X[i]);}
		}
	return 0;
}
