#include <stdio.h>

int vetor_incrementa (int *v, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		v[i] = v[i] + 1;
		printf("%d\n", v[i]);
	}

}

int main()
{
	int v1[5] = {10,20,30,40,50};
	vetor_incrementa(v1, 5); // [11,21,31,41,51]
}