#include <stdio.h>

int main(void)
{
        int n,neg = 0;
        int contador = 1;

        do{
            printf("Digite o %d número: ",contador);
            scanf("%d",&n);
			
			if (n<0){
				neg++;
			}
			
			contador++;
			
		}while(contador<10);
		
		printf("Quantidade de valores negativos: %d \n",neg);
}
