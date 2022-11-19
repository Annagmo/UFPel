#include <stdio.h>

int main (void){
	int n1,n2,media;
	int pare=1;
	char res;
		
	while (pare){
		
		printf("Digite a primeira nota: ");
		scanf("%d", &n1);

		while (0>n1 || n1>10){
		printf("Nota inválida.");
			printf("Digite uma nota válida: ");
			scanf("%d", &n1);
			} 
		
		printf("Digite a segunda nota: ");
		scanf("%d", &n2);
			
		while (0>n2 || n2>10){
			printf("Nota inválida.");
			printf("Digite uma nota válida: ");
			scanf("%d", &n2);
			} 
		
		media = (n1 + n2)/2;
		printf("A média entre %d e %d é: %d \n",n1,n2,media);
		
		
		
		printf("Digite 1 para SIM e 2 para NÃO:");
		scanf(" %c", &res);
		
		switch (res)
		{
			case '1':
			break;
			
			case '2':
			pare = 0;
			
			default:
			system("clear || cls");
			printf("Opção inválida. \n");
			pare = 0;
		}
	}
}

