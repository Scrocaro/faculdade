#pragma once

#include "ilist.h"

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