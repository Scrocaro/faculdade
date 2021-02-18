#include <stdio.h>
int main(){
    float A[6], B[6], C[7][2];
    int i, j;
    for (i=0; i<7; i++){
        printf("Declare A: ");
        scanf(" %f", &A[i]);
    }
    for (i=0; i<7; i++){
        printf("Declare B: ");
        scanf(" %f", &B[i]);
    }
    for (i=0; i<7; i++){
        C[i][0] = A[i];
    }
    for (i=0; i<7; i++){
        C[i][1] = B[i];
    }
    for (i=0; i<7; i++){
        for (j=0; j<2; j++){
            printf("%d x %d = %.1f\n", i, j, C[i][j]);
        }
    }
}
