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
    if(raiz != NULL){
        em_ordem(raiz->left);
        printf("%d, ", raiz->dado);
        em_ordem(raiz->right);
    }
}

void pos_ordem(no *raiz){
    if (raiz != NULL) {
        pos_ordem(raiz->left);
        pos_ordem(raiz->right);
        printf("%d, ", raiz->dado);
    }
}

no *busca(no *raiz, int valor){
    if(raiz == NULL){
        printf("valor não encontrado\n");
        return NULL;
    }

    if(raiz->dado == valor){
        printf("valor %d encontrado na arvore no endereço %p\n", raiz->dado, raiz);
        return raiz;
    } else if(raiz->dado < valor){
        busca(raiz->right, valor);
    } else {
        busca(raiz->left, valor);
    }
}

no *max(no *raiz){
    if(raiz->right == NULL){
        printf("valor maximo é %d\n", raiz->dado);
        return raiz;
    }
    max(raiz->right);
}

no *min(no *raiz){
    if(raiz->left == NULL){
        printf("valor minimo é %d\n", raiz->dado);
        return raiz;
    }
    min(raiz->left);
}


void suc(no *raiz, int valor){
    no *possivel_valor = busca(raiz, valor);
    
    if(possivel_valor == NULL){
        printf("valor não encontrado na arvore\n");
        return;
    }
    
    if(possivel_valor == max(raiz)){
        printf("valor %d não possui sucessor.\n", valor);
        return;
    }


    if(possivel_valor->right != NULL){
        no *minimo_encontrado = min(possivel_valor->right);
        if(minimo_encontrado == possivel_valor){
            printf("sucessor de %d é %d.\n", valor, minimo_encontrado->dado);
            return;
        }
        printf("sucessor de %d é %d.\n", valor, minimo_encontrado->dado);
        return;
    } else {
        no *ancestral = raiz;
        if(raiz->dado < valor){
            no *alvo = raiz->right;
            while(alvo->dado != valor){
                ancestral = alvo;
                alvo = alvo->left;
            }
            printf("sucessor de %d é %d.\n", valor, ancestral->dado);
            return;
        } else {
            no *alvo = raiz->left;
            if(alvo->dado < valor){
                while(alvo->dado != valor){
                    alvo = alvo->right;    
                }
                printf("sucessor de %d é %d.\n", valor, ancestral->dado);
                return;
            } else {
                while(alvo->dado != valor){
                    ancestral = alvo;
                    alvo = alvo->left;
                }
                printf("sucessor de %d é %d.\n", valor, ancestral->dado);
                return;
            }
        }
    }
}
