#include "big_file.h"
BUFFER* BufferSaida_Criar(int k);
void BufferSaida_Inserir(BUFFER* buffer, ITEM_VENDA iv_saida);
void BufferSaida_Despejar(BUFFER* buffer, int* flag);
void BufferSaida_Destruir(BUFFER* buffer);