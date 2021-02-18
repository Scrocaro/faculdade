/*Escreva uma função que crie um vetor preenchido com valores aleatórios*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int vetor_aleatorio(int tam)
{
	int i;
	int *v;
	for (i = 0; i < tam; i++)
	{
		v[i] = rand() % 100;
	}
}

int main(){
	int *v1 = vetor_aleatorio(10);
	int *v2 = vetor_aleatorio(100);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d", v1[i]);
	}
}