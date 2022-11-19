#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPCAO (sizeof(int))
#define QTD_PESSOAS (sizeof(int))
#define NOME_AUX (sizeof(char[10]))
#define BUSCANOME (sizeof(char[10]))
#define NOME_EXCLUI_AUX (sizeof(char[10]))
#define EXCLUINOME (sizeof(char[10]))
#define NOME_EXCLUIDO (sizeof(char[10]))

void *insere(void *pbuffer);
void lista (void *pbuffer);
void busca (void *pbuffer);
void *remover(void *pbuffer);

typedef struct{
    char nome[10];
    int idade;
    long int tel;
} Pessoa;

Pessoa pessoas[10];

int main(){

    void *pbuffer = NULL;

    pbuffer = malloc(OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO);

    if (pbuffer == NULL){
        printf("Erro na alocação de memoria.\n");
        exit(1);
    }

    *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO) = 0; //0 pessoas

    printf("\n Bem-vindo à string de nomes!\n"); //menu:
	while (*(int *)(pbuffer) != 5) { // se ele não pedir para sair, continua rodando.
		printf("\nopções disponı́veis:\n");
		printf("\t1 p/ Adicionar pessoa.\n");
		printf("\t2 p/ Listar totas as pessoas.\n");
        printf("\t3 p/ Buscar pessoa.\n");
        printf("\t4 p/ Remover pessoa.\n");
        printf("\t5 p/ Sair.\n");

		printf("Entre com a  opção desejada: ");
		scanf("%d", (int *)(pbuffer));


        switch (*(int *)(pbuffer)) {
            case 1:
            pbuffer = insere(pbuffer);
            break;

            case 2:
            if (*(int *)(pbuffer + OPCAO) == 0) {
                printf("Você não inseriu nada na agenda. \n\n");
                exit(1);
            }
            else{
                lista(pbuffer);
            }
            break;

            case 3:
            busca(pbuffer);
            break;

            case 4:
            remover(pbuffer);
            break;

            case 5:
            free(pbuffer);
            break;

            default:
            break;
        }
    }
exit(0);
}

void *insere(void *pbuffer){
    if (*(int *)(pbuffer + OPCAO) >= 10) {
        printf("Lista cheia!\n\n");
        return pbuffer;
    } else {
        printf("Digite o nome:");
        scanf("%s", (pessoas + *(int *)(pbuffer + OPCAO)) -> nome);
        getchar();

        printf("Digite a idade:");
        scanf("%d", &(pessoas + *(int *)(pbuffer + OPCAO)) -> idade);
        getchar();
    
        printf("Digite o telefone:");
        scanf("%ld", &(pessoas + *(int *)(pbuffer + OPCAO)) -> tel);
        getchar();

        *(int *)(pbuffer + OPCAO) = *(int *)(pbuffer + OPCAO) + 1;
    }

    return pbuffer;
}

void lista(void *pbuffer){
    printf("\nAgenda:\n\n");
    for (*(int *)(pbuffer + OPCAO + QTD_PESSOAS) = 0 ; *(int *)(pbuffer + OPCAO + QTD_PESSOAS) < *(int*)(pbuffer + OPCAO) ; *(int *)(pbuffer + OPCAO + QTD_PESSOAS)+=1){
        printf("Nome: %s\n", (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS)) -> nome);
        printf("Idade: %d\n", (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS)) -> idade);
        printf("Numero: %ld\n\n", (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS)) -> tel);
    }
}

void busca(void *pbuffer){
    printf("Insira o nome a ser buscado:\n");
    scanf("%s", (char *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX));
    getchar();

    for (*(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME) = 0 ; *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME) < *(int*)(pbuffer + OPCAO) ; *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME)+=1){
        if(strcmp((char *)(pbuffer + OPCAO+ QTD_PESSOAS + NOME_AUX), (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME)) -> nome ) == 0){
        printf("Nome: %s\n", (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME)) -> nome);
        printf("Idade: %d\n", (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME)) -> idade);
        printf("Numero: %ld\n\n", (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME)) -> tel);
        }
    }
    (printf("O nome não está na lista."));
}

void *remover(void *pbuffer){
    printf("Digite o nome a ser removido: ");
    scanf("%s", (char *)(pbuffer + OPCAO + QTD_PESSOAS + NOME_AUX + BUSCANOME + NOME_EXCLUI_AUX )); 
    getchar();

    for(*(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX) = 0; *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX) < *(int *)(pbuffer + OPCAO); *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX) += 1){ // O contador passa pelos nomes

        if(strcmp((char *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME), (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX)) -> nome ) == 0) { // Se o nome digitado estiver na lista entra nesse if

            for(*(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO) = *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX); *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO) < *(int *)(pbuffer + OPCAO); *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO) += 1){  // passa pelos nomes

                strcpy((pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO)) -> nome, (pessoas + 1 + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO)) -> nome); //puxa pro próximo
                (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO)) -> idade = (pessoas + 1 + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO)) -> idade;
                (pessoas + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO)) -> tel = (pessoas + 1 + *(int *)(pbuffer + OPCAO + QTD_PESSOAS + BUSCANOME + NOME_EXCLUI_AUX + EXCLUINOME + NOME_EXCLUIDO)) -> tel;
            }
            *(int *)(pbuffer + OPCAO) = *(int *)(pbuffer + OPCAO) - 1;
            return pbuffer;
        }
    }
    printf("O nome não está na lista!\n\n");
return pbuffer;
}
