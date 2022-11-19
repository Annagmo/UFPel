#include <stdio.h>

typedef struct {
	int dia;
	int mes;
	int ano;
} data;

int main()
{
	data aniversario;

	aniversario.dia = 14;
	aniversario.mes = 1;
	aniversario.ano = 1975;

	printf("%d / %d / %d.", aniversario.dia, aniversario.mes, aniversario.ano);
	return 0;
}
