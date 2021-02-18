/*Faça um programa que, dado um conjunto de N números, determine o menor valor,
o maior valor e a soma dos valores. */
#include <stdio.h>
int main(){
    float x, s, maior, menor;
    int n, ni;
    printf("Quantos números deseja digitar: ");
    scanf("%d", &n);
    printf("1/%d número: ", n);
    scanf("%f", &x);
    s=x;
    maior=x;
    menor=x;
    for(ni=2; ni<=n; ni++){
        printf("%d/%d número: ", ni, n);
        scanf("%f", &x);
        if(x>maior){
            maior=x;
        }
        if(x<menor){
            menor=x;
        }
        s=s+x;
    }
    printf("maior número: %.2f\n", maior);
    printf("menor número: %.2f\n", menor);
    printf("Soma: %.2f\n", s);
    return 0;
}
