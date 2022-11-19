//validação while

#include <stdio.h>

int main () {
int x; 

printf("digite valor: "); 
scanf("%d",&x);
while(x<0){
	printf("Valor inválido. \ndigite valor: "); 
	scanf("%d",&x);
}



}
