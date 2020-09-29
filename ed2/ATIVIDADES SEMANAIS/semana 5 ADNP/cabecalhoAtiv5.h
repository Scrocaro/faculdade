int busca_seq(int *v, int n, int x);
int busca_bin(int *v, int e, int d, int x);

int minK(int *v, int i, int n, int menor);
int selectionMinK(int *v, int n, int k);
int quickMinK(int *v, int e, int d, int k);
int heapMinK(int *v, int n, int k);
int partition(int *v, int inicio, int fim);
void heapSort(int *v, int n);
void buildMinHeap(int *v, int n);
void minHeapify(int *v, int i, int th);

void troca(int* v, int n1, int n2);
int esq(int i);
int dir(int i);
void embaralhar(int *v, int ini, int fim);
int * random_vector_unique_elems(int n, int seed);