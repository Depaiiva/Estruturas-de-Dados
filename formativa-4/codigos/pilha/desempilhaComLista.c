#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p == NULL || p->prox == NULL) return 0; // pilha vazia

    celula *remover = p->prox;
    *y = remover->dado;
    p->prox = remover->prox;
    free(remover);
    return 1;
}
