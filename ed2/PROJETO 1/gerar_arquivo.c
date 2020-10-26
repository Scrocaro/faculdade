#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"
#include "TAD_Arquivo.h"

int main(int argc, char** argv)
{
    float n_registros = 256000;
    float B = 8388608;
    float S = B/8;
    float E = 1024 * n_registros;
    float K = ceil(E/B);

    printf("%f", K);

    printf("sizeof(ITEM_VENDA) = %ld\n", sizeof(ITEM_VENDA));
    gerar_array_iv("teste.dat", n_registros, 42);
    
    Arquivo_Dividir("teste.dat", K, n_registros);

    BUFFER_VET vet[(int)K];
    
    for (int i = 0; i < K; i++)
    {
        char tmp[10], titulo[50] = "buffer_p";
        itoa(i, tmp, 10);
        strcat(titulo, tmp);
        strcat(titulo, ".dat");
        vet[i].b = BufferEntrada_Criar(titulo, K, n_registros);
        vet[i].n_buff = K;
    }
    printf("\n%d\n", vet[0].b->ocupado);

    
    ITEM_VENDA consumido3;
    for(int w = 0; w < K; w++){
        for(int j = 0; j < K; j++){
            consumido3 = BufferEntrada_Consumir(vet[w].b);
        }
    }
    //for(int i = 0; i < K; i++)
    for(int j = 0; j < K; j++)
        printf("id[%d] = %u\n", 0, vet[0].b->iv[j].id);   
    
    
    printf("\n%d", vet[0].b->ocupado);
    system("pause");
    return 0;
}
