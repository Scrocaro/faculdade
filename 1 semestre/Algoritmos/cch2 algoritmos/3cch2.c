#include <stdio.h>
int main(){
    int dia;
    printf("Digite um número de 1 a 7: ");
    scanf("%d", &dia);
    switch (dia){
      case 1: printf("1 é Domingo\n");
              break;
      case 2: printf("2 é Segunda\n");
              break;
      case 3: printf("3 é Terça\n");
              break;
      case 4: printf("4 é Quarta\n");
              break;
      case 5: printf("5 é Quinta\n");
              break;
      case 6: printf("6 é Sexta\n");
              break;
      case 7: printf("7 é Sábado\n");
              break;
      default:  printf("Você deve digitar números inteiros de 1 a 7!\n");
    }
      return 0;
}
