#include <stdio.h>
int main()
{
	int a, b;
	float c;
	a = 2;
	b = 10;
	c = 2 / ( (float) 1 / a + (float) 1 / b);
	printf("a= %d b= %d\n", a, b);
	printf("a média harmônica de a e b é: %f", c);
	return 0;
}
