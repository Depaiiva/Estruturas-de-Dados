#include <stdio.h>
#include <string.h>

#define MAX 500

char pilha[MAX];
int topo = -1;

void push(char c) {
  pilha[++topo] = c;
}

char pop() {
  return pilha[topo--];
}

char topo_pilha() {
  return pilha[topo];
}

int vazia() {
  return topo == -1;
}

int precedencia(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

int associatividade_dir(char op) {
  return op == '^';
}

int verificar_parenteses(char *expr) {
  int cont = 0;
  for (int i = 0; expr[i]; i++) {
    if (expr[i] == '(') cont++;
    else if (expr[i] == ')') cont--;
    if (cont < 0) return 0; // fecha sem abrir
  }
  return cont == 0;
}

int main() {
  char expr[MAX + 1];
  scanf("%s", expr);

  if (!verificar_parenteses(expr)) {
    printf("incorretamente parentizada\n");
    return 0;
  }

  int n = strlen(expr);
  for (int i = 0; i < n; i++) {
    char c = expr[i];
    if (c >= 'A' && c <= 'Z') {
      printf("%c", c);
    }
    else if (c == '(') {
      push(c);
    }
    else if (c == ')') {
      while (!vazia() && topo_pilha() != '(') {
        printf("%c", pop());
      }
      if (!vazia()) pop(); // descarta '('
    }
    else { // operador
      while (!vazia() && topo_pilha() != '(') {
        char o2 = topo_pilha();
        int p1 = precedencia(c);
        int p2 = precedencia(o2);
        if ( (associatividade_dir(c) && p1 < p2) ||
             (!associatividade_dir(c) && p1 <= p2) ) {
          printf("%c", pop());
        } else {
          break;
        }
      }
      push(c);
    }
  }

  while (!vazia()) {
    printf("%c", pop());
  }
  printf("\n");

  return 0;
}
