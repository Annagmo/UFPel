/* lista da aula 3 */
 
#include <stdio.h>


int main ()
{
	int d,m,a,r;
	
	printf("digite a idade em dias:");
	scanf("%d", &d);
	printf("digite a idade em meses:");
	scanf("%d", &m);
	printf("digite a idade em anos:");
	scanf("%d", &a);
		
	r = d + (m * 30) +(a * 365);
	
	printf("idade em dias é: %d ", r);

		
}
