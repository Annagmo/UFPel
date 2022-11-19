#include <stdio.h>

int main(void)
{
        int continuar=1;
        char opcao;
        int contador = 0;

        while(continuar)
        {
            
            printf("(1)Álcool, (2)Gasolina, (3)Diesel, (4)Fim \n");
            scanf(" %c",&opcao);

            switch(opcao)
            {
                case '1':
					printf("ÁLCOOL \n");
					contador++;
                    break;
                    
                case '2':
					printf("GASOLINA \n");
					contador++;
                    break;
                    
                case '3':
					printf("DIESEL \n");
					contador++;
                    break;
                    
                case '4':
					printf("Quantidade de clientes: %d", contador);
                    continuar = 0;
                    break;
                
                default:
					printf("Insira uma opção válida. \n");
					break;
            }

        }

}

