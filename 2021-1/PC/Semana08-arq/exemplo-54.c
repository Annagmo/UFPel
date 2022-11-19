#include <stdio.h>
int main()
{
	FILE *fp;
	char nome_arquivo[32];
	double a;

	printf("Informe o nome do arquivo: ");
	scanf("%s", nome_arquivo);
	fp = fopen(nome_arquivo, "w");
	printf("Informe um numero (-999 para sair): ");
	scanf("%lf", &a);
	while (a != -999) {
		fprintf(fp, "%10.4lf", a);
		printf("Informe um numero (-999 para sair): ");
		scanf("%lf", &a);
	}
	fclose(fp);

	fp = fopen(nome_arquivo, "r");
	printf("\n***** conteudo do arquivo criado ******\n");
	while (fscanf(fp, "%lf", &a) != EOF)
		printf("\n\t %lf", a);
	fclose(fp);
	return 0;
}
