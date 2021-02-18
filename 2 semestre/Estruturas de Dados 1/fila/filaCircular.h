#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;

Fila* fila_criar();
void fila_destruir(Fila* f);

Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);

Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);

Fila* fila_criar()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->vetor = (Tipo*) malloc(sizeof(Tipo));
    f->inicio = f->vetor;
    f->fim = f->vetor;
    f->tam = 0;
}

Boolean fila_inserir(Fila* f, Tipo elemento)
{
    Fila* aux = f;
    f->inicio = 
}
