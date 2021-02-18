#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5


// DADOS
typedef int DataType;
typedef enum {false, true} Boolean;

typedef struct
{
    DataType* vet;
    int size;
    int length;
} Vetor;


//OPERAÇÕES (PROTÓTIPOS)

Vetor* vetor_new();
void vetor_free(Vetor* v);
void vetor_print(Vetor* m);
Boolean vetor_insert(Vetor* v, DataType element, int index);
Boolean vetor_add(Vetor* v, DataType element);
void space_add();
//OPERAÇÕES (IMPLEMENTAÇÃO)

Vetor* vetor_new()
{
    Vetor *vetor = (Vetor*)malloc(sizeof(Vetor));
    vetor->vet = (DataType*)calloc(LENGTH, sizeof(DataType));
    vetor->size = 0;
    vetor->length = 5;
    return vetor;
}

void vetor_free(Vetor* v)
{
    free(v);
}

void vetor_print(Vetor* m)
{
    for(int i=0; i<m->length; i++)
    {
        printf("[%d]", m->vet[i]);
    }
    printf("\n");
}

Boolean vetor_insert(Vetor* v, DataType element, int index)
{
    int tamanho = v->length;
    int usado = v->size;
    if (tamanho > usado)
    {
        for (int i = tamanho; i > index; i--)
        {
            v->vet[i] = v->vet[i - 1];
        }
        v->vet[i] = element;
        usado++;
    else
    {
        int vett[usado];
        for (int i = 0; i < usado; i++)
        {
            vett[i] = v->vet[i];
        }
        tamanho = tamanho * 2;
        v->vet = (int *)calloc(LENGTH, sizeof(int));
        for (int i = 0; i < tamanho; i++)
        {
            v->vet[i] = 0;
        }
        for (i = 0; i < usado; i++)
        {
            v->vet[i] = vett[i];
        }
        for (i = tamanho; i > index; i--)
        {
            v->vet[i] = v->vet[i - 1];
        }
        v->vet[i] = element;
        usado++;
    }
}

Boolean vetor_add (Vetor* v, DataType element)
{
    int tamanho = v->length, usado = v->size;
    if (tamanho > usado)
    {
        v->vet[usado] = element;
        usado++;
    }
    else
    {
        int vett[v->size];
        for (int i = 0; i < usado; i++)
        {
            vett[i] = v->vet[i];
        }
        tamanho = tamanho * 2;
        v->vet = (int *)calloc(LENGTH, sizeof(int));
        for (int i = 0; i < tamanho; i++)
        {
            v->vet[i] = 0;
        }
        for (int i = 0; i < usado; i++)
        {
            v->vet[i] = vett[i];
        }
        v->vet[i] = element;
        usado++;
    }
}

DataType vetor_remove1(Vetor *v, int index)
{
    int x = v->vet[index], y = 0;
    for (int i = index; i < v->size; i++)
    {
        v->vet[i] = v->vet[i + 1];
    }
    for (int i = 0; i < v->length; i++)
    {
        if (v->vet[i] != 0)
            y++;
    }
    if (y < v->length  /4)
    {
        int vett[v->size];
        for (int i = 0; i < v->size; i++)
        {
            vett[i] = v->vet[i];
        }
        free(v);
        v->length = v->length /2;
        v->vet = (int *)calloc(LENGTH, sizeof(int));
        for (int i = 0; i < v->size; i++)
        {
            v->vet[i] = vett[i];
        }
    }
    v->size--;
    return x;
}

Boolean vetor_remove2(Vetor *v, int index, DataType *ptr)
{
    int x = v->vet[index], y = 0;
    for (int i = index; i < v->size; i++)
    {
        v->vet[i] = v->vet[i + 1];
    }
    for (int i = 0; i < v->length; i++)
    {
        if (v->vet[i] != 0)
            y++;
    }
    if (y < v->length /4)
    {
        int vett[v->size];
        for (int i = 0; i < v->size; i++)
        {
            vett[i] = v->vet[i];
        }
        free(v);
        v->length = v->length /2;
        v->vet = (int *)calloc(LENGTH, sizeof(int));
        for (int i = 0; i < v->size; i++)
        {
            v->vet[i] = vett[i];
        }
    }
    v->size--;
    *ptr = x;
}

DataType vetor_shift1(Vetor *v)
{
    int x = v->vet[0], y = 0;;
    v->vet[0] = 0;
    for (int i = 0; i < v->size; i++)
    {
        v->vet[i] = v->vet[i + 1];
    }
    for (int i = 0; i < v->length; i++)
    {
        if (v->vet[i] != 0)
            y++;
    }
    if (y < v->length /4)
    {
        int vet[v->size];
        for (int i = 0; i < v->size; i++)
        {
            vett[i] = v->vet[i];
        }
        free(v);
        v->length /= 2;
        v->vet = (int *)calloc(LENGTH, sizeof(int));
        for (int i = 0; i < v->size; i++)
        {
            v->vet[i] = vett[i];
        }
    }
    v->size--;
    return x;
}

Boolean vetor_shift2(Vetor *v, DataType *ptr)
{
    int x = v->vet[0], y = 0;
    v->vet[0] = 0;
    for (int i = 0; i < v->size; i++)
    {
        v->vet[i] = v->vet[i + 1];
    }
    for (int i = 0; i < v->length; i++)
    {
        if (v->vet[i] != 0)
            y++;
    }
    if (y < v->length / 4)
    {
        int vett[v->size];
        for (int i = 0; i < v->size; i++)
        {
            vett[i] = v->vet[i];
        }
        free(v);
        v->length /= 2;
        v->vet = (int *)calloc(LENGTH, sizeof(int));
        for (int i = 0; i < v->size; i++)
        {
            v->vet[i] = vett[i];
        }
    }
    v->size--;
    *ptr = x;
}

DataType vetor_get1(Vetor *v, int index)
{
    return v->vet[index];
}

Boolean vetor_get2(Vetor *v, int index, DataType *ptr)
{
    *ptr = v->vet[index];
}

DataType *vetor_get3(Vetor *v, int index)
{
    return v->vet[index];
}

Vetor *vetor_sub1(Vetor *v, int index)
{
    Vetor *sub = vetor_new();
    if (index >= 0)
    {
        for (int i = 0; i <= index; i++)
        {
            vetor_add(sub, v->vet[i]);
            sub->size++;
        }
    }
    else
    {
        for (int i = v->size; i >= index; i--)
        {
            vetor_add(sub, v->vet[i]);
            sub->size++;
        }
    }
    
    return sub;
}

Vetor* vetor_sub2(Vetor* v, int start, int end)
{
    Vetor *sub = vetor_new();
    if (start <= end)
    {
        for (int i = start; i <= end; i++)
        {
            vetor_add(sub, v->vet[i]);
            sub->size++;
        }
    }
    else
    {
        for (int i = end; i >= start; i--)
        {
            vetor_add(sub, v->vet[i]);
            sub->size++;
        }
    }
    
    return sub;
}

void vetor_map(Vetor *v, void (*funcao)(DataType *))
{
    funcao(v);
}

Boolean vetor_set(Vetor *v, int index, DataType valor)
{
    v->vet[index] = valor;
}

int vetor_size(Vetor* v)
{
    return v->size;
}