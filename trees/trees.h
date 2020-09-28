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
/*
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
*/

void pre_ordem (TAB *a) {
  printf ("<");
  if (!vazia (a)) {
    printf ("%d", a->info);
    pre_ordem (a->esq);
    pre_ordem (a->dir);
  }
  printf (">");
}

void pos_ordem (TAB *a) {
  printf ("<");
  if (!vazia (a)) {
    pos_ordem (a->esq);
    pos_ordem (a->dir);
    printf ("%d", a->info);
  }
  printf (">");
}

void ordem_simetrica (TAB *a) {
  printf ("<");
  if (!vazia (a)) {
    ordem_simetrica (a->esq);
    printf ("%d", a->info);
    ordem_simetrica (a->dir);
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

int buscar (TAB *a, int elem) { // retorna 0 se o elemento não existe ou 1 caso contrário
  if (!a) {
    return 0;
  }
  return (elem == a->info) || buscar (a->esq, elem) || buscar (a->dir, elem);
}

// TODO: CORRIGIR ESTA FUNÇÃO
int buscar_elem (TAB *a, int elem) { // retorna 0 se o elemento não existe ou o elemento caso contrário
  if (!a) {
    return 0;
  }
  if (elem == a->info) {
    return a->info;
  }
  return buscar_elem (a->esq, elem) || buscar_elem (a->dir, elem);
}

void liberar (TAB *a) {
  if (!vazia(a)) {
    liberar (a->esq);
    liberar (a->dir);
    free (a);
  }
}