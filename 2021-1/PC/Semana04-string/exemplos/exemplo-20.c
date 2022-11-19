#include <stdio.h>
#include <string.h>
int main()
{
	char str[80] = "Nome: Marilton Aguiar;Cidade: Pelotas;Estado: RS";
	char *token;
	token = strtok(str, ";");
	printf(" %s\n", token);
	token = strtok(NULL, ";");
	printf(" %s\n", token);
	token = strtok(NULL, ";");
	printf(" %s\n", token);
	return 0;
}
