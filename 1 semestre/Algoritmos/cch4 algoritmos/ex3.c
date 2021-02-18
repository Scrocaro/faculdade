/*Ler dois vetores A e B, cada um com 12 elementos. Construir uma matriz C de duas dimensões,
onde a primeira coluna da matriz C deverá ser formada pelos elementos do vetor A multiplicados
por 2 e a segunda coluna deverá se formada pelos elementos do vetor B subtraídos de 5. */
#include <stdio.h>
int main(){
    int veta[11], vetb[11], C[12][2], i, j;
    for (i=0; i<=11; i++){
        printf("%d/12 Vetor a: ", i+1);
        scanf("%d", &veta[i]);
    }
    for (j=0; j<=11; j++){
        printf("%d/12 Vetor b: ", j+1);
        scanf("%d", &vetb[j]);
    }
    for (i=0; i<=11; i++){
      veta[i] = 2 * veta[i];
    }
    for (j=0; j<=11; j++){
      vetb[j] = vetb[j] - 5;
    }
    for (i=0; i<=11; i++){
        C[i][0] = veta[i];
    }
    for (j=0; j<=11; j++){
        C[j][1] = vetb[j];
    }
    for (i=0; i<=11; i++){
        for (j=0; j<=1; j++){
            printf("%d x %d = %d\n", i+1, j+1, C[i][j]);
        }
    }
    return 0;
}
