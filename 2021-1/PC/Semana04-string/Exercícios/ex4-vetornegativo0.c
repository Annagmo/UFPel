/*Ler um vetor C de 10 elementos inteiros. Após o término da leitura, trocar todos os valores
negativos do vetor C por 0. Após todas as trocas terem sido efetuadas, escrever o vetor C.*/
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	float C[10];
	int i;
	
	for (i=0;i<10;i++){
		printf("Digite um valor:");
		scanf("%f",&C[i]);
	}
		
	for (i=0;i<10;i++){
		if(C[i]<0){
		C[i]= 0;}
		}
	for (i=0;i<10;i++){printf("%.1f\n",C[i]);}
	return 0;
}
