/*Escreva um programa para ler um vetor de 10 palavras.
A seguir ler uma letra. Copiar para outro vetor (sem deixar espaços vagos) 
todas as palavras que começam a letra informada. Após o término na cópia 
escrever o vetor gerado.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{

	char *vetor[10]= {"O","rato","roeu","a","roupa","do","rei","de","roma","fim"};
	char caractere,*retirada[10];
	//char palavra[30];//eu quebro o vetor, jogo a palavra pra um vetor, vajo se tem a letra, e enfio no outro
	int i=0,j,k;
	//j,k=0;//tam;
	
	//inicialização do vetor com espaços:
	for(j=0;j<10;j++){
		retirada[j] = " ";
	}
	
	//Pegar o caractere:
	printf("Digite o caractere: ");
	caractere = getchar();
	getchar();

	
	// Lembre-se que :   printf("%c\n",*vetor[0]);       retorna: a
	//                   printf("%s\n",vetor[0]);        retorna: anna
	
	for(j=0;j<10;j++){
		if(caractere==*vetor[j]){ // se não começar com a letra *vetor[j]
			retirada[k] = vetor[j]; //a palavra vetor[j]  entra na retirada. 
			k++;
		}
	}
	for(j=0;j<10;j++){
		printf("%s ",retirada[j]);
		}
	i++;
	
		
	return 0;
}
