
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct pessoa{
	char nome[10];
	char idade[10];
	char telefone[15];	
}pessoa;

void *pbuffer;
int nPessoas;
pessoa *pessoas;
int cont;
pessoa *removerNome;

int main(void){


int op, i;
char *nomeBusca[10];
int qtd_pessoasAux;

pbuffer = malloc(sizeof(pessoa));
if (pbuffer == NULL) {
  printf("Sem memoria\n");
  exit(1);
} 

printf("\n Bem-vindo a string de nomes!\n"); //menu:
	while (op != 5) { // se ele não pedir para sair, continua rodando.
		printf("\nOpções disponı́veis:\n");
		printf("\t1 p/ Adicionar pessoa.\n");
		printf("\t2 p/ Remover pessoa.\n");
        printf("\t3 p/ Buscar pessoa.\n");
		printf("\t4 p/ Listar totas as pessoas.\n");
        printf("\t5 p/ Sair.\n");

		printf("Entre opção desejada: ");
		scanf("%d", &op);
		

			switch(op) {

			case 1:
			fflush (stdin);
			nPessoas = nPessoas+1;
			pbuffer = realloc(pbuffer,( sizeof(pessoa) * 2 * nPessoas));
			pessoas = pbuffer + sizeof(pbuffer); //- sizeof(pessoa);
			if (pbuffer == NULL) {
				printf("Sem memoria\n");
				exit(EXIT_FAILURE);
			}
			printf("Digite o nome: ");
			scanf("%s",pessoas->nome);
			printf("Digite o telefone: ");
			scanf("%s",pessoas->telefone);
			printf("Digite a idade: ");
			scanf("%s",pessoas->idade);
			pessoas++;

			break;

			
			case 2:
			printf("\nDigite o nome que deseja remover: ");
			scanf("%s",removerNome->nome);
			qtd_pessoasAux = nPessoas;
			for (i = 0; i < qtd_pessoasAux; i++)
			{
			if( strcpy(pessoas->nome,removerNome->nome)==0){
				qtd_pessoasAux--;
				pbuffer = realloc(pbuffer, sizeof(pessoas) + sizeof(pessoa)* qtd_pessoasAux);
			}
			else{printf("nome nao encontrado.");}
			}
			break;

			case 3:
			pessoas = pbuffer + sizeof(pessoas);
			cont = -1;
			printf("Digite o nome para a busca: ");
			scanf("%s", nomeBusca);
			for(i = 0;i < nPessoas;i++){
				if(strcmp(pessoas->nome, nomeBusca)== 0){
					printf ("Pessoa Encontrada com sucesso:\n");
					printf("\tNome:%s\n\tIdade:%s\n\tTelefone:%s\n",pessoas->nome, pessoas->idade,pessoas->telefone);
					cont++;
				}
				pessoas++;
			}
			if(cont == -1)
				printf("\nEste nome não esta na lista.");
			break;


			case 4:
			printf("\n---- Agenda de Nomes ----\n");
			pessoas = pbuffer + sizeof(pessoas) ;
			for(i = 0;i < nPessoas; i++){
				printf("\n\tNome: %s",pessoas->nome);
				printf("\n\tTelefone: %s",pessoas->telefone);
				printf("\n\tIdade: %s",pessoas->idade);
				pessoas++;
			}
			printf("\n");
			break;

            		case 5:
			break;

			default:
			printf("\n\nOPCAO INVALIDA!\n");
		}
	}
return 0;
    
}



