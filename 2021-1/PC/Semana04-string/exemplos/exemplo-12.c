#include <stdio.h>
int main()
{
	float num[3][4];
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++) {
			printf("digite o elemento da linha %d, coluna %d\n",
			       i + 1, j + 1);
			scanf("%f", &num[i][j]);
		}
	return 0;
}
