/*Uma empresa contratou 15 funcionários temporários. De acordo com o valor das vendas mensais, os  funcionários  adquirem  pontos
que  determinarão  seus  salários  ao  final  de  cada  mês.  Faça  um programa que:
a) Cadastre os nomes dos funcionários e suas respectivas vendas mensais;
b) Calcule e mostre a pontuação geral de cada funcionário nos três meses. Sabe-se que R$ 100,00 equivalem a 1 ponto;
c) Calcule e mostre a pontuação geral de todos os funcionários a cada mês;
d) Determine  e  mostre  a  maior  pontuação  atingida  nos  três  meses,  mostrando  o  nome  do funcionário. Desconsiderar empates;
e) Determine e mostre o valor total vendido.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 5

int i, j, maiorpont = 0;
char maiorpontnome[51];
float totalvendas = 0;

void cadastro();


struct REG
{
    char nome[51];
    float vendaMensal[3];
    int pontotal, pontomes;
};
struct REG funcionario[N];

void cadastro()
{
    for (i=0; i<N; i++)
    {
        printf("Funcionario %d: \n", i+1);
        funcionario[i].pontotal = 0;
        printf("Nome: ");
        scanf(" %[^\n]", funcionario[i].nome);
        for (j=0; j<3; j++)
        {
            printf("Venda mes %d em reais: ", j+1);
            scanf("%f", &funcionario[i].vendaMensal[j]);
            totalvendas = totalvendas + funcionario[i].vendaMensal[j];
            funcionario[i].pontomes = floor(funcionario[i].vendaMensal[j]/100);
            funcionario[i].pontotal += floor(funcionario[i].vendaMensal[j]/100);
            printf("Pontuação do funcionario %d  no  mes %d:  %d\n", i+1, j+1, funcionario[i].pontomes);
            printf("\n%d\n", funcionario[i].pontotal);

        }
        if (funcionario[i].pontotal > maiorpont)
        {
            maiorpont = funcionario[i].pontotal;
            strcpy(maiorpontnome, funcionario[i].nome);
        }
        printf("pontuação total do funcionario %d: %d\n", i+1, funcionario[i].pontotal);
        printf("funcionario cadastrado!\n\n");
    }
    printf("\nMaior pontuação:\n Funcionario: %s\n Pontuação: %d\n", funcionario[i].nome, maiorpont);
    printf("\nO total de vendas foi: %.2f", totalvendas);
}

int main()
{
    cadastro();
    return 0;
}
