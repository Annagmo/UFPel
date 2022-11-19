/*14. Ler um vetor de até 20 elementos. A leitura deverá ser executada até que o vetor fique
preenchido, ou seja informado um valor negativo ou zero. Ler 2 valores que representam 2
posições (índices) no vetor (aceitar apenas índices válidos), escrever os valores nas posições
entre estes índices (inclusive).*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int X[20],i=0,indice1,indice2;
	
	//inicializar o vetor:
	for (i=0;i<10;i++){X[i]=0;}
	
	printf("Digite o primeiro valor de índice:");
	scanf("%d",&indice1);
	printf("Digite o segundo valor de índice:");
	scanf("%d",&indice2);
	
	i = indice1;
	
	printf("Digite um valor:");
	scanf("%d",&X[i]);
	while(X[i]>0 && i<indice2){
		i++;
		printf("Digite um valor:");
		scanf("%d",&X[i]);

	}
	
	printf("\nVetor X: ");
	for (i=0;i<10;i++){
		if(X[i]>=0){printf("%2d ",X[i]);} 
		}
	
	printf("\n\nindices: ");
	for (i=0;i<10;i++){printf("%2d ",i);}
	return 0;
}


