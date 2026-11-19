/* Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva */

#include <stdio.h>
#include <stdlib.h>

#include "algoritmo.h"
#include "algoritmo_priv.h"

/*
 * Matriz de adjacencia do campus.
 * Ordem dos vertices: 0 = Bloco A, 1 = Bloco B, 2 = Laboratorio,
 *                     3 = Refeitorio, 4 = Biblioteca
 * INF = nao existe caminho direto entre os dois predios.
 */
int grafo[numVertices][numVertices] = {
    /*        BA   BB   La   Re   Bi */
    /*BA*/ {   0, INF, 210, 190, 160 },
    /*BB*/ { INF,   0, 240, INF, INF },
    /*La*/ { 210, 240,   0, INF, INF },
    /*Re*/ { 190, INF, INF,   0, 280 },
    /*Bi*/ { 160, INF, INF, 280,   0 }
};

/* Nomes dos predios, na mesma ordem do grafo */
const char *nomes[numVertices] = {
    "Bloco A", "Bloco B", "Laboratorio", "Refeitorio", "Biblioteca"
};

/* Tabela do Dijkstra: distancia, predio anterior e se ja foi visitado */
DJ list[numVertices];

/* Dijkstra: preenche a tabela list a partir do predio de origem (0 a 4) */
void dijkstra(int origem) {
    int i;

    for (i = 0; i < numVertices; i++) {
        list[i].distancia = INF;
        list[i].deOnde = -1;
        list[i].menorValor = 0;
    }
    list[origem].distancia = 0;
    recursividade(origem);
}

void recursividade(int menor) {
    int i;
    int nova;
    int pequeno;
    int base = 0;
    int id = -1;

    /* Se todos os vertices ja foram visitados, termina */
    for (i = 0; i < numVertices; i++) {
        base += list[i].menorValor;
    }
    if (base == numVertices) {
        return;
    }

    pequeno = INF + 1;
    list[menor].menorValor = 1;

    /* Atualiza a distancia dos vizinhos do vertice atual */
    for (i = 0; i < numVertices; i++) {
        if (list[i].menorValor == 0 && grafo[menor][i] != INF) {
            nova = list[menor].distancia + grafo[menor][i];
            if (nova < list[i].distancia) {
                list[i].distancia = nova;
                list[i].deOnde = menor;
            }
        }
    }

    /* Escolhe o vertice nao visitado com a menor distancia */
    for (i = 0; i < numVertices; i++) {
        if (pequeno > list[i].distancia && list[i].menorValor == 0) {
            pequeno = list[i].distancia;
            id = i;
        }
    }

    if (id == -1) {
        return;
    }

    recursividade(id);
}

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
  char *siglas[numVertices] = {"BlA", "BlB", "Lab", "Ref", "Bib"};
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

  /* Inicializacao dos contadores */
  int i, j, k;

  /* Copia do grafo para a matriz de distancias */
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
      dist[i][j] = grafo[i][j];
    }
  }

  /* Loop das distancias, i = origem, j = destino, k = intermediario */
  for (k = 0; k < numVertices; k++) {
    for (i = 0; i < numVertices; i++) {
      for (j = 0; j < numVertices; j++) {
        /* Verifica se ha caminho entre i -> k e k -> j */
        if (dist[i][k] != INF && dist[k][j] != INF) {
          /* Se o caminho passando por k for menor que o caminho atual,
             atualiza a distancia entre i e j. */
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
  }
}
