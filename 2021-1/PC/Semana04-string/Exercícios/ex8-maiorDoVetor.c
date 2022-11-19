/*Ler um vetor Q de 10 posições (aceitar somente números positivos). Escreva a seguir o valor
do maior elemento de Q e a respectiva posição(índice) que ele ocupa no vetor.*/

#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int Q[10],maior=-5,i;
	
	

	for (i=0;i<10;i++){
		printf("Digite um valor:");
		scanf("%d",&Q[i]);
		while(Q[i]<0){printf("Digite um valor positivo:");scanf("%d",&Q[i]);}
	}
	for (i=0;i<10;i++){
		if (i == 0) {maior = Q[i];}
		if (Q[i] > maior) {maior = Q[i];}
		}
	printf("%d\n",maior);
	for (i=0;i<10;i++){
		if(Q[i]==maior){
		printf("Maior número = %d, índice: %d",Q[i],i);}
	}
	return 0;
}
