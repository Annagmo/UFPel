#include <stdio.h>
//int NegadorDeBits(unsigned char n);

int main()
{
	unsigned char x;

	x = 7;
	printf("%d", x);
	x = x << 1; // x*2^1
	printf("\n%d", x); //o x agora é 14
	x = x << 3; // x*2^3
	printf("\n%d", x); //o x agora é 112
	x = x << 2; // x*2^2
	printf("\n%d", x); //o x agora é 192
	x = x >> 1; // x/2^1
	printf("\n%d", x); //o x agora é 96
	x = x >> 2; // x/2^2
	printf("\n%d", x); //o x agora é 24
	x = ~x; //~ operator is bitwise negation
	printf("\n%d", x); //o x agora é 231
	return 0;
	
	//NegadorDeBits(x);
}

/* 
24 em bits:  00011000

231 em bits: 11100111
 */

/*int NegadorDeBits(unsigned char n){
	unsigned char y;
	int contador = 1;
	
	printf("\n\n\nFunção Negador de Bits:\n");
	
	if(contador<=n){
		y = ~contador;
		printf("Número %d é oposto em bits ao número %d\n",contador,y);
		contador++;
	}
	return 0;
}*/
