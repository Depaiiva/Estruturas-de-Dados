#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *criaPilha(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->prox = NULL;
    return cabeca;
}

celula *empilhamento(celula *cabeca, int dado){
    if(cabeca == NULL) return NULL;

    celula *novaCabeca = malloc(sizeof(celula));
    cabeca->dado = dado;
    novaCabeca->prox = cabeca;
    return novaCabeca;
}

celula *desempilha(celula *cabeca, int *y){
    if(cabeca == NULL) return NULL;

    celula *temp = cabeca->prox;
    *y = cabeca->prox->dado; // *y = temp->dado
    free(cabeca);
    return temp;
}

void destroiPilha(celula *cabeca){
    if(cabeca != NULL){
        destroiPilha(cabeca->prox);
    }
    free(cabeca);
}



void imprime(celula *cabeca){
    if(cabeca == NULL){
        printf("NULL\n");
        return;
    }
    celula *temp = cabeca->prox;
    while(temp != NULL){
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

int main(void){
    celula *p = criaPilha();
    p = empilhamento(p, 10);
    p = empilhamento(p, 20);
    p = empilhamento(p, 30);
    p = empilhamento(p, 40);
    p = empilhamento(p, 50);
    int y;
    imprime(p);
    printf("\n");
    p = desempilha(p, &y);
    imprime(p);
    printf("%d\n", y);
    printf("\n");
    int x;
    p = desempilha(p, &x);
    imprime(p);
    printf("%d\n", x);
    destroiPilha(p);
    imprime(p);
    return 0;
}