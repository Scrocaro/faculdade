/*Desenvolva um gerador de tabuada, capaz de gerar a tabuada de qualquer número
inteiro  entre  1  a  10.  O  usuário  deve  informar  de  qual  numero  ele  deseja  ver  a
tabuada. A saída deve ser conforme o exemplo abaixo: */
#include <stdio.h>
int main(){
    int x, i=0;
    printf("Digite um número inteiro: ");
    scanf("%d", &x);
    for(i=1; i<=10; i++){
        printf("%d x %d = %d\n", x, i, x*i);

    }
    return 0;
}
