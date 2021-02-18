#include <stdio.h>
int main(){
  int sexo;
  printf("Esse algoritmo calcula o seu peso ideal.\n Se você é homem, digite 1\n Se você é mulher, digite 2.\n");
  scanf("%d", &sexo);
  float peso;
  printf("Digite seu peso em kg:\n");
  scanf("%f", &peso);
  float h;
  printf("Declare sua altura em metros (use '.' em vez de ','): ");
  scanf("%f", &h);
  float ideal;
  if (sexo == 1){
    ideal = (72.7*h)-58;
    printf("Seu peso ideal é: %.3f\n", ideal);
    if (peso < ideal-1){
      printf("Seu peso atual é menor do que o ideal.\n");
    }else if (peso > ideal + 1){
      printf("Seu peso atual é maior do que o ideal.\n");
    }else{
      printf("Você está dentro do peso ideal (Há uma margem de 1 kilo do peso correto).\n");
    }
  }else if (sexo == 2){
    ideal = (62.1*h)-44.7;
    printf("Seu peso ideal é: %.3f\n", ideal);
    if (peso < ideal-1){
      printf("Seu peso atual é menor do que o ideal.\n");
    }else if (peso > ideal + 1){
      printf("Seu peso atual é maior do que o ideal.");
    }else{
    printf("Você está dentro do peso ideal (Há uma margem de 1 kilo do peso correto).\n");
    }
  }else{
    printf("Você não digitou um número válido.\n");
  }
  return 0;
}
