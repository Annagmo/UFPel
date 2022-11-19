#include <stdio.h>
#include<math.h>
int main(){
int n1, n2;
	
printf("Digite os gols do Grêmio: ");
scanf("%d",&n1);
printf("Digite os gols do Inter: ");
scanf("%d",&n2);

if ( n1 > n2 ) {
	printf("Grêmio Venceu");
}
if ( n1 == n2) {
	printf("Foi empate");
}
if ( n2 > n1) {
	printf("Inter ganhou");
}	

return 0;
}

