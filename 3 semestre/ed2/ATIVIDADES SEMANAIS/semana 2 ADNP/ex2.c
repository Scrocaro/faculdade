#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// FUNCOES
void merge(int *v, int p, int q, int r);
void mergeSort(int *v, int e, int d);
int partition(int *v, int p, int r);
void quickSort(int *v, int e, int d);


void selectionSort (int *v, int n, int *cont);
void bubbleSort (int *v, int n, int *cont);
void insertionSort (int *v, int k, int *cont);

int max (int *v, int ini, int fim, int *cont);
void troca (int *v, int a, int b);
void insertion (int *v, int n, int *cont);
int* random_vetor (int qtdPos, int max, int seed);

// IMPLEMENTACOES
void merge(int *v, int p, int q, int r)
{
    int *e, *d, i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    e = (int*) malloc(sizeof(int) * (n1 + 1));
    d = (int*) malloc(sizeof(int) * (n2 + 1));

    for(i = 0; i < n1; i++)
        e[i] = v[p + i];
    e[n1] = INT_MAX;

    for(j = 0; j < n2; j++)
        d[j] = v[q+1 + i];
    d[n2] = INT_MAX;


    i = 0;
    j = 0;

    for(k = p; k <= r; k++)
    {
        if(e[i] <= d[j])
        {
            v[k] = e[i];
            i++;
        }
        else
        {
            v[k] = d[j];
            j++;
        }
    }
    
    free(e);
    free(d);
}

void mergeSort(int *v, int e, int d)
{
    int m;

    if(e < d)
    {
        m = (e+d)/2;
        mergeSort(v, e, m);
        mergeSort(v, m+1, d);
        merge(v, e, m, d);
    }
}

int partition(int *v, int p, int r)
{
    int x, i, j;
    x = v[r];
    i = p-1;
    for(j = p; j < r; j++)
    {
        if(v[j] <= x)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);

    return i+1;
}

void quickSort(int *v, int e, int d)
{
    int q;
    if(e < d)
    {
        q = partition(v, e, d);
        quickSort(v, e, q-1);
        quickSort(v, q+1, d);
    }
}

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

int main(int argc, char** argv){
    int qtdPos = 100000;
    int num = qtdPos * 100;
    int seed = 0;
    int cont = 0;
    int *v = random_vetor(qtdPos, num, seed);
    int *v2 = random_vetor(qtdPos, num, seed);
    int *v3 = random_vetor(qtdPos, num, seed);
    int *v4 = random_vetor(qtdPos, num, seed);
    int *v5 = random_vetor(qtdPos, num, seed);

    clock_t time;

    printf("\n SELECTION SORT\n");
    time = clock();
    selectionSort(v, qtdPos, &cont);
    time = clock() - time;
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
    time = clock();
    selectionSort(v, qtdPos, &cont);
    time = clock() - time;
    printf("\ntempo em segundos vet ja ordenado: %f\n", ((float)time/CLOCKS_PER_SEC));

    printf("\n\n\n");
    
    printf("\n BUBBLE SORT\n");
    time = clock();
    bubbleSort(v2, qtdPos, &cont);
    time = clock() - time;
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
    time = clock();
    bubbleSort(v2, qtdPos, &cont);
    time = clock() - time;
    printf("\ntempo em segundos vet ja ordenado: %f\n", ((float)time/CLOCKS_PER_SEC));

    printf("\n\n\n");

    printf("\n INSERTION SORT\n");
    time = clock();
    insertionSort(v3, qtdPos, &cont);
    time = clock() - time;
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
    time = clock();
    insertionSort(v3, qtdPos, &cont);
    time = clock() - time;
    printf("\ntempo em segundos vet ja ordenado: %f\n", ((float)time/CLOCKS_PER_SEC));

    printf("\n\n\n");

    printf("\n MERGE SORT\n");
    time = clock();
    mergeSort(v4, 0, qtdPos-1);
    time = clock() - time;
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
    time = clock();
    mergeSort(v4, 0, qtdPos-1);
    time = clock() - time;
    printf("\ntempo em segundos vet ja ordenado: %f\n", ((float)time/CLOCKS_PER_SEC));

    printf("\n\n\n");

    printf("\n QUICK SORT\n");
    time = clock();
    quickSort(v5, 0, qtdPos-1);
    time = clock() - time;
    printf("\ntempo em segundos: %f\n", ((float)time/CLOCKS_PER_SEC));
    time = clock();
    quickSort(v5, 0, qtdPos-1);
    time = clock() - time;
    printf("\ntempo em segundos vet ja ordenado: %f\n", ((float)time/CLOCKS_PER_SEC));
}