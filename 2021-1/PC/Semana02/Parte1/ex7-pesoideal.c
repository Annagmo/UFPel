/*Tendo como entrada a altura e o sexo (codificado da seguinte forma: 1:feminino
2:masculino) de uma pessoa, construa um programa que calcule e imprima seu peso ideal,
utilizando as seguintes fórmulas:
- para homens: (72.7 * h)-58
- para mulheres: (62.1*h)-44.7*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int sexo;
	float altura,peso;

	printf("Digite 1 para sexo feminino e 2 para sexo masculino: ");
	scanf("%d", &sexo);
	
	printf("Digite a altura (X.xx): ");
	scanf("%f", &altura);

		
	switch(sexo){
		case 1:
			peso = (62.1 * altura) - 44.7 ;
			break;
		case 2:
			peso = (72.7 * altura)-58;
			break;	
		default:
			printf("Código inválido.");	
			break;
	}
	printf("%f",peso);
	return 0;
}
