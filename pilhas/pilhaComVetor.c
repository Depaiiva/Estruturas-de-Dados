#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int N;
    int topo;
} pilha;

pilha *criarPilha(int N){
    pilha *p = malloc(sizeof(pilha));
    p->dados = malloc(N * sizeof(int));
    p->N = N;
    p->topo = 0;
    return p;
}

int empilhar(pilha *p, int x){
    if(p->N == p->topo){
        p->dados = realloc(p->dados, 2 * p->N * sizeof(int));
        if(p->dados == NULL) return 1;
        p->N = 2*p->N;
    }
    p->dados[p->topo] = x;
    p->topo++;
    return 0;
}

int desempilhar(pilha *p, int *y){
    if(p->topo == 0) return 1;
    p->topo--;
    *y = p->dados[p->topo];
    return 0;
}

void detruir(pilha *p){
    free(p->dados);
    free(p);
}


int main(void){

    return 0;
}