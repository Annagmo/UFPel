#include <stdio.h>
//o prof que fez
int main(){
	int nt, soma=0, t1=0, t2=1, t3,i;


	printf("digite numero de termos:");
	scanf("%d",&nt);
	if (nt >=0)
		printf("%d ",t1);
	if (nt >=1){
		printf("%d ",t2);
	soma+=t2;
	}
	
	for(i=3;i<=nt;i++){
		t3=t1+t2;
		printf("%d ",t3);
		soma+=t3;
		t1=t2;
		t2=t3;
	}
	printf("Soma: %d ",soma);

}

