#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int PrismaRet(float c, float a, float l);

int main()
{
	float comprimento, altura, largura;
	
	printf("Digite o comprimento da cozinha:");
	scanf("%f", &comprimento);
	
	printf("Digite a largura da cozinha:");
	scanf("%f", &largura);
	
	printf("Digite o comprimento da cozinha:");
	scanf("%f", &altura);
	
	printf("Quantidade de azulejos: %d",PrismaRet(comprimento,altura,largura));
}

int PrismaRet(float c, float a, float l){
	float superficie;
	int azulejos;
	superficie = 2*c + 2*a + 2*l;
	azulejos = (superficie/1.5);
	return azulejos;	
}


