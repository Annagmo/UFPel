#include <stdio.h>

int main (){
	float x,y,div;
	printf("Digite o numerador: ");
	scanf("%f", &x);

	printf("Digite o denominador: ");
	scanf("%f", &y);
	
	do { printf("Digite o denominador: ");
		scanf("%f", &y);
	}while (y==0);
	
	div = x/y;
	printf("A divisão de %f, %f será: %.2f",x,y,div);

}
