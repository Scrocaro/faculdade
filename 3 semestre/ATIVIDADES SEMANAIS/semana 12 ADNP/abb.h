#pragma once

typedef struct ABB
{
    struct ABB *esq;
    struct ABB *dir;
    int chave;
} ABB;

ABB* ABB_Criar(int chave, ABB* esq, ABB* dir);
void ABB_Inserir_I(ABB **A, int chave);
void ABB_Inserir(ABB **A, int chave);
void ABB_Destruir(ABB **A);
void ABB_Sort(int* v, int n , float *altura);
int ABB_Altura(ABB *A);