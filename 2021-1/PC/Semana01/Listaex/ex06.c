/*Escreva um programa para ler o número de eleitores de um município, o número de votos
brancos, nulos e válidos. Calcular e escrever o percentual que cada um representa em
relação ao total de eleitores.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void votacao();
int main(){votacao();}

void votacao(){
	int eleitores, brancos, nulos, validos;
	float Pcbrancos, Pcnulos, Pcvalidos;
	
	printf("Digite o total de eleitores:");
	scanf("%d", &eleitores);
	printf("Digite o total de votos brancos:");
	scanf("%d", &brancos);
	printf("Digite o total de votos nulos:");
	scanf("%d", &nulos);
	printf("Digite o total de votos válidos:");
	scanf("%d", &validos);
	
	Pcbrancos = (brancos *100)/ eleitores;
	Pcnulos = (nulos*100)/eleitores;
	Pcvalidos = (validos*100)/eleitores;
	
	printf("Porcentagem de votos brancos: %.1f\n",Pcbrancos);
	printf("Porcentagem de votos nulos: %.1f\n",Pcnulos);
	printf("Porcentagem de votos validos: %.1f\n",Pcvalidos);
}

