#include <stdio.h>
#include <stdlib.h>

#define MAXK 100

long long heap[MAXK];
int heap_size = 0;

// Função para trocar dois elementos no heap
void troca(long long *a, long long *b) {
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}

// Sobe o elemento no heap (max-heap) a partir do índice i
void sift_up(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[i] > heap[p]) {
            troca(&heap[i], &heap[p]);
            i = p;
        } else {
            break;
        }
    }
}

// Desce o elemento no heap (max-heap) a partir do índice i
void sift_down(int i) {
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int maior = i;
        if (l < heap_size && heap[l] > heap[maior]) {
            maior = l;
        }
        if (r < heap_size && heap[r] > heap[maior]) {
            maior = r;
        }
        if (maior != i) {
            troca(&heap[i], &heap[maior]);
            i = maior;
        } else {
            break;
        }
    }
}

// Insere uma nova placa x no max-heap de tamanho até MAXK
void heap_insert(long long x) {
    if (heap_size < MAXK) {
        // ainda há espaço: insere e sobe
        heap[heap_size] = x;
        sift_up(heap_size);
        heap_size++;
    } else {
        // heap cheio com as 100 menores até agora; se x < raiz (máximo das 100 menores),
        // substitui raiz e reequilibra
        if (x < heap[0]) {
            heap[0] = x;
            sift_down(0);
        }
        // caso contrário, x é maior que as 100 menores atuais: descarta
    }
}

// Comparador para qsort, ordem ascendente
int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int op;
    // total de inserções não é armazenado: a lógica do heap já lida com quantidade > 100
    // Apenas para saber se inserimos menos de 100 placas até agora: heap_size reflete isso.

    // Ler até EOF
    while (scanf("%d", &op) == 1) {
        if (op == 1) {
            long long p;
            if (scanf("%lld", &p) != 1) break;
            heap_insert(p);
        } else if (op == 2) {
            int t;
            if (scanf("%d", &t) != 1) break;
            // Se nunca inseriu nada, nada a imprimir: mas conforme enunciado, provavelmente não ocorre.
            if (heap_size == 0) {
                printf("\n");
                continue;
            }
            // Copia heap para vetor temporário
            int atual = t;
            if (atual > heap_size) atual = heap_size;
            long long temp[MAXK];
            for (int i = 0; i < heap_size; ++i) {
                temp[i] = heap[i];
            }
            // Ordena ascendente até heap_size; depois imprimimos os 'atual' primeiros
            qsort(temp, heap_size, sizeof(long long), cmp_ll);
            for (int i = 0; i < atual; ++i) {
                printf("%lld", temp[i]);
                if (i < atual - 1) printf(" ");
            }
            printf("\n");
        } else {
            // operação desconhecida: pode ignorar ou parar
        }
    }
    return 0;
}
