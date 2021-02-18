/*Faça um Programa para
ler três idades de alunos e seguir as seguintes instruções:
•Se  a  média  de  idade  dos  alunos  é  inferior  de  25,  apresentar  a  mensagem
"Turma Jovem";
•Se  a  média  de  idade  dos  alunos  é  entre  25  e  40,  apresentar  a  mensagem
"Turma Adulta";
•Se  a  média  de  idade  dos
alunos  é  acima  de  40  anos,  apresentar  a
mensagem "Turma Idosa".*/
#include <stdio.h>
int main(){
    int n1, n2, n3;
    float med;
    printf("Digite 3 idades: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    med = (n1+n2+n3)/3;
    if(med<25){
        printf("Turma jovem.\n");
    }else if(med<=25 && med<=40){
        printf("Turma adulta.\n");
    }else if(med>40){
        printf("Turma idosa.\n");
    }
    return 0;
}
