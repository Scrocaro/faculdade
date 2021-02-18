#include <stdio.h>
#include <stdlib.h>


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
    vetor->vet = (DataType*)calloc(5, sizeof(DataType));
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
    if (v->size >= v->length)
    {
        printf("Não pode por nessa casa.\n");
    }
    else
    {
      for (int i = v->length; i > index; i--)
      {
          v->vet[i] = v->vet[i-1];
      }
      v->vet[index] = element;
      v->size++;
      //vetor_add(v, element);
    }
}

void space_add (Vetor* v)
{
    if (v->size == v->length)
    {
        Vetor *vett = (Vetor*)malloc(sizeof(Vetor));
        vett->vet = (DataType*)calloc(2 * v->length, sizeof(DataType));
        v->length = v->length * 2;
        vett->length = v->length;
        vett->size = v->size;
        for (int i = 0; i < vett->length; i++)
        {
            v->vet[i] = vett->vet[i];
        }
        printf("%d\n", v->length);
        printf("%d\n", vett->size);
    }
    /*if (v->size == v->length)
    {
        Vetor *vet = (Vetor*)malloc(sizeof(Vetor));
        vet->vet = (DataType*)calloc(2*v->length, sizeof(DataType));
        vet->length = v->length*2;
        vet->size = v->size;
        for (int i = v->length; i > 0; i--)
        {
            vet->vet[i] = v->vet[i];
        }
        v->vet = vet->vet;
    }*/
}

Boolean vetor_add (Vetor* v, DataType element)
{
    space_add(v);
    for (int i = 0; i < v->length; i++)
    {
        v->vet[i] = v->vet[i+1];
    }
    v->vet[v->length-1] = element;
    v->size++;
    /*ultimo = v->length;
    v->vet[ultimo] = element;*/

}
