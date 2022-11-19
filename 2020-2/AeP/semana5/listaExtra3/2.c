#include <stdio.h>

int main(void)
{
        int n,interv = 0,Ninterv = 0;
        int contador = 1;

        do{
            printf("Digite o %d número: ",contador);
            scanf("%d",&n);
			
			if (n>=10 && n<=20){interv++;}
			else{Ninterv++;}
			
			contador++;
			
		}while(contador<10);
		
		printf("Quantidade de valores no intervalo: %d \n",interv);
		printf("Quantidade de valores fora do intervalo: %d \n",Ninterv);
}

