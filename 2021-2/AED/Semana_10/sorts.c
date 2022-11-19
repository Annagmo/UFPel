/* Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.
2- O programa deve solicitar o tamanho do vetor de números (n) que será ordenado
3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.
4- Faça um código que verifica se o resultado dado por cada algoritmo de ordenação está correto.
5- Use a melhor lib (defina a melhor no item 7) para calcular quanto tempo cada algoritmo de ordenação levou para terminar: https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
6- No 1:1 vou perguntar sobre questões de desempenho relacionadas a esse exercício, então pense sobre desempenho, otimizações, avaliação de tempo, complexidade, hardware, etc
7- Faça teste de leaks de memória.
8- Faça um vídeo explicando todos os pontos. Por favor, não faça o vídeo mais longo do que o necessário e não esqueça das regras de envio de material.
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int* insertionSort(int data[], int n);
int* SelectionSort (int data[],int n);
void Quicksort (int data[],int esquerda,int direita);
void merge(int *pVetor, int esquerda, int middle, int direita);
void mergeSort(int data[],int esquerda,int direita);
void ordenado(int data[], int n);

int main(void)
{
    int i, opcao, tamV=0,cont;
    int *pVetor = NULL;
    int *Vcopia; //cria vetor secundário para não perder o original.
    float insertion, selection;
    double quick, merge;

    struct timeval begin, end;

    printf("\n Bem-vindo ao código de algoritmos de ordenação!\n"); //menu:
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamV);
    getchar();
    
    srand(time(0));

    pVetor = malloc(tamV * sizeof(int));
    Vcopia = malloc(tamV * sizeof(int));

    for (i = 0; i < tamV; i++)
    {
        pVetor[i] = rand() % 100;
    }

	while (opcao!=5){ // se ele não pedir para sair, continua rodando.
		printf("\nOpções disponı́veis:\n");
		printf("\t1 p/ Insertion Sort\n");
		printf("\t2 p/ Selection Sort\n");
        printf("\t3 p/ Quick Sort\n");
		printf("\t4 p/ Merge sort\n");
        printf("\t5 p/ Sair.\n");

        printf("\nDigite:");
		scanf("%d", &opcao);
        getchar(); 

        switch (opcao){

			case 1:
            printf("\nINSERTION SORT:\n");
            printf("\nVetor antes da ordenação:\n");
            
            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
            printf("%d, ", pVetor[cont]);
            printf("]");

            printf("\nVetor depois da ordenação:\n");
            
            for(cont = 0; cont < tamV; cont++) //copia vetor
                Vcopia[cont] = pVetor[cont];

            gettimeofday(&begin, 0); //inicia tempo
            insertionSort(Vcopia, tamV);
            gettimeofday(&end, 0); //termina tempo

            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
                printf("%d, ", Vcopia[cont]);
            printf("]");

            printf("\nTempo de ordenação do algoritmo 𝗶𝗻𝘀𝗲𝗿𝘁𝗶𝗼𝗻 𝘀𝗼𝗿𝘁: %.10f s.\n", ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6));
            insertion = ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6);

            ordenado(Vcopia,tamV);
            printf("\n\n#########################################\n");
			break;

            //----------------------------------------

			case 2:
            printf("\nSELECTION SORT:\n");
            printf("\nVetor antes da ordenação:\n");
            
            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
            printf("%d, ", pVetor[cont]);
            printf("]");

            printf("\nVetor depois da ordenação:\n");
        
            for(cont = 0; cont < tamV; cont++)  //copia vetor
                Vcopia[cont] = pVetor[cont];

            gettimeofday(&begin, 0); //inicia tempo
            SelectionSort(Vcopia, tamV);
            gettimeofday(&end, 0); //termina tempo

            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
                printf("%d, ", Vcopia[cont]);
            printf("]");

            printf("\nTempo de ordenação do algoritmo 𝘀𝗲𝗹𝗲𝗰𝘁𝗶𝗼𝗻 𝘀𝗼𝗿𝘁: %.10f s.\n", ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6));
            selection = ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6);

            ordenado(Vcopia,tamV);
            printf("\n\n#########################################\n");
			break;

            //----------------------------------------
			case 3:
            printf("\nQUICK SORT:\n");
            printf("\nVetor antes da ordenação:\n");
            
            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
            printf("%d, ", pVetor[cont]);
            printf("]");

            printf("\nVetor depois da ordenação:\n");
        
            for(cont = 0; cont < tamV; cont++) //copia vetor
                Vcopia[cont] = pVetor[cont];

            gettimeofday(&begin, 0); //inicia tempo
            Quicksort(Vcopia, 0, tamV-1);
            gettimeofday(&end, 0); //termina tempo

            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
                printf("%d, ", Vcopia[cont]);
            printf("]");

            printf("\nTempo de ordenação do algoritmo 𝗾𝘂𝗶𝗰𝗸 𝘀𝗼𝗿𝘁: %.10f s.\n", ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6));
            quick = ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6);

            ordenado(Vcopia,tamV);
            printf("\n\n#########################################\n");
			break;

            //----------------------------------------
			case 4:
            printf("\nMERGE SORT:\n");
            
            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
            printf("%d, ", pVetor[cont]);
            printf("]");

            printf("\nVetor depois da ordenação:\n");
        
            for(cont = 0; cont < tamV; cont++) //copia vetor
                Vcopia[cont] = pVetor[cont];

            gettimeofday(&begin, 0); //inicia tempo
            mergeSort(Vcopia, 0, tamV-1);
            gettimeofday(&end, 0); //termina tempo

            printf("[");
            for (cont = 0; cont < tamV; cont++)//imprime vetor
                printf("%d, ", Vcopia[cont]);
            printf("]");

            printf("\nTempo de ordenação do algoritmo 𝗺𝗲𝗿𝗴𝗲 𝘀𝗼𝗿𝘁: %.10f s.\n", ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6));
            merge = ((end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec))*1e-6);

            ordenado(Vcopia,tamV);
            printf("\n\n#########################################\n");
			break;
            //----------------------------------------

            case 5://fim
            printf("\n\n\n");
            printf("X         \10   Insertion \t    Selection \t       Quick \t\t  Merge\n");
            printf("Insertion \10  -----            %.10f      %.10f  \t %.10f\n"   , (insertion-selection) , (insertion-quick) , (insertion-merge));
            printf("Selection \10  %.10f      -----            %.10f  \t %.10f\n"   , (selection- insertion), (selection- quick), (selection- merge));
            printf("Quick     \10  %.10f     %.10f    \4 -----  \t\t %.10f\n"   , (quick-insertion      , (quick-selection) , (quick-merge)));
            printf("Merge     \10  %.10f      %.10f    \4 %.10f  \t -----\n"   , (merge-insertion)     , (merge-selection) , (merge-quick));
			break;

			default:
			printf("\n\nOPCAO INVALIDA!\n");
		}
	}
free(pVetor);
free(Vcopia);
return 0;
    
}

int* insertionSort(int data[], int n)
{
  int tmp,i,j;

  if(n ==1) return data;

  for (j = 1; j < n; j++){
    i=j-1;
    tmp = data[j];
    while((i >= 0) && (tmp < data[i])){
      data[i + 1] = data[i];
      i--;
    }
    data[i + 1] = tmp;
  }
  return data;
}


int* SelectionSort (int data[],int n) 
{
   int min,tmp,i,j,min_id;
   if(n ==1) return data;

   for (i=0; i<n-1; i++) {
       min = data[i];

       for (j=i+1; j<n; j++)
           if (data[j] < min) {
              min = data[j];
              min_id = j;
           }
       tmp = data[i];
       data[i] = data[min_id];
       data[min_id] = tmp;
       min_id = i+1;
   }
   return data;
}


void Quicksort (int data[],int esquerda,int direita) 
{
   int pivo,tmp,i,j;
   
   i = esquerda;
   j = direita;

   pivo = data[(rand() % (direita+1))];
   if(direita+1 == 1) return;

   do {
        while(data[i] < pivo)
           i++;
        while(pivo < data[j])
           j--;
        if (i <= j) {
           tmp = data[i];
           data[i] = data[j];
           data[j] = tmp;
           i++;
           j--;
       }
   } while (i <= j);
   if (esquerda < j) 
    Quicksort(data,esquerda,j);
   if (i < direita) 
    Quicksort(data,i,direita);
}


void mergeSort(int data[],int esquerda,int direita)
{
    int meio;
    if((direita+1)==1) return;

    if(esquerda<direita){
        meio = (direita+esquerda)/2;
        mergeSort(data, esquerda, meio);
        mergeSort(data, meio + 1, direita);
        merge(data, esquerda, meio, direita);
    }
}


void merge(int vetor[], int esquerda, int meio, int direita){
    int *vetAux;
    int contAux=0, comecoEsq = esquerda, comecoDir = meio+1;    // a divisao será do estilo:     [6, 89, 34, 73|, 2, 0, 41]
                                                                //                                             |
    vetAux = (int*)malloc((direita+1) * sizeof(int));

    
    while(comecoEsq <= meio && comecoDir <= direita){
        if(vetor[comecoEsq] <= vetor[comecoDir]) {
            vetAux[contAux] = vetor[comecoEsq];
            comecoEsq++;
        } else {
            vetAux[contAux] = vetor[comecoDir];
            comecoDir++;
        }
        contAux++;
    }

    while(comecoEsq <= meio){     //se ainda tem nrs na primeira metade
        vetAux[contAux++] = vetor[comecoEsq++];
    }

    while(comecoDir <= direita) {  //se ainda tem nrs na segunda metade
        vetAux[contAux++] = vetor[comecoDir++];
    }

    for(contAux = esquerda; contAux <= direita; contAux++){   //copia vetor aux para vetor original
        vetor[contAux] = vetAux[contAux-esquerda];
    }

    free(vetAux);
}

void ordenado(int data[], int n){
    int i;
    for(i=0; i<n-1 ; i++) { 
        if(data[i]>data[i+1]){
            printf("\nO vetor não foi ordenado corretamente\n");
            return;
            }
        }
        printf("\nO vetor foi ordenado corretamente\n");
}