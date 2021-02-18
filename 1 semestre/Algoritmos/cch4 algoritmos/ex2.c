#include <stdio.h>
int main(){
    int A[9], B[9], i, j, cont = 0, conta = 0;
    for (i=0; i<10; i++){
        printf("Declare A: ");
        scanf(" %d", &A[i]);
    }
    for (j=0; j<10; j++){
        printf("Declare B: ");
        scanf(" %d", &B[j]);
    }
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            if (A[i]>B[j]){
                cont = cont + 1;
            }
        }
        if (cont >= 1){
          conta = conta + 1;
        }
    }
    printf("%d", conta);
    return 0;
}
