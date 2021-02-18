/*Faça um programa que peça uma nota, entre zero e dez. Mostre uma mensagem
caso  o  valor  seja  inválido  e  continue  pedindo  até  que  o  usuário  informe  um  valor válido. */
#include <stdio.h>
int main(){
    float x;
    printf("Digite uma nota entre 0 e 10: ");
    scanf("%f", &x);
    while(x<=0 || x>=10){
        printf("Digite uma nota: ");
        scanf("%f", &x);
    }
    return 0;
}
