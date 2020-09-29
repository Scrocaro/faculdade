#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#ifndef __ILIST_H__
#define __ILIST_H__

typedef struct INOH
{
    int chave;
    int valor;
    int ocupado;
}INOH;

typedef struct ILIST
{
    INOH *nos;
    int max;
    int tam;
    int alloc;
    int alloc_step;
}ILIST;

ILIST* ILIST_Criar(int alloc_step);
int ILIST_Inserir(ILIST *L, int chave, int valor);
int ILIST_Remover(ILIST *L, int chave);
int ILIST_Buscar(ILIST *L, int chave);
INOH* ILIST_Endereco(ILIST* L, int pos);

#endif

typedef struct THED
{
    int M;
    ILIST** th;
}THED;

int THED_Hash(THED* TH, int chave);
THED* THED_Criar(int m, int alloc_step);
void THED_Inserir(THED* TH, int chave, int valor);
INOH* THED_Buscar(THED* TH, int chave);
void THED_Remover(THED* TH, int chave);
THED* inserir_n_aleatorios(int n, int m, int seed);
int THED_MaisLonga(THED* TH);
int THED_MaisCurta(THED* TH);
float THED_TamMedio(THED* TH);


ILIST* ILIST_Criar(int alloc_step)
{
    ILIST *L;
    int i;

    L = malloc(sizeof(ILIST));

    L->alloc = alloc_step;
    L->alloc_step = alloc_step;
    L->tam = 0;
    L->max = 0;
    L->nos = calloc(alloc_step, sizeof(INOH));

    for(i = 0; i < alloc_step; i++)
        L->nos[i].ocupado = 0;

    return L;
}

int ILIST_Inserir(ILIST *L, int chave, int valor)
{
    int i = 0, livre = -1;

    for(;i < L->max; i++)
    {
        if((L->nos[i].chave == chave) && (L->nos[i].ocupado))
        {
            livre = -1;
            L->tam--;
            break;
        }

        if(L->nos[i].ocupado == 0)
            if(livre == -1)
                livre = i;
    }

    if(livre != -1)
        i = livre;

    if(i >= L->max)
        L->max++;

    if(i >= L->alloc)
    {
        L->alloc = L->alloc + L->alloc_step;
        L->nos = realloc(L->nos, sizeof(INOH) * L->alloc);
    }

    L->nos[i].chave = chave;
    L->nos[i].valor = valor;
    L->nos[i].ocupado = 1;
    L->tam++;

    return i;
}

int ILIST_Remover(ILIST *L, int chave)
{
    int pos = ILIST_Buscar(L, chave);

    if(pos != -1)
    {
        L->tam--;
        L->nos[pos].ocupado = 0;
    }

    return pos;
}

int ILIST_Buscar(ILIST *L, int chave)
{
    int i = 0;
    
    for(;i < L->max; i++)
        if((L->nos[i].chave == chave) && (L->nos[i].ocupado))
            return i;

    return -1;
}

INOH* ILIST_Endereco(ILIST *L, int pos)
{
    if(pos != -1)
        return &L->nos[pos];
    
    return NULL;
}


int THED_Hash(THED* TH, int chave)
{
    return chave % TH->M;
}

THED* THED_Criar(int m, int alloc_step)
{
    THED *nova;
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

int main(int argc, char** argv)
{
    int m = 1000;
    int n = 100000;
    int seed = 42;
    THED* th = inserir_n_aleatorios(n, m, seed);

    printf("maior: %d\n", THED_MaisLonga(th));
    printf("menor: %d\n", THED_MaisCurta(th));
    printf("media: %f\n", THED_TamMedio(th));

    return 0;
}