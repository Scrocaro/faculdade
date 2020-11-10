#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cabecalhoAtiv5.h"

int busca_seq(int *v, int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i] == x)
            return i;
    }
    return -1;
}

int busca_bin(int *v, int e, int d, int x)
{
    int m;
    if(e <= d)
    {
        m = (e + d) / 2;
        if(v[m] == x)
            return m;

        else
        {
            if(x > v[m])
                return busca_bin(v, m+1, d, x);

            else
                return busca_bin(v, e, m-1, x);
            
        }
    }
    return -1;
}

int selectionMinK(int *v, int n, int k)
{
    int *aux = calloc(n, sizeof(int)), j = k;

    memcpy(aux, v, sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        int posMenor = minK(aux, i, n, i);
        troca(aux, i, posMenor);
        j--;
        if(j == 0) 
            break;
    }
    return aux[k-1];
}

int heapMinK(int *v, int n, int k)
{
    int i = k-1;

    buildMinHeap(v, n);
    
    while(i > 0)
    {
        troca(v, 0, n-1);
        n--;
        buildMinHeap(v, n);
        i--;
    }
    return v[0];
}

void heapSort(int *v, int n)
{
    buildMinHeap(v, n);
    for(int i = n-1; i > 0; i--)
    {
        troca(v, 0, i);
        buildMinHeap(v, i);
    }
}

void buildMinHeap(int *v, int n)
{
    for(int i = n/2; i >= 0; i--)
        minHeapify(v, i, n);
}

void minHeapify(int *v, int i, int tam)
{
    int e, d, menor = i;
    e = esq(i);
    d = dir(i);

    if((e < tam) && (v[e] > v[i]))
        menor = e;

    if((d < tam) && (v[d] > v[menor]))
        menor = d;

    if(menor != i)
    {
        troca(v, i, menor);
        minHeapify(v, menor, tam);
    }
}

int quickMinK(int *v, int e, int d, int k)
{
    int q;

    if(e < d)
    {
        q = partition(v, e, d);
        if(q == k) 
            return v[k-1];
        if(q < k)
            quickMinK(v, q+1, d, k);
        if(q > k)
            quickMinK(v, e, q-1, k);
    }
    return v[k-1];
}

int partition(int *v, int p, int r)
{
    int pivo = v[r];
    int i = p-1;

    for(int j = p; j < r; j++)
    {
        if(v[j] <= pivo)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);
    return i+1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int minK(int *v, int i, int n, int posMenor)
{
    for(int j = i; j < n; j++)
    {
        if(v[j] < v[posMenor])
            posMenor = j;
    }
    return posMenor;
}

int* random_vector_unique_elems(int n, int seed)
{
    int* v = (int*) calloc(n, sizeof(int));
    srand(seed);

    for(int i = 0; i < n; i++) 
        v[i] = i+1;
        
    embaralhar(v, 0, n);

    return v;
}

void embaralhar(int *v, int ini, int fim){
    int i, j;

    for(i = fim-1; i > ini; i--)
    {
        j = (rand() % (i + 1));
        j = (j <= ini) ? ini+1 : j;
        troca(v, i, j);
    }
}

void troca(int* v, int n1, int n2)
{
    int aux = v[n1];
    v[n1] = v[n2];
    v[n2] = aux;
}

int esq(int i)
{
    return (2*i) + 1;  
}

int dir(int i)
{
    return esq(i) + 1;
}

int main()
{
    int seed = 42, 
    n = 500000;
    int k = 1;
    int* v = random_vector_unique_elems(n, seed);
    
    clock_t t;

    t = clock();
    selectionMinK(v, n, k);
    t = clock() - t;
    printf("selection: %fs\n", ((float)t/(CLOCKS_PER_SEC)));

    v = random_vector_unique_elems(n, seed);

    t = clock();
    heapMinK(v, n, k);
    t = clock() - t;
    printf("heap: %fs\n", ((float)t/(CLOCKS_PER_SEC)));

    v = random_vector_unique_elems(n, seed);

    t = clock();
    quickMinK(v, 0, n-1, k);
    t = clock() - t;
    printf("quick: %fs\n", ((float)t/(CLOCKS_PER_SEC)));
}