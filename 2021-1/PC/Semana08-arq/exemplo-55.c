#include <stdio.h>
#include <stdlib.h>

int main()
{
	int inum = 10;
	float fnum = 2.5;
	double pi = 3.141516;
	char c = 'Z';
	FILE *pa;
	char *nome = "texto.txt";

	if ((pa = fopen(nome, "w+b")) == NULL) {
		printf("\n\nNao foi possivel abrir o arquivo para escrita.\n");
		exit(1);
	}
	fwrite(&inum, sizeof(int), 1, pa);
	fwrite(&fnum, sizeof(float), 1, pa);
	fwrite(&pi, sizeof(double), 1, pa);
	fwrite(&c, sizeof(char), 1, pa);

	rewind(pa);

	fread(&inum, sizeof(int), 1, pa);
	fread(&fnum, sizeof(float), 1, pa);
	fread(&pi, sizeof(double), 1, pa);
	fread(&c, sizeof(char), 1, pa);

	printf("%d, %f, %lf, %c\n", inum, fnum, pi, c);

	fclose(pa);
	exit(0);
}
