#include <stdio.h>

int main(void)
{
        int soma,contador = 0;

        while(soma<100){
			soma = soma + contador;
			contador++;
		}
		printf("%d",contador-1); //devemos diminuir 1 pois na ultima tentativa, quando o contador testa a soma, ela já ultrapassa 100.
}
