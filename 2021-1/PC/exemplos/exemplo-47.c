#include <stdio.h>
int main()
{
	struct {
		int a;
		int b;
	} x, y;

	x.a = 10;
	y = x;
	printf("%d", y.a);
	return 0;
}
