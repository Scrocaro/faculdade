#include <stdio.h>
int x = 273, cent, dez, resto1, resto2, uni, inverso;

void calculo()
{
    cent = x/100;
    resto1 = x%100;
    dez = resto1/10;
    resto2 = resto1%10;
    uni = resto2;
    printf("%d%d%d", uni, dez, cent);
}

 int main()
 {
     calculo();
 }
