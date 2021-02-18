/*Faça  um  programa  que  peça  para  n  pessoas  a  sua  idade,  ao  final  o  programa
devera  verificar  se  a  média  de  idade  da  turma  varia  entre  0  e  25,26  e  60  e  maior
que  60;  e  então,  dizer  se  a  turma  é  jovem,  adulta  ou  idosa,  conforme  a  média calculada. */
#include <stdio.h>
int main(){
    int pessoas, i=0, y, s;
    float m;
    printf("N° de pessoas: ");
    scanf("%d", &pessoas);
    for(i=1; i<=pessoas; i++){
        printf("pessoa %d de %d. IDADE: ", i, pessoas);
        scanf("%d", &y);
        s=s+y;
    }
    m=s/(float)pessoas;
    if(m>=0 && m<=25){
        printf("turma jovem");
    }
    else if(m<=60){
        printf("turma adulta");
    }
    else{
        printf("turma idosa");
    }
    return 0;
}
