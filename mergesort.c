#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void troca(int *x, int *y) {
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}

void fill(int vet[]) {
  int i;
  srand(time(NULL));
  for (i = 0; i < N; i++) {
    vet[i] = rand() % 100;
  }
}

void imprime(int vet[]) {
  int i;
  for (i = 0; i < N; i++) {
    printf("[%d]", vet[i]);
  }
  printf("\n");
}

void merge(int vet[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = 0;
  int n = (right - left) + 1;
  int *vaux = (int *)malloc(n * sizeof(int));

  while (i <= mid && j <= right) {
    if (vet[i] < vet[j]) {
      vaux[k++] = vet[i++];
    } else {
      vaux[k++] = vet[j++];
    }
  }

  // Copia os elementos restantes da primeira parte
  while (i <= mid) {
    vaux[k++] = vet[i++];
  }

  // Copia os elementos restantes da segunda parte
  while (j <= right) {
    vaux[k++] = vet[j++];
  }

  for (k = 0, i = left; k < n; i++, k++) {
    vet[i] = vaux[k];
  }

  free(vaux);
}

void mergesort(int vet[], int left, int right) {
  int mid;
  if (left >= right) {
    return;
  }

  mid = (left + right) / 2;
  mergesort(vet, left, mid);
  mergesort(vet, mid + 1, right);
  merge(vet, left, mid, right);
}

int main() {
  int vet[N];

  fill(vet);
  imprime(vet);
  mergesort(vet, 0, N - 1);
  imprime(vet);
}
