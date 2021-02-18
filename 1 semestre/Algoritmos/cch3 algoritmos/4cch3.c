/*Faça  um  programa  que  receba  dois  números  inteiros  e  gere  os  números  inteiros
que estão no intervalo compreendido por eles. */
#include <stdio.h>
int main(){
    int x, y, i=0;
    printf("Digite dois números inteiros: ");
    scanf("%d%d", &x, &y);
    if(x<y){
        y--;
        for(i=x; x!=y; y--){
            printf("%d\n", y);
        }
    }else if(x>y){
        x--;
        for(i=y; x!=y; x--){
            printf("%d\n", x);
        }
    }else{
        printf("Não há números inteiros entre %d e %d", x, y);
    }
    return 0;
}
