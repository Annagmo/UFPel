#include <stdio.h>
int main(){
float v1,v2;
int op;
printf("_______________________________________________\n");
printf("|                                             |\n");
printf("|   Bem Vindo a calculadora de dois valores   |\n");
printf("|_____________________________________________|\n");
printf("                                               \n");

printf("Digite o primeiro valor: ");
scanf("%f",&v1);
printf("Digite o segundo valor: ");
scanf("%f",&v2);

printf("                                               \n");
printf("_______________________________________________\n");
printf("|                                             |\n");
printf("|  Digite o número do operador a sua escolha: |\n");
printf("|                                             |\n");
printf("|   1.Adição                                  |\n");
printf("|   2.Subtração                               |\n");
printf("|   3.Divisão                                 |\n");
printf("|   4.Multiplicação                           |\n");
printf("|_____________________________________________|\n");
printf("                                               \n");
printf("Escolha: ");
scanf("%d",&op);

if ( op == 1 ) {
	printf("Adição resultante: %f", (v1 + v2));
}
if ( op == 2 ) {
	printf("Subtração resultante: %f", (v1 - v2));
}
if ( op == 3 ) {
	printf("Divisão resultante: %f", (v1/v2));
}
if ( op == 4 ) {
	printf("Multiplicação resultante: %f", (v1 * v2));
}


if ( op < 1  || op > 4 ){
	printf("Favor difitar uma operação válida");
}


return 0;
}
