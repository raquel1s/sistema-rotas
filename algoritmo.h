// Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas
// Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva

#ifndef ALGORITMO_H
#define ALGORITMO_H

// Variáveis de ambiente

// Infinito para o caminho Floyd Warshall
#define INF 999999
// Número de vértices da matriz
#define numVertices 5

// definir matriz aqui

// definir as funções aqui

void floydWarshall(int grafo[numVertices][numVertices],
                   int dist[numVertices][numVertices]);

#endif
