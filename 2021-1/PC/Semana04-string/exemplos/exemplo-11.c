#include <stdio.h>
int main()
{
	float nota[50];
	int i;
	for (i = 0; i < 100; i++) {
		printf("Nota %d:\n", i + 1);
		scanf("%f", &nota[i]);
		printf("Nota %.2f:\n",nota[i]);
	}
		for (i = 0; i < 100; i++) {
		printf("Nota %.2f:\n",nota[i]);
	}
	return 0;
}
