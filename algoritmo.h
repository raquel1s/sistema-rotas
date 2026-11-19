/* Cauã Rodrigues Bortolan Ribeiro, Gustavo Henrique Antunes de Lima, Lucas Fernandes, Mathias Colletta Guth Dziurkowski, Raquel da Silva */

#ifndef ALGORITMO_H
#define ALGORITMO_H

/* Infinito: representa que nao existe caminho direto */
#define INF 999999
/* Numero de vertices (predios) do grafo */
#define numVertices 5

/* Matriz de adjacencia do campus (unica, usada por todos os algoritmos) */
extern int grafo[numVertices][numVertices];

/* Nomes dos predios, na mesma ordem das linhas/colunas do grafo */
extern const char *nomes[numVertices];

/* Dijkstra: calcula a menor distancia da origem ate todos os predios */
void dijkstra(int origem);
void recursividade(int menor);

/* Floyd-Warshall e alcancabilidade */
void calcularAlcancabilidade(int grafo[numVertices][numVertices],
                             int alcance[numVertices][numVertices]);

void exibirAlcancabilidade(int grafo[numVertices][numVertices]);

void floydWarshall(int grafo[numVertices][numVertices],
                   int dist[numVertices][numVertices]);

#endif
