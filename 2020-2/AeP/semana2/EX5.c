#include <stdio.h>

int main(void){
	
	float a;
	printf("Digite a idade:");
	scanf("%f",&a);
	
	if (5 <= a && a <= 7) {
	printf("O nadador é da categoria infantil A.");
	}
	if (8 <= a && a <= 10) {
	printf("O nadador é da categoria infantil B.");
	}
	if (11 <= a && a <= 13) {
	printf("O nadador é da categoria juvenil A.");
	}
	if (14 <= a && a <= 17) {
	printf("O nadador é da categoria juvenil B.");
	}
	if (a > 18) {
	printf("O nadador é da categoria adulto.");
	}	
	if (a < 5) {
        printf("O nadador não está em uma categoria");
	}
}
