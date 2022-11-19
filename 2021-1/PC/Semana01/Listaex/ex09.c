/*uma loja vende bicicletas com um acréscimo de 50 % sobre o seu preço de custo. Ela paga a
cada vendedor 2 salários-mínimos mensais, mais uma comissão de 15 % sobre o preço de
custo de cada bicicleta vendida, dividida igualmente entre eles. Escreva um programa que
leia o número de empregados da loja, o valor do salário-mínimo, o preço de custo de cada
bicicleta, o número de bicicletas vendidas, calcule e escreva: O salário final de cada
empregado e o lucro (líquido) da loja.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bicicleta(int Num_empregados, float SalMin,float CustoBici,int Nr_bici);

int main()
{
	int Nr_empregados, Nr_bicicleta;
	float SalMinimo, CustoBicicleta;

	
	printf("Digite o número de empregados da loja:");
	scanf("%d", &Nr_empregados);
	printf("Digite o valor do salário-mínimo:");
	scanf("%f", &SalMinimo);
	printf("Digite o preço de custo de cada bicicleta:");
	scanf("%f", &CustoBicicleta);
	printf("Digite o número de bicicletas vendidas:");
	scanf("%d", &Nr_bicicleta);
	
	
	bicicleta(Nr_empregados,SalMinimo,CustoBicicleta,Nr_bicicleta);
}

void bicicleta(int Num_empregados, float SalMin,float CustoBici,int Nr_bici){
	float lucro,VendaBici,comissao,salario;
	
	VendaBici = (50 * CustoBici)/100 + CustoBici;
	lucro = (VendaBici * Nr_bici)-(CustoBici * Nr_bici);
	
	comissao = ((15* CustoBici)/100)/Num_empregados; //comissão individual que vai ser acrescida no salario
	salario = (2 * SalMin) + comissao;
	
	printf("\nO salário final de cada empregado é: %.2f\n",salario);
	printf("O lucro (líquido) da loja é: %.2f reais\n",lucro);	
}
