#include <stdio.h>
#include<math.h>
int main(){
int cod;
float n1, n2, n3, Mp;
	
printf("Digite o código: ");
scanf("%d",&cod);
printf("Digite a primeira nota: ");
scanf("%f",&n1);
printf("Digite a segunda nota: ");
scanf("%f",&n2);
printf("Digite a terceira nota: ");
scanf("%f",&n3);
 
/* como n2 e n3 tem o mesmo peso essa condicional aborda as combinações 123 e 132*/
if (n1 > n2 && n1 > n3) {
	Mp = (( n1 * 4 ) + (n2 * 3) + (n3 * 3)) /10;
}	
/* como n2 e n3 tem o mesmo peso essa condicional aborda as combinações 231 e 213*/
if ( n2 > n1 && n2 > n3 ){
	Mp = (( n2 * 4 ) + (n1 * 3) + (n3 * 3)) /10;
}
/* como n2 e n3 tem o mesmo peso essa condicional aborda as combinações 321 e 312*/
if ( n3 > n2 && n3 > n1 ){
	Mp = (( n3 * 4 ) + (n1 * 3) + (n2 * 3)) /10;
}

/*para quando as duas maiores notas são iguais*/
if ( n3 == n2 && n3 > n1){       /*ex: caso 233 */
	Mp = (( n3 * 4 ) + (n1 * 3) + (n2 * 3)) /10;
}
if ( n3 == n1 &&
 n3 > n2){       /*ex: caso 323 */
	Mp = (( n3 * 4 ) + (n1 * 3) + (n2 * 3)) /10;
}
if ( n1 == n2 && n1 > n3){ /*ex: caso 322 */
	Mp = (( n1 * 4 ) + (n3 * 3) + (n2 * 3)) /10;
}
if ( n1 == n2 && n2 == n3){ /*Para quando os 3 são iguais, ex: caso 333 */
	Mp = (( n1 * 4 ) + (n3 * 3) + (n2 * 3)) /10;
}




if ( Mp >= 5) {
	printf("\n Código: %d \n Nota 1: %f \n Nota 2: %f \n Nota 3: %f \n Média Ponderada: %f \n APROVADO", cod, n1, n2, n3, Mp);

	
} 
else if ( Mp < 5) {
	printf("\n Código: %d\n Nota 1: %f \n Nota 2: %f \n Nota 3: %f \n Média Ponderada: %f\n REPROVADO", cod, n1, n2, n3, Mp);
}
return 0;
}
