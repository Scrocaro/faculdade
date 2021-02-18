/*Escreva uma função que crie um clone de um determinado vetor.*/

#include <stdio.h>

int  vetor_cloneA (int *vet, int tam)
{
	int* vetor = (int*) calloc(tam, sizeof(int));
	for (int i = 0; i < tam; ++i)
	{
		*(vetor + i) = *(vet + i);
	}
	return vetor;
}

int main()
{
	int v[5] = {2,4,6,8,10};
	int *copia1, *copia2;
	copia1 = vetor_cloneA(v, 5);
	for(int i = 0; i < 5; i++)
	    printf("%d\n", copia1[i]);
}