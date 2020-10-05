#include <stdlib.h>
#include <stdio.h>

typedef struct abb
{
  int info;
  struct abb *esq, *dir;
} TABB;

TABB *inicializar()
{
  return NULL;
}

int vazia(TABB *a)
{
  return (a == NULL);
}

void imprimir_tabb(TABB *a)
{
  printf("<");
  if (!vazia(a))
  {
    imprimir_tabb(a->esq);
    printf("%d", a->info);
    imprimir_tabb(a->dir);
  }
  printf(">");
}

void liberar(TABB *a)
{
  if (!vazia(a))
  {
    liberar(a->esq);
    liberar(a->dir);
    free(a);
  }
}

TABB *inserir(TABB *a, int elem)
{
  if (!a)
  {
    TABB *novo = (TABB *)malloc(sizeof(TABB));
    novo->info = elem;
    // novo->esq = novo->dir = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
  }
  if (a->info == elem)
  {
    return a;
  }
  if (a->info > elem)
  {
    a->esq = inserir(a->esq, elem);
  }
  else
  {
    a->dir = inserir(a->dir, elem);
  }
  return a;
}

TABB *v2a (int *vet, int n) {
  if (n == 0) {
    return NULL;
  }

  TABB *a = inicializar();
  a = inserir(a, vet[n / 2]);

  a->esq = v2a(vet, n / 2);

  if (n % 2 == 0) {
    a->dir = v2a(&vet[n / 2 + 1], n / 2 - 1);
  }
  else {
    a->dir = v2a(&vet[n / 2 + 1], n / 2);
  }

  return a;
}

int buscar (TABB *a, int elem) {
  if (!a) {
    return 0;
  }
  if (a->info == elem) {
    return 1;
  }
  if (a->info > elem) {
    return buscar (a->esq, elem);
  }
  return buscar (a->dir, elem);
}