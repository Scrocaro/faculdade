#include <stdio.h>
#include <math.h>
int main (){
	float tamanho, lata, precolata, galao, precogalao, qtdtinta;
	printf("Digite o tamanho da �rea em m�: \n");
	scanf("%f", &tamanho);
	qtdtinta = tamanho/6;
	lata = qtdtinta/18;
	precolata = ceil(lata)*80;
	galao = qtdtinta/3.6;
	precogalao = ceil(galao)*25;
	printf("Se comprar apenas em latas, a quantidade de latas a comprar � %.2f e o pre�o ser�: %.2f R$.\n", ceil(lata), precolata);
	printf("Se comprar apenas em gal�es, a quantidade de gal�es a comprar � %.2f e o pre�o ser�: %.2f R$.\n",  ceil(galao), precogalao);
	float galaom, latasm;
	int resto;
	resto = ceil(qtdtinta);
	latasm = floor(lata); 
	galaom = resto%18;
	galaom = galaom/3.6;
	galaom = ceil(galaom);
	float precomenor;
	precomenor = (latasm*80)+(galaom*25);
	printf("Para gastar o menor valor poss�vel em reais, deve-se  comprar: %.2f latas e %.2f gal�es, custando %.2f R$\n", latasm, galaom, precomenor);
	return 0;
}	
