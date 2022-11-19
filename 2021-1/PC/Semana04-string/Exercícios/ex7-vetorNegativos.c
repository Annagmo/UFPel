/*7. Ler um vetor X de 10 elementos. A seguir copie todos os valores negativos de vetor X para o
vetor R (sem deixar elementos vazios entre os valores copiados). Escrever o vetor R.*/
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int X[10],R[10];
	int i,j=0;
	
	for (i=0;i<10;i++){R[i]=0;}
	for (i=0;i<10;i++){
		printf("Digite um valor:");
		scanf("%d",&X[i]);
	}
		
	for (i=0;i<10;i++){
		if(X[i]<0){
			R[j]=X[i];
			j++;
			}
		}
	printf("Vetor R:");
	for (i=0;i<10;i++){
		if(R[i]!=0){
		printf("%d ",R[i]);}
	}
	return 0;
}
