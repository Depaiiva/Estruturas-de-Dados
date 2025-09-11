#include <stdio.h>
#include "pilha.h"

int main(void){
    celula *p = cria_pilha();
    for(int i = 0; i < 11; i++){
        empilha(p, &i);
    }
    imprimir_formato_pilha(p);
    printf("------------------------\n");
    int y;
    desempilha(p, &y);
    imprimir_formato_pilha(p);
    printf("------------------------\n");
    int a = 10;
    empilha(p, &a);
    imprimir_formato_pilha(p);
    return 0;
}