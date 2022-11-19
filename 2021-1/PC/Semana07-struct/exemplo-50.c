#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} ponto;

typedef struct {
	ponto cie;		//canto inferior esquerdo
	ponto csd;		//canto superior direito
} retangulo;

typedef struct {
	ponto centro;
	float raio;
} circulo;

float distancia(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2));
}

int main()
{
	ponto A;
	ponto B;
	circulo C;
	retangulo R;
	float dist;

	printf("Informe as coordenadas do ponto A: ");
	scanf("%d %d", &A.x, &A.y);
	printf("Informe as coordenadas do ponto B: ");
	scanf("%d %d", &B.x, &B.y);

	R.cie = A;
	R.csd = B;
	printf("Coordenada do CIE de R: (%d,%d)\n", R.cie.x, R.cie.y);
	printf("Coordenada do CSD de R: (%d,%d)\n\n", R.csd.x, R.csd.y);

	C.centro = B;
	C.raio = 10.0;
	printf("Coordenada do centro de C: (%d,%d)\n", C.centro.x, C.centro.y);
	printf("Raio de C: %f\n", C.raio);

	dist = distancia(C.centro.x, C.centro.y, A.x, A.y);
	if (dist <= C.raio)
		printf("O ponto A está DENTRO do círculo C.\n");
	else
		printf("O ponto A está FORA do círculo C.\n");
	printf("Distância do ponto A ao centro de C: %f", dist);
	return 0;
}
