#include<stdio.h>
#include<math.h>

int main()
{
int cod_aluno;
float nota1, nota2, nota3, mediaponderada;

scanf("%d",&cod_aluno);
scanf("%f",&nota1);
scanf("%f",&nota2);
scanf("%f",&nota3);

if (nota1 > nota2 && nota1 > nota3){
mediaponderada = (( nota1 * 4 ) + (nota2 * 3) + (nota3 * 3)) /10;
}

else if (nota2 > nota1 && nota2 > nota3){
mediaponderada = (( nota2 * 4 ) + (nota1 * 3) + (nota3 * 3)) /10;
}

else if (nota3 > nota1 && nota3 > nota2){
mediaponderada = (( nota3 * 4 ) + (nota1 * 3) + (nota2 * 3.)) /10;
}

if (mediaponderada >= 5.00){
printf("CODIGO = %d\n",cod_aluno);
printf("NOTA 1 = %.2f\n",nota1);
printf("NOTA 2 = %.2f\n",nota2);
printf("NOTA 3 = %.2f\n",nota3);
printf("MEDIA = %.2f\n",mediaponderada);
printf("APROVADO\n");
}

else if (mediaponderada < 5.00){
printf("CODIGO = %d\n",cod_aluno);
printf("NOTA 1 = %.2f\n",nota1);
printf("NOTA 2 = %.2f\n",nota2);
printf("NOTA 3 = %.2f\n",nota3);
printf("MEDIA = %.2f\n",mediaponderada);
printf("REPROVADO\n");
}

return 0;	
}
