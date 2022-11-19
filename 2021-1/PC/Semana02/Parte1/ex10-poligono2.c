/*Acrescente as seguintes mensagens a solução do exercício anterior conforme o caso.
- Caso o número de lados seja inferior a 3 escrever NÃO É UM POLÍGONO.
- Caso o número de lados seja superior a 5 escrever POLÍGONO NÃO IDENTIFICADO.*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	int lados,tamanho;
		printf("Qual o número de lados? ");
		scanf("%d",&lados);
		
	if(lados==3 || lados==4){
		printf("Qual o tamanho do lado? ");
		scanf("%d",&tamanho);
		if(lados==3){ printf("O polígono é um triângulo e seu perímetro é: %d ",lados*tamanho);}
		else printf("O polígono é um quadrado e sua área é: %d ",tamanho*tamanho);
	}
	else if(lados==5||lados<3){
		if(lados<3){printf("NÃO É UM POLÍGONO.");}
		else printf("O polígono é um pentágono.");
	}
	else if (lados>5){ printf("POLÍGONO NÃO IDENTIFICADO.");}
		
return 0;	
}
