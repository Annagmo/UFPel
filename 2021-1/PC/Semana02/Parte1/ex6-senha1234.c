/*Escreva um programa que verifique a validade de uma senha fornecida pelo usuário. A
senha válida é o número 1234. Deve ser impressa uma das seguintes mensagens:
-ACESSO PERMITIDO caso a senha seja válida.
-ACESSO NEGADO caso a senha seja inválida.*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int tentativa;

	printf("Digite a Senha: ");
	scanf("%d", &tentativa);
		
	switch(tentativa){
		case 1234 :
			printf("ACESSO PERMITIDO");
			break;
		default:
			printf("ACESSO NEGADO");	
			break;
	}
	
	return 0;
}
