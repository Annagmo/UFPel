#include <stdio.h>

int main(void){
	
	float a, b, c, m1, m2, m3;
	printf("Digite o primeiro número:");
	scanf("%f",&a);
	printf("Digite o segundo número:");
	scanf("%f", &b);
	printf("Digite o terceiro número:");
	scanf("%f", &c);
	
		if (a > b && a > c){
		m1 = a;
		if (b > c){
			m2 = b;
			m3 = c;
		}
		if ( c > b){
			m2 =c;
			m3 = b;
		}
	}
	if (b > c && b > a){
		m1 = b;
		if (a> c){
			m2 = a;
			m3 = c;
		}
		if ( c > a){
			m2 =c;
			m3 = c;
		}
	}
	if (c > a && c > b){
		m1 = c;
		if (b> a){
			m2 = b;
			m3 = a;
		}
		if ( a > b ){
			m2 =a;
			m3 = b;
		}
	}
printf(" Em ordem crescente: %f %f %f.", m3, m2, m1);

return 0;
}
