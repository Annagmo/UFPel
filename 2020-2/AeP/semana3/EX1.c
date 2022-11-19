#include <stdio.h>
#include<math.h>
int main(){
float n1, n2, Med;
	
printf("Digite a primeira nota: ");
scanf("%f",&n1);
printf("Digite a segunda nota: ");
scanf("%f",&n2);
Med = (n1 + n2)/2;

if ( 0 <= Med && Med < 3 ) {
	printf("\n Média: %f \n REPROVADO", Med);
}
if ( Med >= 3 && Med < 7 ) {
	printf("\n Média: %f \n EM EXAME", Med);
}
if ( Med >= 7 && Med <= 10 ) {
	printf("\n Média: %f \n APROVADO", Med);
}	
if ( Med < 0 || Med > 10 ) {
	printf("\n Média inválida. Favor inserir notas válidas."
	);
}

return 0;
}

