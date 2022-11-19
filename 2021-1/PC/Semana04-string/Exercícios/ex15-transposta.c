/*15. Ler uma matriz A de L linhas por C colunas. Gerar e imprimir uma matriz T transposta de A.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int A[10][10],T[10][10],i,j,L,C;
	
	//inicializar a matriz:
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){A[i][j]=-95;T[i][j]=-95;}}
	
	printf("Digite o número de linhas:");
	scanf("%d",&L);
	printf("Digite o número de colunas:");
	scanf("%d",&C);

	for (i=0;i<L;i++){
		for (j=0;j<C;j++){
			printf("Digite o valor A[%d][%d]: ",i,j);
				scanf("%d",&A[i][j]);
			}
		}

	for (i=0;i<=L;i++){
		for (j=0;j<=C;j++){
			T[i][j]=A[j][i];
			}
		}
		
	printf("\nMatriz T: \n");	
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if(T[i][j]!=-95){printf("%d ",T[i][j]);}
			}
		printf("\n");
		}
	return 0;
}

