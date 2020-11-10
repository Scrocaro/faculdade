#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_ea.h"

int main(int argc, char** argv)
{
    int n = 10000;
    int* v = random_vector(n, n*10, 42);
    int v_teste[22] = {9973, 10000, 11987, 12000, 13999, 14000, 15991,
                        16000, 17989, 18000, 19997, 20000, 21997, 22000,
                        23993, 24000, 25999, 26000, 27997, 28000, 29989, 30000};
    
    for(int i=0; i<22; i++)
    {
        THEA* TH = THEA_Criar(v_teste[i]);
        for(int j=0; j<n; j++)
            THEA_Inserir(TH, v[j], v[j]);

        printf("\n\nm = %d\nn = %d\nalpha = %f\n", TH->m, TH->n, TH->n/(float)v_teste[i]);
        printf("Mal Sucedido = %f\n", THEA_TamMedioClusters(TH));
        printf("Bem Sucedido = %f\n", THEA_CustoBemSucedida(TH));
        printf("MaxClust = %d\n\n\n", THEA_ClusterMaximo(TH));
    }

    return 0;
}
