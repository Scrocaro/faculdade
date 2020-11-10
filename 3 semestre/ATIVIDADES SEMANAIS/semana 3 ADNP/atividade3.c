#include <stdio.h>
#include <stdlib.h>

//////////////////CABEÇALHO////////////////////////////
int esq(int i);
int dir(int i);
void maxheapify(int *v, int i, int th);
void buildmaxheap(int *v, int n);
void heapsort(int *v, int n);

int FP_inicio(int* fp, int n);
int FP_remover_maximo(int* fp, int n);
int FP_inserir(int* fp, int n, int x);
int FP_minInicio(int *fp, int n);
void minheapify(int* v, int i, int tam);
int FP_minRemover(int* fp, int n);
int FP_minInserir(int* fp, int n, int x);
void buildminheap(int* fp, int n);

void troca(int *v, int n1, int n2);
int pai(int i);

float abreArquivo();
float lucro(int nFila, int *assentos, int assentosOcupados);
void dados(int *v, int n);
//////////////////IMPLEMENTAÇÃO/////////////////////////////
/////AUX/////
void troca(int *v, int maior, int i)
{
    int aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;
}

int pai(int i)
{
  return (i-1)/2;
}

//////heap//////
int esq(int i)
{
    return 2*i + 1;
}

int dir(int i)
{
    return 2 * i + 2;
}

void maxheapify(int *v, int i, int tam)
{
    int e, d, maior = i;
    e = esq(i);
    d = dir(i);

    if((e < tam) && (v[e] > v[i]))
        maior = e;

    if((d < tam) && (v[d] > v[maior]))
        maior = d;

    if(maior != i)
    {
        troca(v, i, maior);
        maxheapify(v, maior, tam);
    }
}

void buildmaxheap(int *v, int n)
{
    for(int i = n/2; i >= 0; i--)
    {
        maxheapify(v, i, n);
    }
}

void heapsort(int *v, int n)
{
    buildmaxheap(v, n);
    for(int i = n-1; i > 0; i--)
    {
        troca(v, 0, i);
        maxheapify(v, 0, i);
    }
}

///////Fila de prioridade/////////
int FP_inicio(int* fp, int n)
{
    buildmaxheap(fp, n);

    return fp[0];
}

int FP_remover_maximo(int* fp, int n)
{
    troca(fp, 0, n-1);
    maxheapify(fp, 0, n-1);

    return n-1;
}

int FP_inserir(int* fp, int n, int x)
{
    int tam = n+1;
    fp[n] = x;
    while(fp[n] > fp[pai(n)])
    {
        troca(fp, n, pai(n));
        n = pai(n);
    }
    return tam;
}

/////trocando prioridade/////
void buildminheap(int* fp, int n)
{
    for(int i = n/2; i >= 0; i--)
        minheapify(fp, i, n);
}

int FP_minInicio(int *fp, int n)
{
    buildminheap(fp, n);
    
    return fp[0];
}

int FP_minRemover(int* fp, int n)
{
    troca(fp, 0, n-1);
    minheapify(fp, 0, n-1);

    return n-1;
}

int FP_minInserir(int* fp, int n, int x)
{
    int tam = n+1;
    fp[n] = x;

    while(fp[n] < fp[pai(n)])
    {
        if(n <= 0) 
            break;

        troca(fp, n, pai(n));
        n = pai(n);
    }

    return tam;
}

void minheapify(int* v, int i, int tam)
{
    int maior = i;
    int e = esq(i);
    int d = dir(i);

    if((e < tam) && (v[e] < v[i]))
        maior = e;

    if((d < tam) && (v[d] < v[maior]))
        maior = d;

    if(maior != i)
    {
        troca(v, i, maior);
        minheapify(v, maior, tam);
    }
}
/////ESTADIO/////

float obterDados()
{
    FILE* arq = fopen("casos.txt", "r");

    if(arq == NULL) 
        return -1;

    int n1[2], i = 0, j = 0, assentosOcupados = 0;
    int *assentos = (int*) calloc(1000, sizeof(int));
    char *parcial = (char*) calloc(1000, sizeof(char));
    char aux = fgetc(arq);

    while(aux != '\n'){
        if(aux != ' ')
            parcial[i++] = aux;
        aux = fgetc(arq);

        if(aux == ' ' || aux == '\n')
        {
            if(atoi(parcial) > 1000)
                return -1;

            n1[j++] = atoi(parcial);
            free(parcial);
            parcial = (char*) calloc(1000, sizeof(char));
            i = 0;
        }
    };

    while(aux != EOF){
        if(aux != ' ' && aux != '\n') 
            parcial[i++] = aux;

        aux = fgetc(arq);
        
        if(aux == ' ' || aux == EOF)
        {
            if(atoi(parcial) > 1000) 
                return -1;

            assentosOcupados = FP_minInserir(assentos, assentosOcupados, atoi(parcial));
            free(parcial);
            parcial = (char*) calloc(1000, sizeof(char));
            i = 0;
        }
    };
    
    if(n1[0] < assentosOcupados)
        return -1;
    
    dados(assentos, assentosOcupados);
    fclose(arq);

    return lucro(n1[1], assentos, assentosOcupados);
}

float lucro(int nFila, int *assentos, int assentosOcupados)
{
    float lucroTotal = 0;

    while(assentosOcupados > 0)
    {
        int min = FP_minInicio(assentos, assentosOcupados);
        assentosOcupados = FP_minRemover(assentos, assentosOcupados);

        while(min > 0 && nFila > 0)
        {
            int aux = 100 + (100/min);
            lucroTotal += aux;
            min--;
            nFila--;
        }
    }

    return lucroTotal;
}

void dados(int *v, int n)
{
  for(int i=0; i < n; i++)
  {
    printf("%d ", v[i]);
    fflush(stdout);
  }
}

////////////////////////////////////////////////////////////////////
int main()
{
    float v = obterDados();

    if(v != -1)
    {
        printf("valor maximo: %f\n", v);
    }
    else
    {
        printf("algo deu errado.\n");
    }

    return 0;
}