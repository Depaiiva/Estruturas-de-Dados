#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    if (l == NULL || l1 == NULL || l2 == NULL) return;

    celula *atual = l->prox;
    celula *proxima;
    celula *fim1 = l1;
    celula *fim2 = l2;

    while (atual != NULL) {
        proxima = atual->prox;
        atual->prox = NULL;

        if (atual->dado % 2 == 0) {
            fim2->prox = atual;
            fim2 = atual;
        } else {
            fim1->prox = atual;
            fim1 = atual;
        }

        atual = proxima;
    }
}