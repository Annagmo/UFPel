#include <stdio.h>
int pot(int n, int e);
int total = 0;

int main()
{
	int t = 10;
	printf("%d %d %d", t, total, pot(t, 2));
	return 0;
}

int pot(int n, int e)
{
	total = n;
	for (; e > 1; e--)
		total = total * n;
	return (total);
}
