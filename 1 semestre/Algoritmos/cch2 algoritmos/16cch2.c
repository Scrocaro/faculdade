#include <stdio.h>
int main(){
	float preco, aum, precofim, imp;
	int cat;
	char sit;
	printf("pre�o: ");
	scanf("%f", &preco); 
	printf("Situa��o:\nR-necessita refrigera��o\nN-N�o necessita refrigera��o\n");
	scanf(" %c", &sit);
	printf("categoria:\n1-limpeza\n2-Alimenta��o\n3-vestu�rio\n");
	scanf("%d", &cat);
		if(preco<=25){
			if(cat==1){
				aum=preco*0.05;
			}
			else if(cat==2){
				aum=preco*0.08;
			}
			else{
				aum=preco*0.1;
			}
		}
		else{
			if(cat==1){
				aum=preco*0.12;
			}
			else if(cat==2){
				aum=preco*0.15;
			}
			else{
				aum=preco*0.18;
			}
		}
	printf("Aumento: %.2f\n", aum);
	if(cat==2 || sit=='R' || sit=='r'){
		imp=preco*0.05;
	}
	else{
		imp=preco*0.08;
	}
	printf("Imposto: %.2f\n", imp);
	precofim=preco+aum+imp;
	printf("Novo pre�o (com aumento e imposto): %.2f\n", precofim);
	printf("Classifica��o: ");
	if(precofim<=35){
		printf("Barato\n");
	}
	else if(precofim>35 && precofim<=80){
		printf("normal\n");
	}
	else{
		printf("Caro\n");
	}
	return 0;
}
