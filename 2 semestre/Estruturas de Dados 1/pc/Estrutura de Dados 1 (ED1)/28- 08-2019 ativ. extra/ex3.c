#include <stdio.h>

int vetor_ex1(int* v, int tam, int valor)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		v[i] = valor;
		// *(v + i) = valor;
		valor += 1;
	}
	return v[tam - 1];
}

int main()
{
	int v1[4];
	int v2[7];
	printf("\n[%d]\n", vetor_ex1(v1, 4, -1));
	printf("\n[%d]\n", vetor_ex1(v2, 7, 99));
	printf("\n[%d]\n", vetor_ex1(v1, 4, 0));
}