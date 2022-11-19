#include <stdio.h>

int main(void){
	
	float a, b, c;
	printf("Digite o primeiro número:");
	scanf("%e",&a);
	
	printf("Digite o segundo número:");
	scanf("%e", &b);
	
	printf("Digite o terceiro número:");
	scanf("%e", &c);
	
	if (a < (b+c) && b < (c+a) && c < (a+b)) {
		printf("Esses números são capazes de formar um triângulo");
		}
	else{
        printf("Esses números não são capazes de formar um triângulo");
	}
}
