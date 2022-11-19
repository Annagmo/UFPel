#include <stdio.h>

int main(void)
{
		int n1,n2,media;
        int continuar=1;
        char opcao;
        int contador = 0;

        while(continuar){
			
			printf("Digite nota 1:");
            scanf("%d",&n1);
            
			printf("Digite nota 2:");
            scanf("%d",&n2);
            
            media = (n1+n2)/2;
            printf("A média será: %d \n",media);
            
            printf("Repetir? (1)Sim (2)Nao\n");
            scanf(" %c",&opcao);
			
			if(media>=6){
			contador++;
			}
			
            switch(opcao)
            {
                case '1':
                    break;

                case '2':
                    continuar = 0;
            }

        }
		printf("Quantidade de aprovados: %d",contador);

}
