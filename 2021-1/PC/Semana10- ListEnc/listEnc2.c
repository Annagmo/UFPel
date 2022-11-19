/*esse é um programa de lista encadeada básico 
 * (parecido com o exemplo do prof) com algumas alterações*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct cel celula;
struct cel {
	int dado;
	celula *prox;
};

void insere (int x, celula *p){
	celula *nova;
	nova = (celula *) malloc (sizeof(celula));
	nova->dado = x;
	nova->prox = p->prox;
	p->prox = nova;
}

void imprime(celula *ini){	
	celula *p;
	printf("\nValores na lista:\n");
	
	for (p = ini->prox; p != NULL; p = p->prox) {
		printf ("%d\t", p->dado);
	}
	printf ("\n");
}

/*aqui é onde eu realmente fiz algo diferente:
 * tem vários tipos de jogo do bicho. eu escolhi o que é gerado um nr de 4 digitos
 * as apostas do usuário tem 2 dígitos (teria que conferir). E se, alguma
 * aposta do usuário bater com os ultimos 2 dígitos do número sorteado ele ganha.
 * (cada nr é relacionado a um animal, eu não tentei isso ainda)*/
 
void resultado(celula *ini){ 
	int cont=0;	
	int rand_num;
	
	srand(time(0));
	rand_num = rand() % 9000 + 1000; //o número aleatório é gerado
	celula *p;
	
	for (p = ini->prox; p != NULL; p = p->prox) {
		if(p->dado==(rand_num%100)){ //%100 compara os dois últimos dígitos
			cont++; //se baterem os números, aumenta o contador
			}
		}
	if(cont>0){
		printf("\nVocê venceu!\n"); // se o contador não for 0, tu vence.
	}
	else{
		printf("\nVocê perdeu!\n");
	}
	printf ("\nO número sorteado foi: %d \n",rand_num);
}

int main() {	
	int op = -1, valor;
	celula *lista = NULL;
	lista = (celula *) malloc(sizeof(celula));
	
	printf("\n Bem-vindo ao Jogo do Bicho!\n"); //menu:
	while (op != 3) { // se ele não pedir pra ver o resultado, continua rodando.
		printf("\nOpções disponı́veis:\n");
		printf("\t1 p/ imprimir a lista de apostas.\n");
		printf("\t2 p/ fazer uma nova aposta.\n");
		printf("\t3 p/ ver o resultado.\n");
		printf("Entre opção desejada: ");
		scanf("%d", &op);
		

			switch(op) {

			case 1:
			imprime(lista);
			break;
			
			case 2:
			printf("\nEntre com o número da aposta: ");
			scanf("%d", &valor);
			insere(valor, lista);
			printf("\nAposta adicionada a lista.\n ");
			break;
			
			case 3:
			resultado(lista);
			break;
			default:
			printf("\n\nOPCAO INVALIDA!\n");
		}
	}
return 0;
}
