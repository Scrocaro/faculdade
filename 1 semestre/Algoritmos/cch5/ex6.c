/*Uma empresa armazena informações sobre as contas a receber de seus clientes. Cada uma dessas contas tem as seguintes informações:
    *numero do documento,
    *código do cliente,
    *data de vencimento,
    *data de pagamento,
    *valor da conta,
    *juros.
Faça um programa para cadastrar um documento. Se a data de pagamento for maior que a data de vencimento, o programa deve calcular o campo juros
da tabela documentos (a cada dia de atraso, deve-se aplicar 0,02% de multa). O programa deve ler informações sobre 15 documentos e,
depois, mostrar todos os documentos lidos e o total geral a receber (valor das contas + juros) e a média dos juros. */

#include <stdio.h>
#define N 3
float somajuros = 0, mediajuros;
int qtdmes, qtddias;
void cadastro();

struct REG
{
    int doc, cod, pagdia, pagmes, vencdia, vencmes;
    float valorconta;
};
struct REG cliente[N];

void cadastro()
{
    int cont = 0;
    for (int i=0; i<N; i++)
    {
        printf("Cliente %d\n", i+1);
        printf("Número de documento: ");
        scanf("%d", &cliente[i].doc);
        printf("Valor da conta: ");
        scanf("%f", &cliente[i].valorconta);
        printf("Mes do vencimento: ");
        scanf("%d", &cliente[i].vencmes);
        printf("Dia do vencimento: ");
        scanf("%d", &cliente[i].vencdia);
        printf("Mes do pagamento: ");
        scanf("%d", &cliente[i].pagmes);
        printf("Dia de pagamento: ");
        scanf("%d", &cliente[i].pagdia);
        if (cliente[i].vencmes <= cliente[i].pagmes)
        {
            qtdmes = cliente[i].pagmes - cliente[i].vencmes;
            qtddias = qtdmes*30;
            if (cliente[i].vencdia < cliente[i].pagdia)
                qtddias = qtddias + cliente[i].pagdia - cliente[i].vencdia;
                cont++;
                cliente[i].valorconta = cliente[i].valorconta + qtddias*1.02;
                somajuros = somajuros + qtddias*1.02;
        }
    }
    mediajuros = somajuros/cont;
    printf("\n\n");
    for (int i=0; i<N; i++)
    {
        printf("cliente %d:\n", i+1);
        printf("Documento: %d\n", cliente[i].doc);
        printf("Total a receber: %.2f\n", cliente[i].valorconta);
    }
    printf("\n\nMédia dos juros: %.2f\n", mediajuros);
}

int main()
{
    cadastro();
}
