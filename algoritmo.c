#include <stdio.h>
#include <stdlib.h>

#include "algoritmo.h"
#include "algoritmo_priv.h"

int origem;
int destino;

DJ list[5];
    
const int matrizMap[5][5] = {
        /* BA   BB   La   Re   Bi*/    
    /*BA*/{0  , fi , 210, 190, 160},
    /*BB*/{fi , 0  , 240, fi , fi },
    /*La*/{210, 240, 0  , fi , fi },
    /*Re*/{190, fi , fi , 0  , 280},
    /*Bi*/{160, fi , fi , 280, 0  }
};

/*incluir o código da função*/

void dijkstra(){
    int i;

    pergunta();
    for(i = 0;i < 5;i++){
        list[i].distancia = fi;
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
    
    pequeno = fi+1;
    list[menor].menorValor = 1;

    for(i = 0;i<5;i++){
        if(list[i].menorValor == 0 && matrizMap[menor][i] != fi){
            nova = list[menor].distancia +matrizMap[menor][i];
            if(nova < list[i].distancia){
                list[i].distancia = nova; 
                list[i].deOnde = menor;
                printf("\n\ntroca\n\n");
            }
        }
    }

    for(i = 0;i<5;i++){
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

