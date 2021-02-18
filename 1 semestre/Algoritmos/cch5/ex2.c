/* Foi realizado uma pesquisa de algumas características físicas de 50 habitantes de uma certa região.
De cada habitante foram coletados os seguintes dados:
sexo, altura, idade e cor dos olhos ( A – Azuis, V – Verdes ou C – Castanhos).
Faça um programa que leia esses dados e armazene-os em um registro do tipo vetor. Determine:
a) A média de idade das pessoas com olhos castanhos e altura superior a 1,60 m;
b) A maior idade entre os habitantes;
c) A quantidade de indivíduos do sexo feminino cuja idade esteja entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 1,70 m;
d) O percentual de homens; */
#include <stdio.h>
#define N 50

void dados();

int soma1=0, maioridade=0, soma2=0, soma3=0;
float media1=0, percent;    /*soma1 e media1 serão usadas no item a*/    /*soma2 será usada no item c*/   /*soma3 e percent serão usadas no item d*/

struct REG
{
    int sex, y, h;
    char cor;
};

struct REG pessoa[N];

void dados()
{
    for (int i=1; i<=N; i++)
    {
        printf("PESSOA %d/50\n", i);
        printf("Sexo (1 - Masc 2 - Fem): ");
        scanf("%d", &pessoa[i].sex);
        printf("altura em cm: ");
        scanf("%d", &pessoa[i].h);
        printf("Idade: ");
        scanf("%d", &pessoa[i].y);
        printf("Cor dos olhos (A - Azuis, V - Verdes, C - Castanhos): ");
        scanf(" %c", &pessoa[i].cor);
        if (pessoa[i].cor == 'C' && pessoa[i].h > 160)
            soma1 = soma1 + 1;
        if (pessoa[i].y > maioridade)
            maioridade = pessoa[i].y;
        if (pessoa[i].sex == 2)
        {
            if ((pessoa[i].y > 20 && pessoa[i].y <= 45) || (pessoa[i].cor == 'V' && pessoa[i].h < 170))
                soma2 = soma2 + 1;
        }
        if (pessoa[i].sex == 1)
            soma3 = soma3 + 1;
    }
}

int main()
{
    dados();
    media1 = soma1/50.0;
    percent = (soma3*100.0)/50.0;
    printf("Média de idade das pessoas com olhos castanhos e altura superior a 160 cm: %.2f\n", media1);
    printf("Maior idade entre os habitantes: %d\n", maioridade);
    printf("A quantidade de indivíduos do sexo feminino cuja idade esteja entre 20 e 45 anos (inclusive) ou que tenham olhos verdes e altura inferior a 170 cm: %d\n", soma2);
    printf("O percentual de homens: %.2f%%\n", percent);
}








