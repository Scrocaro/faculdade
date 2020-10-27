#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"
#include "TAD_Arquivo.h"

#define n_registros 256000   //qtd registros total
#define E 1024 * n_registros //tam em bytes do arq entrada

#define B 8388608            //tam max buffer

#define S B/8                //tam max buffer saida

#define n_reg_b_s S/1024     //qtd registros buffer saida

#define K ceil(E/B)+1          //qtd arquivos menores

#define n_reg_b_e ceil(((B - S) / K) / sizeof(ITEM_VENDA))

/*int argMin(BUFFER_VET* vet){
    
    return menorIndex;
}
*/

int main(int argc, char** argv)
{
    clock_t start_t, end_t, total_t;
    start_t = clock();
    gerar_array_iv("teste.dat", n_registros, 42);
    
    Arquivo_Dividir("teste.dat", K, n_reg_b_e);

    BUFFER_VET vet[(int)K];
    
    for (int i = 0; i < K; i++)
    {
        char tmp[10], titulo[50] = "buffer_p";
        itoa(i, tmp, 10);
        strcat(titulo, tmp);
        strcat(titulo, ".dat");
        vet[i].b = BufferEntrada_Criar(titulo, n_registros, K);
        vet[i].n_buff = K;
    }
    
    //ARQ SAIDA
    FILE* arq = fopen("saida.dat", "wb");
    fclose(arq);
    /////////////////////////////////////////////////////////////////////////
    
    BUFFER* bufferSaida = BufferSaida_Criar(n_reg_b_s);

    while(bufferGeral_Vazio(vet) != 1)
    {
        while(bufferSaida->ocupado < n_reg_b_s)
        {
            uint32_t menor = vet[0].b->iv[0].id;
            int menorIndex = -2;

            for(int i = 1; i < vet->n_buff; i++){
                if(vet[i].b->iv[0].id < menor){
                    menorIndex = i;
                    menor = vet[i].b->iv[0].id;
                }
            }

            if(menorIndex == -2) break;

            int flag = 0;
            ITEM_VENDA menorItem = BufferEntrada_Consumir(vet[menorIndex].b, &flag);

            if(flag == 1){
                BufferEntrada_Destruir(vet);
            }

            BufferSaida_Inserir(bufferSaida, menorItem);
        }
        BufferSaida_Despejar(bufferSaida);
    }

    /////////////////////////////////////////////////////////////////////////

    //INTERCALAÇÃO K-VIAS
    for(int i=0; i<K; i++){
        free(vet[i].b->iv);
        free(vet[i].b);
        free(vet);
    }

    for(int i=0; i<K; i++){
        char strNome[50] = "buffer_p"; 
        char tmp[10];
        itoa(i, tmp, 10);
        strcat(strNome, tmp);
        strcat(strNome, ".dat");
        int del = remove(strNome);
    }
    int del = remove("teste.dat");

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo: %lf\n", (double)total_t);
    
    
    system("pause");
    return 0;
}
