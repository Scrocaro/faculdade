/*Faça  um  Programa  que  peça  2  números  inteiros  e  um  número  real.  Calcule  e
mostre:
•o produto do dobro do primeiro com metade do segundo .
•a soma do triplo do primeiro com o terceiro.
•o terceiro elevado ao cubo.*/
#include <stdio.h>
int main(){
  int x, y;
  float z;
  printf("Digite três números, dois inteiros e um real, respectivamente: ");
  scanf("%d%d%f", &x, &y, &z);
  printf("2x%d x (%d/2) = %d\n", x, y, (2*x)*(y/2));
  printf("3x%d + %.1f = %.1f\n", x, z, (3*x)+z);
  printf("%.1f^3 = %.1f\n", z, z*z*z);
  return 0;
}
