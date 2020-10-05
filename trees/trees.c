#include <stdio.h>
#include <locale.h>
#include "trees.h"

int main () {
  setlocale(LC_ALL, "Portuguese");

  int resultado;
  TAB *result;
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

  resultado = buscar (a1, 27);
  if (!resultado) {
    printf ("Elemento não encontrado\n");
  }
  else {
    printf ("Elemento encontrado\n");
  }

  result = buscar_elem (a1, 10);
  if (resultado) {
    printf ("Resultado nó: %d\n", result->info);
  }
  else {
    printf ("Resultado nó: Não encontrado\n");
  }

  printf ("Liberando memória...\n");
  liberar (a1);
  printf ("Memória liberada\n");

  ordem_simetrica (a1);

  return 0;
}