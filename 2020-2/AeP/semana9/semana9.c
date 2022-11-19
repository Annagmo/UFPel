#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int i, notas[10];
		
		for (i=0; i<10; i++){notas[i] = 0}
        
		for (i=0; i<10; i++){
		printf("Digite o valor da posição %d", i);
		scanf("%d", notas[i]);
        }
		
		for (i=10; i<10; i--){
		printf("%d:",notas[i]);
        }
     return(0);
       
}

