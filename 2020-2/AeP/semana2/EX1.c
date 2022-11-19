#include <stdio.h>

int main(void){
	
	int a, b;
	printf("Digite o primeiro número:");
	scanf("%d",&a);
	printf("Digite o segundo número:");
	scanf("%d", &b);
	if (a > b){
	printf("Menor valor: %d\nMaior valor: %d\n",b, a);
	}
	if ( b > a){
	printf("Menor valor: %d\nMaior valor: %d\n",a,b);
	}
	if ( b == a){
	printf("OS valores %d, %d são iguais.",a,b);
	}
}
	
