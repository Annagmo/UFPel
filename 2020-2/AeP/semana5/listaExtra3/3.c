#include <stdio.h>

int main(void)
{
        int n,soma = 0,media;
        int contador = 1;

        do{
            printf("Digite o %d número: ",contador);
            scanf("%d",&n);
			
			soma = soma + n;
			contador++;
			
		}while(contador<10);
		
		media = soma/10;
		printf("A média será: %d \n",media);
}

