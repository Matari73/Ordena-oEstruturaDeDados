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

int partition(int vet[], int left, int right) {
  int i, j, pivo;

  pivo = vet[left];
  i = left + 1;
  for (j = i; j <= right; j++) {
    if (vet[j] < pivo) {
      troca(&vet[j], &vet[i]);
      i++;
    }
  }
  troca(&vet[left], &vet[i - 1]);
  return i - 1;
}

int partition1(int vet[], int left, int right) {
  int i = left, j = right - 1;
  troca(&vet[left + ((right - left) / 2)], &vet[right]);
  while (i <= j) {
    while (vet[i] <= vet[right] && i < right) {
      i++;
    }
    while (vet[j] > vet[right] && j >= left) {
      j--;
    }
    if (i < j) {
      troca(&vet[i], &vet[j]);
    }
  }
  troca(&vet[i], &vet[right]);
  return i;
}

void quicksort(int vet[], int left, int right) {
  // https://www.hackerearth.com/pt-br/practice/algorithms/sorting/quick-sort/visualize/
  int pivot;
  if (left >= right) {
    return;
  }

  pivot = partition(vet, left, right);
  quicksort(vet, left, pivot - 1);
  quicksort(vet, pivot + 1, right);
}

int main() {
  int vet[N];

  fill(vet);
  imprime(vet);
  quicksort(vet, 0, N - 1);
  imprime(vet);
}
