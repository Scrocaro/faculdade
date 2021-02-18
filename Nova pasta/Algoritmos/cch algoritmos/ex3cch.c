#include <stdio.h>
int main(){
  float n1, n2, n3, n4;
  printf("Digite quatro notas (separadas por espaço) e o programa calculará sua média bimestral:");
  scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
  printf("A média aritmética é: %.2f\n", (n1 + n2 + n3 + n4)/4);
  return 0;
}
