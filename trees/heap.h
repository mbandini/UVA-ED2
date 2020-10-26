#include <stdio.h>

int pai (int indice) {
  return indice / 2;
}

int esquerda (int indice) {
  return indice * 2;
}

int direita (int indice) {
  return (indice * 2) + 1;
}

void max_heapfy (int *v, int n, int pos) {
  int maior = pos;
  int e = esquerda(pos);
  int d = direita(pos);

  if ((e <= n) && (v[e] > v[pos])) {
    maior = e;
  }

  if ((d <= n) && (v[d] > v[pos])) {
    maior = d;
  }

  if (maior != pos) {
    int temp = v[pos];
    v[pos] = v[maior];
    v[maior] = temp;
    max_heapfy(v, n, maior);
  }
}

void build_max_heap (int *v, int n) {
  int i;
  for (i = n/2; i >= 1; i--) {
    max_heapfy(v, n, i);
  }
}

void imprimir (int *v, int n) {
  int i;
  for (i = 1; i <= n; i++) {
    printf("%d   ", v[i]);
  }
  printf("\n\n");
}

// IMPLEMENTAR A FUNÇÃO HEAPSORT