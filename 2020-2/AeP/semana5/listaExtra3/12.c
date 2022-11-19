#include <stdio.h>

int main(void)
{
        int n,fat = 1,i;
        
		printf("digite o numero:");
		scanf("%d",&n);
		
		if(n<0){	
			do{printf("digite o numero:");
			scanf("%d",&n);
			}while(n<0);
		}
		
        for(i=n;i>=1;i--){
			if(n==0){
				fat = 1;
			}
			else{
				fat=fat*i;
			}

		}
		printf("%d",fat);
}
