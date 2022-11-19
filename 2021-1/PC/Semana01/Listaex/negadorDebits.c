
#include <stdio.h>
int NegadorDeBits(unsigned char n);

int main()
{
	unsigned char x,y;

	x = 24;

	int contador = 1;
	
	printf("Negador de Bits:\n");
	
	while(contador<=x){
		y = ~contador;
		printf("Número %d é oposto em bits ao número %d\n",contador,y);
		contador++;
	}
	return 0;
}

/* 
24 em bits:  00011000

231 em bits: 11100111
 */


