/*Se o cliente comprar mais de 8 Kg em frutas ou o valor total da compra ultrapassar R$  25,00,  receberá  ainda  um  desconto  de  10%  sobre  este  total.
Escreva  um algoritmo  para  ler  a  quantidade  (em  Kg)  de  morangos  e  a  quantidade  (em  Kg)  de maças adquiridas e escreva o valor a ser pago pelo cliente.*/
#include <stdio.h>
int main(){
    float morango, maca, precomorango, precomaca, precototal;
    printf("kg morango e kg maçã, respectivamente: ");
    scanf("%f%f", &morango, &maca);
    if(morango<=5){
        precomorango=2.5;
    }else{
        precomorango=2.2;
    }
    if(maca<=5){
        precomaca=1.8;
    }else{
        precomaca=1.5;
    }
    precomorango=precomorango*morango;
    precomaca=precomaca*maca;
    precototal=precomorango+precomaca;
    if(morango+maca>8 || precomorango+precomaca>25){
        precototal=precototal*0.9;
    }
    printf("Preço total: %.2f\n", precototal);
    return 0;
}
