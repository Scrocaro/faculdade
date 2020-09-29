#include "tabelahash_ea.h"
#include <stdlib.h>

static int eh_primo(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            return -1;
        }
    }
    return n;
}

static int prox_primo(int n)
{
    if(n <= 1)
        return 2;

    while(1)
    {
        n++;
        if(eh_primo(n))
            return n;
    }
}



static void THEA_Redimensionar(THEA* TH, int m_novo)
{
    ELEM *nova, *antiga;
    int i = 0, m_antigo;
    nova = malloc(sizeof(ELEM) * m_novo);
    for(; i < m_novo; i++)
        nova[i].estado = E_LIVRE;
    
    antiga = TH->TH;
    m_antigo = TH->m;
    TH->TH = nova;
    TH->m = m_novo;
    TH->n = 0;

    for(i = 0; i < m_antigo; i++)
        if(antiga[i].estado == E_OCUPADO)
            THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);

    free(antiga);
}

int THEA_Hash(THEA* TH, int chave, int k)   // endereço inicial para fazer inserção
{
    switch (TH->f_sondagem)
    {
    case FS_LINEAR:
        return ((chave % TH->m) + k) % TH->m;   //    hash modular com sondagem linear
    case FS_QUADRATICA:
        return ((chave % TH->m) + k*k) % TH->m;   //  hash modular com sondagem quadratica
    case FS_HASH_DUPLO:
        return ((chave % TH->m) + k*((chave % TH->s) + 1)) % TH->m;   //  hash modular com sondagem via hash duplo
    }
}

THEA* THEA_Criar(int m, FSONDAGEM f_sondagem)
{
    THEA* novo;
    novo = malloc(sizeof(THEA));    
    novo->TH = malloc(sizeof(ELEM) * m);
    novo->m = m;
    novo->n = 0;
    novo->s = m-1;
    for(int i = 0; i < m; i++)
        novo->TH[i].estado = E_LIVRE;

    novo->f_sondagem = f_sondagem;

    return novo;
}


int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int h, k, h_inicial;
    k = 0;
    if(TH->n+1 > TH->m / 2)
    {
        int m_novo = prox_primo(TH->m * 2);
        TH->s = m_novo-1;
        THEA_Redimensionar(TH, m_novo);
    }   
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while(TH->TH[h].estado == E_OCUPADO)
    {
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
        TH->n--;
    }
}

int* random_vector(int n, int max, int seed)
{
    int* v = malloc(sizeof(int)*n);
    srand(seed);

    for(int i=0; i<n; i++)
        v[i] = rand() % max;

    return v;
}
