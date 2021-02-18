/*Faça  um  programa  para  uma  loja  de  tintas.  O  programa  deverá  pedir  o  tamanho
em metros quadrados da área a ser pintada. Considere que a cobertura da tinta é
de  1  litro  para  cada  3  metros  quadrados  e  que  a  tinta  é  vendida  em  latas  de  18
litros,  que  custam  R$  80,00.  Informe  ao  usuário  a  quantidades  de  latas  de  tinta  a
serem compradas e o preço total.*/
#include <stdio.h>
int main(){
    float tamanho, qtdtinta, preco, latas;
    printf("Digite o tamanho em m² da área a ser pintada: ");
    scanf("%f", &tamanho);
    qtdtinta = tamanho/3;
    latas = qtdtinta/18;
    preco = latas * 80;
    printf("Você usará %.2f latas de tintas, preço total será: %.2f R$\n", latas, preco);
    return 0;
}
