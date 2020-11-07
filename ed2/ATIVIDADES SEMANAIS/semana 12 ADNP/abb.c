#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "abb.h"

ABB* ABB_Criar(int chave, ABB* esq, ABB* dir)
{
    ABB* A = (ABB*) malloc(sizeof(ABB));

    A->chave = chave;
    A->dir = dir;
    A->esq = esq;

    return A;
}

void ABB_Inserir(ABB **A, int chave)
{
    if((*A) == NULL)
    {
        *A = ABB_Criar(chave, NULL, NULL);

        return;
    }
    else
    {
        if((*A)->chave > chave)
        {
            ABB_Inserir(&(*A)->esq, chave);
        }
        else
        {
            ABB_Inserir(&(*A)->dir, chave);
        } 
    }
}

void ABB_Inserir_I(ABB **A, int chave)
{    
    if(*A == NULL)
    {
        *A = ABB_Criar(chave, NULL, NULL);
    }
    ABB **aux = A;

    while(*aux != NULL)
    {
        if(chave > (*aux)->chave)
        {
            aux = &(*aux)->dir;
        }
        else if (chave < (*aux)->chave)
        {
            aux = &(*aux)->esq;
        }
        else 
        {
            return;
        }
    }

    *aux = ABB_Criar(chave, NULL, NULL);
}

void ABB_Destruir(ABB **A)
{
    if((*A) == NULL)
    {
        return;
    }

    ABB_Destruir(&(*A)->esq);
    ABB_Destruir(&(*A)->dir);
    free(A);
}

static void ABB_Sort_I(ABB *A, int *v, int n)   // necesária devido ao tamanho dos testes
{
    ABB **fila = calloc(n, sizeof(ABB)), *aux;
    int a = 1, b = n-1, i = 0;
    fila[i] = A;

    while(a > i)
    {
        aux = fila[i++];
        v[b--] = aux->chave;

        if(aux->esq != NULL) 
        {
            fila[a++] = aux->esq;
        }
        if(aux->dir != NULL) 
        {
            fila[a++] = aux->dir;
        }
        
        free(fila[i-1]);
    }

    free(fila);
}

void ABB_Sort(int* v, int n, float *altura)
{
    ABB *A = NULL;

    for(int i = 0; i < n; i++)
    {
        ABB_Inserir_I(&A , v[i]);
    }

    *altura += ABB_Altura(A);
    ABB_Sort_I(A, v, n);
}

int ABB_Altura(ABB *A)
{
    if(A == NULL)
    {
        return -1;
    }

    int altura_dir = ABB_Altura(A->dir);
    int altura_esq = ABB_Altura(A->esq);

    if(altura_esq < altura_dir)
    {
        return altura_dir+1;
    }
    else
    {
        return altura_esq+1;
    }
}