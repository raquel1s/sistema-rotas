// Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas
// Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva

#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

static char *nomes[numVertices] = {"Biblioteca", "Bloco A", "Bloco B",
                                   "Laboratorio", "Refeitorio"};

/* Desenho do campus em ASCII. Os numeros sao as distancias em metros. */
void exibirMapa(void) {
  printf("\n============== MAPA DO CAMPUS ==============\n\n");
  printf(" [Biblioteca]----160----[Bloco A]----210----[Laboratorio]\n");
  printf("       |                    |                     |\n");
  printf("       |                    |                     |\n");
  printf("      280                  190                   240\n");
  printf("       |                    |                     |\n");
  printf("       |                    |                     |\n");
  printf("       +----[Refeitorio]----+                [Bloco B]\n");
  printf("\nDistancias em metros.\n");
}

/* Lista cada caminho direto entre dois locais (sem repetir) */
void exibirConexoes(int grafo[numVertices][numVertices]) {
  int i, j;

  printf("\n========== CAMINHOS DIRETOS ==========\n\n");

  for (i = 0; i < numVertices; i++) {
    for (j = i + 1; j < numVertices; j++) {
      if (grafo[i][j] != INF) {
        printf("%-12s <-> %-12s : %d m\n", nomes[i], nomes[j], grafo[i][j]);
      }
    }
  }
}

/* Matriz com a menor distancia entre todos os pares (Floyd-Warshall) */
void exibirDistancias(int grafo[numVertices][numVertices]) {
  int dist[numVertices][numVertices];
  char *siglas[numVertices] = {"Bib", "BlA", "BlB", "Lab", "Ref"};
  int i, j;

  floydWarshall(grafo, dist);

  printf("\n====== MENOR DISTANCIA ENTRE LOCAIS (m) ======\n\n");

  printf("%-5s", "");
  for (j = 0; j < numVertices; j++) {
    printf("%6s", siglas[j]);
  }
  printf("\n");

  for (i = 0; i < numVertices; i++) {
    printf("%-5s", siglas[i]);
    for (j = 0; j < numVertices; j++) {
      if (dist[i][j] == INF) {
        printf("%6s", "INF");
      } else {
        printf("%6d", dist[i][j]);
      }
    }
    printf("\n");
  }

  printf("\nINF - Nao existe caminho\n");
}