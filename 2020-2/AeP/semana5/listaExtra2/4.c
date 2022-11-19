#include <stdio.h>

int main(void)
{
        int continuar=1;
        int senha,cont=0;
		
        while(continuar)
        {
            printf("Digite a senha:");
            scanf("%d",&senha);

            switch(senha)
            {
				case 2009:
					printf("ACESSO PERMITIDO \n");
                    continuar = 0;
                    break;
                    
                default:
					printf("ACESSO NEGADO \n");
					cont++;
                    break;
            }

        }
	printf("vezes: %d",cont);
}


