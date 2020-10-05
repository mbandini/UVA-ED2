/*
EXERCÍCIO:
1) Desenvolver o programa tabb.c de maneira a criar a árvore binária de busca usada nos exemplos do slide.

2) Aplicar a funçao de imprimir a árvore binária de busca.

3) Criar e aplicar corretamente uma função de busca em uma árvore binária de busca.

4) (Desafio) Retornar uma ABB a partir de um vetor ordenado (TABB *v2a (int *vet, int n);)

Exemplo: [1, 2, 3, 4, 5, 6, 7, 8]
          5
        /   \
       3     7
      / \   / \
     2   4 6   8
    /
   1

Exemplo: [1, 2, 3, 4, 5, 6, 7, 8, 9]
          5
        /   \
       3     8
      / \   / \
     2   4 7   9
    /     /
   1     6
Dica: Dividir o vetor e pegar o elemento mais próximo do meio
*/

#include <stdio.h>
#include <locale.h>
#include "tabb.h"
#define N 7
#define M 8
#define P 9

int main () {
  setlocale(LC_ALL, "Portuguese");
  int vetor1[N] = {1, 2, 3, 4, 5, 6, 7};
  int vetor2[M] = {1, 2, 3, 4, 5, 6, 7, 8};
  int vetor3[P] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  TABB *newabb1 = v2a (vetor1, N);
  TABB *newabb2 = v2a (vetor2, M);
  TABB *newabb3 = v2a (vetor3, P);

  imprimir_tabb (newabb1);
  printf ("\n+++++++++++++++++++\n");
  imprimir_tabb (newabb2);
  printf ("\n+++++++++++++++++++\n");
  imprimir_tabb (newabb3);
  printf ("\n+++++++++++++++++++\n");

  printf ("Buscar pelo 8 na árvore 1: %d\n", buscar (newabb1, 8)); // retornar 0
  printf ("Buscar pelo 7 na árvore 2: %d\n", buscar (newabb2, 7)); // retornar 1
  printf ("Buscar pelo 9 na árvore 3: %d\n", buscar (newabb3, 9)); // retornar 1
  printf ("Buscar pelo -1 na árvore 3: %d\n", buscar (newabb3, -1)); // retornar 0

  return 0;
}