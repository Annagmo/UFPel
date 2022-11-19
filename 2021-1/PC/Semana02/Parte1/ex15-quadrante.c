/*Escreva um programa para ler as coordenadas (X, Y) de um ponto no sistema cartesiano e
escrever o quadrante ao qual o ponto pertence. Considere que o usuário não informará
nenhuma coordenada igual a zero.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	int x,y;
	
	printf("Digite a primeira coordenada: ");
	scanf("%d",&x);
	printf("Digite a segunda coordenada: ");
	scanf("%d",&y);
	
	if(x>0){
		if(y>0){printf("Primeiro quadrante");}
		else printf("Quarto quadrante");
	}
	if(x<0){
		if(y>0){printf("Segundo quadrante");}
		else printf("Terceiro quadrante");
	}
	return 0;
}
