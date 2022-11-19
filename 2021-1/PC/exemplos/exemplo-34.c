#include <stdio.h>
int is_in(char *s, char c);

int main()
{
	char *palavra = "alo mundo";
	char o = 'o';

	if (is_in(palavra, o))
		printf("A palavra contém o caractere.");
	else
		printf("A palavra não contém o caractere.");
	return 0;
}

int is_in(char *s, char c)
{
	while (*s)
		if (*s == c)
			return 1;
		else
			s++;
	return 0;
}
