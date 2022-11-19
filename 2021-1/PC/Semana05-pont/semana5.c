#include <stdio.h>

/*void iniciavet(int *v, int qtd, int valor)
{
	int i;
	for(i=0;i<qtd;i++)
	v[i] = valor;
	
}

int main()
{
	int i;
	float vet[10];
	
	iniciavet(vet, 10, 7);
	for(i=0; i<10; i++)
	printf("%f ", vet[i]);
	
	return 0;	
	
}*/
void leitura ( int *qtde, int pares[100][2]);

int main(){
	int valores[100][2];
	int q, i;
	
	leitura(&q, valores);
	
	printf("Foram lidos %d pares de valores.\n",q);
	
	for(i=0; i<q; i++)
		printf( "%d %d\n", valores[i][0], valores[i][1]);
	return 0;
}

void leitura (int *qtde, int pares[100][2]) {
	*qtde=0;
	while (scanf("%d%d", &pares[*qtde][0], &pares[*qtde][1])==2)
		(*qtde)++;
}
	
	

