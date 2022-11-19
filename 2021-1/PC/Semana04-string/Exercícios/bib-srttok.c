/* strtok.c */
 
#include <stdio.h>
#include <string.h>
 
int main(void)
{
   char *psRetorno;
   char sFrase[]="Mario Quintana, o maior poeta gaúcho";
 
   printf("\nFrase = %s", sFrase);
 
   /* Primeira pesquisa por espaço em branco. */
   psRetorno = strtok(sFrase, " ");
 
   printf("\nRetorno = %s", psRetorno);
   printf("\nFrase = %s", sFrase);
 
   do
   {
      /* Nas próximas chamadas, deve-se passar um ponteiro “nulo”. 
         Isto “indica” para a função que a pesquisa deve continuar 
         no ponteiro anterior. */
      psRetorno = strtok('\0', ", "); //Demais pesquisas por , (vírgula) ou espaço em branco.
 
      /* Um valor nulo (NULL) é considerado sempre falso em comparações 
         booleanas (verdadeiro ou falso). */
      if(psRetorno)
      {
         printf("\nRetorno = %s", psRetorno);
      } 
   } while(psRetorno);
   return 0;
}
