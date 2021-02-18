/*Tendo como dados de entrada a altura de uma pessoa, construa um algoritmo que
calcule seu peso ideal, usando a seguinte fórmula: (72.7*altura)–58*/
#include <stdio.h>
int main(){
  float x;
  printf("Digite sua altura em metros (usando '.' em vez de ','): ");
  scanf("%f", &x);
  float ideal = (72.7*x)-58;
  printf("O peso ideal para você é %.3f\n", ideal);
  return 0;
}
