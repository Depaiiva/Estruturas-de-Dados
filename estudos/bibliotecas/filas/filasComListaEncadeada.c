#include "filasComListaEncadeada.h"

no *criaNo(){
    no *fila = malloc(sizeof(no));
    if(fila == NULL) return NULL;
    fila->prox = fila;
    return fila;
}

no *enfileira(no *cabeca, int valor){
    //criação da nova cabeça
    no *novacabeca = malloc(sizeof(no));
    if(novacabeca == NULL) return NULL;

    // fazendo que a nova cabeça aponte para o inicio da fila
    novacabeca->prox = cabeca->prox;

    // o cabeça antigo se torne o final da fila
    cabeca->valor = valor;

    // o cabeça antigo aponte para a nova cabeça que é o final da fila
    cabeca->prox = novacabeca;
    return novacabeca;
}

int desenfileira(no *cabeca, int *y){
    if(cabeca == NULL) return 1;
    no *temp = cabeca->prox;
    *y = temp->valor;
    cabeca->prox = temp->prox;
    free(temp);
    return 0;
}

void *destruir(no *cabeca){
    if(cabeca == NULL) return NULL;
    int y;
    while(cabeca->prox != cabeca){
        desenfileira(cabeca, &y);
    }
    free(cabeca);
    return NULL;
}

void imprimir(no *cabeca) {
    if(cabeca == NULL || cabeca->prox == cabeca){
        printf("PILHA VAZIA\n");
        return;   
    }
    no *temp = cabeca->prox; // Começa do primeiro elemento da fila
    while (temp != cabeca) {
        printf("[%d]->", temp->valor);
        temp = temp->prox;
    }
    printf("[%d]\n", cabeca->prox->valor);
}
