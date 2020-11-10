// counting sort //

typedef struct
{
    int dado;
    int chave;
}info;

void countingsort(info *v, int n);

void countingsortDEC(int *v, int n, int div, int base, int *temp);

void countingsortBIN(int *v, int n, int pos, int *temp);

// radix sort //

void radixsort(int *v, int n);

void radixsortBIN(int *v, int n);

// aux //

int* random_vetor (int qtdPos, int max, int seed);

int max(info *v, int n);

int maxRadix(int *v, int n);
