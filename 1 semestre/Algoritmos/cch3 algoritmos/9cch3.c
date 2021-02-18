/*A série de Fibonacci é formada pela seqüência 1,1,2,3,5,8,13,21,34,55,... Faça um
programa capaz de gerar a série até o n-ésimo termo.*/
#include <stdio.h>
int main(){
    int n1=1, n2=1, n3, i=0, n;
    printf("n=");
    scanf("%d", &n);
        if (n==1){
            printf("1");
        }else if(n==2){
            printf("1, 1");
        }else{
            printf("1, 1");
            for (i=0; i<n-2; i++) {
                n3=n1+n2;
                n1=n2;
                n2=n3;
                printf(", %d", n3);
            }
        }
    printf(".\n");
    return 0;
}
