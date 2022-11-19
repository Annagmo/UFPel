#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int i, j, k, m[10][10];
	srandom(time(NULL));
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			k = random() % 100;
			if (k < 20)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
