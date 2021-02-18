/*Escreva um algoritmo que calcule e mostre a potência de um
determinado número somente usando ooperador de multiplicação.*/
#include <stdio.h>



int calculo1(int x, int y)
{
    int result = 1;
    for(int i=0; i<y; i++)
    {
    	result = result * x;
    }
    return result;
}

int calculo2(int x, int y, int *result)
{
    *result = 1;
    for(int i=0; i<y; i++)
    {
    	*result = *result * x;
    }
}

int main()
{
  //caso 1
	printf("2^5: %d\n", calculo1(2, 6));
  //caso 2
  int r;
  calculo2(2, 6, &r);
  printf("2^5: %d\n", r);
}
