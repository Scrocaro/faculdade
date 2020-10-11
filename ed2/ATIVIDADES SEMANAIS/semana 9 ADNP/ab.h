#pragma once
#ifndef __AB_H__
#define __AB_H__

typedef struct AB
{
    struct AB *esq;
    struct AB *dir;
    int dado;
} AB;

//videos
void imprimir_pre_ordem(AB* A, int tab, char direcao, FILE *txt);
void imprimir_em_ordem(AB* A);
void imprimir_pos_ordem(AB* A);

AB* AB_Buscar(AB *A, int dado);
AB* AB_Criar(int dado, AB* esq, AB* dir);
void AB_Inserir(AB **A, int dado);
void AB_Destruir(AB** A);

//implementação
void AB_Remover(AB **A, int dado);
void AB_Imprimir(AB *A, char* caso);

void AB_Remover_No_Folha(AB *pai, AB *folha);
void AB_Remover_No_Filho_Unico(AB *pai, AB *no);
void AB_Remover_No_Dois_Filhos(AB *no);

#endif