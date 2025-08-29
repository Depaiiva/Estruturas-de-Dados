#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

celula *cria_pilha(){
    celula *pilha = malloc(sizeof(celula));
    pilha->prox = NULL;
    pilha->dado = 0;
    return pilha;
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
    }
    printf("\n");
}