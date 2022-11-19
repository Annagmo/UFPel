#include <stdio.h>

int main(void){
	
	float a, b, c, m1, m2;
	printf("Digite o primeiro número:");
	scanf("%f",&a);
	printf("Digite o segundo número:");
	scanf("%f", &b);
	printf("Digite o terceiro número:");
	scanf("%f", &c);
	
	if (a > b && a > c ){
		m1 = a;
		if (b > c){
			m2 = b;
		}
		if ( c > b){
			m2 =c;
		}
	}
	if (b > c && b > a){
		m1 = b;
		if (a> c){
			m2 = a;
		}
		if ( c > a){
			m2 =c;
		}
	}
	if (c > a && c > b){
		m1 = c;
		if (b> a){
			m2 = b;
		}
		if ( a > b ){
			m2 =a;
		}
	}
printf("Os maiores valos são: %f e %f, e a multiplicação é: %f", m1, m2, (m1 * m2));


return 0;
}
