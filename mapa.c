/* Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva */

#include <stdio.h>
#include <stdlib.h>

#include "mapa.h"

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
