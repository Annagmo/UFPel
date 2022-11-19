#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char *p1, c, s[80];

	p1 = s;
	do {
		i = 0;
		while ((c = getchar()) != '\n') {
			s[i] = c;
			i++;
		}
		s[i] = '\0';

		while (*p1)
			printf(" %c", *p1++);
		printf("\n");
	} while (strcmp(s, "feito!"));
	return 0;
}
