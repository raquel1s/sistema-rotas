
// GRUPO: CAUÃ RODRIGUES BORTOLAN RIBEIRO, GUSTAVO HENRIQUE ANTUNES DE LIMA, LUCAS FERNANDES, MATHIAS COLLETTA GUTH DZIURKOWSKI, RAQUEL DA SILVA

#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "mapa.h"
int grafo[numVertices][numVertices] = {
    /*  Bib   BlA   BlB   Lab   Ref */
    {   0,  160,  INF,  INF,  280 },  /* Biblioteca  */
    { 160,    0,  INF,  210,  190 },  /* Bloco A     */
    { INF,  INF,    0,  240,  INF },  /* Bloco B     */
    { INF,  210,  240,    0,  INF },  /* Laboratorio */
    { 280,  190,  INF,  INF,    0 }   /* Refeitorio  */
};

int main(){
    // fazer menu aqui
}