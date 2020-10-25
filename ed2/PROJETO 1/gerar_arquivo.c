#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"
#include "TAD_Arquivo.h"

int main(int argc, char** argv)
{
    int n_registros = 256000;
    int B = 8388608;
    int S = B/8;
    int E = 1024 * n_registros;
    int K = ceil(E/B);

    printf("sizeof(ITEM_VENDA) = %ld\n", sizeof(ITEM_VENDA));
    gerar_array_iv("teste.dat", n_registros, 42);
    
    Arquivo_Dividir("teste.dat", K, n_registros);

    BUFFER_VET vet[K];
    
    for (int i = 0; i < K; i++)
    {
        char tmp[10], titulo[50] = "buffer_p";
        itoa(i, tmp, 10);
        strcat(titulo, tmp);
        strcat(titulo, ".dat");
        vet[i].b = BufferEntrada_Criar(titulo, K, n_registros);
        vet[i].n_buff = K;
    }
    
    BufferEntrada_Consumir(vet[0].b);
    for(int i = 0; i < K; i++)
        for(int j = 0; j < K; j++)
            printf("id[%d] = %u\n", i, vet[i].b->iv[j].id);   
    
    return 0;
}
