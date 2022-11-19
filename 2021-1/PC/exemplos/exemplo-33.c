#include <stdio.h>

int substring(char *string1, char *string2);

int main()
{
	if (substring("C eh legal", "eh"))
		printf("É substring!\n");
	else
		printf("Não é substring!\n");
	return 0;
}

int substring(char *string1, char *string2)
{
	int i;
	char *p1, *p2;

	for (i = 0; string1[i]; i++) {
		p1 = &string1[i];
		p2 = string2;
		while (*p2 && *p2 == *p1) {
			p1++;
			p2++;
		}
		if (!*p2)
			return 1;
	}
	return 0;
}
