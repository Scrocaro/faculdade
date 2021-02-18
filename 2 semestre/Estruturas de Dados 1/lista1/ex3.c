/*O sistema de notas de algumas universidades são calculadas de acordo com a seguinte tabela:
Maior ou igual a 9.0                     A
Maior ou igual a 7.0 e menor que 9.0     B
Maior ou igual a 6.0 e menor que 7.0     C
Menor do que 6.0                         I (Insuficiente)
Escreva um algoritmo que dado uma nota, converta e mostre o seu conceito equivalente.*/
#include <stdio.h>
void calculo()
{
	int nota = 10;
	char conceito;
	if (nota < 6)
		conceito = 'I';
	else if (nota >= 6 && nota < 7)
		conceito = 'C';
	else if (nota >= 7 && nota < 9)
		conceito = 'B';
	else
		conceito = 'A';
	printf("%c", conceito);
}

int main()
{
	calculo();
}