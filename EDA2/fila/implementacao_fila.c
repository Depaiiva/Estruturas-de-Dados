#include <stdio.h>
#include "fila.h"

int main(void){
    celula *f = cria_fila();
    for(int i = 0; i < 10; i++){
        f = enfileira(f, i);
    }
    imprimir(f);
    for(int i = 0; i < 6; i++){
        int a;
        desenfileira(f, &a);
    }
    imprimir(f);
    int b = destroi_fila(f);
    imprimir(f);
    printf("%d", b);
    return 0;
}