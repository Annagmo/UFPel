#include <stdio.h>

int main(void)
{
		float n1,n2,total,medApv=0,media;
        int qtd,contador=1;
        float aprovados = 0,exame = 0, reprovados = 0;
        
        printf("Quantos alunos?:");
        scanf("%d",&qtd);

        while(contador<=qtd){
			
			printf("Digite nota 1:");
            scanf("%f",&n1);
            
			printf("Digite nota 2:");
            scanf("%f",&n2);
            
            media = (n1 + n2)/2;
			
			if(media>=7){
				medApv = medApv + media;
				aprovados++;
			}
			if(media>=3 && media<7){
			exame++;
			}
			if(media<3){
				reprovados++;
			}
			contador++;

        }
        total = aprovados + exame + reprovados;
        
		printf("Quantidade de aprovados: %.0f \n",aprovados);
		printf("Quantidade de alunos em exame: %.0f \n",exame);
		printf("Quantidade de reprovados: %.0f \n",reprovados);
		printf("Média dos aprovados: %.2f \n",medApv);

		printf("Porcentagem de reprovados: %.1f \n",((reprovados * 100)/total));


}

