#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

no *cria_raiz(int valor){
    no *raiz = malloc(sizeof(no));
    if(raiz == NULL) return NULL;
    raiz->dado = valor;
    raiz->left = NULL;
    raiz->right = NULL;
    return raiz;
}

no *insercao(no *raiz, int valor){
    if(raiz == NULL){
        return cria_raiz(valor);
    }

    if(valor < raiz->dado){
        raiz->left = insercao(raiz->left, valor);
    } else if(valor > raiz->dado){
        raiz->right = insercao(raiz->right, valor);
    }

    return raiz;
}

void pre_ordem(no *raiz){
    if(raiz != NULL){
        printf("%d, ", raiz->dado);
        pre_ordem(raiz->left);
        pre_ordem(raiz->right);
    }

}

void em_ordem(no *raiz){
    if(raiz->left == NULL){
        printf("%d, ", raiz->dado);
    } else {
        em_ordem(raiz->left);
        printf("%d, ", raiz->dado);
        if(raiz->right != NULL){
            em_ordem(raiz->right);
        }
    }
}

void pos_ordem(no *raiz){
    if(raiz->left == NULL && raiz->right == NULL){
        printf("%d, ", raiz->dado);
        return;
    }

    if(raiz->left != NULL){
        pos_ordem(raiz->left);
    }

    if(raiz->left != NULL){
        pos_ordem(raiz->right);
    }

    printf("%d, ", raiz->dado);
}