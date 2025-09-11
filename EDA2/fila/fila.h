#ifndef FILA_H
#define FILA_H

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

celula *cria_fila();
celula *enfileira(celula *cabeca, int x);
int desenfileira(celula *cabeca, int *y);
int destroi_fila(celula *cabeca);
void imprimir(celula *cabeca);

#endif