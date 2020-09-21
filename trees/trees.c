#include <stdio.h>
#include <locale.h>
#include "trees.h"

int main () {
  setlocale(LC_ALL, "Portuguese");
  TAB *a0 = inicializar ();
  TAB *a5 = criar (5, NULL, NULL);
  TAB *a6 = criar (6, NULL, NULL);
  TAB *a7 = criar (7, NULL, NULL);
  TAB *a8 = criar (8, NULL, NULL);
  TAB *a9 = criar (9, NULL, NULL);
  TAB *a4 = criar (4, a8, a9);
  TAB *a2 = criar (2, a4, a5);
  TAB *a3 = criar (3, a6, a7);
  TAB *a1 = criar (1, a2, a3);

  if (vazia(a1)) {
    printf ("Árvore Vazia\n");
  }
  else {
    printf ("Árvore não Vazia com valor igual a: %d\n\n", a1->info);
  }

  printf ("Percurso em pré ordem\n");
  pre_ordem (a1);
  printf ("\n+++++++++++++++++++++++++\n\n");

  printf ("Percurso em pós ordem\n");
  pos_ordem (a1);
  printf ("\n+++++++++++++++++++++++++\n\n");

  printf ("Percurso em ordem simétrica\n");
  ordem_simetrica (a1);
  printf ("\n+++++++++++++++++++++++++\n\n");

  printf ("Quantidade de folhas: %d\n", cf (a3));

  // liberar (a1);

  return 0;
}