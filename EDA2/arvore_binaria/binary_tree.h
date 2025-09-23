#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct no {
    int dado;
    struct no *left;
    struct no *right;
}no;

no *cria_raiz(int valor);
no *insercao(no *raiz, int valor);
no *busca(no *raiz, int valor);
no *remocao(no *raiz, int valor);

void pre_ordem(no *raiz);
void em_ordem(no *raiz);
void pos_ordem(no *raiz);

no *max(no *raiz);
no *min(no *raiz);

void suc(no *raiz, int valor);

#endif