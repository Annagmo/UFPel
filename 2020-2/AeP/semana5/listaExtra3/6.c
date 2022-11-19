#include <stdio.h>

int main(void)
{
        int n1,n2,menor,maior,soma=0,contador=0;

		printf("Digite o valor1: ");
        scanf("%d",&n1);
        
        printf("Digite o valor2: ");
        scanf("%d",&n2);
        
        if (n1 != n2){
			if (n1>n2){
				menor = n2;
				maior = n1;
				}
			else{
				menor = n1;
				maior = n2;
				}
			}
		else{
			menor = n1; //só vai ter o própio número para somar.
			maior = n2;
		}
        
        
        contador = menor;
        
        
        while(contador>=menor && contador<=maior){
			soma = soma + contador;
			contador++;
			}
		
		printf("A soma inclusa entre os números %d e %d é: %d",n1,n2,soma);
}


