/*Escreva um programa para ler o salário mensal e o percentual de reajuste. Calcular e
escrever o valor do novo salário.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float renda(float x, float y);

int main()
{
	float salario,reajuste;
	printf("Digite o salário mensal:");
	scanf("%f", &salario);
	
	printf("Digite o percentual de reajuste:");
	scanf("%f", &reajuste);
	
	printf("novo salário: %.2f",renda(salario,reajuste));
}

float renda(float x, float y){
	float NovoSal;
	y = y/100;
	
	NovoSal = x + (x*y);
	return NovoSal;	
}

