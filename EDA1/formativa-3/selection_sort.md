# Ordenação por Seleção (Selection Sort) em C

A ordenação por seleção é um algoritmo simples de ordenação que divide o vetor em duas partes: a parte ordenada e a parte não ordenada. A cada iteração, o menor (ou maior) elemento da parte não ordenada é selecionado e trocado com o primeiro elemento desta parte.

---

## 🧠 Ideia Principal

1. Percorra o vetor e encontre o menor elemento.
2. Troque o menor elemento com o primeiro elemento do vetor.
3. Repita o processo para o restante do vetor, começando da posição seguinte.
4. Ao final, o vetor estará ordenado.

---

## 📌 Exemplo

Vetor inicial: **[5, 3, 4, 1, 2]**

| Iteração | Resultado Parcial         | Menor Elemento |
|----------|-----------------------------|----------------|
| 1        | [1, 3, 4, 5, 2]             | 1              |
| 2        | [1, 2, 4, 5, 3]             | 2              |
| 3        | [1, 2, 3, 5, 4]             | 3              |
| 4        | [1, 2, 3, 4, 5]             | 4              |

---

## 💻 Implementação em C

```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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

    selectionSort(arr, n);

    printf("Vetor ordenado: ");
    printArray(arr, n);

    return 0;
}
```

---

## ⏱️ Complexidade do Algoritmo

| Caso        | Complexidade |
|-------------|--------------|
| Melhor caso | **O(n²)** |
| Médio caso  | **O(n²)** |
| Pior caso   | **O(n²)** |

---

## ✅ Vantagens
✔ Fácil de entender e implementar  
✔ Não precisa de memória extra  
✔ Pouco número de trocas

## ❌ Desvantagens
❌ Ineficiente para grandes conjuntos de dados  
❌ Sempre realiza O(n²) comparações, independentemente da entrada  
❌ Instável (pode mudar a ordem de elementos iguais)

---

Se quiser, posso continuar com Bubble Sort, Merge Sort, Quick Sort ou até gerar um PDF com todos os algoritmos! 😄
