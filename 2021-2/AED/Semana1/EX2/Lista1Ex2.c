
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
 
int j, tam = 0, op, contador=0;  
char palavra[20], *str_palavra, *token[20], *novaString[100];

str_palavra = (char*) malloc (strlen(palavra)*sizeof(char));
if(str_palavra == NULL){printf("sem memoria");}


printf("\n Bem-vindo a string de nomes!\n"); //menu:
	while (op != 4) { // se ele não pedir para sair, continua rodando.
		printf("\nOpções disponı́veis:\n");
		printf("\t1 p/ Adicionar nome.\n");
		printf("\t2 p/ Remover nome.\n");
		printf("\t3 p/ Listar todos os nomes.\n");
        printf("\t4 p/ Sair.\n");

		printf("Entre opção desejada: ");
		scanf("%d", &op);
		

			switch(op) {

			case 1:
			palavra[0] = '\0'; // limpa a palavra

			printf("Coloque o Nome:\n");
            scanf("%s", palavra);
            strcat(str_palavra, palavra);
            strcat(str_palavra, ";");

            tam= strlen(palavra); //pega o tamanho do nome
            str_palavra = (char*)realloc(str_palavra, tam); //ajusta a string para o formato de apenas os nomes contidos.
			if(str_palavra == NULL){printf("sem memoria");}
			break;

			
			case 2:
			novaString[0] = '\0'; //limpa a novastring
			token[0] = '\0'; //limpa o token
			palavra[0] = '\0'; // limpa a palavra

			token[0] = strtok(str_palavra, ";"); //separa a string no primeiro token
			
  			while (token[contador] != NULL)
  			{
				contador++;
				token[contador] = strtok(NULL, ";");
			}

			printf("Qual nome deve ser excluido?\n");
			scanf("%s", palavra);

			for (int j = 0; j <= contador - 1; j++)	// um -1 para o NULL.
			{		
				if(strcmp(token[j], palavra) != 0){
					strcat(novaString, token[j]); //armazena todos os tokens menos o ultimo na nova string
					strcat(novaString, ";"); //coloca o separador novamente
				}
			}
			strcpy(str_palavra ,novaString);
			str_palavra = (char*)realloc(str_palavra, strlen(str_palavra)); //ajusta a string para o formato de apenas os nomes contidos.
			printf("\nPalavra retirada.");
			break;



			case 3:
            printf("\nA string de nomes e: %s", str_palavra);
            printf("\n");
			break;


			case 4:
			break;


			default:
			printf("\n\nOPCAO INVALIDA!\n");
		}
	}


novaString[0] = '\0'; //limpa a novastring
token[0] = '\0'; //limpa o token
palavra[0] = '\0'; // limpa a palavra
free(str_palavra); //apaga tudo do conteudo do ponteiro
return 0;
    
}
