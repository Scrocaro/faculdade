#include <stdio.h>
int main(){
    int tipo, pagamento;
    float kg, preco1, preco2, preco3, precototal;
    printf("Tipo de carne:\n 1-Filé duplo\n 2-Alcatra\n 3-Picanha\n");
    scanf("%d", &tipo);
    printf("Quantidade em kg: ");
    scanf("%f", &kg);
    printf("Tipo pagamento:\n 1-cartão tabajara\n qualquer outra tecla-dinheiro\n");
    scanf("%d", &pagamento);
    printf("NOTA FISCAL:\n quantidade carne: %.2f\n", kg);
    if(tipo==1){
        printf("carne: File Duplo\n");
        if(kg<=5){
            preco1=4.9;
        }else{
            preco1=5.8;
		}
		precototal=preco1*kg;
    }
    else if(tipo==2){
        printf("carne: Alcatra\n");
        if(kg<=5){
            preco2=5.9;
        }else{
            preco2=6.8;
        }
        precototal=preco2*kg;
    }
    else if(tipo==3){
        printf("carne: Picanha\n");
        if(kg<=5){
    		preco3=6.9;
        }else{
          	preco3=7.8;
        }
        precototal=preco3*kg;
    }
    printf("Preço total: %.2f\n", precototal);
    if(pagamento==1){
        printf("tipo de pagamento: Cartão tabajara\n Desconto: %.2f\n Preço a pagar: %.2f\n", (precototal*0.05), precototal*0.95);
    }else{
        printf("tipo de pagamento: Dinheiro\n");
	}
    return 0;
}
