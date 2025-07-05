#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x){
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->dado = x;
    novaCelula->prox = le->prox;
    le->prox = novaCelula;
}

void insere_antes(celula *le, int x, int y){
    celula *anterior = le;
    celula *atual = le->prox;

    while(atual != NULL && atual->dado != y){
        anterior = atual;
        atual = atual->prox;
    }

    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->dado = x;

    if(atual == NULL){
        anterior->prox = novaCelula;
        novaCelula->prox = NULL;
        return;
    }

    novaCelula->prox = atual;
    anterior->prox = novaCelula;
}