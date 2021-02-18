#include <stdio.h>
int main(){
    float l1, l2, l3;
    printf("Declare as medidas de 3 lados do triângulo: ");
    scanf("%f%f%f", &l1, &l2, &l3);
    if(l1<l2+l3 && l2<l1+l3 && l3<l1+l2){
        if(l1==l2==l3){
            printf("Triângulo equilátero.\n");
        }else if(l1==l2 || l2==l3 || l3==l1){
            printf("Triângulo isósceles.\n");
        }else if(l1!=l2!=l3){
            printf("triângulo escaleno.\n");
        }
    }else{
        printf("não é um triângulo.\n");
    }
    return 0;
}
