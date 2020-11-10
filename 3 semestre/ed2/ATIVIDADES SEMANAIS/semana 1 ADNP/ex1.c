#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// PRINCIPAIS //
void selectionSort (int *v, int n, int *cont);
void bubbleSort (int *v, int n, int *cont);
void insertionSort (int *v, int k, int *cont);

// AUXILIARES //
int max (int *v, int ini, int fim, int *cont);
void troca (int *v, int a, int b);
void insertion (int *v, int n, int *cont);
int* random_vetor (int qtdPos, int max, int seed);

// IMPLEMENTAÇÃO //
int* random_vetor (int qtdPos, int max, int seed)
{
    int* v = (int*) calloc(qtdPos, sizeof(int));
    srand(seed);
    for(int i = 0; i < qtdPos; i++)
    {
        v[i] = rand() % max;
    }

    return v;
}

int max(int *v, int ini, int fim, int *cont)
{
    int posMaior = fim;
    
    for(int i = ini; i <= fim; i++)
    {
        if(v[i] > v[fim] && v[i] > v[posMaior]) 
        {
            *cont = *cont+1;
            posMaior = i;
        }
    }

    return posMaior;
}

void troca(int *v, int maior, int i)
{
    int aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;
}

void insertion(int *v, int k, int *cont)
{
    int i = k-1;
    int x = v[k];

    while(i >= 0 && v[i] > x)
    {
        *cont = *cont + 1; 
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = x;
}

void selectionSort(int *v, int n, int *cont)
{
    int maior;
    for(int i = n-1; i > 0; i--)
    {
        maior = max(v, 0, i, cont);
        troca(v, maior, i);
    }
}

void bubbleSort(int *v, int n, int *cont)
{
    for(int i = n-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            *cont = *cont + 1;
            if(v[j] > v[j+1])
            {
                troca(v, j, j+1);
            }
        }
    }
}

void insertionSort(int *v, int n, int *cont)
{
    for(int j = 1; j < n; j++)
    {
        insertion (v, j, cont);
    }
}

int main()
{
    int qtdPos = 100;
    int n = 1000;
    int seed = 0;
    int  cont = 0;
    int *v = random_vetor(qtdPos, n, seed);
    int *v2 = random_vetor(qtdPos, n, seed);
    int *v3 = random_vetor(qtdPos, n, seed);

    clock_t time;

    printf("\n SELECTION SORT\n");
    time = clock();
    selectionSort(v, qtdPos, &cont);
    time = clock() - time;
    printf("\ncomparações: %d\n", cont);
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
    
    printf("\n\n\n");
    
    printf("\n BUBBLE SORT\n");
    cont = 0;
    time = clock();
    bubbleSort(v2, qtdPos, &cont);
    time = clock() - time;
    printf("\ncomparações: %d\n", cont);
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));

    printf("\n\n\n");

    printf("\n INSERTION SORT\n");
    cont = 0;
    time = clock();
    insertionSort(v3, qtdPos, &cont);
    time = clock() - time;
    printf("\ncomparações: %d\n", cont);
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
}