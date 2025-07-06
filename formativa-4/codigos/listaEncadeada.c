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

void remove_depois(celula *p){
    if (p == NULL || p->prox == NULL) return;

    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
}

void remove_elemento(celula *le, int x){
    if(le == NULL || le->prox == NULL) return;

    celula *anterior = le;
    celula *atual = le->prox;
    while(atual != NULL && atual->dado != x){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL) return;
    anterior->prox = atual->prox;
    free(atual);
}

void remove_todos_elementos(celula *le, int x){
    celula *anterior = le;
    celula *atual = le->prox;
    while(atual != NULL){
        if(atual->dado == x){
            anterior->prox = atual->prox;
            free(atual);
            atual = anterior->prox; 
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

void mescla_listas(celula *l1, celula *l2, celula *l3){
    if(l1 == NULL || l2 == NULL) return;
    
    celula *p1 = l1->prox;
    celula *p2 = l2->prox;
    celula *p3 = l3;

    while(p1 != NULL && p2 != NULL){
        if(p1->dado <= p2->dado){
            p3->prox = p1;
            p1 = p1->prox;
        } else {
            p3->prox = p2;
            p2 = p2->prox;
        }
        p3 = p3->prox;
    }
    
    if(p1 != NULL){
        p3->prox = p1;
    } else {
        p3->prox = p2;
    }
    
}

void divide_lista(celula *l, celula *l1, celula *l2) {
    if (l == NULL || l1 == NULL || l2 == NULL) return;

    celula *atual = l->prox;
    celula *proxima;
    celula *fim1 = l1;
    celula *fim2 = l2;

    while (atual != NULL) {
        proxima = atual->prox;
        atual->prox = NULL;

        if (atual->dado % 2 == 0) {
            fim2->prox = atual;
            fim2 = atual;
        } else {
            fim1->prox = atual;
            fim1 = atual;
        }

        atual = proxima;
    }
}


int main(void){

    return 0;
}