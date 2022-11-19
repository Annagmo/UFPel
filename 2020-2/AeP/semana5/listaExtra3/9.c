#include <stdio.h>
int main(void)
{
        int c = 0,soma,n,a;
        
		printf("Digite um valor A: ");
		scanf("%d",&a);
		printf("Digite um valor N: ");
		scanf("%d",&n);
		
		soma = 0;
		
			while(c<n){
				soma += a;
				a++;
				c = c + 1;
			
			}

		printf("%d",soma); 
}
