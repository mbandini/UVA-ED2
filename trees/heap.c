#include "heap.h"
#define N 10

int main () {
  int v[11] = { -1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

  imprimir(v, N);

  build_max_heap(v, N);

  imprimir(v, N);

  // CHAMADA DA FUNÇAO HEAP SORT

  return 0;
}