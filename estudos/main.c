#include "bibliotecas/pilhas/pilhaComListaEncadeada.h"

int main(void){
    no *pilha = criaNo();
    empilhar(pilha, 10);
    imprimir(pilha);
    empilhar(pilha, 8);
    imprimir(pilha);
    empilhar(pilha, 70);
    imprimir(pilha);
    empilhar(pilha, 15);
    imprimir(pilha);
    int y;
    desimpilhar(pilha, &y);
    imprimir(pilha);
    desimpilhar(pilha, &y);
    imprimir(pilha);
    desimpilhar(pilha, &y);
    imprimir(pilha);
    return 0;
}