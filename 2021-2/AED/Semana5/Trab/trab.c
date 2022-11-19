/*EX:
Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
    Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pbuffer.
        Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pbuffer.
        Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
    Não pode usar struct em todo o programa.
    Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
    Implementar a base de dados da agenda usando lista duplamente ligada
        Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
Seguir as orientações elaborados pelo monitor para código!
Entregar um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory.
*/

//DEFINES:
//O que estaria dentro da struct
#define NOME (sizeof(char) * 10)
#define IDADE (sizeof(int))
#define TEL (sizeof(long int))
//-----

#define PONTPONT (sizeof(void **)) // ponteiro para pont
#define OPCAO (sizeof(int)) // opcao menu
#define CONTADOR (sizeof(int)) // contador
//----

//Saber de onde vim e para onde vou: Tam da pessoa anterior na lista e tam da pessoa posterior
#define P_POSTERIOR ((sizeof(char) * 10) + sizeof(int) + sizeof(long int) + sizeof(void **)) //tamanho nome + tam idade + tamanho telefone + tam do ponteiro p/ pont
#define P_ANTERIOR ((sizeof(char) * 10) + sizeof(int) + sizeof(long int)) //tamanho nome + tam idade + tamanho telefone

//----
//primeira e ultimas pessoas da lista
#define PRIMEIRA_P (sizeof(int)) //o nr da pessoa anterior
#define ULTIMA_P (sizeof(int) + sizeof(void **)) // o nr da pessoa posterior mais o onteiro para ponteiro
//----
	
//BIBLIOTECAS:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CÓDIGO:
void adiciona(void *pbuffer, void *lista);
//void remover(void *pbuffer, void *lista);
void lista(void *pbuffer, void *lista);
void addOrdenado(void *pbuffer, void *contato, void *lista);

