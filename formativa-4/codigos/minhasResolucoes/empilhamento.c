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

void imprime(celula *le){
    if(le == NULL){
        printf("NULL\n");
        return;
    }
    celula *temp = le->prox;
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
    imprime(p);
    return 0;
}