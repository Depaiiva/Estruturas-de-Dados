#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
  celula *novo = malloc(sizeof(celula));
  if (novo == NULL) return NULL;
  novo->dado = x;
  novo->prox = NULL;

  if (f == NULL) {
    return novo;
  }

  celula *p = f;
  while (p->prox != NULL) {
    p = p->prox;
  }
  p->prox = novo;

  return f;
}
