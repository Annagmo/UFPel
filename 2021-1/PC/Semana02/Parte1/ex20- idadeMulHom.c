/*Escreva um programa que leia a idade de 2 homens e 2 mulheres (considere que a idade dos
homens será sempre diferente, assim como das mulheres). Calcule e escreva a soma das
idades do homem mais velho com a mulher mais nova, e o produto das idades do homem
mais novo com a mulher mais velha.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	int m1,m2,h1,h2;
	
	printf("Digite a idade de uma mulher: ");
	scanf("%d",&m1);
	printf("Digite a idade de uma mulher: ");
	scanf("%d",&m2);
	printf("Digite a idade de um homem: ");
	scanf("%d",&h1);
	printf("Digite a idade de um homem: ");
	scanf("%d",&h2);
	
	if(m1<m2){
		if(h1<h2){
			printf("a soma das idades do homem mais velho com a mulher mais nova: %d + %d = %d",h2,m1,h2+m1);
			printf("\no produto das idades do homem mais novo com a mulher mais velha: %d * %d = %d",h1,m2,h1*m2);
			}
		else{printf("a soma das idades do homem mais velho com a mulher mais nova: %d + %d = %d",h1,m1,h1+m1);
			printf("\no produto das idades do homem mais novo com a mulher mais velha: %d * %d = %d",h2,m2,h2*m2);
			}
	}
	else{
		if(h1<h2){
			printf("a soma das idades do homem mais velho com a mulher mais nova: %d + %d = %d",h2,m2,h2+m2);
			printf("\no produto das idades do homem mais novo com a mulher mais velha: %d * %d = %d",h1,m1,h1*m1);
			}
		else{printf("a soma das idades do homem mais velho com a mulher mais nova: %d + %d = %d",h1,m2,h1+m2);
			printf("\no produto das idades do homem mais novo com a mulher mais velha: %d * %d = %d",h2,m1,h2*m1);
			}
	}
	return 0;
}

