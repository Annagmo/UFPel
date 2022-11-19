#include <stdio.h>

int main(void){
	
	int x, y;;
	printf("Digite a primeira coordenada:");
	scanf("%d",&x);
	printf("Digite a segunda coordenada:");
	scanf("%d", &y);

if ( x > 0 && y > 0){
	printf("primeiro quadrante: (%d,%d)", x, y);
}
if ( x < 0 && y > 0){
	printf("segundo quadrante: (%d,%d)", x, y);
}
if ( x < 0 && y < 0){
	printf("terceiro quadrante: (%d,%d)", x, y);
}
if ( x > 0 && y < 0){
	printf("quarto quadrante: (%d,%d)", x, y);
}
if ( x == 0 || y == 0){
	printf("O ponto (%d,%d) não está em nenhum quadrante.", x, y);
}


return 0;
}
