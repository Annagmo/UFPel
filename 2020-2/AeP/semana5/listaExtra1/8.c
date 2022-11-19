#include <stdio.h>

int main(void)
{
	float a, b, c;
	int continuar=1;
	char opcao;

	while(continuar)
	{
		printf("Digite o primeiro número:");
		scanf("%e",&a);
		
		printf("Digite o segundo número:");
		scanf("%e", &b);
		
		
		printf("Digite o terceiro número:");
		scanf("%e", &c);
		
		printf("Os dados informados estão corretos?:");
	
	
		printf("(1)Sim (2)Nao\n");
		scanf(" %c",&opcao);

		switch(opcao)
		{
			case '2':
				break;

			case '1':
				continuar = 0;
		}

	}
	
	if (a < (b+c) && b < (c+a) && c < (a+b)) 
	{
		printf("Esses números são capazes de formar um triângulo. \n");
		
		if (a==b && a==c){
			printf("O triângulo é equilátero.");
		}
		else{
			if (a==b || a==c || b==c){
				printf("O triângulo é isósceles.");
			}
			else{
				printf("O triângulo é escaleno.");
				}
		}	
	}
	else{
        printf("Esses números não são capazes de formar um triângulo");
	}
	

}

