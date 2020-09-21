#include <stdio.h>
#include "trees.h"

int main () {
  TAB *a0 = inicializar ();
  TAB *a4 = criar (4, NULL, NULL);
  TAB *a5 = criar (5, NULL, NULL);
  TAB *a6 = criar (6, NULL, NULL);
  TAB *a7 = criar (7, NULL, NULL);
  TAB *a2 = criar (2, a4, a5);
  TAB *a3 = criar (3, a6, a7);
  TAB *a1 = criar (1, a2, a3);

  if (vazia(a1)) {
    printf ("Árvore Vazia\n");
  }
  else {
    printf ("Árvore não Vazia com valor igual a: %d\n", a1->info);
  }

  imprimir(a1);

  printf ("\n\nQuantidade de folhas: %d\n", cf (a1));

  // liberar (a1);

  return 0;
}