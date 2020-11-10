#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tabelahash_ea.h"

static void THEA_Redimensionar(THEA* TH, int mNovo)
{
    int mPrimo = mNovo, mAntigo, i;
    if(mPrimo <= 15485863) 
        mPrimo = PL_NextPrime(TH->prime_list, mNovo);

    ELEM *nova = calloc(mPrimo, sizeof(ELEM)); 
    ELEM *antiga = TH->TH;


    mAntigo = TH->m;
    TH->TH = nova;
    TH->m = mPrimo;
    TH->n = 0;
    TH->s = mPrimo-1;
    TH->colisoes = 0;

    for(i = 0; i < mPrimo; i++) 
        nova[i].estado = E_LIVRE;

    for(i = 0; i < mAntigo; i++)
        if(antiga[i].estado == E_OCUPADO)
            THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);
    
    free(antiga);
}

int THEA_Hash(THEA* TH, int chave, int k)   // endereço inicial para fazer inserção
{
    return TH->hash(TH, chave, k);
}

int THEA_HashLinear(THEA* TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

int THEA_HashQuadratica(THEA* TH, int chave, int k)
{
    return ((chave % TH->m) + k*k) % TH->m;
}

int THEA_HashDuplo(THEA* TH, int chave, int k)
{
    return ((chave % TH->m) + k * ((chave % TH->s) + 1)) % TH->m;
}

THEA* THEA_Criar(int m, FSONDAGEM f_sondagem)
{
    int i;
    prime_list_t *primos = PL_Load("primes1.dat", 1000000);
    int mNovo = PL_NextPrime(primos, m);
    THEA* novo = calloc(mNovo, sizeof(THEA));
    ELEM* node = calloc(mNovo, sizeof(ELEM));

    novo->m = mNovo;
    novo->n = 0;
    novo->colisoes = 0;
    novo->prime_list = primos;
    novo->TH = node;
    for(i = 0; i < novo->m; i++)
        novo->TH[i].estado = E_LIVRE;


    switch (f_sondagem)
    {
    case FS_HASH_DUPLO:
        novo->hash = THEA_HashDuplo;
        novo->s = novo->m-1;
        break;
    
    case FS_QUADRATICA:
        novo->hash = THEA_HashQuadratica;
        break;
    
    default:
        novo->hash = THEA_HashLinear;
        break;
    }

    return novo;
}


int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int k, h, h_inicial;

    if(TH->n+1 > TH->m/2)
        THEA_Redimensionar(TH, TH->m*2);  

    k = 0;
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while(TH->TH[h].estado == E_OCUPADO)
    {
        TH->colisoes++;
        
        if(TH->TH[h].chave == chave)
        {
            TH->n--;
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
            break;
    }

    return -1;
}

void THEA_Remover(THEA *TH, int chave)
{
    int temp = THEA_Buscar(TH, chave);
    if(temp != -1)
    {
        TH->TH[temp].estado = E_APAGADO;
        TH->n--;
    }    
}

int* random_vector(int n, int max, int seed)
{
    int* v = malloc(n * sizeof(int));
    srand(seed);

    for(int i=0; i<n; i++)
        v[i] = rand() % max;

    return v;
}

THEA* THEA_Random(int m, int n, int max, int seed, FSONDAGEM f_sondagem)
{
    THEA* random = THEA_Criar(m, f_sondagem);
    int* chave = random_vector(n, max, seed);

    for(int i = 0; i < n; i++)
        THEA_Inserir(random, chave[i], chave[i]);

    return random;
}

int menor(THEA* TH)
{
    int menor = INT_MAX;
    int i = 0;

    for(; i < TH->m; i++)
        if(TH->TH[i].estado == E_OCUPADO)
            if(TH->TH[i].chave < menor)
                menor = TH->TH[i].chave;
    
    return menor;
}

int maior(THEA* TH)
{
    int maior = INT_MIN;
    int i = 0;

    for(; i < TH->m; i++)
        if(TH->TH[i].estado == E_OCUPADO)
            if(TH->TH[i].chave > maior)
                maior = TH->TH[i].chave;
    
    return maior;
}

int THEA_ClusterMax(THEA* TH)
{
    int tmp = 0, maior = -1, i = 0;

    for(; i < TH->m; i++)
    {
        if(TH->TH[i].estado == E_OCUPADO) 
            tmp++;

        else
        {
            if(tmp > maior) 
                maior = tmp;

            tmp = 0;
        }
    }

    return maior;
}

float THEA_TamMedioClusters(THEA* TH)
{
    int tam = 0, qtdClusters = 0;

    for(int i = 0; i < TH->m; i++)
    {
        if(TH->TH[i].estado == E_OCUPADO) 
            tam++;

        else if(TH->TH[i-1].estado == E_OCUPADO) 
            qtdClusters++;
    }

    if(qtdClusters == 0) 
        return (float)tam;

    return (float)tam/qtdClusters;
}

float THEA_CustoBemSucedida(THEA *TH)
{
    int *T = calloc(TH->m, sizeof(int));
    int iCluster = 0, tamCluster = 0;
    float cont = 0;
    #define MAX(a,b) (a>b) ? a : b

    for(int i = 0; i < TH->m; i++)
    {
        if(TH->TH[i].estado == E_OCUPADO) 
            tamCluster++;

        else if(TH->TH[i-1].estado == E_OCUPADO)
        {
            T[iCluster++] = tamCluster;
            tamCluster = 0;
        }
    }

    if(iCluster == 0 && tamCluster > 0)
        T[iCluster++] = tamCluster;

    for(int i = 0; i < iCluster; i++)
        cont += MAX((T[i]/2), 1);

    return ((float)1/TH->n) * cont;
}