/*Escreva um programa para ler uma temperatura em graus Fahrenheit, calcular e escrever o
valor correspondente em graus Celsius.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float temperatura(float f);

int main()
{
	float Fahrenheit;
	printf("Digite a temperatura em Fahrenheit:");
	scanf("%f", &Fahrenheit);
	
	printf("temperatura em Celcius: %.1f",temperatura(Fahrenheit));
}

float temperatura(float f){
	float c;
	c = ((f-32)*5)/9;
	return c;	
}


