#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // interface pro usuario
  Grafo* grafo;
  int menu, n_vertices, resposta=0, op=0, v_origem, v_destino, grau_max;
  float p_aresta = 0;

  do {
    printf("\nInsira o número de vértices: ");
    scanf("%d", &n_vertices);
    if(n_vertices > 20 || n_vertices<0){
      printf("\nValor inválido! Insira um número positivo até 20.");
    }
  } while (n_vertices > 20 || n_vertices < 0);
    printf("\nInsira o grau máximo do vértice: ");
    scanf("%d", &grau_max);

    grafo = criar(n_vertices, grau_max);

  do {
    printf("\nMenu:");
    printf("\n1. Inserir aresta");
    printf("\n2. Remover aresta");
    printf("\n3. Listar grafo");
    printf("\n4. Sair\n");
    printf("\n");
    scanf("%d", &menu);

    switch (menu){
      case 1:
        do {
          printf("\nInsira o peso da aresta: ");
          scanf("%f", &p_aresta);
          if (p_aresta < 0){
            printf("\nValor inválido! Insira um valor positivo.");
          }
        } while (p_aresta < 0);
        printf("\nInsira o vértice de origem da nova aresta: ");
        scanf("%d", &v_origem);
        printf("\nInsira o vértice de destino da nova aresta: ");
        scanf("%d", &v_destino);
        insereAresta(grafo, v_origem, v_destino,p_aresta);
      break;

      case 2:
        printf("\nInsira o vértice de origem da aresta removida: ");
        scanf("%d",&v_origem);
        printf("\nInsira o vértice de destino da aresta removida: ");
        scanf("%d",&v_destino);
        removeAresta(grafo, v_origem, v_destino);
      break;

      case 3:
        imprimir(grafo);
      break;

      case 4:
        resposta = 1;
      break;
    }

    
  } while (resposta==0);

  desaloca(grafo);
  return 0;
}