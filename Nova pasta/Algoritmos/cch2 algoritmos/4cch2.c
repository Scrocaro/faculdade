#include <stdio.h>
int main(){
    float preco;
    int cod;
    printf("Digite o preço de custo do produto e o código de origem (1 até 8), respectivamente: ");
    scanf("%f%d", &preco, &cod);
    switch (cod){
        case 1: printf("Preço: %.2f\n Origem: Sul.\n", preco);
                break;
        case 2: printf("Preço: %.2f\n Origem: Norte\n", preco);
                break;
        case 3: printf("Preço: %.2f\n Origem: Leste.\n", preco);
                break;
        case 4: printf("Preço: %.2f\n Origem: Oeste.\n", preco);
                break;
        case 5 ... 6: printf("Preço: %.2f\n Origem: Nordeste.\n", preco);
                break;
        case 7 ... 8: printf("Preço: %.2f\n Origem: Centro-Oeste.\n", preco);
                break;
        default: printf("Preço: %.2f\n Origem: importado.", preco);
    }
    return 0;
}
