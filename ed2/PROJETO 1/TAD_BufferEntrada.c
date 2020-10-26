#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"

BUFFER* BufferEntrada_Criar(char* teste, float k, float n_registros)
{
    BUFFER* buffer = malloc(sizeof(BUFFER));
    ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * ceil(n_registros/k));
    FILE* arq = fopen(teste, "rb");
        
    fread(p, sizeof(ITEM_VENDA), ceil(n_registros/k), arq);

    buffer->iv = p;
    buffer->bloco = 1;
    buffer->buffer_pk = teste;
    buffer->n_reg_max = k;
    buffer->ocupado = buffer->n_reg_max;
    
    fclose(arq);
    return buffer;
}

ITEM_VENDA BufferEntrada_Proximo(BUFFER* buffer, int atual)
{
  if(atual < buffer->n_reg_max)
    return buffer->iv[atual+1];
}

void BufferEntrada_Reencher(BUFFER* buffer){
  
  ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * buffer->n_reg_max);
  FILE* arq = fopen(buffer->buffer_pk, "rb");

  fseek(arq, buffer->bloco*(buffer->n_reg_max)*sizeof(ITEM_VENDA), SEEK_SET);

  fread(p, sizeof(ITEM_VENDA), buffer->n_reg_max, arq);
  buffer->iv = p;
  buffer->ocupado = buffer->n_reg_max;
  buffer->bloco++;
}

ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer)
{ 
  BufferEntrada_Reencher(buffer);

  ITEM_VENDA consumido = buffer->iv[0];

  ITEM_VENDA* novo = malloc(sizeof(ITEM_VENDA) * buffer->n_reg_max);

  for(int i = 0; i < buffer->n_reg_max; i++)
    novo[i] = BufferEntrada_Proximo(buffer, i);

  buffer->iv = novo;
  buffer->iv[buffer->n_reg_max-1].id = 0;
  buffer->ocupado--;
  return consumido;
}


int BufferEntrada_Vazio(BUFFER* buffer)
{ 
  FILE* aux = fopen(buffer->buffer_pk, "rb");
  ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * buffer->n_reg_max);
  fread(p, sizeof(ITEM_VENDA), buffer->n_reg_max, aux);
  for(int i = 0; i < buffer->n_reg_max; i++){
    if(buffer->iv[i].id != 0)
      return 0;
  }
  return 1;
}


void BufferEntrada_Destruir(char* teste, BUFFER_VET* vet)
{
  for(int i; i < vet->n_buff; i++){
    if(BufferEntrada_Vazio(vet[i].b)){
      free(vet);
      remove(teste);
    }
  }
}
