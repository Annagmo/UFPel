/*
 * Escreva um programa, que crie e preencha um vetor com 1000 números inteiros
aleatórios (variando de 0 até 3000, inclusive).
Ainda nesse programa, crie um menu com as seguintes opções (utilize uma função
para cada opção):
Opção 1 - Imprima o maior número e sua respectiva posição no vetor.
Opção 2 - Imprima todos os números pares do vetor (caso não encontre, informe o usuá-
rio).
Opção 3 – Inverter os valores no próprio vetor (Obs.: Só armazenar na ordem inversa! Não
imprima o vetor!). Após inverter, imprima para o usuário: “O conteúdo do vetor foi invertido”
Opção 4 – Imprimir o vetor.
Opção 5 - Sair.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void MaiorNum(int v[]){ //função para a opcao 1.
	int i,maior = v[0];
	for(i=1;i<1000;i++){
		if(v[i]>=maior){maior = v[i];}
	}
	
	for(i=1;i<1000;i++){
		if(v[i]==maior){
			printf("O maior número do vetor aleatório é: %d e é o %dº termo",maior,i+1);
			printf("\n\n");
		}
	}
}

void ImprimePar(int v[]){ //função para a opcao 2.
	int i;
	
	for(i=0;i<1000;i++){
		if(v[i]%2==0){printf("%d, ",v[i]);}
	}
	printf("\n\n");
}




void InverteVetor(int v[]){ //função para a opcao 3.
	int i,j=999,auxiliar;
	
	for(i=0;i<=j;i++){
		auxiliar = v[i];
		v[i] = v[j];
		v[j] = auxiliar;
		j--;
	}
	for(i=0;i<1000;i++){printf("%d, ",v[i]);}
	
	printf("\n\n");
}


void ImprimeVetor(int v[]){ //função para a opcao 4.
	int i;
	for(i=0;i<1000;i++){
		printf("%d, ",v[i]);
	}
	printf("\n\n");
}
int main(){
	int vetorAleat[1000],i,opcao;
	
	//srand(clock());
	for(i=0;i<1000;i++){ //crie e preencha vetor
		vetorAleat[i] = rand() % 3001; //vai variar de 0 a 3000
	}
	
	while(opcao!=5){
	//menu:
	printf("---------------------------------------\n");
	printf("|  Bem- Vindo ao Programa de Vetores  |\n");
	printf("---------------------------------------\n\n");
	printf("Escolha dentre as seguintes opções:\n\n");
	printf("Opcão 1: Maior número e posição no vetor.\n");
	printf("Opcão 2: Números pares do vetor.\n"); 
	printf("Opcão 3: Armazenamento na ordem inversa.\n");
	printf("Opcão 4: Imprimir o vetor.\n");
	printf("Opcão 5: Sair.\n\n");         
	printf("Digite:");
	scanf("%d",&opcao);
	
		switch(opcao){
			case 1:
				MaiorNum(vetorAleat);
				break;
			case 2:
				ImprimePar(vetorAleat);
				break;
			case 3:
				InverteVetor(vetorAleat);
				printf("O conteúdo do vetor foi invertido.\n");
				break;
			case 4:
				ImprimeVetor(vetorAleat);
				break;
			case 5:
				break;
				
			default:
				printf("Digite uma opção válida: \n");
				break;
		}
	}
	return 0;
}
