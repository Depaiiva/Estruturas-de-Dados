#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

celula *cria_fila(){
    celula *cabeca = malloc(sizeof(celula));
    if(cabeca == NULL) return NULL;
    cabeca->prox = cabeca;
    return cabeca;
}

celula *enfileira(celula *antiga_cabeca, int x){
    celula *nova_cabeca = malloc(sizeof(celula));
    if(nova_cabeca == NULL || antiga_cabeca == NULL) return NULL;
    antiga_cabeca->dado = x;
    nova_cabeca->prox = antiga_cabeca->prox;
    antiga_cabeca->prox = nova_cabeca;
    return nova_cabeca;
}

int desenfileira(celula *cabeca, int *y){
    if(cabeca->prox == cabeca) return 1;
    celula *temp = cabeca->prox;
    cabeca->prox = temp->prox;
    *y = temp->dado;
    free(temp);
    return 0;
}

int destroi_fila(celula *cabeca){
    if(cabeca->prox == NULL || cabeca == NULL) return 1;
    celula *temp = cabeca->prox;
    celula *temp_next = temp->prox;
    while(temp != cabeca){
        free(temp);
        temp = temp_next;
        temp_next = temp_next->prox;
    }
    if(cabeca->prox == NULL){
        free(cabeca);
    }
    return 0;
}

void imprimir(celula *cabeca){
    if(cabeca == NULL || cabeca->prox == NULL) return NULL;
    celula *temp = cabeca->prox;
    celula *temp_next = temp->prox;
    while(temp != cabeca){
        if(temp_next != cabeca){
            printf("[%d]-> ", temp->dado);
        } else {
            printf("[%d]", temp->dado);
        }
        temp_next = temp_next->prox;
        temp = temp->prox;
    }
    printf("\n");
}