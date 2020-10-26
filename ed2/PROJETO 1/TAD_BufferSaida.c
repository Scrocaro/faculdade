#include <stdio.h>
#include <stdlib.h>
#include "TAD_BufferSaida.h"
#include "big_file.h"


BUFFER* BufferSaida_Criar(float k)
{
    BUFFER* buffer = malloc(sizeof(BUFFER));
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA) * k);

    for(int i = 0; i < k; i++){
        iv[i].id = 0;
        iv[i].id_venda = 0;
        iv[i].desconto = 0;
        iv[i].data = 0;
        iv[i].obs[0] = '\0';
    }

    buffer->n_reg_max = k;
    buffer->iv = iv;
    buffer->bloco = 0;
    buffer->ocupado = 0;
    buffer->buffer_pk = "saida.dat";

    FILE* arq = fopen("saida.dat", "wb");
    fclose(arq);
    return buffer;
}

void BufferSaida_Inserir(BUFFER* buffer, ITEM_VENDA iv_saida){
    if(buffer->ocupado < buffer->n_reg_max){
        buffer->iv[buffer->ocupado+1] = iv_saida;
        buffer->ocupado++;
    }else{
        BufferSaida_Despejar(buffer);
    }
}

void BufferSaida_Despejar(BUFFER* buffer){
    FILE* arq = fopen(buffer->buffer_pk, "wb");
    fseek(arq, buffer->bloco*sizeof(ITEM_VENDA)*buffer->n_reg_max, SEEK_SET);

    if(buffer->ocupado < buffer->n_reg_max)
        fwrite(buffer->iv, sizeof(ITEM_VENDA), buffer->ocupado, arq);
    else
        fwrite(buffer->iv, sizeof(ITEM_VENDA), buffer->n_reg_max, arq);
    buffer->bloco++;
    fclose(arq);
}

void BufferSaida_Destruir(BUFFER* buffer){
    free(buffer->iv);
    free(buffer);
}
