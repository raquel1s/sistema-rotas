// Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas
// Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva

#include <stdio.h>
#include <stdlib.h>

#include "algoritmo.h"

// incluir o código da função
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
