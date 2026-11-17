// Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas
// Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva

#include <stdio.h>
#include <stdlib.h>

#include "algoritmo.h"
#include "algoritmo_priv.h"

int origem;
int destino;

DJ list[numVertices];
    
const int matrizMap[numVertices][numVertices] = {
        /* BA   BB   La   Re   Bi*/    
    /*BA*/{0  , INF, 210, 190, 160},
    /*BB*/{INF, 0  , 240, INF, INF},
    /*La*/{210, 240, 0  , INF, INF},
    /*Re*/{190, INF, INF, 0  , 280},
    /*Bi*/{160, INF, INF, 280, 0  }
};

/*incluir o código da função*/

void dijkstra(){
    int i;

    pergunta();
    for(i = 0;i < numVertices;i++){
        list[i].distancia = INF;
        list[i].deOnde = -1;
        list[i].menorValor = 0;
    }    
    list[origem-1].distancia = 0;
    recursividade(origem - 1);

    system("clear");
    printf("O caminho para chehar até o destino é:\n");
    imprimirCaminho(destino - 1);

}

void imprimirCaminho(int caminho){
    if(caminho == -1)return;
    imprimirCaminho(list[caminho].deOnde);
    printf(" [%i]",caminho + 1);
}

void recursividade(int menor){
    int i;
    int nova;
    int pequeno;
    int base = 0;
    int id = -1;
    
    for(i = 0;i<5;i++){
        base += list[i].menorValor;
    }
    if(base == 5){
        return;
    }
    
    pequeno = INF+1;
    list[menor].menorValor = 1;

    for(i = 0;i<numVertices;i++){
        if(list[i].menorValor == 0 && matrizMap[menor][i] != INF){
            nova = list[menor].distancia +matrizMap[menor][i];
            if(nova < list[i].distancia){
                list[i].distancia = nova; 
                list[i].deOnde = menor;
                printf("\n\ntroca\n\n");
            }
        }
    }

    for(i = 0;i<numVertices;i++){
        if(pequeno > list[i].distancia && list[i].menorValor == 0){
            pequeno = list[i].distancia;
            id = i;   
        }
    }

    if(id == -1){
        return;
    }
    

    recursividade(id);
}

void pergunta(){
    system("clear");
    legenda();
    printf("\naonde você vai?");
    scanf("%i",&destino);
    fflush(stdin);
    printf("\naonde você está");
    scanf("%i",&origem);
    fflush(stdin);
    
}

void legenda(){
    printf("\n1 - Bloco A (BA)");
    printf("\n2 - Bloco B (BB)");
    printf("\n3 - Laboratorio (La)");
    printf("\n4 - Refeitorio (Re)");
    printf("\n5 - Biblioteca (Bi)");
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
