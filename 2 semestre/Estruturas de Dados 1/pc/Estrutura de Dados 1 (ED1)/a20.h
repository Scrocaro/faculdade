#include <stdlib.h>
typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct no
{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct
{
    No* sentinela;
    int qtd;
}Lista;

/********************************************
 ********************************************/
Lista* lista_criar();
void lista_destruir(Lista* l);

void lista_inserir(Lista* l, Tipo elemento, int posicao);

int lista_remover1(Lista* l, int posicao);
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);
Boolean lista_remover_elemento(Lista* l, Tipo elemento);

Boolean lista_buscar(Lista* l, int posicao, Tipo* endereco);
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);

int lista_tamanho(Lista* l);
void lista_imprimir(Lista* l);

/************ FUNÇÕES AUXILIARES ************/
No* getPos(Lista* l, int posicao);

/*****************************************************************************
 *****************************************************************************/

Lista* lista_criar()
{
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->qtd = 0;
  l->sentinela = (No*)malloc(sizeof(No));
  l->sentinela->ant = l->sentinela->prox = l->sentinela;
  return l;
}

void lista_destruir(Lista* l)
{
  No* aux = l->sentinela;
  for(int i=0; i <= l->qtd; i++){
    No* aux2 = aux->ant;
    free(aux);
    aux = aux2;
  }
  free(l);
}

////////////////////////////////////////////////////////////

void lista_inserir(Lista* l, Tipo elemento, int posicao)
{
  No* pos = getPos(l, posicao);
  No* novo = (No*)malloc(sizeof(No));
  novo->dado = elemento;
  novo->ant = pos->ant;
  novo->prox = pos;
  pos->ant = pos->ant->prox = novo;
  l->qtd++;
}

int lista_remover1(Lista* l, int posicao)
{
  if(l == NULL) return -1;
  No* pos = getPos(l, posicao);
  pos->prox->ant = pos->ant;
  pos->ant->prox = pos->prox;
  int ret = pos->dado;
  free(pos);
  l->qtd--;
  return ret;
}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco)
{
  if(l == NULL) return false;
  No* pos = getPos(l, posicao);
  pos->prox->ant = pos->ant;
  pos->ant->prox = pos->prox;
  *endereco = pos->dado;
  free(pos);
  l->qtd--;
  return true;
}

Boolean lista_remover_elemento(Lista* l, Tipo elemento)
{
  if(l == NULL) return false;
  No* aux = l->sentinela;
  for(int i=0; i<l->qtd; i++){
    aux = aux->prox;
    if(aux->dado == elemento){
      int lixo = lista_remover1(l, i);
      l->qtd--;
      return true;
    }
  }
  return false;
}

////////////////////////////////////////////////////////////

Boolean lista_buscar(Lista* l, int posicao, Tipo* endereco)
{
  if(l == NULL) return false;
  if(posicao <= 0){
    *endereco = l->sentinela->prox->dado;
    return true;
  }
  if(posicao >= l->qtd-1){
    *endereco = l->sentinela->ant->dado;
    return true;
  }
  //
  No* aux = l->sentinela;
  if(posicao <= l->qtd/2)
    for(int i=0; i <= posicao; i++)
      aux = aux->prox;
  else
    for(int i=l->qtd-1; i >= posicao; i--)
      aux = aux->ant;
  //
  *endereco = aux->dado;
  return true;
}

Boolean lista_contem(Lista* l, Tipo elemento)
{
  if(l == NULL) return false;
  No* aux = l->sentinela;
  for(int i=0; i<l->qtd; i++){
    aux = aux->prox;
    if(aux->dado == elemento) return true;
  }
  return false;
}

int lista_posicao(Lista* l, Tipo elemento)
{
  if(l == NULL) return -1;
  No* aux = l->sentinela;
  for(int i=0; i<l->qtd; i++){
    aux = aux->prox;
    if(aux->dado == elemento) return i;
  }
  return -1;
}


////////////////////////////////////////////////////////////

int lista_tamanho(Lista* l)
{
  return l->qtd;
}

void lista_imprimir(Lista* l)
{
  if(l == NULL) return;
  if(l->qtd <= 0) printf("Lista vazia.\n");
  printf("Lista = [");
  No* aux = l->sentinela;
  for(int i=0; i<l->qtd; i++){
    aux = aux->prox;
    printf("%d", aux->dado);
    if(i != l->qtd-1) printf(", ");
  }
  printf("].\n");
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

No* getPos(Lista* l, int posicao)
{
  if(posicao <= 0) return l->sentinela->prox;
  if(posicao >= l->qtd-1) return l->sentinela;
  //
  No* aux = l->sentinela;
  if(posicao <= l->qtd/2)
    for(int i=0; i <= posicao; i++)
      aux = aux->prox;
  else
    for(int i=l->qtd-1; i >= posicao; i--)
      aux = aux->ant;
  return aux;
}
