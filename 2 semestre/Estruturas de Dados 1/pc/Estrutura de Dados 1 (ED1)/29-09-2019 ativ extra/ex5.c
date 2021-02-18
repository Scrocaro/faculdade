/*
1. Alocar um novo vetor com o dobro do tamanho do vetor recebido por parâmetro.
2. Copiar os valores para o vetor novo
3. Preencher com 0 as novas posições
4. Desalocar o vetor antigo
5. Atualizar a referência do vetor recebido por parâmetro
*/
#include <stdio.h>
#include <stdlib.h>

int vetor_dobraTamanho(int *vet, int tam)
{
	int tam2 = tam * 2;
	int* vetor = (int*) calloc(tam2, sizeof(int));
	for (int i = 0; i < tam2; i++)
	{
	 	if(i <= tam) 
	 	{
		    *(vetor + i) = *(vet + i); 
	    }
		else
    	{
	       *(vetor + i) = 0;
		}
		printf("%d\n", vetor[i]);
	}
	free(vetor);
}

int main()
{
	int* v = (int*) calloc(3, sizeof(int));
	v[0] = 2;
	v[1] = 4;
	v[2] = 6;
	int novoTamanho = vetor_dobraTamanho(v, 3);
	//Resultado esperado
	// [2,4,6,0,0,0]
}
