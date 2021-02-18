#include <stdio.h>
int main(){
    float hora, salhora, salbruto, ir, inss, fgts, sind;
    printf("Digite o seu salário em reais por hora e a quantidade de horas trabalhada no mês: ");
    scanf("%f%f", &salhora, &hora);
    salbruto = hora*salhora;
    inss = salbruto*0.1;
    fgts = salbruto*0.11;
    sind = salbruto*0.03;
    if(salbruto <=900){
        printf("Salário bruto: %.2fR$\n", salbruto);
        printf("IR: isento\n");
        printf("INSS: %.2f R$\n", inss);
        printf("FGTS: %.2f R$\n", fgts);
        printf("Sindicato: %.2f R$\n", sind);
        printf("Salário líquido: %.2f R$\n", salbruto-inss-sind);
    }else if(salbruto > 900 && salbruto <= 1500){
        ir = salbruto*0.05;
        printf("Salário bruto: %.2fR$\n", salbruto);
        printf("IR: %.2f R$\n", ir);
        printf("INSS: %.2f R$\n", inss);
        printf("FGTS: %.2f R$\n", fgts);
        printf("Sindicato: %.2f R$\n", sind);
        printf("Salário líquido: %.2f R$\n", salbruto-ir-inss-sind);
    }else if(salbruto > 1500 && salbruto<=2500){
        ir = salbruto*0.1;
        printf("Salário bruto: %.2fR$\n", salbruto);
        printf("IR: %.2f R$\n", ir);
        printf("INSS: %.2f R$\n", inss);
        printf("FGTS: %.2f R$\n", fgts);
        printf("Sindicato: %.2f R$\n", sind);
        printf("Salário líquido: %.2f R$\n", salbruto-ir-inss-sind);
    }else if(salbruto>2500){
        ir = salbruto*0.2;
        printf("Salário bruto: %.2fR$\n", salbruto);
        printf("IR: %.2f R$\n", ir);
        printf("INSS: %.2f R$\n", inss);
        printf("FGTS: %.2f R$\n", fgts);
        printf("Sindicato: %.2f R$\n", sind);
        printf("Salário líquido: %.2f R$\n", salbruto-ir-inss-sind);
    }
    printf("FGTS não é descontado do salário, empresa que paga");
    return 0;
}
