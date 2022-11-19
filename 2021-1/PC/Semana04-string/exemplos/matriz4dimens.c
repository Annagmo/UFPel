#include <stdio.h>
int main()
{
	float num[1][2][3][4];
	int i, j,k,l;

	for (i = 0; i < 1; i++)
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++) {
				for (l = 0; l < 4; l++) {
					printf("digite o elemento [%d][%d][%d][%d]:\n",i + 1, j + 1,k+1,l+1);
					scanf("%f", &num[i][j][k][l]);
				}
			}
		}
		
	printf("Matriz:");
		for (i = 0; i < 1; i++)
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++) {
				for (l = 0; l < 4; l++) {
					printf("%.2f",num[i][j][k][l]);
					printf("\n");
				}
			printf("\n");
			}
		printf("\n");
		}
	return 0;
}
