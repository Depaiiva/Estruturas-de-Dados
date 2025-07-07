#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define TAM 30

typedef struct {
    char cidades[MAX][TAM];
    int ini, fim;
} Fila;

void inicializa(Fila *f) {
    f->ini = 0;
    f->fim = 0;
}

int vazia(Fila *f) {
    return f->ini == f->fim;
}

void enfileira(Fila *f, char *s) {
    strcpy(f->cidades[f->fim++], s);
}

void desenfileira(Fila *f, char *dest) {
    strcpy(dest, f->cidades[f->ini++]);
}

char* frente(Fila *f) {
    return f->cidades[f->ini];
}

int tamanho(Fila *f) {
    return f->fim - f->ini;
}

int main() {
    Fila fila;
    char cidade[TAM];
    inicializa(&fila);

    while (scanf("%s", cidade) != EOF) {
        enfileira(&fila, cidade);
    }

    if (vazia(&fila)) return 0;

    char anterior[TAM];
    desenfileira(&fila, anterior);
    printf("%s\n", anterior);

    while (!vazia(&fila)) {
        int n = tamanho(&fila);
        int mudou = 0;

        for (int i = 0; i < n; i++) {
            char atual[TAM];
            desenfileira(&fila, atual);

            char ultima = anterior[strlen(anterior) - 1];
            char primeira = atual[0];

            if (!mudou && primeira != ultima) {
                printf("%s\n", atual);
                strcpy(anterior, atual);
                mudou = 1;
            } else {
                enfileira(&fila, atual);
            }
        }

        if (!mudou) {
            break;
        }
    }

    return 0;
}
