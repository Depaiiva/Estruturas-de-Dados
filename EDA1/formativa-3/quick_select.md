# Quick Select em C

O Quick Select é um algoritmo para encontrar o **k-ésimo menor elemento** de um vetor sem ordená-lo completamente. Ele é baseado no particionamento do Quick Sort.

---

##  Ideia Principal

1. Escolher um pivô.
2. Particionar o vetor ao redor do pivô.
3. Se a posição do pivô for igual a k, retornamos o valor.
4. Caso contrário, repetimos o processo apenas em um dos lados do vetor.

---

##  Complexidade

| Caso        | Complexidade |
|-------------|--------------|
| Melhor      | **O(n)** |
| Médio       | **O(n)** |
| Pior        | **O(n²)** |

---

##  Estabilidade e Memória

| Propriedade       | Detalhe |
|-------------------|---------|
| Estável           | ❌ Não |
| Uso de memória    | **O(log n)** (recursão) |

---
