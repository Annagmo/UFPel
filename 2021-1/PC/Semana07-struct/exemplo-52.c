#include <stdio.h>

enum meses {
	janeiro =
	    1, fevereiro, marco, abril, maio, junho, julho, agosto, setembro,
	outubro, novembro, dezembro
};

int main()
{
	int mes_corrente;
	int soma, dif;
	enum meses fim;

	printf("Digite o mês corrente (1 a 12): ");
	scanf("%d", &mes_corrente);

	fim = dezembro;

	soma = (int)mes_corrente;
	dif = (int)fim - (int)mes_corrente;
	printf("\n%d meses a menos, pois faltam %d para acabar este ano.\n", soma, dif);
	return 0;
}
