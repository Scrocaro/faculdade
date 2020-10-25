#pragma once

#include <stdint.h>

typedef struct ITEM_VENDA{
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
}ITEM_VENDA;

typedef struct BUFFER
{
    ITEM_VENDA* iv;
    int ocupado;
    int n_reg_max;
    FILE* buffer_pk;
} BUFFER;

typedef struct BUFFER_VET{
    BUFFER* b;
    int n_buff;
}BUFFER_VET;


void gerar_array_iv(const char* arquivo_saida, unsigned int n_registros, int seed);