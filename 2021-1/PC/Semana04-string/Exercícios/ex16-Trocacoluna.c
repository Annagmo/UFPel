/*16. Ler uma matriz 5 x 5. Trocar os elementos das colunas pares com os elementos das colunas
ímpares subsequentes (0 e 1, 2 e 3, até 4 e 5). Após o término das trocas escrever a matriz.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int A[6][6],aux[6][6],i,j;
	
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

