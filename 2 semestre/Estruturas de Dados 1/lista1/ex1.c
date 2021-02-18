/*Escreva um algoritmo que calcule e mostre a potência de um 
determinado número somente usando ooperador de multiplicação.*/

#include <stdio.h>
int x = 3, y = 0, result;

int calculo()
{
    result = x*x;
    for(int i=1; i<y-1; i++)
    {
    	result = result * x;
    }

	if (y == 0)
	    printf("1");
	if (y == 1)
	    printf("%d", x);
	if (y > 1)
	    printf("%d", result);
}

int main()
{
	calculo();
}