//Escreva um programa para ler o raio de um círculo, calcular e escrever a sua área.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.141592
float CalculArea(float x);

int main()
{
	float raio;
	printf("Digite o raio da circunferência:");
	scanf("%f", &raio);
	
	printf("Área = %f",CalculArea(raio));
}

float CalculArea(float x){
	float area;
	
	area = (Pi * (x*x));
	return area;	
}

