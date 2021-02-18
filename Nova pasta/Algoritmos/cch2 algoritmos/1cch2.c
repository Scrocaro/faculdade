#include <stdio.h>
int main(){
    float sal;
    printf("Digite seu salário em reais: ");
    scanf("%f", &sal);
    if (sal <= 280){
        printf("Seu salário é: %.2f\n", sal);
        printf("Seu aumento será de 20%%\n");
        printf("Seu salário aumentará em %.2f R$\n", (sal*1.2)-sal);
        printf("Seu novo salário será: %.2f R$\n", sal*1.2);
    }else if (sal > 280 && sal <= 700){
        printf("Seu salário é: %.2f\n", sal);
        printf("Seu aumento será de 15%%\n");
        printf("Seu salário aumentará em %.2f R$\n", (sal*1.15)-sal);
        printf("Seu novo salário será: %.2f R$\n", sal*1.15);
    }else if (sal > 700 && sal <= 1500){
        printf("Seu salário é: %.2f\n", sal);
        printf("Seu aumento será de 10%%\n");
        printf("Seu salário aumentará em %.2f R$\n", (sal*1.1)-sal);
        printf("Seu novo salário será: %.2f R$\n", sal*1.1);
    }else{
        printf("Seu salário é: %.2f\n", sal);
        printf("Seu aumento será de 5%%\n");
        printf("Seu salário aumentará em %.2f R$\n", (sal*1.05)-sal);
        printf("Seu novo salário será: %.2f R$\n", sal*1.05);
    }
    return 0;
}
