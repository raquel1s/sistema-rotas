
// GRUPO: CAUÃ RODRIGUES BORTOLAN RIBEIRO, GUSTAVO HENRIQUE ANTUNES DE LIMA, LUCAS FERNANDES, MATHIAS COLLETTA GUTH DZIURKOWSKI, RAQUEL DA SILVA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "mapa.h"
#include "algoritmo_priv.h"

extern DJ list[numVertices];

int grafo[numVertices][numVertices] = {
    /*  Bib   BlA   BlB   Lab   Ref */
    {   0,  160,  INF,  INF,  280 },  /* Biblioteca  */
    { 160,    0,  INF,  210,  190 },  /* Bloco A     */
    { INF,  INF,    0,  240,  INF },  /* Bloco B     */
    { INF,  210,  240,    0,  INF },  /* Laboratorio */
    { 280,  190,  INF,  INF,    0 }   /* Refeitorio  */
};

static const char *nomesPredios[numVertices] = {
    "Biblioteca", "Bloco A", "Bloco B", "Laboratorio", "Refeitorio"
};

/* Nomes na ordem usada pelo Dijkstra (mesma da legenda 1 a 5) */
static const char *nomesDj[numVertices] = {
    "Bloco A", "Bloco B", "Laboratorio", "Refeitorio", "Biblioteca"
};

/* Matriz de alcancabilidade (1 = existe caminho, 0 = nao existe) */
static int alcance[numVertices][numVertices];



static char minuscula(char c)
{
    if (c >= 'A' && c <= 'Z') return (char)(c - 'A' + 'a');
    return c;
}


static int iguais(const char *a, const char *b)
{
    while (*a && *b) {
        if (minuscula(*a) != minuscula(*b)) return 0;
        a++;
        b++;
    }
    return *a == *b;
}

static void limpar(char *s)
{
    int ini = 0, fim = (int)strlen(s) - 1;
    int i;

    while (fim >= 0 && (s[fim] == '\n' || s[fim] == '\r' || s[fim] == ' '))
        fim--;
    s[fim + 1] = '\0';
    while (s[ini] == ' ')
        ini++;
    if (ini > 0) {
        for (i = 0; s[ini + i] != '\0'; i++)
            s[i] = s[ini + i];
        s[i] = '\0';
    }
}

static void listarPredios(void)
{
    int i;
    printf("\nPredios disponiveis:\n");
    for (i = 0; i < numVertices; i++)
        printf("  %d - %s\n", i + 1, nomesPredios[i]);
    printf("\n");
}


static int lerPredio(const char *mensagem)
{
    char linha[100];
    int i, num;

    for (;;) {
        printf("%s", mensagem);
        if (fgets(linha, sizeof(linha), stdin) == NULL)
            return -1;
        limpar(linha);

        if (linha[0] >= '0' && linha[0] <= '9') {
            num = atoi(linha);
            if (num >= 1 && num <= numVertices)
                return num - 1;
        } else {
            for (i = 0; i < numVertices; i++)
                if (iguais(linha, nomesPredios[i]))
                    return i;
        }
        printf("Predio invalido! Digite o numero ou o nome.\n");
    }
}

static int lerOpcao(void)
{
    char linha[50];
    int op;

    do {
        if (fgets(linha, sizeof(linha), stdin) == NULL)
            return 0;
    } while (linha[0] == '\n' || linha[0] == '\r'); /* ignora linha vazia */

    if (sscanf(linha, "%d", &op) != 1)
        return -1;
    return op;
}


static void imprimirRotaNomes(int v)
{
    if (v == -1) return;
    imprimirRotaNomes(list[v].deOnde);
    if (list[v].deOnde != -1) printf(" -> ");
    printf("%s", nomesDj[v]);
}

static void opcaoMenorRota(void)
{
    dijkstra();

    printf("\n====== MENOR ROTA ======\n");
    if (list[destino - 1].distancia == INF) {
        printf("Nao existe caminho entre %s e %s.\n",
               nomesDj[origem - 1], nomesDj[destino - 1]);
    } else {
        printf("De %s ate %s\n", nomesDj[origem - 1], nomesDj[destino - 1]);
        printf("Rota: ");
        imprimirRotaNomes(destino - 1);
        printf("\nDistancia total: %d m\n", list[destino - 1].distancia);
    }
    printf("========================\n");
}

static void opcaoVerificarConexao(void)
{
    int a, b;

    listarPredios();
    a = lerPredio("Primeiro predio: ");
    if (a < 0) return;
    b = lerPredio("Segundo predio: ");
    if (b < 0) return;

    printf("\n");
    if (alcance[a][b])
        printf("Existe caminho entre %s e %s.\n",
               nomesPredios[a], nomesPredios[b]);
    else
        printf("NAO existe caminho entre %s e %s.\n",
               nomesPredios[a], nomesPredios[b]);
}

static void exibirMatrizAlcancabilidade(void)
{
    int i, j;

    printf("\n====== MATRIZ DE ALCANCABILIDADE ======\n\n");
    printf("%-16s", "");
    for (i = 0; i < numVertices; i++)
        printf("%-4d", i + 1);
    printf("\n");
    for (i = 0; i < numVertices; i++) {
        printf("%d - %-12s", i + 1, nomesPredios[i]);
        for (j = 0; j < numVertices; j++)
            printf("%-4d", alcance[i][j]);
        printf("\n");
    }
    printf("\n1 - Existe caminho\n0 - Nao existe caminho\n");
    printf("\n=======================================\n");
}

static void exibirMenu(void)
{
    printf("\n=======================================\n");
    printf("       SISTEMA DE ROTAS DO CAMPUS\n");
    printf("=======================================\n\n");
    printf("1 - Exibir mapa do campus\n");
    printf("2 - Encontrar menor rota entre dois predios\n");
    printf("3 - Verificar conexao entre dois predios\n");
    printf("4 - Exibir matriz de alcancabilidade\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opcao: ");
}

int main(void)
{
    int opcao;

    calcularAlcancabilidade(grafo, alcance);

    do {
        exibirMenu();
        opcao = lerOpcao();

        switch (opcao) {
            case 1: exibirMapa();                  break;
            case 2: opcaoMenorRota();              break;
            case 3: opcaoVerificarConexao();       break;
            case 4: exibirMatrizAlcancabilidade(); break;
            case 0: printf("\nEncerrando o programa...\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
