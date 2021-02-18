#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int DataType;

/************************************************
 * ESTRUTURA
 ***********************************************/

typedef struct{
    DataType* vetor;
    int tam;
    int qtde;
}Fila;


/************************************************
 * PROTOTIPOS
 ***********************************************/
Fila* fila_criar(int tam);
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, DataType data);
Boolean fila_remover(Fila* f, DataType* removido);
Boolean fila_primeiro(Fila* f, DataType* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, DataType elemento);
void fila_imprimir(Fila* f);

//FUNCOES AUXILIARES
void aux_troca(DataType* a, DataType* b);
void aux_aumentaVetor(Fila* f);
void aux_diminuiVetor(Fila* f);
void aux_sobeHeap(Fila* f, int k);
void aux_desceHeap(Fila* f, int k);
#define PAI(i) ((i-1)/2)
#define IRMAO_DIREITA(i) (i+1)
#define IRMAO_ESQUERDA(i) (i-1)
#define FILHO_ESQUERDA(i) (2*i+1)
#define FILHO_DIREITA(i) (2*i+2)
#define LOG2 0.3010299956
/************************************************
 * IMPLEMENTACAO
 ***********************************************/

 Fila* fila_criar(int tam){
   if(tam <= 0) return NULL;
   Fila* f = (Fila*)malloc(sizeof(Fila));
   f->tam = tam;
   f->qtde = 0;
   f->vetor = (DataType*)calloc(f->tam, sizeof(DataType));
   return f;
 }

void fila_destruir(Fila* f){
   free(f->vetor);
   free(f);
}

void fila_imprimir(Fila* f){
  if(f == NULL) return;
  printf("v = [");
  for(int i=0; i<f->tam-1; i++){
    //(f->tam-i)*LOG2;
    printf("%d", f->vetor[i]);
    if(i != f->tam-2) printf(", ");
    if(i % 15 == 0 && i != 0 && i != f->tam-2) printf("\n     ");
  }
  printf("]\n");
}

////////////////////////////////////////////////////////////////////

Boolean fila_inserir(Fila* f, DataType data){
  if(f == NULL) return false;
  if(f->qtde >= f->tam) aux_aumentaVetor(f);
  //
  f->vetor[f->qtde] = data;
  f->qtde++;
  aux_sobeHeap(f, f->qtde-1);
  return true;
}

Boolean fila_remover(Fila* f, DataType* removido){
  if(f == NULL) return false;
  if(f->qtde == 0) return false;
  if( (((f->qtde-1)*100)/f->tam) <= 25) aux_diminuiVetor(f);
  //
  *removido = f->vetor[0];
  aux_troca(&f->vetor[0], &f->vetor[f->qtde-1]);
  aux_desceHeap(f, 0);
  f->vetor[f->qtde-1] = 0;
  f->qtde--;
}

////////////////////////////////////////////////////////////////////

Boolean fila_primeiro(Fila* f, DataType* endereco){
  if(f == NULL) return false;
  if(f->qtde <= 0) return false;
  *endereco = f->vetor[0];
  return true;
}

int fila_tamanho(Fila* f){
  if(f == NULL) return -1;
  return f->qtde;
}

int fila_contem(Fila* f, DataType elemento){
  if(f == NULL) return -1;
  for(int i=0; i<f->qtde; i++){
    if(f->vetor[i] == elemento) return i;
  }
  return -1;
}


/************************************************
 * IMPLEMENTACAO AUXILIARES
 ***********************************************/

void aux_sobeHeap(Fila* f, int k){
  if(k <= 0 || k > f->tam) return;
  //
  if(f->vetor[k] > f->vetor[PAI(k)]){
    aux_troca(&f->vetor[k], &f->vetor[PAI(k)]);
    int aux_k = PAI(k);
    aux_sobeHeap(f, aux_k);
  }
}

void aux_desceHeap(Fila* f, int k){
    if(k < 0 || FILHO_ESQUERDA(k) >= f->tam) return; //Checa se já está no nivel final.
    //
    int aux_k = f->tam;
    int maiorFilho = FILHO_ESQUERDA(k);
    if(FILHO_DIREITA(k) < f->tam){
      maiorFilho = (f->vetor[FILHO_ESQUERDA(k)] >= f->vetor[FILHO_DIREITA(k)] ? FILHO_ESQUERDA(k) : FILHO_DIREITA(k));
    }
    //
    if(f->vetor[maiorFilho] > f->vetor[k]){
      aux_troca(&f->vetor[maiorFilho], &f->vetor[k]);
      aux_desceHeap(f, maiorFilho);
    }
}

void aux_troca(DataType* a, DataType* b){
    DataType temp = *a;
    *a = *b;
    *b = temp;
}

void aux_aumentaVetor(Fila* f){
  f->tam *= 2;
  DataType* v = (DataType*)calloc(f->tam, sizeof(DataType));
  for(int i=0; i<f->qtde; i++){
    v[i] = f->vetor[i];
  }
  free(f->vetor);
  f->vetor = v;
}

void aux_diminuiVetor(Fila* f){
  f->tam = f->tam/2;
  DataType* v = (DataType*)calloc(f->tam, sizeof(DataType));
  for(int i=0; i<f->qtde; i++){
    v[i] = f->vetor[i];
  }
  free(f->vetor);
  f->vetor = v;
}
