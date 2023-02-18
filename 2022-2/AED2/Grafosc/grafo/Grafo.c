#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct grafo {
  int n_vertices;
  int grau_max;
  int **arestas;
  float **pesos;
  int *grau;
};

Grafo *criar(int n_vertices, int grau_max) {
  Grafo *grafo = (Grafo *)malloc(sizeof(struct grafo));
  if (grafo != NULL) {
    grafo->n_vertices = n_vertices;
    grafo->grau_max = grau_max;
    // criação do array de grau
    // é usada a funcao calloc porque todo vértice começa sem arestas:
    grafo->grau = (int *)calloc(n_vertices, sizeof(int));
    // criação da matriz de arestas
    grafo->arestas = (int **)malloc(n_vertices * sizeof(int));
    // criação da lista de adjacência para cada vértice, ou seja, cada vertice
    // vai possuir uma matriz de arestas com o numero de grau maximo dele
    for (int i = 0; i < n_vertices; i++) {
      grafo->arestas[i] = (int *)malloc(grau_max * sizeof(int));
      // criação da matriz de pesos, onde cada posição armazena o peso
      grafo->pesos = (float **)malloc(n_vertices * sizeof(float *));
      for (int j = 0; j < n_vertices; j++) {
        grafo->pesos[j] = (float *)malloc(grau_max * (sizeof(float)));
      }
    }
  }
  return grafo;
}

// não obrigatório
void desaloca(Grafo *grafo) {
  if (grafo != NULL) {
    int i;
    for (i = 0; i < grafo->n_vertices; i++)
      free(grafo->arestas[i]);
    free(grafo->arestas);

    for (i = 0; i < grafo->n_vertices; i++) {
      free(grafo->pesos[i]);
    }

    free(grafo->pesos);
    free(grafo->grau);
    free(grafo);
  }
}

int insereAresta(Grafo *grafo, int orig, int dest, float peso) {
  if ((grafo == NULL) || (orig < 0 || orig >= grafo->n_vertices) ||
      (dest < 0 || dest >= grafo->n_vertices))
    return 0;

  grafo->arestas[orig][grafo->grau[orig]] = dest;

  grafo->pesos[orig][grafo->grau[orig]] = peso;
  grafo->grau[orig]++;

  return 1;
}

// não obrigatório
int removeAresta(Grafo *grafo, int orig, int dest) {
  if ((grafo == NULL) || (orig < 0 || orig >= grafo->n_vertices) ||
      (dest < 0 || dest >= grafo->n_vertices))
    return 0;

  int i = 0;

  while (i < grafo->grau[orig] && grafo->arestas[orig][i] != dest)
    i++;

  if (i == grafo->grau[orig])
    return 0; // elemento nao encontrado

  grafo->grau[orig]--;
  grafo->arestas[orig][i] = grafo->arestas[orig][grafo->grau[orig]];

  grafo->pesos[orig][i] = grafo->pesos[orig][grafo->grau[orig]];
  return 1;
}

void imprimir(Grafo *grafo) {
  if (grafo == NULL) {
    printf("Nada a exibir!");
    return;
  }

  int i, j;
  for (i = 0; i < grafo->n_vertices; i++) {
    printf("%d: ", i);
    for (j = 0; j < grafo->grau[i]; j++) {
      printf("%d(%.2f), ", grafo->arestas[i][j], grafo->pesos[i][j]);
    }
    printf("\n");
  }
}
