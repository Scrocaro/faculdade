#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

ASCIITrie* AT_Buscar_R(ASCIITrie* T, unsigned char *chave, int n, int p)
{
  if(T == NULL)
    return NULL;

  if(p == n)
    return T;

  return AT_Buscar_R(T->filhos[chave[p]], chave, n, p+1);
}

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave)
{
  AT_Buscar_R(T, chave, strlen(chave), 0);
}

ASCIITrie *AT_Buscar_I(ASCIITrie *T, unsigned char *chave)
{
  if(T == NULL) 
    return NULL;

  int j = strlen(chave);
  int i = 0;
  ASCIITrie **tmp = &T;

  while(j != 0)
  {
    if((*tmp)->filhos[chave[i]] == NULL)
      return NULL;

    tmp = &((*tmp)->filhos[chave[i]]);
    i++;
    j--;
  }

  return (*tmp);
}

ASCIITrie* AT_Criar()
{
  ASCIITrie* noh;
  noh = malloc(sizeof(ASCIITrie));
  noh->estado = AT_LIVRE;
  noh->val = 0;
  noh->tam = 0;

  for(int i = 0; i < 256; i++)
    noh->filhos[i] = NULL;
  
  return noh;
}

void AT_Inserir_R(ASCIITrie **T, unsigned char *chave, int val, int n, int p)
{
  if((*T) == NULL)
    *T = AT_Criar();

  if(p == n)
  {
    (*T)->val = val;
    (*T)->estado = AT_OCUPADO;
    return;
  }
  
  AT_Inserir_R(&(*T)->filhos[chave[p]], chave, val, n, p+1);
}

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int val)
{
  AT_Inserir_R(T, chave, val, strlen(chave), 0);
  (*T)->tam++;
}

void AT_Inserir_I(ASCIITrie **T, unsigned char *chave, int val)
{
  if(*T == NULL) 
    *T = AT_Criar();

  int j = strlen(chave);
  int i = 0;
  ASCIITrie **tmp = T;

  while(j != 0)
  {
    if((*tmp)->filhos[chave[i]] == NULL) 
      (*tmp)->filhos[chave[i]] = AT_Criar();

    tmp = &((*tmp)->filhos[chave[i]]);
    i++;
    j--;
  }

  (*T)->tam++;
  (*tmp)->estado = AT_OCUPADO;
  (*tmp)->val = val;
}

void AT_Remover_I(ASCIITrie **T, unsigned char *chave)
{
  ASCIITrie ***remocao = calloc(strlen(chave), sizeof(ASCIITrie**));
  ASCIITrie **tmp = T;
  int conex = 0;
  int qtdRemocao = 0;

  for(int i = 0; i < strlen(chave); i++)
  {
    conex = 0;
    if((*tmp)->filhos[chave[i]] != NULL)
    {
      for(int j = 0; j < 256; j++) 
        if((*tmp)->filhos[j] != NULL) 
          conex++;

      if(conex == 1) 
        remocao[qtdRemocao++] = tmp;

      tmp = &((*tmp)->filhos[chave[i]]);
    }
  }

  if(qtdRemocao == 0) 
    return;

  free(*tmp);
  *tmp = NULL;

  for(int x = 0; x < qtdRemocao; x++)
  {
    free(*(remocao[x]));
    *(remocao[x]) = NULL; 
  }
}

void AT_Remover_R(ASCIITrie **T, unsigned char *chave, int n, int p)
{
  if(*T == NULL) 
    return;

  if(p == n)
    (*T)->estado = AT_OCUPADO;

  else
    AT_Remover_R(&(*T)->filhos[chave[p]], chave, n, p+1);

  if((*T)->estado == AT_OCUPADO)
  {
    for(int i = 0; i < 256; i++) 
      if((*T)->filhos[i] != NULL) 
        return;

    free(*T);
    *T = NULL;
  }
}

void AT_Remover(ASCIITrie **T, unsigned char *chave)
{
  AT_Remover_R(T, chave, strlen(chave), 0);
}

void AT_Imprimir_R(ASCIITrie *T, unsigned char c, int nivel)
{
  if(T == NULL) return;
  
  for(int i = 0; i < nivel; i++) 
    printf("-");

  char e = (T->estado == 0) ? 'L': 'O';
  printf("(%c) %d (%c)\n", c, T->val, e);

  for(int i = 0; i < 256; i++)
    if(T->filhos[i] != NULL)
      AT_Imprimir_R(T->filhos[i], i, nivel+1);
}

void AT_Imprimir(ASCIITrie *T)
{
  AT_Imprimir_R(T, 0, 0);
}
/////////////////////////////////////////////////////////
int AT_Limpa(ASCIITrie *T)
{
  if(T == NULL) 
    return 0;

  int tmp = 0;

  for(int i = 0; i < 256; i++)
  {
    if(T->filhos[i] != NULL)
      return AT_Limpa(T->filhos[i]);

    else
      tmp++;
  }

  if(tmp == 256 && T->estado == AT_OCUPADO)
    return 1;

  else
    return 0;
}

int AT_Tamanho(ASCIITrie *T)
{
  return T->tam;
}

int SubstringCountLenL(char * s, int L)
{
  if(L > strlen(s)) return 0;

  ASCIITrie *subT = NULL;
  char *substring = calloc(L+1, sizeof(char));

  for(int i = 0; i < strlen(s)-1; i++)
  {
    int k = i;
    for(int j = 0; j < L; j++) 
      substring[j] = s[i++];

    if(strlen(substring) == L) 
      AT_Inserir_I(&subT, substring, i);
      
    i = k;
  }

  return AT_Tamanho(subT);
}