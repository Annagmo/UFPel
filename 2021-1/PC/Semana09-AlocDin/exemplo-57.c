#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i, *p, *inicio;
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
	return 0;
}
