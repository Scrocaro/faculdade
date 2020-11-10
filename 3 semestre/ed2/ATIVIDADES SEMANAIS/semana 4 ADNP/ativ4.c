#include <stdio.h>
#include <stdlib.h> //malloc, calloc e free
#include <string.h> //memcpy
#include <time.h>
#include "cabecalhoAtiv4.h"

/// implementação ///

void countingsort(info *v, int n)
{
    int *c, i, j;
    int k = max(v, n); //maior chave
    int t, acumulador = 0;
    info *s = malloc(n * sizeof(info)); //vetor de saida
    c = calloc(k+1, sizeof(int)); //vetor contador

    for(i=0; i<n; i++) //conta a frequencia de cada chave
        c[v[j].chave]++;
    
    for(i=0; i<=k; i++) //soma de prefixo exclusivo(posição que uma chave começa)
    {
        t = c[i];
        c[i] = acumulador;
        acumulador += t;
    }
    for(i=0; i<n; i++) //grava saida
    {
        int chave = v[i].chave;
        int j = c[chave];
        s[j].dado = v[i].dado;
        s[j].chave = v[i].chave;
        c[chave]++;
    }
    memcpy(v, s, sizeof(info) * n); //copia vetor s para o v

    free(s);
    free(c);
}

void countingsortDEC(int *v, int n, int div, int base, int *temp)
{
    int i, t, c[base], acumulador = 0;
    memset(c, 0, base * sizeof(int));

    #define DIGIT(X) (X / div) % base

    for(i=0; i<n; i++)
        c[DIGIT(v[i])]++;
    
    for(i=0; i<base; i++)
    {
        t = c[i];
        c[i] = acumulador;
        acumulador += t;
    }
    
    for(i=0; i<n; i++)
    {
        temp[c[DIGIT(v[i])]] = v[i];
        c[DIGIT(v[i])]++;
    }
    memcpy(v, temp, sizeof(int) * n);
}

void countingsortBIN(int *v, int n, int pos, int *temp)
{
    int i, t, c[2] = {0, 0}, acumulador = 0;

    #define DIGIT_BIN(X) (X >> pos) & 1

    for(i=0; i<n; i++)
        c[DIGIT_BIN(v[i])]++;
    
    c[1] = c[0];
    c[0] = 0;
  
    for(i=0; i<n; i++)
    {
        int chave = DIGIT_BIN(v[i]);
        int j = c[chave];
        temp[j] = v[i];
        c[chave]++;
    }

    memcpy(v, temp, sizeof(int) * n);
}

void radixsort(int *v, int n)
{
    int k, div = 1;
    int *temp = malloc(sizeof(int) * n);
    k = maxRadix(v, n);
    while(k>0)
    {
        countingsortDEC(v, n, div, 10, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}

void radixsortBIN(int *v, int n)
{
    int k, pos = 0;
    int *temp = malloc(sizeof(int) * n);
    k = maxRadix(v, n);

    while(k>0)
    {
        countingsortBIN(v, n, pos, temp);
        pos++;
        k /= 2;
    }

    free(temp);
}

int maxRadix(int *v, int n)
{
    int maior = v[0], i;

    for(i=0; i<n; i++)
    {
        if(v[i] > maior)
            maior = v[i];
    }

    return maior;
}

int max(info *v, int n)
{
    int maiorChave = v[0].chave;

    for(int i=0; i<n; i++)
    {
        if(v[i].chave > maiorChave)
            maiorChave = v[i].chave;
    }

    return maiorChave;
}

int* random_vetor (int qtdPos, int max, int seed)
{
    int *v = calloc(qtdPos, sizeof(int));
    
    srand(seed);
    for(int i = 0; i < qtdPos; i++)
        v[i] = rand() % max;

    return v;
}

/// main ///
int main()
{
    int seed = 0;
    int qtdPos = 1000;
    int max = qtdPos * 100;
    int *v = random_vetor(qtdPos, max, seed);
    clock_t t;
    
    t = clock();
    radixsortBIN(v, qtdPos);
    t = clock() - t;
    printf("binario: %f\n", ((float)t/(CLOCKS_PER_SEC/1000)));
   
    v = random_vetor(qtdPos, max, seed);

    t = clock();
    radixsort(v, qtdPos);
    t = clock() - t;
    printf("decimal: %f\n", ((float)t/(CLOCKS_PER_SEC/1000)));

    return 0;
}