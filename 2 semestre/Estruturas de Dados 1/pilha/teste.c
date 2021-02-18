#include<stdio.h>
#include "Pilha_encadeada.h"



void teste1(){
    Pilha* p = pilha_criar();
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_imprimir(p); // [30,20,10] (topo -> base)
}

int main(){
    teste1();
}
