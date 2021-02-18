/*Faça um programa que mostre os n termos da Série a seguir:
S = 1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ... + n/m*/
#include <stdio.h>
int main(){
    int n, i=0, cont=3;
    printf("Número inteiro positivo: ");
    scanf("%d", &n);
    printf("S= 1/1");
    for(i=2; i<=n; i++){
        printf(" + %d/%d", i, cont);
        cont= cont+2;
    }
    return 0;
}
