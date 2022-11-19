
#include <stdio.h>
int main()
{
	int target, source = 10, *m;

	m = &source;
	target = *m;

	printf("%d", target);
	return 0;
}
