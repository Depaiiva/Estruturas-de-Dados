#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *criaLista(){
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le;
}

int inserirDado(celula *le, int valor){
    if(le == NULL) return 1;

    celula *novaLe = malloc(sizeof(celula));
    if(novaLe == NULL) return 1;

    novaLe->dado = valor;
    novaLe->prox = NULL;
    
    celula *temp = le;
    while(temp->prox != NULL){
        temp = temp->prox;
    }

    temp->prox = novaLe;
    return 0;
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

void imprime_rec(celula *le){
    if(le == NULL || le->prox == NULL){
        printf("NULL\n");
        return;
    }
    
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
}

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

void insere_inicio(celula *le, int x){
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->dado = x;
    novaCelula->prox = le->prox;
    le->prox = novaCelula;
}

void insere_antes(celula *le, int x, int y){
    celula *anterior = le;
    celula *atual = le->prox;

    while(atual != NULL && atual->dado != y){
        anterior = atual;
        atual = atual->prox;
    }

    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->dado = x;

    if(atual == NULL){
        anterior->prox = novaCelula;
        novaCelula->prox = NULL;
        return;
    }

    novaCelula->prox = atual;
    anterior->prox = novaCelula;
}