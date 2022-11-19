/*O banco BANK Co. deseja utilizar o computador para determinar o limite da conta especial
de seus clientes a partir do saldo da conta-corrente e da poupança. Escreva um programa
para ler o saldo da conta-corrente e da poupança de um cliente e escrever o seguinte:
- A mensagem: ‘SEM CONTA ESPECIAL’ se o cliente NÃO possuir o requisito necessário
para a conta especial. (REQUISITO PARA POSSUIR CONTA ESPECIAL: o saldo em, pelo
menos, uma das duas contas deve estar acima de R$1000,00)
- O valor do limite da conta conforme especificação abaixo:
* O valor limite da conta especial fornecido ao cliente deve ser o dobro do maior
saldo (entre c.corrente e poupança) ou o triplo do menor saldo. Deve ser fornecido o valor
de limite maior entre essas 2 situações. OBS: Considere que os saldos da c.corrente e
poupança não são iguais.*/
#include <stdio.h>
#include <stdlib.h>

int main () {
	float contaCorrente,poupanca,limite1,limite2,contaEspecial=0;
	
	printf("Informe o saldo da conta-corrente: ");
	scanf("%e",&contaCorrente);
	printf("Informe o saldo da poupança: ");
	scanf("%e",&poupanca);
	

	
	
	if(contaCorrente>1000 || poupanca>1000){ 
		if(contaCorrente>=poupanca){limite1 = 2*contaCorrente;limite2 = 3*poupanca;}
		else{limite1 = 2*poupanca;limite2 = 3*contaCorrente;}
		contaEspecial=1;
		}
	else{printf("SEM CONTA ESPECIAL.");}
	
	if(contaEspecial==1){
		if(limite1>=limite2){printf("Você possui conta especial, e o limite é: %.2f",limite1);}
		else printf("Você possui conta especial, e o limite é: %.2f",limite2);
	}
	
	return 0;
}
