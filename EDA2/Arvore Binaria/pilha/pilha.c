#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

celula *cria_pilha(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->prox = NULL;
    return cabeca;
}

int empilha(celula *cabeca, int *x){
    celula *novaCelula = malloc(sizeof(celula));
    if(novaCelula == NULL) return 1;
    novaCelula->dado = *x;
    novaCelula->prox = cabeca->prox;
    cabeca->prox = novaCelula;
    return 0;
}

int desempilha(celula *cabeca, int *y){
    if(cabeca->prox == NULL) return 1;
    celula *temp = cabeca->prox;
    *y = temp->dado;
    cabeca->prox = temp->prox;
    free(temp);
    return 0;
}

void destroi_pilha(celula *cabeca){
    celula *temp = cabeca->prox;
    while(temp != NULL){
        celula *temp2 = temp;
        temp = temp->prox;
        free(temp2);
    }
    free(cabeca);
}

void imprimir_pilha(celula *cabeca){
    celula *temp = cabeca->prox;
    while(temp != NULL){
        printf("[%d]->", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void imprimir_formato_pilha(celula *cabeca){
    celula *temp = cabeca->prox;
    while(temp != NULL){
        printf("|[%d]|\n", temp->dado);
        temp = temp->prox;
    }
    printf("[NULL]\n");
}