/*Escreva um programa para ler as notas das duas avaliações de um aluno no semestre,
calcular e escrever a média semestral e uma mensagem indicando se ele foi aprovado,
reprovado ou está em exame.*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int i,media=0,nota;
		for(i=0;i<2;i++){
			printf("Digite a nota %d do aluno:",i+1);
			scanf("%d",&nota);
			media+=nota;
		}
	media = media/2; 
	if(media>=3){
		if (media>=7){printf("APROVADO");}
		else printf("EXAME");
	}
	if(media<3){printf("REPROVADO");}
	
	
return 0;	
}

