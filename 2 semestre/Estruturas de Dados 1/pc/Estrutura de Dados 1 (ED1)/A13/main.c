#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"

Boolean ehPar(DataType* ptr){
  return (*ptr % 2 == 0 ? true : false);
}
Boolean ehImpar(DataType* ptr){
  return (*ptr % 2 == 0 ? false : true);
}

int compara(DataType* a, DataType* b){
  if(*a > *b) return 1;
  else if (*a < *b) return -1;
  else return 0;
}

int main(){
  Vetor* v2 = vetor_load("Vetor.bin");
  vetor_print("v2", v2); // [2,4]
  vetor_free(v2);

  Vetor* v = vetor_new();
  vetor_add(v, 5);
  vetor_add(v, 2);
  vetor_add(v, 4);
  vetor_add(v, 1);
  vetor_add(v, 3);
  vetor_save(v, "Vetor.bin");
  vetor_sort(v);
  vetor_print("v1", v); // [2,4]

  vetor_import(v, "vetor.txt");
  vetor_print("v1", v); // [2,4]
  vetor_free(v);
}
