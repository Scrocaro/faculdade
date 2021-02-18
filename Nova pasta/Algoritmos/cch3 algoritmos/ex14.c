/*aça um programa que peça um número inteiro e determine se ele é ou não um número primo*/
#include <stdio.h>
int main(){
    int n, i=0, cont=0, x;
    printf("Número int: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        x=n%i;
        if(x==0){
            cont++;
        }
    }
    if(cont==2){
        printf("número primo");
    }
    else{
        printf("Não primo");
    }
    return 0;
}
