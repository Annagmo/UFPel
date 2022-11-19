#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct end {
	char nome[100];
	char rua[100];
	char cidade[100];
	char estado[100];
	unsigned long int cep;
} info[MAX];

void cria_lista(void);
void insere(void);
void apaga(void);
void imprime(void);
int menu(void);
int livre(void);
void ler_string(char palavra[100], int tamanho);

int main()
{
	int escolha;

	cria_lista();
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere();
			break;
		case 2:
			apaga();
			break;
		case 3:
			imprime();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	return 0;
}

void cria_lista(void)
{
	int i;
	for (i = 0; i < MAX; i++)
		info[i].nome[0] = '\0';
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome\n");
		printf("\t 3. Listar o arquivo\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 4);
	getchar();
	return c;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';

	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}

}

void insere(void)
{
	int posicao;

	posicao = livre();
	if (posicao == -1) {
		printf("\nEstrutura Cheia!!");
		return;
	}

	printf("-- Registro %d:\n", posicao);
	printf("\t Nome: ");
	ler_string(info[posicao].nome, 100);
	printf("\t Rua: ");
	ler_string(info[posicao].rua, 100);
	printf("\t Cidade: ");
	ler_string(info[posicao].cidade, 100);
	printf("\t Estado: ");
	ler_string(info[posicao].estado, 100);
	printf("\t CEP: ");
	scanf("%lu", &info[posicao].cep);
}

int livre(void)
{
	int i;
	for (i = 0; info[i].nome[0] && i < MAX; i++) ;
	if (i == MAX)
		return -1;
	return i;
}

void apaga(void)
{
	int posicao;

	printf("Número do Registro: ");
	scanf("%d", &posicao);

	if (posicao >= 0 && posicao < MAX)
		info[posicao].nome[0] = '\0';
}

void imprime(void)
{
	int i;

	for (i = 0; i < MAX; i++)
		if (info[i].nome[0] != '\0') {
			printf("-- Registro %d:\n", i);
			printf("\t Nome: %s", info[i].nome);
			printf("\t Rua: %s", info[i].rua);
			printf("\t Cidade: %s", info[i].cidade);
			printf("\t Estado: %s\n", info[i].estado);
			printf("\t CEP: %lu\n", info[i].cep);
		}
}
