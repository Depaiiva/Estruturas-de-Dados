#include <stdio.h>

#define MAX 100000

int fila[MAX];
int frente = 0;
int fim = 0;
int tam = 0;

void enfileira(int x) {
    fila[fim] = x;
    fim = (fim + 1) % MAX;
    tam++;
}

int desenfileira() {
    int x = fila[frente];
    frente = (frente + 1) % MAX;
    tam--;
    return x;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        enfileira(i);
    }

    printf("Cartas descartadas:");

    int primeiro = 1;
    while (tam > 1) {
        int descartada = desenfileira();
        if (primeiro) {
            printf(" %d", descartada);
            primeiro = 0;
        } else {
            printf(", %d", descartada);
        }

        int proxima = desenfileira();
        enfileira(proxima);
    }

    printf("\nCarta restante: %d\n", desenfileira());

    return 0;
}
