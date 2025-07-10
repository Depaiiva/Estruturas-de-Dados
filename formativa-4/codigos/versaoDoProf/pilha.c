#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *criaPilha(){
    celula *pilha = malloc(sizeof(celula));
    pilha->prox = NULL;
    return pilha; // nó cabeça
}

int empilha(celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return 1; // pilha cheia
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
    return 0;
}

celula *desempilha(celula *p){
    if(p->prox == NULL) return NULL;

    celula *ret = p->prox;
    p->prox = ret->prox;
    return ret;
}