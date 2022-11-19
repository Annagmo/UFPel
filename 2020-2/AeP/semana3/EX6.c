#include <stdio.h>

int main(void){
	
	int a, b, c;
	printf("Digite o primeiro número:");
	scanf("%d",&a);
	printf("Digite o segundo número:");
	scanf("%d", &b);
	printf("Digite o terceiro número:");
	scanf("%d", &c);
	
	if (a > b && a > c){
		printf(" %d é o maior valor", a);
	}
	if (b > c && b > a){
		printf(" %d é o maior valor", b);
	}
	if (c > a && c > b){
		printf(" %d é o maior valor", c);
	}
	

return 0;
}
