#include<stdio.h>
#include<stdlib.h>

struct cel {
	int conteudo;
	struct cel *prox;
};

typedef struct cel celula;
void insere(int x, celula * p);
void imprime(celula * ini);
celula *busca(int x, celula * ini);
celula *cria(void);
void remova(int y, celula * ini);
void remova_end(celula * p);

int main()
{
	celula *ini, *pos;
	ini = cria();
	insere(10, ini);
	insere(100, ini);
	insere(1000, ini);
	imprime(ini);
	pos = busca(100, ini);
	insere(99, pos);
	imprime(ini);
	remova(99, ini);
	imprime(ini);
	pos = busca(100, ini);
	remova_end(pos);
	imprime(ini);
	return 0;
}

celula *cria(void)
{
	celula *start;

	start = (celula *) malloc(sizeof(celula));
	start->prox = NULL;
	return start;
}

void insere(int x, celula * p)
{
	celula *nova;

	nova = (celula *) malloc(sizeof(celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}

void imprime(celula * ini)
{
	celula *p;
	for (p = ini->prox; p != NULL; p = p->prox)
		printf("%d\n", p->conteudo);
}

celula *busca(int x, celula * ini)
{
	celula *p;
	p = ini->prox;
	while (p != NULL && p->conteudo != x)
		p = p->prox;
	return p;
}

void remova(int y, celula * ini)
{
	celula *p, *q;
	p = ini;
	q = ini->prox;
	while ((q != NULL) && (q->conteudo != y)) {
		p = q;
		q = q->prox;
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
	}
}

void remova_end(celula * p)
{
	celula *morta;
	morta = p->prox;
	p->prox = morta->prox;
	free(morta);
}
