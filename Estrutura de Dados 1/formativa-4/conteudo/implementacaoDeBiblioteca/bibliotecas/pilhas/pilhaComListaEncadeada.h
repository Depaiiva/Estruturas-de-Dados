#ifndef PILHACOMLISTAENCADEADA_H
#define PILHACOMLISTAENCADEADA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no* prox;
}no;

no *criaNo();
int empilhar(no *cabeca, int valor);
int *desempilhar(no *cabeca, int*y);
void destruir(no *cabeca);
void imprimir(no *cabeca);

#endif