int main(void){

  void *lista = NULL;
    lista = malloc(CONTADOR + PONTPONT + PONTPONT); //qtd de nodos + apontador de nodo anterior + apontador de nodo posterior

    *(int *)(lista) = 0;

    void *pbuffer = NULL;
    pbuffer = malloc(OPCAO + PONTPONT); // nodo: já armazena a opção do menu e o apontador do próximo nodo.

    if (!pbuffer || !lista){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

printf("\n Bem-vindo a string de nomes!\n"); //menu:
	while (*(int *)(pbuffer)!=5) { // se ele não pedir para sair, continua rodando.
		printf("\nOpções disponı́veis:\n");
		printf("\t1 p/ Adicionar pessoa.\n");
		printf("\t2 p/ Remover pessoa.\n");
        printf("\t3 p/ Buscar pessoa.\n");
		printf("\t4 p/ Listar totas as pessoas.\n");
        printf("\t5 p/ Sair.\n");
         printf("\nDigite:");
		scanf("%d", (int *)(pbuffer));
        getchar();
        switch (*(int *)(pbuffer)){

			case 1:
            adiciona(pbuffer, lista);
			break;

			case 2:
            //remover(pbuffer, lista);
			break;

			case 3:
            buscar(pbuffer, lista);
			break;


			case 4:
            listar(pbuffer, lista);
			break;

            case 5:
			break;

			default:
			printf("\n\nOPCAO INVALIDA!\n");
		}
	}
free(lista);
free(pbuffer);
return 0;
    
}

void adiciona(void *pbuffer, void *lista){
    int *Conta_P = (int *)(lista); // qtd de pessoas

    void *contato = NULL; //inicializando um nodo contato vazia

    contato = malloc(NOME + IDADE + TEL + PONTPONT + PONTPONT); 

    if (!contato){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("\nDigite o nome:  ");
    scanf("%s", (char *)contato);
    getchar();

    printf("Digite a idade: ");
    scanf("%d", &*(int *)(contato + NOME));
    getchar();
   
    printf("Digite o telefone: ");
    scanf("%ld", &*(long int *)(contato + NOME + IDADE));
    getchar();

    *(void **)(contato + P_ANTERIOR) = NULL; 
    *(void **)(contato + P_POSTERIOR) = NULL; 

    if (*Conta_P == 0){ // se ainda nao tivermos nenhuma pessoa adicionada
        *(void **)(lista + ULTIMA_P) = contato; // o contato que acabamos de criar vai ser, ao mesmo tempo, a primeira e a ultima pessoa de uma lista unitaria.
        *(void **)(lista + PRIMEIRA_P) = contato;
        
        *Conta_P += 1; //ja possuimos 1 pessoa na lista, entao aumentamos o nr de pessoas

        return;
    }
    else {
    addOrdenado(contato, pbuffer, lista);// criamos uma função para add e ordenar todo mundo que não seja o primeiro nodo adicionado. 
    }

}

void addOrdenado(void *contato, void *pbuffer, void *lista){ //uma função separada só para adicionar e organizar os contatos alfabeticamente
    int *Conta_P = (int *)(lista);

    void *contatoAux = NULL; // um nodo de contato auxiliar

    pbuffer = *(void **)(lista + PRIMEIRA_P);

    while(pbuffer != NULL)
    {
        if(strcmp((char *)contato, (char *)pbuffer) < 0) 
        {
            *(void **)(contato + P_ANTERIOR) = *(void **)(pbuffer + P_ANTERIOR); 
            *(void **)(contato + P_POSTERIOR) = pbuffer;
            
            // PARA ADICIONAR UM CONTATO NO MEIO:
            if(*Conta_P > 1 && *(void **)(pbuffer + P_ANTERIOR) != NULL)
            {
                contatoAux = *(void **)(pbuffer + P_ANTERIOR); 
                *(void **)(contatoAux + P_POSTERIOR) = contato; 
            }

            *(void **)(pbuffer + P_ANTERIOR) = contato;

            // PARA ADICIONAR UM CONTATO NO INÍCIO:
            if(*(void **)(contato + P_ANTERIOR) == NULL) 
            {
                *(void **)(lista + PRIMEIRA_P) = contato; 
            }

            // PARA ADICINAR UM CONTATO NO FIM:
            if(*Conta_P == 1 && *(void **)(pbuffer + P_POSTERIOR) == NULL)
            { 
                *(void **)(lista + ULTIMA_P) = pbuffer;
            }

            *Conta_P += 1; // aumenta o nr de pessoas na lista

            return;
        }

        if(*(void **)(pbuffer + P_POSTERIOR) == NULL)  // depois que o contato estiver sido adicionado, se não existir mais nenhum contato na lista:
        { 
            contatoAux = pbuffer; //passa o conteúdo do pbuffer para o nodo auxiliar.
        }

        pbuffer = *(void **)(pbuffer + P_POSTERIOR); 
    }

    *(void **)(contato + P_ANTERIOR) = contatoAux; 
    *(void **)(contatoAux + P_POSTERIOR) = contato; 
    *(void **)(lista + ULTIMA_P) = contato;

    *Conta_P += 1; // aumenta o nr de pessoas na lista
    free(contato);
    free(contatoAux);
    free(Conta_P);
    return;

}

void listar(void *pbuffer, void *lista){
    void *contato = NULL; // inicia o nodo vazio
    contato = *(void **)(lista + PRIMEIRA_P); //aponta para a cabeça da lista.

    int *Conta_P = (int *)(lista);
    if (*Conta_P == 0)
    {
        printf("\nVocê não adicionou nenhuma pessoa na lista.\n");
    }
    else 
    {
        while(contato != NULL) //percorre os nodos
        {
            printf("Nome: %s\n", (char *)contato);
            printf("Idade: %d\n", *(int *)(contato + NOME)); 
            printf("Numero: %ld\n\n", *(long int *)(contato + NOME + IDADE)); 

            contato = *(void **)(contato +P_POSTERIOR); 
        }
    }
    free(contato);
}

void buscar(void *pbuffer, void *lista){
    void *contato = NULL; //inicializando um nodo contato vazio
    contato = *(void **)(lista + PRIMEIRA_P); //aponta para a cabeça da lista.
    int *Conta_P = (int *)(lista); // contagem dos nodos
    void *busca_nodo = malloc(sizeof(char) * 10); // nome auxiliar

    if (*Conta_P == 0)
    {
        printf("\nVocê não adicionou nenhuma pessoa na lista.\n");
    }
    else
    {
        printf("Nome a ser buscado: ");
        scanf("%s",(char *)busca_nodo);
        getchar();

        while (contato!= NULL) // enquanto não acabar a lista
        {
            if (strcmp((char *)busca_nodo,(char *)contato) == 0)
            {
            printf("\nNome encontrado:");
            printf("\nNome: %s\n", (char *)contato);
            printf("Idade: %d\n", *(int *)(contato + NOME)); 
            printf("Numero: %ld\n\n", *(long int *)(contato + NOME + IDADE));
            return;
            }
            contato = *(void **)(contato +P_POSTERIOR); 
        }

        printf("Nome não encontrado.\n");
    }
    free(contato);
    free(Conta_P);
    free(busca_nodo);
}


void remover(void *pbuffer, void *lista){
    int *Conta_p = (int *)(lista); // qtd de pessoas

    void *contato = NULL; // inicia o nodo da nossa lista de contatos
    contato = *(void **)(lista + PRIMEIRA_P); //aponta para a cabeça da lista de contatos já criada

    void *exclui_nodo =  malloc(sizeof(char) * 10); //nome auxiliar

    if (*Conta_p == 0)
    {
        printf("\nVocê não adicionou nenhuma pessoa na lista.\n");
    }
    else 
    {
        printf("\nDigite o nome a ser excluido:  ");
        scanf("%s", (char *)exclui_nodo);
        getchar();


        while(contato != NULL) //percorre os nodos
        {
            if(strcmp((char *)contato,(char *)exclui_nodo)==0){// se ele achar o nome a ser excluído na lista
                *(void **)(contato +P_ANTERIOR + PONTPONT) = *(void **)(pbuffer +P_POSTERIOR); // passa pro próximo nodo.
                free(contato);
            }
            contato = *(void **)(contato +P_POSTERIOR); // passa pro próximo nodo.
        }

    }
    free(exclui_nodo);
}
