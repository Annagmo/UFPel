/*Ler um vetor U de 10 elementos. Troque a seguir o 1o. elemento com o último, o 2o. com o
penúltimo, etc. até o 5o. com o 6o. e escreva o vetor U assim modificado.*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int U[10];
	int aux[2] = {0,0}, i=0;

	for (i = 0; i < 10; i++){
	printf("Digite um valor:");
	scanf("%d", &U[i] );
	}
	i = 0;

	for (i = 0; i < 5; i++){
		aux[0] = U[i];
		aux[1] = U[(9-i)];
		U[i] = aux[1];
		U[(9-i)] = aux[0];
	}
	
	for (i=0;i<10;i++){printf("%d ",U[i]);}

return 0;
}
