#include <stdio.h>
int main()
{
	int a, b;
	printf("digite dois numeros\n");
	scanf("%d %d", &a, &b);
	if (b)
		printf("%d\n", a / b);
	else
		printf("nao pode dividir por zero");
	return 0;
}
