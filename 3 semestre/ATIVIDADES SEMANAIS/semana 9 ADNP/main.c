#include <stdio.h>
#include "ab.h"

int main(int argc, char** argv)
{
  // CASO A
  AB *caso_a = NULL;

  AB_Inserir(&caso_a, 70);
  AB_Inserir(&caso_a, 39);
  AB_Inserir(&caso_a, 88);
  AB_Remover(&caso_a, 70);

  AB_Imprimir(caso_a, "caso_a.txt");

///////////////////////////////////////////////////////////

  // CASO B
  AB *caso_b = NULL;
  AB_Inserir(&caso_b, 10);
  AB_Inserir(&caso_b, 4);
  AB_Inserir(&caso_b, 20);
  AB_Inserir(&caso_b, 6);
  AB_Inserir(&caso_b, 2);
  AB_Inserir(&caso_b, 3);
  AB_Inserir(&caso_b, 5);
  AB_Inserir(&caso_b, 7);
  AB_Remover(&caso_b, 10);
  AB_Remover(&caso_b, 4);
  AB_Remover(&caso_b, 5);

  AB_Imprimir(caso_b, "caso_b.txt");

///////////////////////////////////////////////////////////

  // CASO C
  AB *caso_c = NULL;
  AB_Inserir(&caso_c, 30);
  AB_Inserir(&caso_c, 50);
  AB_Inserir(&caso_c, 40);
  AB_Inserir(&caso_c, 47);
  AB_Inserir(&caso_c, 15);
  AB_Inserir(&caso_c, 20);
  AB_Inserir(&caso_c, 25);
  AB_Inserir(&caso_c, 17);
  AB_Inserir(&caso_c, 19);
  AB_Inserir(&caso_c, 4);
  AB_Inserir(&caso_c, 7);
  AB_Inserir(&caso_c, 0);
  AB_Remover(&caso_c, 0);
  AB_Remover(&caso_c, 30);
  AB_Remover(&caso_c, 15);
  AB_Remover(&caso_c, 20);
  
  AB_Imprimir(caso_c, "caso_c.txt");

///////////////////////////////////////////////////////////
  
  return 0;
}