#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tabelaHash_ed.h"
#include "ilist.h"

int THED_Hash(THED* TH, int chave)
{
    return chave % TH->M;
}

THED* THED_Criar(int m, int alloc_step)
{
    THED* nova;
    int i;

    nova = malloc(sizeof(THED));
    nova->M = m;
    nova->th = malloc(sizeof(ILIST*) * m);

    for(i=0; i<m; i++)
    {
        nova->th[i] = ILIST_Criar(alloc_step);
    }

    return nova;
}

void THED_Inserir(THED* TH, int chave, int valor)
{
    int h;
    h = THED_Hash(TH, chave);
    ILIST_Inserir(TH->th[h], chave, valor);
}

INOH* THED_Buscar(THED* TH, int chave)
{
    int h, pos;
    h = THED_Hash(TH, chave);
    pos = ILIST_Buscar(TH->th[h], chave);

    if(pos == -1)
        return NULL;

    return ILIST_Endereco(TH->th[h], pos);
}

void THED_Remover(THED* TH, int chave)
{
    int h;
    h = THED_Hash(TH, chave);

    ILIST_Remover(TH->th[h], chave);
}

THED* inserir_n_aleatorios(int n, int m, int seed)
{
    THED *th = THED_Criar(m, n);

    srand(seed);
    for(int i = 0; i < n; i++) 
    {
        int numChave = rand() % (n*10);
        THED_Inserir(th, numChave, numChave);
    }

    return th;
}

int THED_MaisLonga(THED* TH)
{
    int maior = INT_MIN;

    for(int i = 0; i < TH->M; i++)
    {
        if(maior < TH->th[i]->tam)
            maior = TH->th[i]->tam;
    }

    return maior;
}

int THED_MaisCurta(THED* TH)
{
    int menor = INT_MAX;

    for(int i = 0; i < TH->M; i++)
    {
        if(menor > TH->th[i]->tam && TH->th[i]->tam > 0)
            menor = TH->th[i]->tam;
    }

    return menor;
}

float THED_TamMedio(THED* TH)
{
    float media = 0;

    for(int i = 0; i < TH->M; i++)
    {
        media += TH->th[i]->tam;
    }

    return media/TH->M;
}