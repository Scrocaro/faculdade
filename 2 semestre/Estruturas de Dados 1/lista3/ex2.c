#include <stdio.h>

int calculo(int x)
{
    int cent, dez, resto1, resto2, uni, inverso;
    cent = x/100;
    resto1 = x%100;
    dez = resto1/10;
    resto2 = resto1%10;
    uni = resto2;
    inverso = uni*100 + dez*10 + cent;
    return inverso;
}

int calculo2(int y, int *x)
{

    int cent, dez, resto1, resto2, uni, inverso;
    cent = y / 100;
    resto1 = y % 100;
    dez = resto1/10;
    resto2 = resto1%10;
    uni = resto2;
    inverso = uni*100 + dez*10 + cent;
    *x = inverso;
}

 int main()
 {
     //caso 1
     printf("%d\n", calculo(123));
     //caso 2
     int n = 321, num;
     calculo2(n, &num);
     printf("%d\n", num);
 }
