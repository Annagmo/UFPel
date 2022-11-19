#include <stdio.h>

int main(void)
{
		float n1,n2,total;
		float media;
        int continuar=1;
        char opcao;
        float aprovados = 0,exame = 0, reprovados = 0;

        while(continuar){
			
			printf("Digite nota 1:");
            scanf("%f",&n1);
            
			printf("Digite nota 2:");
            scanf("%f",&n2);
            
            media = (n1 + n2)/2;
            printf("A média será: %.1f \n",media);
            
            printf("Repetir? (1)Sim (2)Nao\n");
            scanf(" %c",&opcao);
			
			if(media>=6){
			aprovados++;
			}
			if(media<3){
			reprovados++;
			}
			else{
				exame++;
			}
			
            switch(opcao)
            {
                case '1':
                    break;

                case '2':
                    continuar = 0;
            }

        }
        total = aprovados + exame + reprovados;
        
		printf("Quantidade de aprovados: %.0f \n",aprovados);
		printf("Quantidade de alunos em exame: %.0f \n",exame);
		printf("Quantidade de reprovados: %.0f \n",reprovados);
		
		printf("Porcentagem de aprovados: %.1f \n",((aprovados * 100)/total));
		printf("Porcentagem de alunos em exame: %.1f \n",((exame * 100)/total));
		printf("Porcentagem de reprovados: %.1f \n",((reprovados * 100)/total));


}


