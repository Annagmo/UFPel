#include <stdio.h>
#include "bib.h"

int main()
{
	int n;

	printf("Informe n para o fatorial: ");
	scanf("%d", &n);

	printf("fat(%d) = %d", n, fatorial(n));
	return 0;
}
