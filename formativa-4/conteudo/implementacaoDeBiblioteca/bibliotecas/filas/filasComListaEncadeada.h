#ifndef FILASCOMLISTAENCADEADA_H
#define FILASCOMLISTAENCADEADA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;

no *criaNo();
no *enfileira(no *cabeca, int valor);
int desenfileira(no *cabeca, int *y);
void *destruir(no *cabeca);
void imprimir(no *cabeca);

#endif