#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"
#include "TAD_Arquivo.h"

void troca(ITEM_VENDA *v, int maior, int i)
{
    ITEM_VENDA aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;
}

int partition(ITEM_VENDA *v, int p, int r)
{
    int x, i, j;
    x = v[r].id;
    i = p-1;

    for(j = p; j < r; j++)
    {
        if(v[j].id <= x)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);

    return i+1;
}

void quickSort(ITEM_VENDA *v, int e, int d)
{
    int q;
    if(e < d)
    {
        q = partition(v, e, d);
        quickSort(v, e, q-1);
        quickSort(v, q+1, d);
    }
}
/*
ITEM_VENDA* argMin(BUFFER* buffer){
    ITEM_VENDA* aux1 = buffer->iv[0];
    int aux2 = buffer->iv[0]->id;
    for (size_t i = 0; i < buffer->n_reg_max; i++)
    {
        if(buffer->iv[i].id < aux2){

        }
    }


    return ;

}
*/
void Arquivo_Dividir(char* teste, float k, float n_registros)
{
    ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * ceil(n_registros/k));
    FILE* arq = fopen(teste, "rb");
    
    for(int i = 0; i < k; i++)
    {
        char tmp[10], titulo[50] = "buffer_p";
        itoa(i, tmp, 10);
        strcat(titulo, tmp);
        strcat(titulo, ".dat");
        FILE* saida = fopen(titulo, "wb");

        fseek(arq, i*ceil(n_registros/k)*sizeof(ITEM_VENDA), SEEK_SET);
        fread(p, sizeof(ITEM_VENDA), ceil(n_registros/k), arq);

        quickSort(p, 0, ceil(n_registros / k));

        fwrite(p, sizeof(ITEM_VENDA), n_registros/k, saida);
        fclose(saida);
    }
    
    fclose(arq);
    free(p);
}