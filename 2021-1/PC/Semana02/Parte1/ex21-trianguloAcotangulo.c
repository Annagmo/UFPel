/*Escreva um programa que leia o valor de 3 ângulos de um triângulo e escreva se o triângulo
é acutângulo, retângulo ou obtusângulo.
OBS: triângulo retângulo: possui um ângulo reto.
triângulo obtusângulo: possui um ângulo obtuso.
triângulo acutângulo: possui 3 ângulos agudos.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	int angulo1,angulo2,angulo3;
	
	printf("Digite o primeiro ângulo do triângulo: ");
	scanf("%d",&angulo1);
	printf("Digite o segundo ângulo do triângulo: ");
	scanf("%d",&angulo2);
	printf("Digite o terceiro ângulo do triângulo: ");
	scanf("%d",&angulo3);

	if(angulo1==90 ||angulo2==90 ||angulo3==90 ){printf("É um triângulo retângulo");}
	else{
		if(angulo1>=90 ||angulo2>=90 ||angulo3==90){printf("É um triângulo obtusângulo");}
		else printf("É um triângulo acutângulo");
	}
	return 0;
}


