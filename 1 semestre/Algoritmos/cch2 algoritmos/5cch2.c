/*Altere o programa que calcula a média do aluno, e mostre a mensagem de acordo
com a média. De 0 a 3 -Reprovado, de 3 a 6.9 -Em Exame, de 7 a 10 -Aprovado*/
#include <stdio.h>
int main(){
    float n1, n2, n3, n4;
    printf("Digite 4 notas (de 0 a 10): ");
    scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
    float med=(n1+n2+n3+n4)/4;
    if(med<=3){
        printf("Sua média foi: %.2f. Portanto, Reprovado!\n", med);
    }else if(med>3 && med<=6.9999){
        printf("Sua média foi: %.2f. Portanto, pegou exame.\n", med);
    }else if(med>=7 && med<=10){
        printf("Sua média foi: %.2f. Portanto, aprovado!\n", med);
    }

    return 0;
}
