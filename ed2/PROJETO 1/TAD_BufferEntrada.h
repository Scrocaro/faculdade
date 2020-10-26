#include "big_file.h"

BUFFER* BufferEntrada_Criar(char* teste, float k, float n_registros);

ITEM_VENDA BufferEntrada_Proximo(BUFFER* buffer, int atual);

ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer);

int BufferEntrada_Vazio(BUFFER* buffer);

void BufferEntrada_Destruir(char* teste, BUFFER_VET* vet);