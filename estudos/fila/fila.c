#include <stdio.h>

typedef struct celula{
    int valor;
    struct celula *prox;
}fila;

fila *criaFila(){
    fila *f = malloc(sizeof(fila));
    f->prox = f;
    return f;
}

fila *enfileirar(fila *f, int x){
    fila *novo = malloc(sizeof(fila));
    novo->prox = f->prox;
    f->prox = novo;
    f->valor = x;
    return novo;
}

int desenfileira(fila *f, int *y){
    if(f->prox == f) return 1;
    *y = f->prox->valor;
    fila *lixo = f->prox;
    f->prox = lixo->prox;
    free(lixo);
    return 0;
}

int main(void){

    return 0;
}