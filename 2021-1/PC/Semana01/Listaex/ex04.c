#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float temperatura(float c);

int main()
{
	float celcius;
	printf("Digite a temératura em Celcius:");
	scanf("%f", &celcius);
	
	printf("temperatura em Fahrenheit: %.1f",temperatura(celcius));
}

float temperatura(float c){
	float f;
	f = ((9*c)/5) + 32;
	return f;	
}


