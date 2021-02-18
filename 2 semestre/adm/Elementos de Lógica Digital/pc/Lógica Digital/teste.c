#include <stdio.h>
int main()
{
    for(int i=1; i<10; i++)
    {
    printf("i = %d\n", i);
        for(int j=1; j<10;j++)
        {
            printf(" j = %d\n", j);
            if(j==4) break;
        }
    }
}