#include <stdio.h>
#include <stdlib.h>
#include "tabelahash_ea.h"

int main(int argc, char** argv)
{
    int m = 5;
    int n = 1000000;
    int max = n * 10;
    int seed = 42;
    THEA *linear;
    THEA *quadratica;
    THEA *duplo;


    linear = THEA_Random(m, n, max, seed, FS_LINEAR);
    printf("LINEAR: %d\n", linear->colisoes);

    quadratica = THEA_Random(m, n, max, seed, FS_QUADRATICA);
    printf("QUADRATICO: %d\n", quadratica->colisoes);

    duplo = THEA_Random(m, n, max, seed, FS_HASH_DUPLO);
    printf("DUPLO: %d\n", duplo->colisoes);

    free(linear);
    free(quadratica);
    free(duplo);
    return 0;
}