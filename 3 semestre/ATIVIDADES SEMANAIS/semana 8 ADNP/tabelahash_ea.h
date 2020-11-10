#pragma once
#include "prime_list.h"

typedef enum FSONDAGEM
{
    FS_LINEAR,
    FS_QUADRATICA,
    FS_HASH_DUPLO
} FSONDAGEM;

typedef enum ESTADO
{
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef struct ELEM
{
    int chave;
    int valor;
    ESTADO estado;
} ELEM;

typedef struct THEA
{
    ELEM* TH;
    int m;
    int n;  //numero de posições ocupadas
    int s;
    int colisoes;
    prime_list_t* prime_list;
    int (*hash)(struct THEA* TH, int chave, int k);
} THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m, FSONDAGEM f_sondagem);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar(THEA *TH, int chave);
void THEA_Remover(THEA *TH, int chave);

///////////

int* random_vector(int n, int max, int seed);
THEA* THEA_Random(int m, int n, int max, int seed, FSONDAGEM f_sondagem);
int menor(THEA* TH);
int maior(THEA* TH);

int THEA_HashLinear(THEA* TH, int chave, int k);
int THEA_HashQuadratica(THEA* TH, int chave, int k);
int THEA_HashDuplo(THEA* TH, int chave, int k);

int THEA_ClusterMax(THEA* TH);
float THEA_TamMedioCluster(THEA* TH);
float THEA_CustoBemSucedida(THEA* TH);
