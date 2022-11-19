
#include <stdio.h>
int main()
{
	int x = 0, *p1, *p2;

	p1 = &x;
	p2 = p1;

	printf("%p", p2);
	return 0;
}
