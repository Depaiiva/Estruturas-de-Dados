#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


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

void imprime_rec(celula *le){
    if(le == NULL || le->prox == NULL){
        printf("NULL\n");
        return;
    }
    
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
}