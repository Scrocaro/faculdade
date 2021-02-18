/*Faça  um  programa  que  calcule  o  número  médio  de  alunos  por  turma.  Para  isto,
peça a quantidade de turmas e a quantidade de alunos para cada turma. As turmas não podem ter mais de 40 alunos. */
#include <stdio.h>
int main(){
    int turmas, i=0, alunos, s;
    float m;
    printf("turmas: ");
    scanf("%d", &turmas);
    for(i=1; i<=turmas; i++){
        printf("turma %d/%d. qtd alunos: ", i, turmas);
        scanf("%d", &alunos);
        if(alunos>40){
            printf("A turma deve ter 40 alunos ou menos");
        }
        s=s+alunos;
    }
    m=(float)s/turmas;
    printf("Média alunos/turma: %.1f", m);
    return 0;
}
