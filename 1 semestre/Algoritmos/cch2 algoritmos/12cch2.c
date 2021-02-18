/*Faça  um  programa  que  faça  5  perguntas  para  uma  pessoa  sobre  um  crime.  As perguntas são:
•"Telefonou para a vítima?"
•"Esteve no local do crime?"
•"Mora perto da vítima?"
•"Devia para a vítima?"
•"Já   trabalhou com   a   vítima?"
O   programa   deve   no   final   emitir   uma classificação  sobre  a  participação  da  pessoa  no  crime.  Se  a  pessoa
responder  positivamente  a  2  questões  ela  deve  ser  classificada  como "Suspeita",  entre  3  e  4  como  "Cúmplice"  e  5  como  "Assassino".
Caso contrário, ele será classificado como "Inocente".*/
#include <stdio.h>
int main(){
    int r1, r2, r3, r4, r5, qtd;
    printf("responda 1 como sim e 0 como não.\n");
    printf("Telefonou para a vítima?");
    scanf("%d", &r1);
    printf("Esteve no local do crime?");
    scanf("%d", &r2);
    printf("Mora perto da vítima?");
    scanf("%d", &r3);
    printf("Devia para a vítima?");
    scanf("%d", &r4);
    printf("Já trabalhou com a vítima?");
    scanf("%d", &r5);
    qtd = r1+r2+r3+r4+r5;
    if(qtd==0 || qtd==1){
        printf("inocente\n");
    }else if(qtd==2){
        printf("suspeita\n");
    }else if(qtd==3 || qtd==4){
        printf("cúmplice\n");
    }else if(qtd==5){
        printf("assassino\n");
    }
    return 0;
}
