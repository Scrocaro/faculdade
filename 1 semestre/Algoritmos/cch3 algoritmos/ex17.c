/*programa  que  leia  as  um  conjunto  indeterminado  de  temperaturas,  e  informe  ao
final  a  menor  e  a  maior  temperaturas  informadas,  bem  como  a  média  das temperaturas. */
#include <stdio.h>
int main(){
    int i=1, qtd;
    float tpt, s, ma, me, m;
    printf("qtd temperaturas: ");
    scanf("%d", &qtd);
    printf("temperatura %d/%d: ", i, qtd);
    scanf("%f", &tpt);
    s=s+tpt;
    ma=tpt;
    me=tpt;
    for(i=2; i<=qtd; i++){
        printf("temperatura %d/%d: ", i, qtd);
        scanf("%f", &tpt);
        s=s+tpt;
        if(tpt>ma){
            ma=tpt;
        }
        else if(tpt<me){
            me=tpt;
        }
    }
    m=s/qtd;
    printf("Maior tpt: %.2f\n", ma);
    printf("Menor tpt: %.2f\n", me);
    printf("Média tpt: %.2f\n", m);
    return 0;
}
