#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
} pessoa;

int qtd_pessoas = 0;
void *insere(pessoa *agenda, int qtd_pessoas);
void lista(pessoa *agenda,int qtd_pessoas);

void main(){

    pessoa *agenda = agenda = (pessoa *)malloc(sizeof(pessoa));

    int op;

    printf("\n Bem-vindo a string de nomes!\n"); //menu:
    while (op != 2) { // se ele não pedir para sair, continua rodando.
        printf("\nOpções disponı́veis:\n");
        printf("\t1 p/ Adicionar nome.\n");
        printf("\t2 p/ Sair.\n");

        printf("Entre opção desejada: ");
        scanf("%d", &op);
        

            switch(op) {

            case 1:
            agenda = insere(agenda, qtd_pessoas);
            qtd_pessoas = qtd_pessoas + 1;
            break;

            case 2:
            lista(agenda,qtd_pessoas);
            free(agenda);
            break;


            default:
            printf("\n\nOPCAO INVALIDA!\n");
        }
    }
}

void *insere(pessoa *agenda, int qtd_pessoas){
    if(qtd_pessoas != 0){ //para o resto das pessoas
        agenda = (pessoa *)realloc(agenda, sizeof(pessoa) * (qtd_pessoas + 1));
    }

	printf("Digite o nome:");
    scanf("%s",(agenda+qtd_pessoas)->nome);
    getchar();
    printf("Digite a idade:");
    scanf("%d",&(agenda+qtd_pessoas)->idade);
    getchar();
    printf("Digite a altura em cm:");
	scanf("%d",&(agenda+qtd_pessoas)->altura);
    getchar();

	return agenda;
}

void lista(pessoa *agenda, int qtd_pessoas) {
	int i;
    for (int i = 0; i < qtd_pessoas; i++) {
	printf("Nome: %s\n", (agenda+i)->nome);
	printf("Idade: %d\n", (agenda+i)->idade);
	printf("Altura: %d\n", (agenda+i)->altura);
	}
}
