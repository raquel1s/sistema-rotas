// Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas
// Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva

#include <stdio.h>
#include <stdlib.h>

#include "algoritmo.h"

void calcularAlcancabilidade(int grafo[numVertices][numVertices],
                             int alcance[numVertices][numVertices]) {
  int dist[numVertices][numVertices];
  int i, j;

  floydWarshall(grafo, dist);

  for (i=0; i<numVertices; i++) {
    for (j=0; j<numVertices; j++) {
      if(dist[i][j] != INF){
        alcance[i][j] = 1;
      }else{
        alcance[i][j] = 0;
      }
    }
  }
}

void exibirAlcancabilidade(int grafo[numVertices][numVertices]) {
  char *siglas[numVertices] = {"Bib", "BlA", "BlB", "Lab", "Ref"};
  int i, j;
  int alcance[numVertices][numVertices];

  calcularAlcancabilidade(grafo, alcance);

  printf("\n====== MATRIZ DE ALCANCABILIDADE ======\n\n");

  printf("%-5s", "");
  for (j = 0; j < numVertices; j++) {
    printf("%5s", siglas[j]);
  }
  printf("\n");

  for (i = 0; i < numVertices; i++) {
    printf("%-5s", siglas[i]);
    for (j = 0; j < numVertices; j++) {
      printf("%5d", alcance[i][j]);
    }
    printf("\n");
  }

  printf("\n1 - Existe caminho\n");
  printf("0 - Nao existe caminho\n");
}

void floydWarshall(int grafo[numVertices][numVertices],
                   int dist[numVertices][numVertices]) {

  // Inicialização dos contadores
  int i, j, k;

  // Cópia do grafo para a matriz de distâncias
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
      dist[i][j] = grafo[i][j];
    }
  }

  // Loop das distâncias, i = origem, j = destino, k = intermediário
  for (k = 0; k < numVertices; k++) {
    for (i = 0; i < numVertices; i++) {
      for (j = 0; j < numVertices; j++) {
        // Verifica se há caminho entre i -> k e k -> j
        if (dist[i][k] != INF && dist[k][j] != INF) {
          // Se o caminho passando por k for menor que o caminho atual,
          // atualiza a distância entre i e j.
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
  }
}
