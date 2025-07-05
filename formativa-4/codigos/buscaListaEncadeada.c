#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


celula *busca(celula *le, int x){
    celula *temp = le->prox;
    while(temp != NULL && temp->dado != x){
        temp = temp->prox;
    }

    if(temp == NULL){
        return NULL;
    }
    return temp;
}

celula *busca_rec(celula *le, int x){
    if(le == NULL) return NULL;
    celula *temp = le->prox;
    if(temp == NULL) return NULL;
    
    if(temp->dado == x) return temp;

    busca_rec(temp, x);
}