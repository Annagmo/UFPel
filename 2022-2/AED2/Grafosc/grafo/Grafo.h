#include <stdio.h>
#include <stdlib.h>

typedef struct grafo Grafo;

Grafo *criar(int n_vertices, int grau_max);

void desaloca(Grafo *grafo);
void imprimir(Grafo *grafo);
int insereAresta(Grafo *grafo, int orig, int dest, float peso);
int removeAresta(Grafo *grafo, int orig, int dest);
