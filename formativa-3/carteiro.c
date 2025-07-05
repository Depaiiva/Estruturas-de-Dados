#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 45000

// Estrutura para representar pares (numero_da_casa, indice) para busca rápida
struct Par {
    long long numero;
    int indice;
};

int comparar(const void *a, const void *b) {
    long long x = ((struct Par*)a)->numero;
    long long y = ((struct Par*)b)->numero;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// Busca binária para encontrar o índice físico de uma casa
int busca_binaria(struct Par arr[], int N, long long numero) {
    int inicio = 0, fim = N-1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (arr[meio].numero == numero) {
            return arr[meio].indice;
        } else if (arr[meio].numero < numero) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    long long casas[MAXN];
    struct Par pares[MAXN];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &casas[i]);
        pares[i].numero = casas[i];
        pares[i].indice = i;
    }

    // Ordena para permitir busca binária por numero
    qsort(pares, N, sizeof(struct Par), comparar);

    long long total_distancia = 0;

    int indice_atual = 0;

    for (int i = 0; i < M; i++) {
        long long entrega;
        scanf("%lld", &entrega);

        int indice_entrega = busca_binaria(pares, N, entrega);
        total_distancia += abs(indice_entrega - indice_atual);
        indice_atual = indice_entrega;
    }

    printf("%lld\n", total_distancia);
    return 0;
}
