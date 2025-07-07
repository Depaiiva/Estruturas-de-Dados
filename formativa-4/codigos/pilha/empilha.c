#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        int novoTamanho = p->N == 0 ? 1 : 2 * p->N;
        int *novo = realloc(p->dados, novoTamanho * sizeof(int));
        if (novo == NULL) return 0;

        p->dados = novo;
        p->N = novoTamanho;
    }
    p->dados[p->topo++] = x;
    return 1;
}
