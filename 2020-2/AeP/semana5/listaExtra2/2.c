#include <stdio.h>

int main(void)
{
		float n1,n2;
		float media;
        int continuar=1;
        char opcao;
        int aprovados = 0,exame = 0, reprovados = 0;

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
		printf("Quantidade de aprovados: %d \n",aprovados);
		printf("Quantidade de alunos em exame: %d \n",exame);
		printf("Quantidade de reprovados: %d \n",reprovados);

}
