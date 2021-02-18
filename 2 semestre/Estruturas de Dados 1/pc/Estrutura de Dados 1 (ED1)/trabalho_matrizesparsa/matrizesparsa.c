#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int linha;
    int coluna;
    int valor;
    struct node* direita;
    struct node* baixo;
    struct node* esquerda;
    struct node* cima;

}Node;

typedef struct
{
    Node** linhas;    //ponteiro para o vetor cujas células são ponteiros de nós
    Node** colunas;   //ponteiro para o vetor cujas células são ponteiros de nós
    int numLinhas;    //Quantidade de linhas da matriz
    int numColunas;   //Quantidade de colunas da matriz
}Matriz;

/////////////////////////CABEÇALHO/////////////////////////

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
//Cria uma matriz vazia e devolve seu endereço de memória.

int matriz_atribuir(Matriz* m, int linha, int coluna, int valor);
//Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.

int matriz_acessar(Matriz* m, int linha, int coluna);
//Devolve o valor correspondente a linha e coluna solicitada. Faça a validação dos índices. Caso a posição solicitada esteja fora do intervalo, devolva zero.

void matriz_imprimir(Matriz* m);
//Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não reprewardados na matriz (valor zero), também devem ser impressos.

void matriz_desalocar(Matriz* m);
//Libera toda memória alocada dinamicamente para a matriz.

//Funções extras
Node* buscaBaixoNo(Matriz* m, int linha, int coluna);
Node* buscaProxNo(Matriz* m, int linha, int coluna);
Node* buscaNo(Matriz* m, int linha, int coluna);

/////////////////////////IMPLEMENTAÇÃO/////////////////////////

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas)
{
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    m->numLinhas = qtdeLinhas;
    m->numColunas = qtdeColunas;
    m->linhas = (Node**)calloc(qtdeLinhas, sizeof(Node*));
    m->colunas = (Node**)calloc(qtdeColunas, sizeof(Node*));

    for(int i = 0; i < qtdeLinhas; i++)
    {
        Node* ward = (Node*)malloc(sizeof(Node));
        ward->direita = ward->baixo = ward->esquerda = ward->cima = ward;
        m->linhas[i] = ward;
    }

    for(int i = 0; i < qtdeColunas; i++)
    {
        Node* ward = (Node*)malloc(sizeof(Node));
        ward->direita = ward->baixo = ward->esquerda = ward->cima = ward;
        m->colunas[i] = ward;
    }
    return m;
}

int matriz_atribuir(Matriz* m, int linha, int coluna, int valor)
{
    if(m == NULL || linha >= m->numLinhas || coluna >= m->numColunas)
    {
        return 0;
    }
    Node* no = buscaNo(m, linha, coluna);
    if(no == NULL)
    {
        no = (Node*)malloc(sizeof(Node));
        no->linha = linha;
        no->coluna = coluna;
        no->valor = valor;

        Node* prox = buscaProxNo(m, linha, coluna);
        no->direita = prox;
        no->esquerda = prox->esquerda;
        prox->esquerda->direita = no;
        prox->esquerda = no;

        Node* baix = buscaBaixoNo(m, linha, coluna);
        no->baixo = baix;
        no->cima = baix->cima;
        baix->cima->baixo = no;
        baix->cima = no;
    }
    else
    {
        no->valor = valor;
    }
    return 1;
}

int matriz_acessar(Matriz* m, int linha, int coluna)
{
    if(m == NULL || linha >= m->numLinhas || coluna >= m->numColunas) return -1;

    Node* no = buscaNo(m, linha, coluna);
    if(no != NULL) return no->valor;

    return -1;
}

void matriz_imprimir(Matriz* m)
{
    printf("\nMatriz:\n");
    for(int i = 0; i < m->numLinhas; i++)
    {
        Node* aux = m->linhas[i]->direita;
        for(int j = 0; j < m->numColunas; j++)
        {
            if(aux->coluna != j) printf("|      |");
            else
            {
                printf("|  %d  |", aux->valor);
                aux = aux->direita;
            }
        }
        printf("\n");
    }
}

void matriz_desalocar(Matriz* m)
{
    if(m == NULL) return;

    for(int i = 0; i < m->numLinhas; i++)
    {
        Node* aux = m->linhas[i]->esquerda;
        while(aux != m->linhas[i])
        {
            Node* aux2 = aux->esquerda;
            free(aux);
            aux = aux2;
        }
        free(m->linhas[i]);
    }

    for(int i = 0; i < m->numColunas; i++)
    {
        free(m->colunas[i]);
    }

    free(m->linhas);
    free(m->colunas);
    free(m);
}

Node* buscaNo(Matriz* m, int linha, int coluna)
{
    int i = 0;
    Node* aux = m->linhas[linha]->direita;
    while(aux->coluna != coluna)
    {
        if(i >= m->numColunas) return NULL;

        aux = aux->direita;
        i++;
    }
    return aux;
}

Node* buscaProxNo(Matriz* m, int linha, int coluna)
{
    int i = 0;
    Node* aux = m->linhas[linha]->direita;
    while(aux->coluna <= coluna)
    {
        if(i >= m->numColunas) return m->linhas[linha];

        aux = aux->direita;
        i++;
    }
    return aux;
}

Node* buscaBaixoNo(Matriz* m, int linha, int coluna)
{
    int i = 0;
    Node* aux = m->colunas[coluna]->baixo;
    while(aux->linha <= linha)
    {
        if(i >= m->numLinhas) return m->colunas[coluna];
        
        aux = aux->baixo;
        i++;
    }
    return aux;
}

int main()
{
    Matriz* m = matriz_criar(4, 4);

    matriz_atribuir(m, 0, 1, 1);
    matriz_atribuir(m, 0, 3, 3);
    matriz_atribuir(m, 0, 2, 2);
    matriz_atribuir(m, 2, 1, 21);
    matriz_atribuir(m, 2, 3, 23);
    matriz_atribuir(m, 2, 2, 22);
    matriz_atribuir(m, 1, 1, 11);
    matriz_atribuir(m, 3, 3, 33);
    matriz_atribuir(m, 1, 2, 12);
    matriz_atribuir(m, 1, 2, 12);

    printf("%d\n", matriz_acessar(m, 1, 1));
    printf("%d\n", matriz_acessar(m, 2, 1));
    printf("%d\n", matriz_acessar(m, 0, 1));
    printf("%d\n\n", matriz_acessar(m, 1, 3));

    matriz_imprimir(m);

    matriz_desalocar(m);

    return 0;
}
