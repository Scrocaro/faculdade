#include <stdio.h>
#include <math.h>
int main(){
    int num, cent, tempNum, dez, uni;
    printf("Digite um número inteiro menor que 1000:");
    scanf("%d", &num);

    if(num >= 100) {cent = floor(num/100); tempNum = num-(cent*100);}else{tempNum = num; cent=0;}
    if(tempNum >= 10){dez = floor(tempNum/10); tempNum = tempNum-(dez*10);}else{dez=0;}
    if(tempNum > 0){uni = tempNum;}else{uni=0;}
    //////////////////////////////////////////////////////////////////////////////////////
    printf("%d =", num);
    if(cent > 0){
        if(cent != 1){ printf(" %d centenas", cent);}else{printf(" %d centena", cent);}
    }

    if(dez > 0){
        if(cent > 0){
            if(uni > 0){
                if(dez != 1){printf(", %d dezenas", dez);}else{printf(", %d dezena", dez);}
            }else{
                if(dez != 1){printf(" e %d dezenas", dez);}else{printf(" e %d dezena", dez);}
            }
        }else{if(dez != 1){printf(" %d dezenas", dez);}else{printf(" %d dezena", dez);}}
    }

    if(uni > 0){
        if(cent > 0 || dez > 0){
            if(uni != 1){printf(" e %d unidades", uni);}else{printf(" e %d unidade", uni);}
        }else{
            if(uni != 1){printf(" %d unidades", uni);}else{printf(" %d unidade", uni);}
        }
    }
    printf(".\n");
    return 0;
}
