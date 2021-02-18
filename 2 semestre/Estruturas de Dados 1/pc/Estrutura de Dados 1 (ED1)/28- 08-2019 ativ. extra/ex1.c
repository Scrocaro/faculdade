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
	printf("\n[");
	for(int j = 0; j < i; j++)
	{
		printf("%d", v[j]);
		if(j < i && j != i-1)
			printf(",");
	} 
	printf("]\n");
}

int main()
{
	int v1[4];
	int v2[7];
	vetor_ex1(v1, 4, -1);
	vetor_ex1(v2, 7, 99);
	vetor_ex1(v1, 4, 0);
}