#include <stdio.h>

/* descrição de registro aleatório - pode ser qualquer uma */
struct rec {
	int x, y, z;
};

/* grava e depois lê 10 registros arbitrários do arquivo "junk". */
int main()
{
	int i, j;
	FILE *f;
	struct rec r;

	/* cria o arquivo de 10 registros */
	f = fopen("junk", "w");
	if (!f)
		return 1;
	for (i = 1; i <= 10; i++) {
		r.x = i;
		fwrite(&r, sizeof(struct rec), 1, f);
	}
	fclose(f);

	/* lê os 10 registros */
	f = fopen("junk", "r");
	if (!f)
		return 1;
	for (i = 1; i <= 10; i++) {
		fread(&r, sizeof(struct rec), 1, f);
		printf("%d\n", r.x);
	}
	fclose(f);
	printf("\n");

	/* usa fseek para ler os 10 registros em ordem inversa */
	f = fopen("junk", "r");
	if (!f)
		return 1;
	for (i = 9; i >= 0; i--) {
		fseek(f, sizeof(struct rec) * i, SEEK_SET);
		fread(&r, sizeof(struct rec), 1, f);
		printf("%d\n", r.x);
	}
	fclose(f);
	printf("\n");

	/* usa fseek para ler todo os outros registros */
	f = fopen("junk", "r");
	if (!f)
		return 1;
	fseek(f, 0, SEEK_SET);
	for (i = 0; i < 5; i++) {
		fread(&r, sizeof(struct rec), 1, f);
		printf("%d\n", r.x);
		fseek(f, sizeof(struct rec), SEEK_CUR);
	}
	fclose(f);
	printf("\n");

	/* usa fseek para ler o 4º registro, altere-o e escreva-o de volta */
	f = fopen("junk", "r+");
	if (!f)
		return 1;
	fseek(f, sizeof(struct rec) * 3, SEEK_SET);
	fread(&r, sizeof(struct rec), 1, f);
	r.x = 100;
	fseek(f, sizeof(struct rec) * 3, SEEK_SET);
	fwrite(&r, sizeof(struct rec), 1, f);
	fclose(f);
	printf("\n");

	/* lê os 10 registros para garantir que o 4º arquivo foi alterado */
	f = fopen("junk", "r");
	if (!f)
		return 1;
	for (i = 1; i <= 10; i++) {
		fread(&r, sizeof(struct rec), 1, f);
		printf("%d\n", r.x);
	}
	fclose(f);
	return 0;
}
