#include <stdio.h>

int main(void){
	
	int x, div;
	
	printf("Digite o número:");
	scanf("%d",&x);
	
	div = x % 2;
	
	if (x < 0){
	printf(" O valor: %d é negativo", x);
	}
	if (x > 0){
	printf(" O valor: %d é positivo", x);
	}
	if (x == 0){
	printf("\nO valor é igual a 0");
	}
	if (div == 0){
	printf("\nO valor: %d é par", x);
	}
	if (div != 0){
	printf("\n O valor: %d é impar", x);
	}
}
	
