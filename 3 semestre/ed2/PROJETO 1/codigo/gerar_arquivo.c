#include <stdio.h> // Uso de FILE
#include <math.h> //Arredondamentos
#include <stdlib.h> //malloc
#include <limits.h> //INT_MAX
#include <time.h> //Calculo do tempo
#include <string.h> //Nomes de arquivos
#include "big_file.h" 
#include "TAD_BufferEntrada.h"
#include "TAD_BufferSaida.h"
#include "TAD_Arquivo.h" //Divisões de arquivos

#define n_registros 256000   //qtd registros total
#define E 1024 * n_registros //tam em bytes do arq entrada

#define B 8388608            //tam max buffer

#define S B/8                //tam max buffer saida

#define n_reg_b_s S/1024     //qtd registros buffer saida

#define K ceil(E/B)+1          //qtd arquivos menores

#define n_reg_b_e ceil(((B - S) / K) / sizeof(ITEM_VENDA))

int main(int argc, char** argv)
{
    clock_t start_t, end_t, total_t;
    
    /////////////////////////////////////////////////////////////////
    gerar_array_iv("teste.dat", n_registros, 42);
    start_t = clock();
    Arquivo_Dividir("teste.dat", K, n_reg_b_e);
    /////////////////////////////////////////////////////////////////
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
    /////////////////////////////////////////////////////////////////////////
    FILE* arq = fopen("saida.dat", "wb");
    fclose(arq);
    /////////////////////////////////////////////////////////////////////////
    BUFFER* bufferSaida = BufferSaida_Criar(n_reg_b_s);
    /////////////////////////////////////////////////////////////////////////
    //Intercalação de K vias
    while(bufferGeral_Vazio(vet) == 0)
    {
        while(bufferSaida->ocupado < bufferSaida->n_reg_max)
        {
            int menor = INT_MAX;
            int menorIndex = INT_MAX;
            
            for(int i = 0; i < vet[0].n_buff; i++){
                if(vet[i].b->iv[0].id < menor){
                    menorIndex = i;
                    menor = vet[i].b->iv[0].id;
                }
            }
            if(menorIndex == INT_MAX) break;
            int flag = 0;
            ITEM_VENDA menorItem = BufferEntrada_Consumir(vet[menorIndex].b, &flag);
            if(flag == 1){
                BufferEntrada_Destruir(vet);
            }
            BufferSaida_Inserir(bufferSaida, menorItem);
        }
        int flag2 = 1;
        BufferSaida_Despejar(bufferSaida, &flag2);
        BufferSaida_Destruir(bufferSaida);
        BUFFER* bufferSaida = BufferSaida_Criar(n_reg_b_s);
        if(flag2 == 1) break;
    }
    /////////////////////////////////////////////////////////////////////////
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
    /////////////////////////////////////////////////////////////////////////

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo: %lf\n", (double)total_t);
    //system("pause");
    return 0;
}
