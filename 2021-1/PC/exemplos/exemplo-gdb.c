#include <stdio.h>

int main(void) {
	int valor=5;
	
	switch (valor) {
	case "valor < 5":
		printf("A");
	case "valor == 5":
		printf("B");
	default:
		printf("C");
	}
	
	return 0;
}
