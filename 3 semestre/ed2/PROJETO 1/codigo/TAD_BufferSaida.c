#include <stdio.h>
#include <stdlib.h>
#include "TAD_BufferSaida.h"
#include "big_file.h"

//Cria buffer saida e seta seus valores
BUFFER* BufferSaida_Criar(int n_reg_b_s)
{
    BUFFER* buffer = malloc(sizeof(BUFFER));
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA) * n_reg_b_s);

    for(int i = 0; i < n_reg_b_s; i++){
        iv[i].id = 0;
        iv[i].id_venda = 0;
        iv[i].desconto = 0;
        iv[i].data = 0;
        iv[i].obs[0] = '\0';
    }

    buffer->n_reg_max = n_reg_b_s;
    buffer->iv = iv;
    buffer->bloco = 0;
    buffer->ocupado = 0;
    buffer->buffer_pk = "saida.dat";

    return buffer;
}

void BufferSaida_Inserir(BUFFER* buffer, ITEM_VENDA iv_saida){
        buffer->iv[buffer->ocupado+1] = iv_saida;
        buffer->ocupado++;
}

//Joga no arquivo saido o buffer
void BufferSaida_Despejar(BUFFER* buffer, int *flag){
    FILE* arq = fopen(buffer->buffer_pk, "wb");
    fseek(arq, buffer->bloco*sizeof(ITEM_VENDA)*buffer->n_reg_max, SEEK_SET);

    if(buffer->ocupado < buffer->n_reg_max){
        fwrite(buffer->iv, sizeof(ITEM_VENDA), buffer->ocupado, arq);
        *flag = 1;
    }
    else
        fwrite(buffer->iv, sizeof(ITEM_VENDA), buffer->n_reg_max, arq);
    
    buffer->bloco++;
    buffer->ocupado = 0;
    fclose(arq);
}

void BufferSaida_Destruir(BUFFER* buffer){
    free(buffer->iv);
    free(buffer);
}
