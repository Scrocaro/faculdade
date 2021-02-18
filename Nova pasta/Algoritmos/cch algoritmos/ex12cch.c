#include <stdio.h>
int main (){
  float peso, excesso, multa;
  printf("Digite o peso em kg: ");
  scanf("%f", &peso);
  if (peso > 50){
    excesso = (peso - 50);
    multa = (excesso * 4);
    printf("O peso excedeu o estabelecido pelo regulamento de pesca do estado de SP. \n Multa: %.2f R$\n peso excedido: %.2f Kg\n", multa, excesso);
  }else{
    excesso = 0.0;
    multa = 0.0;
    printf("Como %.2f <= 50: \n Multa: %.2f R$ \n excesso: %.2f Kg\n", peso, multa, excesso);
  }
  return 0;
}
