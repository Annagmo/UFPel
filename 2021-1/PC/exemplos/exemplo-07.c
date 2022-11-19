#include <stdio.h>
int main()
{
	int a, b;
	float c;

	printf("entre com o valor de a\n");
	scanf("%d", &a);
	printf("entre com o valor de b\n");
	scanf("%d", &b);
	c = 2 / ((float)1 / a + (float)1 / b);
	printf("a=%d b=%d\n", a, b);
	printf("a média harmônica de a e b é: %f", c);
	return 0;
}
