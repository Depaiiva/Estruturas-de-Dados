#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}fila;

fila *criaFila(){
    fila *cabeca = malloc(sizeof(fila));
    if(cabeca == NULL) return NULL;
    cabeca->prox = cabeca;
    return cabeca;
}

fila *enfileira(fila *cabeca, int x){
    fila *novaCabeca = malloc(sizeof(fila));
    if(novaCabeca == NULL) return NULL;
    novaCabeca->prox = cabeca->prox;
    cabeca->prox = novaCabeca;
    cabeca->dado = x;
    return novaCabeca;
}

int desenfileira(fila *cabeca, int *y){
    if(cabeca->prox == cabeca) return 1;
    fila *temp = cabeca->prox;
    *y = temp->dado;
    cabeca->prox = temp->prox;
    free(temp);
    return 0;
}

void destroiFila(fila *cabeca){
    if(cabeca->prox == cabeca) return;
    fila *temp = cabeca->prox;
    int a;
    while(temp != cabeca){
        desenfileira(temp, &a);
    }
    free(cabeca);
}

void imprime(fila *f){
    fila *temp = f->prox;
    if(temp == f){
        return;
    }
    while(temp != f){
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("%d\n", f->prox->dado);
}

int main(void){
    fila *f = criaFila();
    for(int i = 0; i < 20; i++){
        f = enfileira(f, i * 10);
    }
    imprime(f);
    return 0;
}