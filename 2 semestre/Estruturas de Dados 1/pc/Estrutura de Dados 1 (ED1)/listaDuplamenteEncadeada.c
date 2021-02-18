#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Lista;


Lista* lista_criar();
void lista_destruir(Lista* l);////////////////////////////////////////////////////

void lista_inserir(Lista* l, Tipo elemento, int posicao);
void lista_inserir_fim(Lista* l, Tipo elemento);

int* lista_remover1(Lista* l, int posicao);
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);////////////////////////////
Boolean lista_remover_elemento(Lista* l, Tipo elemento);/////////////////////////////////////////


Boolean lista_buscar(Lista* l, int posicao, int* endereco);///////////////////////////////
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);////////////////////////////////////

int lista_tamanho(Lista* l);
void lista_imprimir(Lista* l);


Lista* lista_criar()
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->qtde = 0;

    return l;
}

void lista_inserir(Lista* l, Tipo elemento, int posicao)
{
    int i;
    No* no = (No*) malloc(sizeof(No));
    No* aux = (No*) malloc(sizeof(No));
    No* ult = (No*) malloc(sizeof(No));
    no->dado = elemento;
    l->qtde++;

    ////////////////////// seta o primeiro //////////////////////
    if(l->qtde == 0)
    {
        l->primeiro = no;
        l->primeiro->ant = NULL;
    }

    ////////////////////// seta o ultimo //////////////////////
    for(i = 0; i < l->qtde; i++)
    {
        ult = l->primeiro->prox;
        if(i == l->qtde)
        {
            l->ultimo = ult;
            l->ultimo->prox = NULL;
        }
    }

    ////////////////////// insere //////////////////////
    i = 0;
    do{
        aux->prox = no->prox;
        i++;
        if(i = posicao)
        {
            aux->prox->ant->prox = aux;
            aux->ant = aux->prox->ant;
            aux->prox->ant = aux;
        }
    }while(i < posicao);
}

int* lista_remover1(Lista* l, int posicao)
{
    No* no = (No*) malloc(sizeof(No));
    No* aux = (No*) malloc(sizeof(No));
    no = l->primeiro;
    for(int i = 0; i < posicao; i++)
    {
        no = no->prox;
    }
    aux->prox = no->prox;
    no->ant->prox = aux;
    aux->ant = no->ant;
    no->prox->ant = aux;
    free(no);

    return l;
}

void lista_imprimir(Lista* l)
{
    No* aux = (No*) malloc(sizeof(No));
    aux = l->primeiro;
    for(int i = 0; i < l->qtde-1; i++)
    {
        printf("%d", aux->dado);
        aux = aux->prox;
    }
}

int lista_tamanho(Lista* l)
{
    printf("%d", l->qtde);
    return l->qtde;
}

void lista_inserir_fim(Lista* l, Tipo elemento)
{
    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    l->ultimo->prox = no;
    no->prox = NULL;
    l->qtde++;
}

Boolean lista_contem(Lista* l, Tipo elemento)
{
    int cont = 0;
    No* no = (No*) malloc(sizeof(No));
    no = l->primeiro;
    for(int i = 0; i < l->qtde; i++)
    {
        if(no->dado == elemento) cont++;
        no = no->prox
    }
    if(cont == 0){ return false;}
    else{ return true;}
}

int main()
{
    Lista* l = lista_criar();
    lista_inserir_fim(l, 1);
    lista_inserir_fim(l, 2);
    lista_inserir_fim(l, 3);
    lista_imprimir(l);
    lista_tamanho(l);

    return 0;
}