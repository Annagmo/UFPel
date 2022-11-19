#include <stdio.h>

int main(void){
	
	float x;
	printf("Digite a nota:");
	scanf("%e",&x);
	if (0 < x && x <= 5){
	printf("O conceito é C.");
	}
		
	if (5 < x && x <= 7){
	printf("O conceito é C.");
	}
	if (7 < x && x <= 9){
		printf("O conceito é B.");
	}
	
	if (9 < x && x <= 10){
		printf("O conceito é A.");
	}
	if (x < 0 || x > 10){
		printf("Insira uma nota válida");
	}
}
	
