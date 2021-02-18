#include <stdio.h>
int main(){
  float x;
  printf("Digite um valor para o lado de um quadrado: ");
  scanf("%f", &x);
  printf("A área desse quadrado vale: %.1f\n", x*x);
  printf("O dobro dessa área vale: %.1f\n", x*x*2);
  return 0;
}
