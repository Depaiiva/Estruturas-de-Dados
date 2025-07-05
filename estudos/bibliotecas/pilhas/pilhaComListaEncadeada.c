#include "pilhaComListaEncadeada.h"

no *criaNo(){
    no *p = malloc(sizeof(no));
    p->prox = NULL;
    return p;
}

int empilhar(no *cabeca, int valor){
    no *temp = cabeca->prox;
    no *novo = criaNo();
    if(novo == NULL) return 1;
    novo->dado = valor;
    cabeca->prox = novo;
    novo->prox = temp;
    return 0;
}


int *desempilhar(no *cabeca, int *y){
    if(cabeca == NULL || cabeca->prox == NULL)
    return 1;

    no *temp = cabeca->prox;
    *y = temp->dado;
    cabeca->prox = temp->prox;
    free(temp);
    return 0;
}

void destruir(no *cabeca){
    while(cabeca->prox != NULL){
        int y;
        desempilhar(cabeca, &y);
    }
    free(cabeca);
}

void imprimir(no *cabeca){
    if(cabeca == NULL || cabeca->prox == NULL){
        printf("ERRO");
        return;
    }
    no *temp = cabeca->prox;
    while(temp != NULL){
        printf("[%d]->", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}