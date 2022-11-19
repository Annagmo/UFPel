#include <stdio.h>

int main(void)
{
        int n,soma = 0,media,qtd;
        int contador = 1;

		printf("Quantos alunos são? ");
        scanf("%d",&qtd);
        do{
            printf("Digite a %d nota: ",contador);
            scanf("%d",&n);
			
			soma = soma + n;
			contador++;
			
		}while(contador<=qtd);
		
		media = soma/qtd;
		printf("A média será: %d \n",media);
}


