/*Foi feita uma estatística em 15 estados brasileiros para coletar dados sobre acidentes de trânsito.
Em cada estado observou-se os seguintes aspectos:
I–Nome do estado;
II –Número de veículos que circulam nesse estado (em 2000);
III –Número de acidentes de trânsito (em 2000);
Deseja-se saber:
a) Qual o maior e o menor índice de acidentes de trânsito e o nome dos estados em que eles ocorreram;
b) Qual o percentual de veículos em cada estado;
c) Qual a número de acidentes em cada um dos estados.*/

#include <stdio.h>
#include <string.h>
#define N 15

int maiorindice = 0, menorindice = 0, nveictotal = 0;
char estmai[2], estmei[2];
float percent[N];
void dados();

struct REG
{
    char estado[2];
    int nveic, nacid;
};
struct REG estado[N];

void dados()
{
    int i=0;
    printf("Estado 1: \n");
    printf("  Sigla do estado (letra maiúscula): ");
    scanf(" %[^\n]", &estado[1].estado);
    printf("  Número de veículos que circulam nesse estado: ");
    scanf("%d", &estado[1].nveic);
    printf("  Número de acidentes de trânsito: ");
    scanf("%d", &estado[1].nacid);
    menorindice = estado[1].nacid;
    maiorindice = estado[1].nacid;
    strcpy (estmai, estado[1].estado);
    strcpy (estmei, estado[1].estado);
    nveictotal = nveictotal + estado[1].nveic;
    for (i=2; i<=N; i++)
    {
        printf("Estado %d: \n", i);
        printf("  Sigla do estado (letra maiúscula): ");
        scanf(" %[^\n]", &estado[i].estado);
        printf("  Número de veículos que circulam nesse estado: ");
        scanf("%d", &estado[i].nveic);
        printf("  Número de acidentes de trânsito: ");
        scanf("%d", &estado[i].nacid);
        if (estado[i].nacid > maiorindice)
        {
            maiorindice = estado[i].nacid;
            strcpy (estmai, estado[i].estado);
        }
        if (estado[i].nacid < menorindice)
        {
            menorindice = estado[i].nacid;
            strcpy (estmei, estado[i].estado);
        }
        nveictotal = nveictotal + estado[i].nveic;
    }
    for (i=1; i<=N; i++)
    {
        percent[i] = estado[i].nveic*100.0/nveictotal;
    }
}

int main()
{
    int i=0;
    dados();
    printf("\n\n  Maior indice de acidentes: %d\n", maiorindice);
    printf("    Estado: %s\n\n", estmai);
    printf("  Menor indice de acidentes: %d\n", menorindice);
    printf("    Estado: %s\n\n", estmei);
    for (i=1; i<=N; i++)
        printf("  Percentual de veículos no estado %d: %.2f\n", i, percent[i]);
    printf("\n\n");
    for (i=1; i<=N; i++)
        printf("  Número de acidentes no estado %d: %d", i, estado[i].nveic);
}
