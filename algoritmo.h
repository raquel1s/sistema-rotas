#ifndef ALGORITMO_H
#define ALGORITMO_H

#define fi 9999
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

#endif