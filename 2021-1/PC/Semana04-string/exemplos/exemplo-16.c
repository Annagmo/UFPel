#include <stdio.h>
int main()
{
	char linha[100] = { "A linha." };
	int i = 0;

	while (linha[i] != '\0') {
		putchar(linha[i]);
		i++;
	}
	return 0;
}
