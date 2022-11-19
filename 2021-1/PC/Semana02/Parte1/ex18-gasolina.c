/*Um posto está vendendo combustíveis com a tabela de descontos abaixo. Escreva um
programa que leia o número de litros vendidos, o tipo de combustível (codificado da
seguinte forma: 1-álcool 2-Gasolina), o preço do combustível, calcule e imprima o valor a
ser pago pelo cliente.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	float preco,desconto,gasto;
	int litrosVendidos, opcao;
	
	printf("Digite o número de litros vendidos: ");
	scanf("%d",&litrosVendidos);
	printf("Digite o preço do combustível: ");
	scanf("%f",&preco);
	
	printf("\n________________________");
	printf("\n|Opções:                |");
	printf("\n|       1: Álcool       |");
	printf("\n|       2: Gasolina     |");
	printf("\n|_______________________|");

	printf("\n\nDigite a opção: ");
	scanf("%d",&opcao);
	
	if(opcao==1){
		if(litrosVendidos> 0 && litrosVendidos<20){
			desconto = 0.03 * litrosVendidos;
			gasto = litrosVendidos * preco;
			printf("Valor a ser pago: %.2f",gasto-desconto);
			}
		else{
			desconto = 0.05* litrosVendidos;
			gasto = litrosVendidos * preco;
			printf("Valor a ser pago: %.2f",gasto-desconto);
			}
	}
		
	else if(opcao==2){
		if(litrosVendidos>=0 && litrosVendidos<20){
			desconto = 0.035 * litrosVendidos;
			gasto = litrosVendidos * preco;
			printf("Valor a ser pago: %.2f",gasto-desconto);
			}
		else{
			desconto = 0.06 * litrosVendidos;
			gasto = litrosVendidos * preco;
			printf("Valor a ser pago: %.2f",gasto-desconto);
			}
	}
	else printf("Insira uma opção válida");
	return 0;
}
