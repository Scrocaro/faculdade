#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

//Registro utilizado para acomodar cada elemento da pilha (Nó).
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

//Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
typedef struct{
    No* topo;
    int qtde;
}Pilha;

//////////////////////
Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
void pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
*/
Pilha* pilha_criar(){
  Pilha* pl = (Pilha*)malloc(sizeof(Pilha));
  pl->topo = NULL;
  pl->qtde = 0;
  return pl;
}

/**
 * Desaloca a pilha <p>.
*/
void pilha_destruir(Pilha* p){
  No* tmp = p->topo;
  while(tmp!=NULL){
    No* tmp2 = tmp->prox;
    free(tmp);
    tmp = tmp2;
  }
  free(p);
}

/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
*/
Boolean pilha_push(Pilha* p, Tipo elemento){
  No* el = (No*)malloc(sizeof(No));
  el->dado = elemento;
  el->prox = p->topo;
  if(el != NULL){
    p->topo = el;
    p->qtde++;
    return true;
  }else{
    free(el);
    return false;
  }
}

/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
*/
Tipo* pilha_pop1(Pilha* p){
  if(p->topo != NULL){
    Tipo* el = (Tipo*)malloc(sizeof(Tipo));
    *el = p->topo->dado;
    No* tmp = p->topo;
    p->topo = p->topo->prox;
    p->qtde--;
    free(tmp);
    return el;
  }
  else return NULL;
}

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
*/
Boolean pilha_pop2(Pilha* p, Tipo* end){
  if(p->topo != NULL){
    *end = p->topo->dado;
    No* tmp = p->topo;
    p->topo = p->topo->prox;
    p->qtde--;
    free(tmp);
    return true;
  }
  else return false;
}

/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
*/
void pilha_imprimir(Pilha* p){
  printf("Vetor = [");
  No* tmp = p->topo;
  int tst=0;
  while(tmp != NULL){
    if(tmp->prox == NULL) printf("%d", tmp->dado);
    else printf("%d, ", tmp->dado);
    tmp = tmp->prox;
  }
  printf("]\n");
}

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
*/
int pilha_posicao(Pilha* p, Tipo elemento){
  No* tmp = p->topo;
  int pos=0;
  for(int i=0; i<p->qtde; i++){
    if(tmp->dado == elemento){
      return pos;
    }else{
      tmp = tmp->prox;
      pos++;
    }
  }
  return -1;
}

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
*/
int pilha_tamanho(Pilha* p){
  return p->qtde;
}

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
*/
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
  int qtde = 0;
  for(int i=0; i<tam; i++){
    pilha_push(p, vetor[i]);
    qtde++;
  }
  return qtde;
}

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
*/
void pilha_inverter(Pilha* p){
  Tipo vet[p->qtde];
  int cont=0;
  //cria vetor invertendo-o ao mesmo tempo.
  No* tmp = p->topo;
  while(tmp != NULL){
    vet[cont] = tmp->dado;
    tmp = tmp->prox;
    cont++;
  }
  //cria pilha c/ Vetor
  pilha_destruir(p);
  Pilha* p2 = pilha_criar();
  pilha_pushAll(p2, vet, cont);
}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
*/
Pilha* pilha_clone(Pilha* p){
  Pilha* p2 = (Pilha*)malloc(sizeof(Pilha));
  No* tmp = p->topo;
  while(tmp != NULL){
    pilha_push(p2, tmp->dado);
    tmp = tmp->prox;
  }
  return p2;
}
