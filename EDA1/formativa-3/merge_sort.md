# Merge Sort em C

O Merge Sort é um algoritmo baseado na técnica **Dividir para Conquistar (Divide and Conquer)**. Ele divide o vetor em duas partes, ordena cada metade recursivamente e depois faz a mesclagem (**merge**) das partes ordenadas.

---

## 🧠 Ideia Principal

1. Dividir o vetor ao meio recursivamente até que cada parte tenha apenas um elemento.
2. Mesclar (merge) as duas metades de forma ordenada.
3. Repetir o processo até reconstruir o vetor completamente ordenado.

---

## 💻 Código em C

```c
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

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
| Pior        | **O(n log n)** |

---

## 📊 Estabilidade e Memória

| Propriedade       | Detalhe |
|-------------------|---------|
| Estável           | ✔ Sim |
| Uso de memória    | Usa memória extra (**O(n)**) |

---
