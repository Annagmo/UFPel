/*Escreva um programa para ler as 4 notas obtidas por um aluno em 4 avaliações. Calcular a
média usando a seguinte fórmula:*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 float media(int n1, int n2, int n3,int n4){
	float mediafinal=0.0;
	mediafinal = (n1+(n2*2)+(n3*3)+n4)/7;
	return mediafinal;
}
void classifica(float m){
	if(m>=0 && m<6){printf("Categoria D");}
	if(m>=6 && m<7.5){printf("Categoria C");}
	if(m>=7.5 && m<9){printf("Categoria B");}
	if(m>=9 && m<=10){printf("Categoria A");}
	
}
int main (){
  int nota1,nota2,nota3,nota4;
  float mediaUser;
  
	printf("Digite a primeira nota: ");
    scanf("%d", &nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%d", &nota2);
    
    printf("Digite a terceira nota: ");
    scanf("%d", &nota3);
    
    printf("Digite a quarta nota: ");
    scanf("%d", &nota4);
    
    mediaUser = media(nota1,nota2,nota3,nota4);
    printf("media: %.2f\n",mediaUser);
    classifica(mediaUser);

    
  return 0;
}



