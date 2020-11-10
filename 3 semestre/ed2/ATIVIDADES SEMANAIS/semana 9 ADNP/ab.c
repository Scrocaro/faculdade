#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

void imprime_pre_ordem(AB *A, int tab, char direcao, FILE *txt)
{
  if(A == NULL) return;

  for(int i = 0; i < tab; i++) 
    fputc('\t', txt);

  fprintf(txt, "(%c) %d\n", direcao, A->dado);

  imprime_pre_ordem(A->esq,tab + 1, 'e', txt);
  imprime_pre_ordem(A->dir, tab + 1, 'd', txt);
}

void imprime_em_ordem(AB *A)
{
  if(A == NULL) 
    return;

  imprime_em_ordem(A->esq);
  printf("%d ",A->dado);
  imprime_em_ordem(A->dir);
}

void imprime_pos_ordem(AB *A)
{
  if(A == NULL)
    return;
    
  imprime_pos_ordem(A->esq);
  imprime_pos_ordem(A->dir);
  printf("%d ",A->dado);
}

AB* AB_Criar(int dado, AB* esq, AB* dir)
{
  AB* novo = malloc(sizeof(AB));

  novo->dado =  dado;
  novo->esq = esq;
  novo->dir = dir;

  return novo;
}

void AB_Destruir(AB **A)
{
  if((*A) == NULL) 
    return;
  
  AB_Destruir(&(*A)->esq);
  AB_Destruir(&(*A)->dir);
  free(A);
}

AB* AB_Buscar(AB* A, int dado)
{
  if(A == NULL)
    return NULL;

  if(A->dado == dado)
    return A;

  if(dado < A->dado)
    return AB_Buscar(A->esq, dado);

  //if(dado > A->dado)
    return AB_Buscar(A->dir, dado);
}

void AB_Inserir(AB **A, int dado)
{
  if((*A) == NULL)
  {
    *A = AB_Criar(dado, NULL, NULL);
    return;
  }
  else
  {
    if(dado < (*A)->dado)
      AB_Inserir(&(*A)->esq, dado);
    
    else
      AB_Inserir(&(*A)->dir, dado);
  }
}

void AB_Imprimir(AB *A, char* caso)
{
  FILE *txt = fopen(caso, "w");

  imprime_pre_ordem(A, 0, 'r', txt);
  fclose(txt);
}

/////////////////////////remoção//////////////////////////////
void AB_Remover_No_Folha(AB *pai, AB *folha)
{
  if(folha->dado < pai->dado)
    pai->esq = NULL;

  else
    pai->dir = NULL;

  free(folha);
}

void AB_Remover_No_Filho_Unico(AB *pai, AB *no)
{
  if(no->dado < pai->dado)
  {
    if(no->esq != NULL)
      pai->esq = no->esq;

    else
      pai->esq = no->dir;
  }
  else
  {
    if(no->esq != NULL)
      pai->dir = no->esq;

    else
      pai->dir = no->dir;
  }

  free(no);
}

void AB_Remover_No_Dois_Filhos(AB *no)
{
  AB* sucessor = no->dir;
  AB* pai_sucessor = no;

  while(sucessor->esq != NULL)
  {
    pai_sucessor = sucessor;
    sucessor = sucessor->esq;
  }

  no->dado = sucessor->dado;

  if(sucessor->dir == NULL && sucessor->esq == NULL)
    AB_Remover_No_Folha(pai_sucessor, sucessor);
    
  else
    AB_Remover_No_Filho_Unico(pai_sucessor, sucessor);

}

void AB_Remover(AB **A, int dado)
{
  if((*A) == NULL) 
    return;

  AB *no = (*A);
  AB *pai = (*A);

  while(no->dado != dado)
  {
    pai = no;
    if(dado < no->dado)
      no = no->esq;

    else
      no = no->dir;
  }

  if(no->dir == NULL && no->esq == NULL)
    AB_Remover_No_Folha(pai, no);

  else if(no->dir == NULL || no->esq == NULL)
    AB_Remover_No_Filho_Unico(pai, no);

  else
    AB_Remover_No_Dois_Filhos(no);
}