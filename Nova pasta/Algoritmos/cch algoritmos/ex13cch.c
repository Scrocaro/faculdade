#include <stdio.h>
int main(){
    float horas, salariohora, salariobruto, inss, ir, sindicato, salarioliquido;
    printf("Digite quanto você ganha por hora em reais e o número de horas trabalhadas no mês, respectivamente: ");
    scanf("%f%f", &salariohora, &horas);
    salariobruto = horas*salariohora;
    inss = salariobruto*0.08;
    ir = salariobruto*0.11;
    sindicato = salariobruto*0.05;
    salarioliquido = (salariobruto)-(inss)-(ir)-(sindicato);
    printf("Seu salário bruto é: %.2f\n", salariobruto);
    printf("Você paga %.2f R$ de Imposto de renda\n", ir);
    printf("Você paga %.2f R$ no INSS\n", inss);
    printf("Você paga %.2f R$ ao sindicato\n", sindicato);
    printf("Seu salário líquido é: %.2f R$\n", salarioliquido);

    return 0;
}
