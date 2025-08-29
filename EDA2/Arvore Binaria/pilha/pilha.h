#ifndef PILHA_H
#define PILHA_H

typedef struct celula {
    int dado;
    struct celula *prox;
}celula;

celula *cria_pilha();
int empilha(celula *cabeca, int *x);
int desempilha(celula *cabeca, int *y);
void destroi_pilha(celula *cabeca);
void imprimir_pilha(celula *cabeca);

#endif