#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *criaPilha(){
    celula *cabeca = malloc(sizeof(celula));
    if(cabeca == NULL) return NULL;
    cabeca->prox = NULL;
    return cabeca;
}

int empilha(celula *cabeca, int dado){
    if(cabeca == NULL) return 1;

    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->dado = dado;
    novaCelula->prox = cabeca->prox;
    cabeca->prox = novaCelula;
    return 0;
}

int desempilha(celula *cabeca, int *y){
    if(cabeca == NULL || cabeca->prox == NULL) return 1;

    celula *temp = cabeca->prox;
    *y = temp->dado;
    cabeca->prox = temp->prox;
    free(temp);
    return 0;
}