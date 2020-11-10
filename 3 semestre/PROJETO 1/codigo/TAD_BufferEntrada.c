#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"

//Prepara os buffers iniciais, frações das divisões do buffer inicial
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
//////////////////////////////////////////////////////////////////////
int BufferEntrada_Proximo(BUFFER* buffer, int atual)
{
  if(buffer->n_reg_max-buffer->ocupado == buffer->n_reg_max) return INT_MAX;
  if(BufferEntrada_Vazio(buffer) == 1) return INT_MAX;
  return atual+1;
}

void moverBuffer(BUFFER* buffer, int* flag){
  if(buffer->ocupado <= 0)  *flag = 1;
  for(int i = 0; i < buffer->n_reg_max-1; i++){
    int prox = BufferEntrada_Proximo(buffer, i);
    if(prox != INT_MAX) buffer->iv[i] = buffer->iv[prox];
    
  }
}
/////////////////////////////////////////////////////////////////////
int BufferEntrada_Reencher(BUFFER* buffer)
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
    return -1;
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

//Ao consumir um elemento, a função move todos os elementos uma casa para frente e retorna a struct consumida
ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer, int* flag)
{ 
  if(BufferEntrada_Vazio(buffer) == 1) *flag = 1;

  if(buffer->ocupado <= 0){
    int i = BufferEntrada_Reencher(buffer);
    if(i == -1) *flag = 1;
  }
  
  ITEM_VENDA consumido = buffer->iv[0];

  moverBuffer(buffer, &flag);

  buffer->ocupado--;
  buffer->iv[buffer->ocupado+1].id = 0;
  return consumido;
}


int BufferEntrada_Vazio(BUFFER* buffer)
{ 
  if(buffer->ocupado > 0)
      return 0;
  else{
    return 1;
  }
}

int bufferGeral_Vazio(BUFFER_VET* vet){
  int aux=0;
  for(int i = 0; i < vet[0].n_buff; i++){
    if(BufferEntrada_Vazio(vet[i].b) == 0)
      return 0;
    else
    {
      aux++;
      if(aux == vet->n_buff-1)
        return 1;
    }
  }
}

////////////////////////////////////////////////////////////////
void BufferEntrada_Destruir(BUFFER_VET* vet)
{
  for(int i; i < vet->n_buff; i++){
    if(BufferEntrada_Vazio(vet[i].b)){
      free(vet[i].b);
      if(i+1 == vet->n_buff) free(vet);
    }
  }
}
