#include <stdio.h>
int main()
{
	int i, n;
	float valor, media;
	media = 0;

	printf("entre com o numero de valores\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("entre com o %d valor\n", i + 1);
		scanf("%f", &valor);
		media += valor;
	}
	media /= n;
	printf("A media destes valores eh:%f\n", media);
	return 0;
}
