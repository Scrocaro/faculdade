#include <stdio.h> //NULL
#include "ilist.h"

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