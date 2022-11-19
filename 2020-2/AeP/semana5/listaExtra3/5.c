#include <stdio.h>

int main(void)
{
        int n1,n2,soma=0,contador;

		printf("Digite o valor1: ");
        scanf("%d",&n1);
        
        printf("Digite o valor2: ");
        scanf("%d",&n2);
        
        contador = n1;
        
        while(contador>=n1 && contador<=n2){
			soma = soma + contador;
			contador++;
			}
		
		printf("A soma inclusa entre os números %d e %d é: %d",n1,n2,soma);
}


