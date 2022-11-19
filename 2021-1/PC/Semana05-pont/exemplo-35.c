#include <stdio.h>
int soma_um();

int main()
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", soma_um());
	return 0;
}

int soma_um(void)
{
	static int num = 0;
	return ++num;
}
