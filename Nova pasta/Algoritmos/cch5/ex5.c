#include <stdio.h>
#include <string.h>
#define N 4
float lucrop, porcentlucro;

int menu();
void cadastro();
void lucro();
void qtd();

struct REG
{
    int cod, qtdestoq, estoqmin;
    float pcompra, pvenda;
    char * desc[51];
};
struct REG item[N];

int menu()
{
    int op;
    printf("\nMENU:\n");
    printf(" 1 - cadastrar produto\n 2 - Lucro\n 3 - Produtos com estoque abaixo do mínimo\n 0 - Finalizar programa\n");
    scanf("%d", &op);
    return op;
}

void cadastro()
{
    for (int i=0; i<N; i++)
    {
        printf("\nPRODUTO %d: \n", i+1);
        printf("Código do produto: ");
        scanf("%d", &item[i].cod);
        printf("Quantidade mínima de estoque: ");
        scanf("%d", &item[i].estoqmin);
        printf("Quantidade em estoque: ");
        scanf("%d", &item[i].qtdestoq);
        printf("Preço de compra: ");
        scanf("%f", &item[i].pcompra);
        printf("Preco de venda: ");
        scanf("%f", &item[i].pvenda);
        printf("Descrição: ");
        scanf(" %[^\n]", &item[i].desc);
        printf("\nProduto cadastrado.\n");
    }
}

void lucro()
{
    for (int i=0; i<N; i++)
    {
        printf("PRODUTO %d:\n", i+1);
        lucrop = item[i].pvenda - item[i].pcompra;
        porcentlucro = ((item[i].pvenda * 100.0)/item[i].pcompra)-100;
        printf("Lucro: %.2fR$\n", lucrop);
        printf("Porcentagem de lucro: %.2f%%\n", porcentlucro);
    }
}

void qtd()
{
    int cont = 0;
    for (int i=0; i<N; i++)
    {
        if (item[i].qtdestoq < item[i].estoqmin)
        {
            cont++;
            printf("Produto %d\n", i+1);
        }
    }
    if (cont == 0)
    {
        printf("Não há produtos em falta no estoque.\n");
    }
}

int main()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
            case 1: cadastro();
                break;
            case 2: lucro();
                break;
            case 3: qtd();
                break;
            case 0: printf("Programa finalizado.\n");
            break;
            default: printf("Opção inválida.\n");
        }
    }
    while (op != 0);
}
