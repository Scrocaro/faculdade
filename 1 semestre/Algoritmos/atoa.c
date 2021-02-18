#include <stdio.h>

int main()
{
    char n1[5] = {'E', 'J', 'O', 'T', 'Y'};
    char n2[5] = {'B', 'G', 'L', 'Q', 'V'};
    char n3[6] = {'A', 'F', 'K', 'P', 'U', 'Z'};
    int i, j, k;

    for (i=0; i<=4; i++)
    {
        for (j=0; j<=4; j++)
        {
            for (k=0; k<=5; k++)
            {
                printf("%c %c %c \n", n1[i], n2[j], n3[k]);
            }
        }
    }
}