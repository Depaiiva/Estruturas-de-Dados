# Quick Sort em C

O Quick Sort é um algoritmo eficiente de ordenação baseado em **Dividir para Conquistar**. Ele escolhe um pivô e particiona o vetor de forma que elementos menores ficam à esquerda e maiores à direita.

---

## 🧠 Ideia Principal

1. Escolher um pivô.
2. Colocar todos os menores à esquerda e os maiores à direita (particionamento).
3. Recursivamente aplicar o Quick Sort nas duas partes.

---

## 💻 Código em C

```c
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

---

## ⏱️ Complexidade

| Caso        | Complexidade |
|-------------|--------------|
| Melhor      | **O(n log n)** |
| Médio       | **O(n log n)** |
| Pior        | **O(n²)** (quando o pivô é sempre o pior possível) |

---

## 📊 Estabilidade e Memória

| Propriedade       | Detalhe |
|-------------------|---------|
| Estável           | ❌ Não |
| Uso de memória    | **O(log n)** de pilha recursiva |

---
