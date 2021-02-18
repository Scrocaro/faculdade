#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim;
    No* ult;
    int qtde;
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
    f->qtde = 0;
    f->prim = NULL;
    f->ult = f->prim;
    return f;
}

Boolean fila_inserir(Fila* f, Tipo elemento)
{
    No* no = (No*) malloc(sizeof(No));
    
    
    if(f->prim == NULL)
    {
        f->prim = no;
        f->ult = no->prox;
    }
    else if(f->qtde == 1)
    {
        f->prim->prox = no;
        f->ult = f->prim->prox;
    }
    else
    {
        f->ult->prox = no;
    }
    no->dado = elemento;

    f->qtde++;
    return true;
}

void fila_imprimir(Fila* f)
{
    int cont = 0;
    No* aux = f->prim;
    printf("[");
    while(cont < f->qtde){
        printf("%d, ", aux->dado);
        aux = aux->prox;
        cont++;
    }
    printf("]");
}

int fila_tamanho(Fila* f)
{
    No* aux = f->prim;
    int cont = 0;
    while(aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    cont = cont - 1;
    return cont;
}

int fila_contem(Fila* f, Tipo elemento)
{
    No* aux = f->prim;
    int x = 0;
    while(aux->prox != NULL)
    {
        if(aux->dado == elemento)  x++;
        aux = aux->prox;
    }
    if(x != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void fila_destruir(Fila* f)
{
    free(f);
}

int main()
{
    Fila* f = fila_criar();
    fila_inserir(f, 0);
    fila_inserir(f, 1);
    fila_inserir(f, 2);
    fila_inserir(f, 3);
    fila_inserir(f, 4);
    fila_inserir(f, 5);
    fila_tamanho(f);
    fila_imprimir(f);
}
