#include <stdio.h>
int maximo(int n, int v[]);

int main()
{
	int x[5] = { 4, 3, 5, 7, 6 };

	printf("%d", maximo(5, x));
	return 0;
}

int maximo(int n, int v[])
{
	if (n == 1)
		return v[0];
	else {
		int x;
		x = maximo(n - 1, v);
		if (x > v[n - 1])
			return x;
		else
			return v[n - 1];
	}
}
