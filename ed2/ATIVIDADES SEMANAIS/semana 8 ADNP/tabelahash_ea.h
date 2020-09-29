#pragma once

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
}ESTADO;

typedef struct ELEM
{
    int chave;
    int valor;
    ESTADO estado;
}ELEM;

typedef struct THEA
{
    int m;
    int n;  //numero de posições ocupadas
    FSONDAGEM f_sondagem;
    int s;
    ELEM* TH;
}THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m, FSONDAGEM f_sondagem);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar(THEA *TH, int chave);
void THEA_Remover(THEA *TH, int chave);

int* random_vector(int n, int max, int seed);
