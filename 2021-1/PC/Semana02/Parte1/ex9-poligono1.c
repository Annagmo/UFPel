/*Escreva um programa para ler o número de lados de um polígono regular, e a medida do
lado (a medida do lado só deve ser lida para polígono com 3 ou 4 lados). Calcular e
imprimir o seguinte:
- Se o número de lados for igual a 3 escrever TRIÂNGULO e o valor do seu perímetro.
- Se o número de lados for igual a 4 escrever QUADRADO e o valor da sua área.
- Se o número de lados for igual a 5 escrever PENTÁGONO.
OBS: Considere que o usuário só informará os valores 3,4 ou 5.*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int lados,tamanho;
		printf("Qual o número de lados? ");
		scanf("%d",&lados);
		
	if(lados==3 || lados==4){
		printf("Qual o tamanho do lado? ");
		scanf("%d",&tamanho);
		if(lados==3){ printf("O polígono é um triângulo e seu perímetro é: %d ",lados*tamanho);}
		else { printf("O polígono é um quadrado e sua área é: %d ",tamanho*tamanho);}
	}
	else printf("O polígono é um pentágono.");
		
return 0;	
}
