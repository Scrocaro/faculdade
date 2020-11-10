#include "big_file.h"

BUFFER* BufferEntrada_Criar(char* teste, int n_registros, int k);

int BufferEntrada_Proximo(BUFFER* buffer, int atual);

void moverBuffer(BUFFER* buffer, int* flag);

ITEM_VENDA BufferEntrada_Consumir(BUFFER* buffer, int* flag);

int BufferEntrada_Vazio(BUFFER* buffer);

int bufferGeral_Vazio(BUFFER_VET* vet);

void BufferEntrada_Destruir(BUFFER_VET* vet);