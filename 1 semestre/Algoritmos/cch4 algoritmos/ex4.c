/*Ler duas matrizes A e B de duas dimensões, sendo a matriz A de 5 X 4 e a matriz B de 4 X 3 (4 linhas  e  3  colunas).
Apresentar  a  matriz  C  como  resultante  da  multiplicação  das  matrizes  A  e  B.
Lembre-se  de  que  existe  uma  lei  matemática  que  rege  a  multiplicação  de  matrizes.
Esta  lei estabelece que uma multiplicação entre matrizes poderá ocorrer quando o número de colunas da
primeira matriz é igual ao número de linhas da segunda matriz, e que o valor resultante da terceira
matriz  é  o  somatório  da  multiplicação  de  cada  elemento  da  coluna  da  primeira  matriz  com  cada
elemento do linha da segunda matriz. */
#include <stdio.h>
int main(){
    int i, j, A[5][4], B[4][3], C[5][3];
    printf("Matriz A\n");
    for (i=1; i<=5; i++){
        for(j=1; j<=4; j++){
            printf("Elemento %d/%d: ", i, j);
            scanf("%d", &A[i][j])
        }
    }
    printf("Matriz B\n");
    for (i=1; i<=4; i++){
        for (j=1; j<=3; j++){
            printf("Elemento %d/%d: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    C[1][1] = A[1][j] * B[i][1]

    return 0;
}
