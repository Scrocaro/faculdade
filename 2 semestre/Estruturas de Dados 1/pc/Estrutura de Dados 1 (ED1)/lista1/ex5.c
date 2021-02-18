/*Escreva um algoritmo para um caixa eletrônico que dado um valor a ser sacado calcule o menor número de cédulas possível. 
Considere que sempre haverá quantidade suficiente de cédulas para efetuar o saque. As cédulas disponíveis são: 100, 50, 20, 10, 5 e 2.*/
#include <stdio.h>

int saque();
int calculo();

int saque()
{
	int qtd;
	printf("quantidade a ser sacada(o número não pode terminar em 3 ou 8): ");
	scanf("%d", &qtd);
	return qtd;
}

int calculo()
{
	int a=saque();
	int qcem=0, qcinq=0, qvint=0, qdez=0, qcinc=0, qdois=0;
	if (a!=0)
	{
		qcem = a/100;
		a = a - (qcem*100);
		if (a!=0)
		{
			qcinq = a/50;
			a = a - (qcinq*50);
			if (a!=0)
			{
				qvint = a/20;
				a = a - (qvint*20);
				if (a!=0)
				{
					qdez = a/10;
					a = a - (qdez*10);
					if (a!=0)
					{
						qcinc = a/5;
						a = a - (qcinc*5);
						if (a!=0)
						{
							qdois = a/2;
						}
					}
				}
			}
		}
	}
	printf("Notas de 100: %d\nNotas de 50: %d\nNotas de 20: %d\nNotas de 10: %d\nNotas de 5: %d\nNotas de 2: %d\n", qcem, qcinq, qvint, qdez, qcinc, qdois);
}

int main()
{
	saque();
	calculo();
}
