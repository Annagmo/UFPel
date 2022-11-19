/*Um motorista de taxi deseja calcular o rendimento de seu carro na praça. Sabendo-se que o
preço do combustível é de R$ 2,70, escreva um programa para ler: a marcação do odômetro
(Km) no início do dia, a marcação (Km) no final do dia, o número de litros de combustível
gasto e o valor total (R$) recebido dos passageiros. Calcular e escrever: a média do consumo
em Km/L e o lucro (líquido) do dia.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void taxi(float inicioDia, float finalDia,float combustivel,float dinheiro);

int main()
{
	float inicioDia,finalDia,litroCombustivel,dinheiro;
	
	printf("Digite a marcação do odômetro(Km) no início do dia:");
	scanf("%f", &inicioDia);
	printf("Digite a marcação(Km) no final do dia:");
	scanf("%f", &finalDia);
	printf("Digite o número de litros de combustível gasto:");
	scanf("%f", &litroCombustivel);
	printf("Digite o valor total (R$) recebido dos passageiros:");
	scanf("%f", &dinheiro);
	
	
	taxi(inicioDia,finalDia,litroCombustivel,dinheiro);
}

void taxi(float inicioDia, float finalDia,float litroCombustivel,float dinheiro){
	float MediaConsumo, lucro, trajeto, GastoCombustivel;
	
	trajeto = finalDia - inicioDia;
	MediaConsumo = trajeto/litroCombustivel;
	GastoCombustivel = litroCombustivel * 2.70;
	lucro = dinheiro - GastoCombustivel;
	printf("\nA média do consumo é: %.2f Km/L \n",MediaConsumo);
	printf("O lucro (líquido) do dia é: %.2f reais\n",lucro);	
}
