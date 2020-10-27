#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"

BUFFER* BufferEntrada_Criar(char* teste, int n_registros, int k)
{ 
    BUFFER* buffer = malloc(sizeof(BUFFER));
    ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * ceil((float)n_registros/k));


    FILE* arq = fopen(teste, "rb");
        
    fread(p, sizeof(ITEM_VENDA), ceil((float)n_registros/k), arq);

    buffer->iv = p;
    buffer->bloco = 1;
    buffer->buffer_pk = teste;
    buffer->n_reg_max = ceil((float)n_registros/k);
    
    buffer->ocupado = buffer->n_reg_max;
    
    fclose(arq);
    return buffer;
}

ITEM_VENDA BufferEntrada_Proximo(BUFFER* buffer, int atual)
{
  if(atual < buffer->ocupado)
    return buffer->iv[atual+1];
}

void BufferEntrada_Reencher(BUFFER* buffer)
{
  FILE* arq = fopen(buffer->buffer_pk, "rb");

  fseek(arq, buffer->bloco*(buffer->n_reg_max)*sizeof(ITEM_VENDA), SEEK_SET);
  int inicio = ftell(arq);
  fseek(arq, 0, SEEK_END);
  int fim = ftell(arq);

  int tam_restante = fim - inicio;
  fseek(arq, buffer->bloco*(buffer->n_reg_max)*sizeof(ITEM_VENDA), SEEK_SET);
  ITEM_VENDA* p;

  if(tam_restante < sizeof(ITEM_VENDA) * buffer->n_reg_max)
  {
    p = malloc(sizeof(ITEM_VENDA) * (tam_restante/sizeof(ITEM_VENDA)));
    fread(p, sizeof(ITEM_VENDA), tam_restante/sizeof(ITEM_VENDA), arq);
    buffer->ocupado = tam_restante/sizeof(ITEM_VENDA);
  }
  else
  {  
    p = malloc(sizeof(ITEM_VENDA) * buffer->n_reg_max);
    fread(p, sizeof(ITEM_VENDA), buffer->n_reg_max, arq);
    buffer->ocupado = buffer->n_reg_max;
  }
  buffer->iv = p;
  buffer->bloco++;
}

ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer, int* flag)
{ 
  if(BufferEntrada_Vazio(buffer) == 1) *flag = 1;
  
  if(buffer->ocupado = 0){
    BufferEntrada_Reencher(buffer);
  }
  
  ITEM_VENDA consumido = buffer->iv[0];

  ITEM_VENDA* novo = malloc(sizeof(ITEM_VENDA) * buffer->n_reg_max);

  for(int i = 0; i < buffer->ocupado; i++)
    novo[i] = BufferEntrada_Proximo(buffer, i);

  buffer->iv = novo;
  //buffer->iv[buffer->ocupado-1].id = 0;
  buffer->ocupado--;
  return consumido;
}


int BufferEntrada_Vazio(BUFFER* buffer)
{ 
  if(buffer->ocupado > 0)
      return 0;
  else{
    buffer->bloco = 0;
    return 1;
  }
}

int bufferGeral_Vazio(BUFFER_VET* vet){
  for(int i = 0; i < vet[0].n_buff; i++){
    if(BufferEntrada_Vazio(vet[i].b) == 0)
      return 0;
  }
  return 1;
}


void BufferEntrada_Destruir(BUFFER_VET* vet)
{
  for(int i; i < vet->n_buff; i++){
    if(BufferEntrada_Vazio(vet[i].b)){
      free(vet[i].b);
      if(i+1 == vet->n_buff) free(vet);
    }
  }
}
