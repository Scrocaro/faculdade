#include <stdio.h>
int main(){
  float m;
  printf("Digite um valor em metros: ");
  scanf("%f", &m);
  printf("%.1f metros equivale a %.1f centimetros\n", m, m*100);
  return 0;
}
