#include <stdlib.h>

typedef struct AB
{
  int info;
  struct AB *esq, *dir;
} TAB;

TAB *inicializar()
{
  return NULL;
}

int vazia(TAB *A)
{
  return (A == NULL);
}

TAB *criar(int r, TAB *e, TAB *d)
{
  TAB *novo = (TAB *)malloc(sizeof(TAB));
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

void pre_ordem(TAB *a)
{
  printf("<");
  if (!vazia(a))
  {
    printf("%d", a->info);
    pre_ordem(a->esq);
    pre_ordem(a->dir);
  }
  printf(">");
}

void pos_ordem(TAB *a)
{
  printf("<");
  if (!vazia(a))
  {
    pos_ordem(a->esq);
    pos_ordem(a->dir);
    printf("%d", a->info);
  }
  printf(">");
}

void ordem_simetrica(TAB *a)
{
  printf("<");
  if (!vazia(a))
  {
    ordem_simetrica(a->esq);
    printf("%d", a->info);
    ordem_simetrica(a->dir);
  }
  printf(">");
}

int cf(TAB *a)
{
  if (!a)
    return 0;
  if ((!a->esq) && (!a->dir))
    return 1;
  return cf(a->esq) + cf(a->dir);
}

int buscar(TAB *a, int elem)
{ // retorna 0 se o elemento não existe ou 1 caso contrário
  if (!a)
  {
    return 0;
  }
  return (elem == a->info) || buscar(a->esq, elem) || buscar(a->dir, elem);
}

// TODO: CORRIGIR ESTA FUNÇÃO
TAB *buscar_elem(TAB *a, int elem) {
  if (!a)
  {
    return NULL;
  }
  if (elem == a->info)
  {
    return a;
  }

  TAB *e = buscar_elem(a->esq, elem);
  if (!e) {
    e = buscar_elem(a->dir, elem);
  }
  return e;
}

void liberar(TAB *a)
{
  if (!vazia(a))
  {
    liberar(a->esq);
    liberar(a->dir);
    free(a);
  }
}

// Q1
int igual (TAB *a1, TAB *a2) { //0 = diferente | 1 = igual
	if ((!a1) && (!a2)) // nenhuma das árvores existe (iguais)
		return 1;
	if ((!a1) || (!a2)) // apenas uma das árvores existe (diferentes)
		return 0;
	if (a1->info == a2->info) // recursividade para avaliar amabas as sub-árvores (se iguais, retorna 1)
		return igual (a1->esq, a2->esq) && igual (a1->dir, a2->dir);
	return 0; // sub-árvores diferentes (retorna 0)
}
// Complexidade assintótica de pior caso da função igual => O(n) - linear

// Q2
TAB* copia (TAB *a) {
	if (!a)
		return NULL;
	else {
		TAB *c = criar (a->info, a->esq, a->dir);
		if (!vazia (a->esq) || (!vazia (a->dir))) { // se pelo menos uma sub-árvore nao for vazia
			copia (a->esq);
			copia (a->dir);
		}
		return c;
	}
}
// Complexidade assintótica de pior caso da função copia => O(n) - linear

// Q3
int conta_pais_um_filho (TAB *a) {
	if (!a)
		return 0;
	if ((vazia (a->esq)) && (!vazia (a->dir))) // se tem apenas sub-árvore à esquerda
		return 1 + conta_pais_um_filho(a->esq);  // conta do lado esquerdo
	if ((!vazia (a->esq)) && (vazia (a->dir))) // se tem apenas sub-árvore à direita
		return 1 + conta_pais_um_filho(a->dir);  // conta do lado direito
	return conta_pais_um_filho(a->esq) + conta_pais_um_filho(a->dir);  // tem sub-árvores em ambos os lados
}
// Complexidade assintótica de pior caso da função conta_pais_um_filho => O(n) - linear