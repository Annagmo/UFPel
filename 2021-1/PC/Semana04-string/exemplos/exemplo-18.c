#include <stdio.h>
int main()
{
	char str[31];
	printf("Digite seu nome: ");
	fgets(str, 30, stdin);
	puts(str);
	return 0;
}
