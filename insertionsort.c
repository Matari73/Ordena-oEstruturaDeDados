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

void insertion(int vet[]) {
  int i, j;

  for (i = 1; i < N; i++) {
    for (j = i; j > 0 && vet[j - 1] > vet[j]; j--) {
      troca(&vet[j - 1], &vet[j]);
    }
  }
}

void insertion2(int vet[]) {
  int i, j, aux;

  for (i = 1; i < N; i++) {
    aux = vet[i];
    for (j = i - 1; j >= 0 && aux < vet[j]; j--) {
      vet[j + 1] = vet[j];
    }
    vet[j + 1] = aux;
  }
}

int main() {
  int vet[N];

  fill(vet);
  imprime(vet);
  insertion(vet);
  imprime(vet);
}
