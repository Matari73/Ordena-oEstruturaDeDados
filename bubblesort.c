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

void bubble(int vet[]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N - 1; j++) {
      if (vet[j] > vet[j + 1]) {
        troca(&vet[j], &vet[j + 1]);
      }
    }
  }
}

void bubble2(int vet[]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N - 1 - i; j++) {
      if (vet[j] > vet[j + 1]) {
        troca(&vet[j], &vet[j + 1]);
      }
    }
  }
}

void bubble3(int vet[]) {
  int i, j, status = 1;
  for (i = 0; i < N && status; i++) {
    status = 0;
    for (j = 0; j < N - 1 - i; j++) {
      if (vet[j] > vet[j + 1]) {
        status = 1;
        troca(&vet[j], &vet[j + 1]);
      }
    }
  }
}

int main() {
  int vet[N];

  fill(vet);
  imprime(vet);
  bubble(vet);
  imprime(vet);
}
