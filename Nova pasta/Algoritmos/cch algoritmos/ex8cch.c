/*Faça  um  Programa  que  peça  a  temperatura  em  graus  Fahrenheit,  transforme  e mostre a temperatura em graus Celsius. Fórmula: C = F-32* 5/9*/
#include <stdio.h>
int main(){
  float fah;
  printf("Digite o valor de uma temperatura em em graus Fahrenheit: ");
  scanf("%f", &fah);
  printf("%.1f °F equivale a %.1f °C\n", fah, (fah-32)*5/9);
  return 0;
}
