#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, novo_n, adic, i, *p, *inicio;

	printf("Entre com o numero de elementos: \n");
	scanf("%d", &n);

	if ((p = (int *)malloc(n * sizeof(int))) == NULL) {
		printf("Não foi possível alocar memória\n");
		exit(1);
	}
	inicio = p;
	for (i = 0; i < n; i++, p++) {
		printf("Entre com o %d valor: \n", i + 1);
		scanf("%d", p);
	}
	p = inicio;
	for (i = 0; i < n; i++, p++) {
		printf("%do. valor: %d\n", i + 1, *p);
	}

	printf("Entre com a quantidade de elementos adicionais: \n");
	scanf("%d", &adic);

	novo_n = adic + n;

	p = inicio;
	p = (int *)realloc(p, novo_n * sizeof(int));

	inicio = p;
	for (i = n; i < novo_n; i++) {
		printf("Entre com o %d valor: \n", i + 1);
		scanf("%d", &p[i]);
	}

	p = inicio;
	for (i = 0; i < novo_n; i++, p++) {
		printf("%do. valor: %d\n", i + 1, *p);
	}
	return 0;
}
