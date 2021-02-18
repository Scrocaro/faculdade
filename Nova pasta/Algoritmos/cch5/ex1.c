/* A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes, coletando dados sobre o salário, idade, gênero e número de filhos.
Faça um programa que leia esses dados de 20 pessoas, calcule e mostre:
a) A média de salário da população;
b) A média do número de filhos;
c) O maior salário;
d) O percentual de mulheres com salário superior a R$ 1000,00. */
#include <stdio.h>

#define N 20
int somasal = 0, somanfilhos = 0, maiorsal = 0;
float mediasal, medianfilhos, nmulheressal = 0, percentual;             /*-nmulheressal- conta quantas mulheres tem salarios maiores que mil*/

void dados();

struct REG{
    float salario;
    int idade, nfilhos, genero;
};
struct REG pessoa[N];

void dados(){
    for (int i = 1; i <= N; i++){
        printf("Pessoa %d/20: \n", i);
        printf("Salario: ");
        scanf("%f", &pessoa[i].salario);
        somasal = somasal + pessoa[i].salario;
        if (pessoa[i].salario > maiorsal)
            maiorsal = pessoa[i].salario;
        printf("idade: ");
        scanf("%d", &pessoa[i].idade);
        printf("Gênero:\n 1 - Masculino\n 2 - Feminino\n 3 - outro\n ");
        scanf("%d", &pessoa[i].genero);
        printf("Número de filhos: ");
        scanf("%d", &pessoa[i].nfilhos);
        somanfilhos = somanfilhos + pessoa[i].nfilhos;
        if (pessoa[i].genero == 2 && pessoa[i].salario > 1000)
            nmulheressal = nmulheressal + 1;
    }
}

int main(){
    dados();
    mediasal = somasal/20.0;
    medianfilhos = somanfilhos/20;
    percentual = (nmulheressal/20.0)*100;
    printf("Média de salário da população: %.2f\n", mediasal);
    printf("Média do número de filhos: %.2f\n", medianfilhos);
    printf("Maior salário: %d\n", maiorsal);
    printf("Percentual de mulheres com salário superior a R$ 1000,00: %.2f%%", percentual);
}















