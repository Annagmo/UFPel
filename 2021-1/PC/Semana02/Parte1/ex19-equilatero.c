/*Escreva um programa que leia as medidas dos lados de um triângulo e escreva se ele é
EQUILÁTERO, ISÓSCELES ou ESCALENO.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	int lado1,lado2,lado3;
	
	printf("Digite o primeiro lado do triângulo: ");
	scanf("%d",&lado1);
	printf("Digite o segundo lado do triângulo: ");
	scanf("%d",&lado2);
	printf("Digite o terceiro lado do triângulo: ");
	scanf("%d",&lado3);
	
	if(lado1==lado3){
		if(lado2==lado1){printf("é equilátero.");}
		else printf("é isósceles.");
	}
	else if(lado2==lado3){
		if(lado1==lado2){printf("é equilátero.");}
		else printf("é isósceles.");
	}
	else if(lado1==lado2){
		if(lado3==lado1){printf("é equilátero.");}
		else printf("é isósceles.");
	}
	else printf("é escaleno.");
	
	
	return 0;
}
