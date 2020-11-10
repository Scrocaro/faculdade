#include "tabelahash_ea.h"
#include <stdlib.h>

int THEA_Hash(THEA* TH, int chave, int k)   // endereço inicial para fazer inserção
{
    return ((chave % TH->m) + k) % TH->m;   // lista circular
}

THEA* THEA_Criar(int m)
{
    THEA* novo;
    novo = malloc(sizeof(THEA));    
    novo->TH = malloc(sizeof(ELEM) * m);
    novo->m = m;
    novo->n = 0;

    for(int i = 0; i < m; i++)
        novo->TH[i].estado = E_LIVRE;

    return novo;
}


int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int h, k, h_inicial, flag = 0;
    k = 0;
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while(TH->TH[h].estado == E_OCUPADO)
    {
        if(TH->TH[h].chave == chave)
        {
            flag = 1;
            break;
        }

        k++;
        h = THEA_Hash(TH, chave, k);

        if(h == h_inicial)
            return -1;
    }

    TH->TH[h].chave = chave;
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;
    if(flag != 1)
        TH->n++;

    return h;
}

int THEA_Buscar(THEA *TH, int chave)
{
    int h, h_inicial, k;
    k = 0;
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while(TH->TH[h].estado != E_LIVRE)
    {
        if((TH->TH[h].estado == E_OCUPADO) && (TH->TH[h].chave == chave))
            return h;

        k++;
        h = THEA_Hash(TH, chave, k);

        if(h_inicial == h)
            return -1;
    }

    return -1;
}

void THEA_Remover(THEA *TH, int chave)
{
    int temp;
    temp = THEA_Buscar(TH, chave);
    if(temp != -1)
    {
        TH->TH[temp].estado = E_APAGADO;
        TH->n -= 1;
    }
}

int THEA_ClusterMaximo(THEA* TH)
{
    int i = 0, tamCluster = 0, maior = 0;

    for(; i < TH->m; i++)
    {
        if(TH->TH[i].estado == E_OCUPADO)
        {
            tamCluster++;
            if(tamCluster > maior)
                maior = tamCluster;
        }   
        else
            tamCluster = 0;
    }

    return maior;
}

float THEA_TamMedioClusters(THEA* TH)
{
    int i = 0, j = 0, tamCluster = 0;
    float media = 0;

    for(; i < TH->m; i++)
    {
        if(TH->TH[i].estado == E_OCUPADO)
            tamCluster++;
            
        else
        {
            if(tamCluster > 0)
            {
                media += tamCluster;
                j++;
            }
            tamCluster = 0;
        }
    }
    
    if(tamCluster > 0)
    {
        media += tamCluster;
        j++;
    }

    return media/(float)j;
}

float THEA_CustoBemSucedida(THEA* TH)
{
    int i = 0, qtdClusters = 0, soma = 0;

    int* vClusters = todosClusters(TH);
    #define MAX(a,b) a>b ? a : b

    for(; vClusters[i] != -1; i++)
    {
        soma += MAX(vClusters[i]/2, 1);
    }

    free(vClusters);

    return soma / (float)TH->n;
}

int* todosClusters(THEA* TH)
{
    int tamCluster = 0, i = 0, j = 0;
    int *vClusters = malloc(sizeof(int) * TH->n);

    for(; i < TH->m; i++)
    {
        if(TH->TH[i].estado == E_OCUPADO)
            tamCluster++;
            
        else
        {
            if(tamCluster > 0)
            {
                vClusters[j] = tamCluster;
                j++;
            }
            tamCluster = 0;
        }
    }

    if(tamCluster > 0)
        vClusters[j] = tamCluster;

    vClusters[j+1] = -1;    //cria flag pra parar o for

    return vClusters;
}

int* random_vector(int n, int max, int seed)
{
    int* v = malloc(sizeof(int)*n);
    srand(seed);

    for(int i=0; i<n; i++)
        v[i] = rand() % max;

    return v;
}