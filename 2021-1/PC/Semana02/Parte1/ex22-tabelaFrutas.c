/*Um mercado está vendendo frutas com a tabela de preços abaixo. Se o cliente comprar mais
de 8 Kg em frutas ou o valor total da compra ultrapassar R$ 35,00, receberá ainda um
desconto de 20 % sobre esse total. Escreva um programa para ler a quantidade (em Kg) de
morangos e a quantidade (em Kg) de maçãs adquiridas e escreva o valor a ser pago pelo
cliente.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	float ValorPago,gastoMorango, gastoMaca;
	int macas,morangos;
	
	printf("Informe quantos quilos de macas foram vendidas: ");
	scanf("%d",&macas);
	printf("Informe quantos quilos de morangos foram vendidos: ");
	scanf("%d",&morangos);
	
	if(macas>5){gastoMaca=2*macas;}
	if(morangos>5){gastoMorango = 4*morangos;}
	
	if(0<=macas && macas<=5){gastoMaca=3*macas;}
	if(0<=morangos && morangos<=5){gastoMorango = 5*morangos;}
	else if (macas<0 || morangos<0){printf("Não é possível comprar quantidade negativa de fruta.");}
	
	if(macas+morangos>=8 || gastoMaca+gastoMorango>= 35){
		ValorPago= 0.80 * (gastoMaca+gastoMorango);
		}
	else ValorPago = gastoMaca+gastoMorango;
	printf("Valor a pagar: %.2f",ValorPago);
	
	return 0;
}
