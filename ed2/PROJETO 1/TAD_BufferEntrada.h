#include "big_file.h"

BUFFER* BufferEntrada_Criar(char* teste, int k, int n);

ITEM_VENDA BufferEntrada_Proximo(BUFFER* buffer, int atual);

ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer);

void BufferEntrada_Vazio(ITEM_VENDA* iv, int n);

void BufferEntrada_Destruir(ITEM_VENDA* iv, int n);