#include <stdlib.h>

typedef struct AB {
  int info;
  struct AB *esq, *dir;
}TAB;

TAB *inicializar () {
  return NULL;
}

int vazia (TAB *A) {
  return (A == NULL);
}

TAB *criar (int r, TAB *e, TAB *d) {
  TAB *novo = (TAB *) malloc(sizeof(TAB));
  novo->info = r;
  novo->esq = e;
  novo->dir = d;
  return novo;
}

void imprimir (TAB *A) {
  printf ("< ");
  if (!vazia (A)) {
    printf ("%d ", A->info);
    if ((!vazia (A->esq)) || (!vazia(A->dir))) {
      imprimir (A->esq);
      imprimir (A->dir);
    }
  }
  printf (">");
}

int cf (TAB *a) {
	if (!a)
		return 0;
	if ((!a->esq) && (!a->dir))
		return 1;
	return cf (a->esq) + cf (a->dir);
}