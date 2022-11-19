/*17. Ler uma matriz n x n que representa a distância existente entre n cidades entre si. A seguir
ler um vetor de tamanho m, com os códigos das cidades de um trajeto. Escrever a distância
total percorrida.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int A[6][6],vetor[6][6],i,j;
	
	//inicializar a matriz:
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){A[i][j]=0;aux[i][j]=0;}}
		
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			printf("Digite o valor A[%d][%d]: ",i,j);
				scanf("%d",&A[i][j]);
			}
		}

	printf("\nMatriz A: \n");	
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
		printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	for (i=0;i<6;i++){
		for (j=0;j<=6;j++){
			if(j%2==0){
			aux[i][j]=A[i][j];
			A[i][j] = A[i][j+1];
			A[i][j+1]= aux[i][j];
			}
		}
	}
		
	printf("\nMatriz A trocada: \n");	
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
		printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}




