#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dado;
    int topo;
    int N;
}pilha;

pilha *criaPilha(int N){
    pilha *p = malloc(N*sizeof(int));
    p->N = N;
    p->topo = 0;
    return p;
}

int empilha(pilha *p, int x){
    if(p->topo == p->N){
        p->dado = realloc(p->dado, 2*p->N*sizeof(int));
        if(p->dado == NULL) return 1;
        p->N = p->N*2;
    }
    p->dado[p->topo] = x;
    p->topo++;
    return 0;
}

int desempilha(pilha *p, int *y){
    if(p->topo == 0) return 1;
    p->topo--;
    *y = p->dado[p->topo];
    return 0;
}

void destroiPilha(pilha *p){
    free(p->dado);
    free(p);
}