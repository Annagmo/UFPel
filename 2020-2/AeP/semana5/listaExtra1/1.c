#include <stdio.h>

int main (){
	float salario,contador = 0,aumento,resultado;
	
	
	while(contador<=30){
		printf("Digite o valor do salário: ");
		scanf("%f", &salario);
		contador++;
		
		if(salario>=3000){
			aumento = 0.03 * salario;
			resultado = aumento + salario;
			printf("O salário aumentado será: %.2f \n",resultado);
		}
		if(salario>= 100 && salario<3000){
			aumento = 0.1 * salario;
			resultado = aumento + salario;
			printf("O salário aumentado será: %.2f \n",resultado);
		}
		if(salario<1000){
			aumento = 0.15 * salario;
			resultado = aumento + salario;
			printf("O salário aumentado será: %.2f \n",resultado);
		}
	}
}
