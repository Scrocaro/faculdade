#include <stdlib.h>
#include "arn.h"

static void rot_esq(ARN **A)
{
    ARN *h = *A;
    ARN *x = h->dir;

    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;

    *A = x;
}

static void rot_dir(ARN **A)
{
    ARN *h = *A;
    ARN *x = h->esq;

    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static int eh_vermelho(ARN *A)
{
    if(A == NULL)
    {
        return 0;
    }

    return (A->cor == C_VERMELHO) ? 1 : 0;
}

static void inverter_cores(ARN *A)
{
    A->cor = C_VERMELHO;
    A->esq->cor = C_PRETO;
    A->dir->cor = C_PRETO;
}

ARN* ARN_Criar(int chave, int valor)
{
    ARN* novo = malloc(sizeof(ARN));

    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

static void ARN_Inserir_R(ARN **A, int chave, int valor)
{
    if(*A == NULL)
    {
        *A = ARN_Criar(chave, valor);
        return;
    }

    if(chave < (*A)->chave)
    {
        ARN_Inserir_R(&(*A)->esq, chave, valor);
    }
    
    if(chave > (*A)->chave)
    {
        ARN_Inserir_R(&(*A)->dir, chave, valor);
    }

    if(eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq))
    {
        rot_esq(A);
    }
    
    if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq))
    {
        rot_dir(A);
    }

    if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir))
    {
        inverter_cores(*A);
    }
}

void ARN_Inserir(ARN** A, int chave, int valor)
{
    ARN_Inserir_R(A, chave, valor);
    (*A)->cor = C_PRETO;
}

void ARN_Sort_R(ARN *A, int *v, int *i)
{
    if(A == NULL)
    {
        return;
    }

    ARN_Sort_R(A->esq, v, i);
    v[(*i)] = A->chave;
    *i += 1;
    ARN_Sort_R(A->dir, v, i);
    
    free(A); 
}

void ARN_Sort(int *v, int n, float *altura)
{
    ARN *A = NULL;
    int i = 0;

    for(int j = 0; j < n; j++)
    {
        ARN_Inserir(&A , v[j], 0);
    }
    
    *altura += ARN_Altura(A);
    ARN_Sort_R(A, v, &i);
}

int ARN_Altura(ARN *A)
{
    if(A == NULL){
        return -1;
    }
    
    int altura_dir = ARN_Altura(A->dir);
    int altura_esq = ARN_Altura(A->esq);

    if(altura_esq < altura_dir)
    {
        if(A->cor == C_PRETO)
        {
            return altura_dir+1;
        }
    }
    else
    {
        if(A->cor == C_PRETO)
        {
            return altura_esq+1;
        }
    }
}