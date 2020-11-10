#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "big_file.h"
#include "TAD_BufferEntrada.h"
#include "TAD_Arquivo.h"

// -------------------------------------------------------QUICK SORT
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
// -----------------------------------------------------------------
// Dividindo arquivo maior em K arquivos de tamanho limitado
void Arquivo_Dividir(char* teste, int k, int n_reg_b_e)
{
    ITEM_VENDA* p = malloc(sizeof(ITEM_VENDA) * n_reg_b_e);
    FILE* arq = fopen(teste, "rb");
    
    for(int i = 0; i < k; i++)
    {
        char tmp[10], titulo[50] = "buffer_p";
        itoa(i, tmp, 10);
        strcat(titulo, tmp);
        strcat(titulo, ".dat");
        FILE* saida = fopen(titulo, "wb");

        fseek(arq, i*k*sizeof(ITEM_VENDA), SEEK_SET);
        
        int inicio = ftell(arq);
        fseek(arq, 0, SEEK_END);
        int fim = ftell(arq);

        int tam_restante = fim - inicio;

        fseek(arq, i*k*sizeof(ITEM_VENDA), SEEK_SET);

        tam_restante = tam_restante/1024;
        
        if(tam_restante>n_reg_b_e){
            fread(p, sizeof(ITEM_VENDA), n_reg_b_e, arq);
            quickSort(p, 0, k);
            fwrite(p, sizeof(ITEM_VENDA), n_reg_b_e, saida);
        }
        else{
            fread(p, sizeof(ITEM_VENDA), tam_restante, arq);
            quickSort(p, 0, tam_restante);
            fwrite(p, sizeof(ITEM_VENDA), tam_restante, saida);
        }
        
        fclose(saida);
    }
    
    fclose(arq);
    //free(p);
}