/*13. Ler um vetor de até 10 elementos. A leitura deverá ser executada até que o vetor fique
preenchido, ou seja informado um valor negativo ou zero. Calcular e imprimir a soma dos
valores maiores que 5 existentes no vetor.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int X[10],i=0,soma=0;
	
	//inicializar o vetor:
	for (i=0;i<10;i++){X[i]=0;}
	
	i=0;
	printf("Digite um valor:");
	scanf("%d",&X[i]);
	while(X[i]>0 && i<9){
		i++;
		printf("Digite um valor:");
		scanf("%d",&X[i]);

	}
	
	for (i=0;i<10;i++){
		if(X[i]>5){soma+=X[i];} 
		}
	
	printf("\nsoma valores maiores que 5: %d",soma);

	return 0;
}


