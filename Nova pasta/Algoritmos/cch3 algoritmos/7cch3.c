/*Faça  um  programa  que  peça  dois  números,  base  e  expoente,  calcule  e  mostre  o
primeiro número elevado ao segundo número. Não utilize a função de potência da
linguagem*/
#include <stdio.h>
int main(){
    int base, expo, pot, i=0;
    printf("base: ");
    scanf("%d", &base);
    printf("expoente: ");
    scanf("%d", &expo);
    pot=1;
    for (i=1; i<=expo; i++) {
        pot=pot*base;
    }
    printf("%d", pot);
    return 0;
}
