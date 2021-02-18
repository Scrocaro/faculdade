#include <stdio.h>
int main(){
  float x, horas;
  printf("Digite quanto você ganha por hora e quantas horas você trabalha por mês, respectivamente (separadas por espaço): ");
  scanf("%f%f", &x, &horas);
  printf("Seu salário é %.2f reais.\n", x*horas);
  return 0;
}
