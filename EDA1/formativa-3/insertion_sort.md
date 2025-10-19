# Ordenação por Inserção (Insertion Sort) em C

A ordenação por inserção é um dos algoritmos mais simples e intuitivos para ordenar uma lista de elementos. Ele funciona de forma semelhante a como organizamos cartas na mão: pegamos uma carta e inserimos ela no local correto em relação às cartas já ordenadas.

---

## 🧠 Ideia Principal

1. Dividimos o vetor em duas partes:
   - Parte ordenada (inicialmente só o primeiro elemento).
   - Parte não ordenada (todos os outros elementos).
2. Para cada elemento da parte não ordenada:
   - Guardamos ele em uma variável temporária.
   - Comparamos com os elementos da parte ordenada.
   - Deslocamos os elementos maiores para a direita.
   - Inserimos o elemento temporário na posição correta.

---

## 📌 Exemplo

Vetor inicial: **[5, 3, 4, 1, 2]**

| Iteração | Resultado Parcial          |
|----------|-----------------------------|
| 1        | [3, 5, 4, 1, 2]            |
| 2        | [3, 4, 5, 1, 2]            |
| 3        | [1, 3, 4, 5, 2]            |
| 4        | [1, 2, 3, 4, 5]            |

---

## 💻 Implementação em C

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Vetor ordenado: ");
    printArray(arr, n);

    return 0;
}
```

---

## ⏱️ Complexidade do Algoritmo

| Caso        | Complexidade |
|-------------|--------------|
| Melhor caso | **O(n)** (vetor já ordenado) |
| Médio caso  | **O(n²)** |
| Pior caso   | **O(n²)** (vetor ordenado de forma decrescente) |

---

## ✅ Vantagens
✔ Simples de entender e implementar  
✔ Bom para vetores pequenos  
✔ Estável (não troca a ordem de elementos iguais)

## ❌ Desvantagens
❌ Ineficiente para vetores grandes  
❌ Complexidade quadrática no pior caso

---

Se quiser, posso continuar com outros algoritmos como Selection Sort, Bubble Sort ou Merge Sort! 😉
