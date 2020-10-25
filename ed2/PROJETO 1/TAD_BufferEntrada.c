#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"

/*
ITEM_VENDA* BufferEntrada_Criar(char* teste, int n_registros)
{
  ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * n_registros);
  FILE* arq = fopen(teste, "rb");
  fread(p, sizeof(ITEM_VENDA), n_registros, arq);

  return p;
}*/

BUFFER* BufferEntrada_Criar(char* teste, int k, int n_registros)
{
    BUFFER* buffer = malloc(sizeof(BUFFER));
    ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * ceil(n_registros/k));
    FILE* arq = fopen(teste, "rb");
        
    fread(p, sizeof(ITEM_VENDA), ceil(n_registros/k), arq);
    
    buffer->iv = p;
    buffer->buffer_pk = arq;
    buffer->n_reg_max = n_registros;

    fclose(arq);
    return buffer;
}

ITEM_VENDA BufferEntrada_Proximo(BUFFER* buffer, int atual)
{
  if(atual >= buffer->n_reg_max) return;

  return buffer->iv[atual+1];
}


ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer)
{
  //if(buffer->ocupado == 0) reencher(buffer);

  ITEM_VENDA xacabal = buffer->iv[0];
  

  ITEM_VENDA aux = buffer->iv[1];
  for (int i = 0; i < buffer->ocupado; i++)
  {
    buffer->iv[i] = aux;
    aux = BufferEntrada_Proximo(buffer, i+1);
  }

  buffer->ocupado--;

  return xacabal;
}
