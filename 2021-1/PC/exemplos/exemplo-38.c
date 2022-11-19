#include <stdio.h>
void imprime(int num[10]);

int main()
{
	int t[10], i;
	for (i = 0; i < 10; i++)
		t[i] = i;
	imprime(t);
	return 0;
}

void imprime(int num[10])
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", num[i]);
}
