#include <stdio.h>

int main(void){
	
	int x;
	printf("Digite o número:");
	scanf("%d",&x);
	if (x < 0){
	printf("O valor: %d é negativo", x);
	}
	if (x > 0){
	printf("O valor: %d é positivo", x);
	}
	if (x == 0){
	printf("O valor é igual a 0");
	}
}
	
