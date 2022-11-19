#include <stdio.h>

int main(void)
{
		int n1,n2;
        int continuar=1;
        char opcao;

        while(continuar){
			
			printf("Digite os gols do Inter:");
            scanf("%d",&n1);
            
			printf("Digite os gols do Grêmio:");
            scanf("%d",&n2);
            
			if (n1 != n2){
				if(n1>n2){printf("Inter ganhou. \n");}
				else{printf("Grêmio ganhou. \n");}
			}
			else{printf("Empate. \n");}
            
            printf("Novo Grenal? (1)Sim (2)Nao\n");
            scanf(" %c",&opcao);
			
            switch(opcao)
            {
                case '1':
                    break;

                case '2':
                    continuar = 0;
                    break;
            }

        }
}

