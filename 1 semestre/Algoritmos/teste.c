#include <stdio.h>


void calculo(int *cent, int *dez, int *uni)
{
    int x = 134, resto1, resto2;
    *cent = x/100;
    resto1 = x%100;
    *dez = resto1/10;
    resto2 = resto1%10;
    *uni = resto2;

}

 int main()
 {
 	int c, d, u;
    calculo(&c, &d, &u);
    printf("%d%d%d", u, d, c);
 }
