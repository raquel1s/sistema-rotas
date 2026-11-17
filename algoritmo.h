// Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas
// Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva

#ifndef ALGORITMO_H
#define ALGORITMO_H

// Infinito para o caminho Floyd Warshall
#define INF 999999
// Número de vértices da matriz
#define numVertices 5

extern int origem;
extern int destino;

/*definir matriz aqui*/
extern const int matrizMap[5][5];


/* definir as funções aqui*/
void dijkstra();
void pergunta();
void legenda();
void recursividade(int menor);
void imprimirCaminho(int caminho);

void calcularAlcancabilidade(int grafo[numVertices][numVertices], int alcance[numVertices][numVertices]);

void exibirAlcancabilidade(int grafo[numVertices][numVertices]);

void floydWarshall(int grafo[numVertices][numVertices],
                   int dist[numVertices][numVertices]);

#endif
