/*10. Ler um vetor M de 10 elementos. Troque a seguir o 1o. elemento com o 6o., o 2o. com o
7o.,etc. até o 5o. com 10o. e escreva o vetor M assim modificado.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int U[10];
	int aux, i=0;

	for (i = 0; i < 10; i++){
	printf("Digite um valor:");
	scanf("%d", &U[i] );
	}

	for (i = 0; i < 5; i++){
		aux = U[i];
		U[i] = U[i+5];
		U[i+5] = aux;
	}
	
	for (i=0;i<10;i++){printf("%d ",U[i]);}

return 0;
}
