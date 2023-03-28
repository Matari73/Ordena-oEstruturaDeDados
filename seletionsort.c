#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void troca(int *x, int *y);
void selection(int vet[]);
void fill(int vet[]);
void imprime(int vet[]);

int main() {
  int vet[N];

  fill(vet);
  imprime(vet);
  selection(vet);
  imprime(vet);
}


void troca(int *x, int *y) {
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}

void fill(int vet[]) {
  int i;
  srand(time(NULL));
  for (i=0; i<N; i++) {
    vet[i] = rand() % 100;
  }
}

void imprime(int vet[]) {
  int i;
  for (i=0; i<N; i++) {
    printf("[%d]", vet[i]);
  }
  printf("\n");
}

void selection(int vet[]) {
  int i, j, min;

  for (i=0; i<N; i++) {
    min = i;
    for (j=i+1; j<N; j++) {
      if (vet[j] < vet[min]) {
        min = j;
      }
    }
    troca(&vet[min], &vet[i]);
  }
}
