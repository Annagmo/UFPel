#include <stdio.h>
int main()
{
	float vet[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	float *f;
	int i;
	f = vet;
	printf("contador/valor/valor/endereco/endereco");
	for (i = 0; i <= 4; i++) {
		printf("\ni = %d", i);
		printf("   vet[%d] = %.1f", i, vet[i]);
		printf("   *(f + %d) = %.1f", i, *(f + i));
		printf("   &vet[%d] = %p", i, &vet[i]);
		printf("   (f + %d) = %p", i, f + i);
	}
	return 0;
}
