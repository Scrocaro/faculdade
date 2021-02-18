#include <stdio.h>

int vetor_dobra (int *v, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		v[i] = v[i] * 2;
		printf("%d\n", v[i]);
	}

}

int main()
{
	int v1[5] = {10,20,30,40,50};
	vetor_dobra(v1, 5); // [20,40,60,80,100]
}