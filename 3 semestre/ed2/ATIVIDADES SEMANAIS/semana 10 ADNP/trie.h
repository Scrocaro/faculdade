#pragma once

typedef enum ASCIITrie_ESTADO
{
  AT_LIVRE,
  AT_OCUPADO
} ASCIITrie_ESTADO;

typedef struct ASCIITrie
{
  int val;
  ASCIITrie_ESTADO estado;
  struct ASCIITrie* filhos[256];
  int tam;
} ASCIITrie;

ASCIITrie* AT_Criar();

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave);
ASCIITrie* AT_Buscar_R(ASCIITrie* T, unsigned char *chave, int n, int p);

void AT_Inserir(ASCIITrie** T, unsigned char *chave, int val);
void AT_Inserir_R(ASCIITrie **T, unsigned char *chave, int val, int n, int p);

ASCIITrie *AT_Buscar_I(ASCIITrie *T, unsigned char *chave);
void AT_Inserir_I(ASCIITrie **T, unsigned char *chave, int val);

void AT_Remover_I(ASCIITrie **T, unsigned char *chave);
void AT_Remover_R(ASCIITrie **T, unsigned char *chave, int n, int p);
void AT_Remover(ASCIITrie **T, unsigned char *chave);

void AT_Imprimir_R(ASCIITrie *T, unsigned char c, int nivel);
void AT_Imprimir(ASCIITrie *T);

int AT_Limpa(ASCIITrie *T);
int AT_Tamanho(ASCIITrie *T);
int SubstringCountLenL(char * s, int L);
