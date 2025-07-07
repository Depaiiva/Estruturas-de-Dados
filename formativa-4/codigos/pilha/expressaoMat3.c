#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 500

char op_pilha[MAX];
int topo_op = -1;

void push_op(char c) {
  op_pilha[++topo_op] = c;
}

char pop_op() {
  return op_pilha[topo_op--];
}

char topo_op_pilha() {
  return op_pilha[topo_op];
}

int vazia_op() {
  return topo_op == -1;
}

int precedencia(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

int associativa_dir(char op) {
  return op == '^';
}

int verificar_parenteses(char *expr) {
  int cont = 0;
  for (int i = 0; expr[i]; i++) {
    if (expr[i] == '(') cont++;
    else if (expr[i] == ')') cont--;
    if (cont < 0) return 0;
  }
  return cont == 0;
}

char posfixa[MAX * 2];
int pos = 0;

void infixa_para_posfixa(char *expr) {
  int n = strlen(expr);
  for (int i = 0; i < n; i++) {
    char c = expr[i];
    if (isalpha(c)) {
      posfixa[pos++] = c;
    }
    else if (c == '(') {
      push_op(c);
    }
    else if (c == ')') {
      while (!vazia_op() && topo_op_pilha() != '(') {
        posfixa[pos++] = pop_op();
      }
      if (!vazia_op()) pop_op();
    }
    else {
      while (!vazia_op() && topo_op_pilha() != '(') {
        char o2 = topo_op_pilha();
        int p1 = precedencia(c);
        int p2 = precedencia(o2);
        if ((associativa_dir(c) && p1 < p2) ||
            (!associativa_dir(c) && p1 <= p2)) {
          posfixa[pos++] = pop_op();
        } else {
          break;
        }
      }
      push_op(c);
    }
  }
  while (!vazia_op()) {
    posfixa[pos++] = pop_op();
  }
  posfixa[pos] = '\0';
}

int val_pilha[MAX];
int topo_val = -1;

void push_val(int x) {
  val_pilha[++topo_val] = x;
}

int pop_val() {
  return val_pilha[topo_val--];
}

int main() {
  char expr[MAX + 1];
  scanf("%s", expr);

  if (!verificar_parenteses(expr)) {
    printf("emf\n");
    return 0;
  }

  infixa_para_posfixa(expr);

  // Inicializar valores
  int valor[26] = {0};
  int lidos[26] = {0};

  char linha[20];
  while (scanf("%s", linha) != EOF) {
    char var = linha[0];
    int val;
    sscanf(linha + 2, "%d", &val);
    valor[var - 'A'] = val;
    lidos[var - 'A'] = 1;
  }

  for (int i = 0; posfixa[i]; i++) {
    char c = posfixa[i];
    if (isalpha(c)) {
      push_val(valor[c - 'A']);
    }
    else {
      int b = pop_val();
      int a = pop_val();
      int res = 0;
      if (c == '+') res = a + b;
      else if (c == '-') res = a - b;
      else if (c == '*') res = a * b;
      else if (c == '/') res = a / b;
      else if (c == '^') res = pow(a, b);
      push_val(res);
    }
  }

  printf("%d\n", pop_val());

  return 0;
}
