#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arn.h"
#include "abb.h"

int* vetor_decrescente(int n)
{
	int *v = malloc(n * sizeof(int));
	int j = n;

	for(int i = 0; i < n; i++) 
	{
		v[i] = j--;
	}

	return v;
}

int* vector_random(int n)
{
  	int *v = calloc(n, sizeof(int));
  	srand(rand());

  	for(int i = 0; i < n; i++) 
  		v[i] = rand();

  	return v;
}

int main(int argc, char** argv)
{
	int teste[] = {1000, 10000, 100000, 500000};
	float media = 0;
	//	para realizar o preenchimento da tabela 3, comentei os testes de vetores decrescentes
	/*
	printf("\n\n==================== VETORES DECRESCENTES ====================n\n\t\t\t\t\tARN:\n");
    for(int i = 0; i < 4; i++)
	{
		int *v = vetor_decrescente(teste[i]);
		float altura = 0;
		int n = teste[i];
		
		printf("\n----- TESTE = %d -----", n);

		time_t inicio = clock();
		ARN_Sort(v, n, &altura);
		time_t fim = clock();

		printf("\ntempo: %f\naltura: %.3f\n", (fim-inicio)/(float)CLOCKS_PER_SEC, altura);
	}

	printf("\n\t\t\t\t\tABB:\n");
	for(int i = 0; i < 4; i++)
	{
		int *v = vetor_decrescente(teste[i]);
		float altura = 0;
		int n = teste[i];

		printf("\n----- TESTE = %d -----", n);

		time_t inicio = clock();
		ABB_Sort(v, n, &altura);
		time_t fim = clock();
		printf("\ntempo: %f\naltura: %.3f", (fim-inicio)/(float)CLOCKS_PER_SEC, altura);
	}
*/
	printf("\n\n==================== VETORES ALEATORIOS ====================\n\n\t\t\t\t\tARN:\n");
	for(int i = 0; i < 4; i++)
	{
		float altura = 0;
		int n = teste[i];
		float media = 0;

		printf("\n----- TESTE = %d -----", n);
		for(int j = 0; j < 10; j++)
		{
			int *v = vector_random(teste[i]);

			time_t inicio = clock();
			ARN_Sort(v, n, &altura);
			media += (float)(clock() - inicio)/(float)CLOCKS_PER_SEC;
		}
		printf("\nMédia de tempo: %f\n", media);
	}

	printf("\n\t\t\t\t\tABB:\n");
	for(int i = 0; i < 4; i++)
	{
		float altura = 0;
		int n = teste[i];
		float media = 0;

		printf("\n----- TESTE = %d -----", n);
		for(int j = 0; j < 10; j++)
		{
			int *v = vector_random(teste[i]);

			time_t inicio = clock();
			ABB_Sort(v, n, &altura);
			media += (float)(clock() - inicio)/(float)CLOCKS_PER_SEC;
		}

		printf("\nMédia de tempo: %f\n", media);
	}

	return 0;
}