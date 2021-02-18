/*Sendo H= 1 + 1/2 + 1/3 + 1/4 + ... + 1/N, Faça umprograma que calcule o valor de H com N termos.*/
#include <stdio.h>
int main(){
    int n, i=0;
    float cont=0, H=0;
    printf("H= 1 + 1/2 + ... + 1/n\n");
    printf("n=");
    scanf("%d", &n);
    for(i=n; i>=1; i--){
        cont = 1/(float)i;
        H = H + cont;
    }
    printf("%.2f", H);
    return 0;
}
