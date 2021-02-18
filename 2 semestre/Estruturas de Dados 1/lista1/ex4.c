/*Escreva um algoritmo que leia 3 inteiros positivos correspondente ao dia, mês e ano de uma determinada data e a mostre por extenso. 
Somente o dia e o mês deve ser escrito por extenso.
Exemplo:12/8/2019: Doze de agosto de 2019*/
#include <stdio.h>
#include <string.h>
void func()
{
	int dia, mes, ano;
	char mes_str[21], dia_str[21];

	printf("Dia:");
	scanf("%d", &dia);
    if (dia>31)
    {
    	printf("erro!\n");
    	return 0;
	}
	printf("Mes:");
	scanf("%d", &mes);
	if (mes>12)
	{
   		printf("erro!\n");
    	return 0;
	}
	printf("Ano:");
	scanf("%d", &ano);
	switch(dia)
  {
    case 1: strcpy (dia_str, "Um");
    		break;
    case 2: strcpy (dia_str, "Dois");
    		break;
    case 3: strcpy (dia_str, "Três");
    		break;
    case 4: strcpy (dia_str, "Quatro");
    		break;
    case 5: strcpy (dia_str, "Cinco");
    		break;
    case 6: strcpy (dia_str, "Seis");
    		break;
    case 7: strcpy (dia_str, "Sete");
    		break;
    case 8: strcpy (dia_str, "Oito");
    		break;
    case 9: strcpy (dia_str, "Nove");
    		break;
    case 10: strcpy (dia_str, "Dez");
    		 break;
    case 11: strcpy (dia_str, "Onze");
    		 break;
    case 12: strcpy (dia_str, "Doze");
    		 break;
    case 13: strcpy (dia_str, "Treze");
    		 break;
    case 14: strcpy (dia_str, "Catorze");
    		 break;
    case 15: strcpy (dia_str, "Quinze");
    		 break;
    case 16: strcpy (dia_str, "Dezesseis");
    		 break;
    case 17: strcpy (dia_str, "Dezessete");
    		 break;
    case 18: strcpy (dia_str, "Dezoito");
    		 break;
    case 19: strcpy (dia_str, "Dezenove");
    		 break;
    case 20: strcpy (dia_str, "Vinte");
    		 break;
    case 21: strcpy (dia_str, "Vinte e um");
    		 break;
    case 22: strcpy (dia_str, "Vinte e dois");
    		 break;
    case 23: strcpy (dia_str, "Vinte e três");
    		 break;
    case 24: strcpy (dia_str, "Vinte e quatro");
    		 break;
    case 25: strcpy (dia_str, "Vinte e cinco");
    		 break;
    case 26: strcpy (dia_str, "Vinte e seis");
    		 break;
    case 27: strcpy (dia_str, "Vinte e sete");
    		 break;
    case 28: strcpy (dia_str, "Vinte e oito");
    		 break;
    case 29: strcpy (dia_str, "Vinte e nove");
    		 break;
    case 30: strcpy (dia_str, "Trinta");
    		 break;
    case 31: strcpy (dia_str, "Trinta e um");
    		 break;

  }
	switch (mes)
	{
		case 1: strcpy (mes_str, "Janeiro");
				break;
		case 2: strcpy (mes_str, "Fevereiro");
				break;
		case 3:	strcpy (mes_str, "Março");
				break;
		case 4: strcpy (mes_str, "Abril");
				break;
		case 5: strcpy (mes_str, "Maio");
				break;
		case 6: strcpy (mes_str, "Junho");
				break;
		case 7: strcpy (mes_str, "Julho");
				break;
		case 8: strcpy (mes_str, "Agosto");
				break;
		case 9: strcpy (mes_str, "Setembro");
				break;
		case 10: strcpy (mes_str, "Outubro");
				 break;
		case 11: strcpy (mes_str, "Novembro");
				 break;
		case 12: strcpy (mes_str, "Dezembro");
				 break;

	}
	printf("%s de %s de %d", dia_str, mes_str, ano);
}

int main()
{
	func();
}
