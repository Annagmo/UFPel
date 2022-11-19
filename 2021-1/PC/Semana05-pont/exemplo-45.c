#include <stdio.h>
#include <stdlib.h>		//por causa de exit()

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Erro: Informe seu nome como parâmetro!\n");
		exit(1);
	}
	printf("Olá, %s!\n", argv[1]);
	return 0;
}
