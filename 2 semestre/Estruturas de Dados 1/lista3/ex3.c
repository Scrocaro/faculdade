/*O sistema de notas de algumas universidades são calculadas de acordo com a seguinte tabela:
Maior ou igual a 9.0                     A
Maior ou igual a 7.0 e menor que 9.0     B
Maior ou igual a 6.0 e menor que 7.0     C
Menor do que 6.0                         I (Insuficiente)
Escreva um algoritmo que dado uma nota, converta e mostre o seu conceito equivalente.*/
#include <stdio.h>

char calculo(float nota)
{
  char conceito;
  if(nota<0 || nota>10) conceito = 'X';

	if (nota < 6) conceito = 'I';
	else if (nota >= 6 && nota < 7) conceito = 'C';
	else if (nota >= 7 && nota < 9) conceito = 'B';
	else conceito = 'A';
  return conceito;
}

char calculo2(float x, char *conceito)
{
  if(x<0 || x>10) *conceito = 'X';
	if (x < 6) *conceito = 'I';
	else if (x >= 6 && x < 7) *conceito = 'C';
	else if (x >= 7 && x < 9) *conceito = 'B';
	else *conceito = 'A';
}

int main()
{
    //caso 1
	  printf("%c\n", calculo(7));
    //caso 2
    float num = 4;
    char c;
    calculo2(num, &c);
    printf("%c\n", c);
}
