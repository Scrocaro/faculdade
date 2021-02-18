#include <stdio.h>
#include <math.h>
int main(){
    float a, b, c, delta, raiza, raizb;
    printf("Para calcular as raízes de uma equação de segundo grau, indique a, b e c, respectivamente: ");
    scanf("%f%f%f", &a, &b, &c);
    delta = (b*b)-(4*a*c);
    raiza=(((-b)+sqrt(delta))/(2.0*a));
    raizb=((-b)-(sqrt(delta)))/(2.0*a);
    if(a==0){
        printf("Como a é igual a 0, a equação não é de segundo grau.\n");
    }else if(delta<0){
        printf("Como delta é negativo, a equação não possui valores reais de raizes\n");
    }else if(delta == 0){
        printf("A equação possui apenas uma raiz real. A raiz é: %.2f\n", (-b)/2*a);
    }else if(delta>0){
        printf("Raizes: %.2f e %.2f\n", raiza, raizb);
    }
    return 0;
}
