#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}fila;

fila *criaFila(){
    fila *cabeca = malloc(sizeof(fila));
    if(cabeca == NULL) return NULL;
    cabeca->prox = cabeca;
    return cabeca;
}

fila *enfileira(fila *cabeca, int x){
    fila *novaCabeca = malloc(sizeof(fila));
    if(novaCabeca == NULL) return NULL;
    novaCabeca->prox = cabeca->prox;
    cabeca->prox = novaCabeca;
    cabeca->dado = x;
    return novaCabeca;
}