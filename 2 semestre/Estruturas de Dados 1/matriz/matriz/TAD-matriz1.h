#include <stdio.h>
#include <stdlib.h>

// DADOS
typedef struct
{
    int **m;
    int linhas;
    int colunas;

} Matriz;

//OPERAÇÕES (PROTÓTIPOS)

Matriz *matriz_cria(int linhas, int colunas);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_imprime(Matriz *m);
void matriz_destroi(Matriz *m);

//OPERAÇÕES (IMPLEMENTAÇÃO)

Matriz *matriz_cria(int linhas, int colunas)
{
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    mat->m = (int **)calloc(linhas, sizeof(int *));
    int i;
    for (i = 0; i < linhas; i++)
    {
        mat->m[i] = (int *)calloc(colunas, sizeof(int));
    }
    mat->linhas = linhas;
    (*mat).colunas = colunas;

    return mat;
}

void matriz_atribui(Matriz *m, int lin, int col, int valor)
{
    m->m[lin][col] = valor;
}

int matriz_acessa1(Matriz *m, int lin, int col)
{
    int x;
    x = m->m[lin][col];
    return x;
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end)
{
  *end = m->m[lin][col];
}

void matriz_imprime(Matriz *m)
{
    int valor;
    printf("\nMatriz %d x %d\n", m->linhas, m->colunas);
    for(int i = 0; i < m->linhas; i++)
    {
        for(int j = 0; j < m->colunas; j++)
        {
            valor = m->m[i][j];
            printf("%d\t", valor);
        }
        printf("\n");
    }
}

void matriz_destroi(Matriz *m)
{
    free(m);
}
