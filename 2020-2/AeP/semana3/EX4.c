#include <stdio.h>
#include<math.h>
int main(){
int n1, n2;
	
printf("Digite o múmero de lados: ");
scanf("%d",&n1);

if ( n1 == 3 || n1 == 4 ){
	printf("Digite a medida dos lados: ");
	scanf("%d",&n2);
}
if ( n1 == 3 ) {
	printf("É um triângulo de perímetro igual a %d", (n1 * n2));
	}
if ( n1 == 4) {
	printf("É um quadrado de área igual a %d", (n2 * n2));
	}
if ( n1 == 5) {
	printf("É um pentágono.");
	}	
if ( n1 < 3) {
	printf("Não é um polígono.");
	}	
if ( n1 > 5) {
	printf("Polígono não identificado.");
	}	
return 0;
}
