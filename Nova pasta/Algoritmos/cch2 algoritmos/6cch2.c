/*Faça  um  programa  que  lê  as  duas  notas  parciais  obtidas  por  um  aluno  numa disciplina  ao  longo
de  um  semestre,  e  calcule  a  sua  média.  A  atribuição  de conceitos obedece à tabela abaixo:
Média de Aproveitamento
Conceito
Entre 9.0 e 10.0A
Entre 7.5 e 9.0B
Entre 6.0 e 7.5C
Entre 4.0 e 6.0D
Entre 4.0 e zeroE
O algoritmo deve mostrar na tela as notas, a média, o conceito correspondente e a
mensagem  “APROVADO”  se
o  conceito  for  A,  B  ou  C  ou  “REPROVADO”  se  o
conceito for D ou E.*/
#include <stdio.h>
int main(){
    float n1, n2, med;
    printf("Digite duas notas entre 0 e 10: ");
    scanf("%f%f", &n1, &n2);
    med=(n1+n2)/2;
    if(n1>10 || n1<0 || n2>10 || n2<0){
      printf("Valor inválido.\n");
    }else if(med>0 && med<=4){
        printf("Notas: %.2f, %.2f\n Média: %.2f\n Conceito: E\n REPROVADO!\n", n1, n2, med);
    }else if(med>4 && med<=6){
        printf("Notas: %.2f, %.2f\n Média: %.2f\n Conceito: D\n REPROVADO!\n", n1, n2, med);
    }else if(med>6 && med<=7.50){
        printf("Notas: %.2f, %.2f\n Média: %.2f\n Conceito: C\n APROVADO!\n", n1, n2, med);
    }else if(med>7.50 && med<=9){
        printf("Notas: %.2f, %.2f\n Média: %.2f\n Conceito: B\n APROVADO!\n", n1, n2, med);
    }else if(med>9 && med<=10){
        printf("Notas: %.2f, %.2f\n Média: %.2f\n Conceito: A\n APROVADO!\n", n1, n2, med);
    }
    return 0;
}
