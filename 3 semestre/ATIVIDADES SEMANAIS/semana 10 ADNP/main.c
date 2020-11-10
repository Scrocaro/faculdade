#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

char* caso(char *txt)
{
  FILE *arq = fopen(txt, "r");
  int tam;

  fseek(arq, 0, SEEK_END);
  tam = ftell(arq);
  fseek(arq, 0, SEEK_SET);

  char *texto = calloc(tam+1, sizeof(char));
  fgets(texto, tam+1, arq);

  return texto;
}

int main(int argc, char** argv)
{
  int L;
  if(argc == 1) 
    L = 3;

  L = atoi(argv[1]);

  printf("\n\n\n\n");
  char caso1[] = "case_100.txt";
  printf("%s\n", caso1);
  char *string1 = caso(caso1);
  printf("L = %d, r: %d\n", L, SubstringCountLenL(string1, L));

  printf("\n\n\n\n");
  char caso2[] = "case_1000.txt";
  printf("%s\n", caso2);
  char *string2 = caso(caso2);
  printf("L = %d, r: %d\n", L, SubstringCountLenL(string2, L));

  printf("\n\n\n\n");
  char caso3[] = "case_10000.txt";
  printf("%s\n", caso3);
  char *string3 = caso(caso3);
  printf("L = %d, r: %d\n", L, SubstringCountLenL(string3, L));

  printf("\n\n\n\n");
  char caso4[] = "case_50000.txt";
  printf("%s\n", caso4);
  char *string4 = caso(caso4);
  printf("L = %d, r: %d\n", L, SubstringCountLenL(string4, L));

  printf("\n\n\n\n");
  char caso5[] = "case_all.txt";
  printf("%s\n", caso5);
  char *string5 = caso(caso5);
  printf("L = %d, r: %d\n", L, SubstringCountLenL(string5, L));
  
  return 0;
}