#include<stdio.h>
int main()
{
	char c, linha[100];
	int i = 0;

	while ((c = getchar()) != '\n') {
		linha[i] = c;
		i++;
	}
	linha[i] = '\0';	//final de string
	printf("%s", linha);
	return 0;
}
