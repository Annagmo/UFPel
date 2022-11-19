#include <stdio.h>
#define MAX 120

int main()
{
	FILE *fp;
	char nome_arq[50], linha[120];

	printf("entre com o nome do arquivo\n");
	scanf("%s", nome_arq);
	if ((fp = fopen(nome_arq, "r")) == NULL) {
		printf("Erro ao abrir o arquivo %s\n", nome_arq);
		exit(1);
	}
	while (fgets(linha, MAX, fp) != NULL) {
		printf("%s", linha);
	}
	return 0;
}
