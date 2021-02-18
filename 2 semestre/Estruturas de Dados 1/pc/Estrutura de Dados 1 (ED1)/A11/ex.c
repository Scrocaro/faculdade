#include <stdio.h>
#include <string.h>

typedef struct
{
    int cod;
    char* desc;
    float preco;
    int qtdestq;
    int qtdPrecos;
}Produto;

typedef struct
{
    char* nome;
    Produto** produtos;
    int qtd;
    int tam;
}Empresa;

Empresa* novaEmpresa(char* nome)
{
    Empresa* e = malloc(sizeof(Empresa));
    e->nome = calloc(sizeof(nome) + 1, sizeof(char));
    e->produtos = (Produto**)calloc(6, sizeof(Produto*));
    e->qtd = 0;
    e->tam = 6;
    return e;
}

Produto* novoProduto(int cod, char* desc, float preco, int qtde, Empresa* e)
{
    e->produtos[e->qtd] = (Produto*)malloc(sizeof(Produto));
    Produto->cod[6] = cod;
    strcpy(e->produtos->nome, desc);
    Produto->preco = preco;
    Produto->qtdestq = qtde;
    e->qtd++;
}

float mediaDePreco(Empresa* e)
{
    float soma = 0;
    for(int i = 0; i< e->qtd; i++)
    {
        soma = soma + e->produtos[i]->preco;
    }
}

int buscaRemoveDuplicados(Empresa* e, int cod)
{
    int cont = 0;
    for(int i = 0; i < e->tam; i++)
    {
        for(int j = 0; j < e->tam; j++)
        if(e->produtos[i]->cod = e->produtos[j]->cod)
        {
            cont++;
            free(e->produtos[i]);
        }
    }
    return cont;
}
int main()
{
    Empresa* e = novaEmpresa("batatinhas");
    novoProduto(0, "usb", 10, 5);
    printf("%s", Empresa->nome);
}
