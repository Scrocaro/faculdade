/*Faça  um  programa  que peça  10  números  inteiros,  calcule  e  mostre  a  quantidade de números pares e a quantidade de números impares. */
#include <stdio.h>
int main(){
    int i=0, x, p=0, im=0;
    for (i=1; i<=10; i++){
        printf("Digite um número: ");
        scanf("%d", &x);

        if (x%2==0) {
            p++;
        }
        else{
            im++;
        }
    }
    printf("PARES: %d\nIMPARES: %d", p, im);
    return 0;
}
