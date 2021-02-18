#include <stdio.h>
int main(){
    float litros;
    char p;
    printf("A - álcool\nG - gasolina\n");
    scanf("%c", &p);
    printf("litros: ");
    scanf("%f", &litros);
    if(p=='A'){
        if(litros<=20){
            printf("preço: %.1f\n", litros*(1.9*0.97));
        }else{
            printf("preço: %.1f\n", litros*(1.9*0.95));
        }
    }else if(p=='G'){
        if(litros<=20){
            printf("preço: %.1f\n", litros*(2.5*0.96));
        }else{
            printf("preço: %.1f\n", litros*(2.5*0.94));
        }
    }else{
        printf("erro\n");
    }
    return 0;
}
