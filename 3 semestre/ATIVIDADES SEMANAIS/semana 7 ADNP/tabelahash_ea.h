#pragma once

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
    ELEM* TH;
}THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar(THEA *TH, int chave);
void THEA_Remover(THEA *TH, int chave);


int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);
float THEA_CustoBemSucedida(THEA *TH);
THEA* THEA_CriaRandom(int m, int n, int max, int seed);
int* todosClusters(THEA* TH);
int* random_vector(int n, int max, int seed);
void funcao_teste(int m);