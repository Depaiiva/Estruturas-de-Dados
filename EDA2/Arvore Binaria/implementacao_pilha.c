#include <stdio.h>
#include "pilha/pilha.h"

int main(void){
    celula *p = cria_pilha();
    for(int i = 0; i < 11; i++){
        empilha(p, &i);
    }
    imprimir_pilha(p);
    return 0;
}