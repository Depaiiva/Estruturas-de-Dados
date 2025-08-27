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

int main() {
  char expr[MAX + 1];
  scanf("%s", expr);

  int ok = 1;
  int n = strlen(expr);

  for (int i = 0; i < n; i++) {
    char c = expr[i];
    if (c == '(' || c == '[' || c == '{') {
      push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (vazia()) {
        ok = 0;
        break;
      }
      char t = topo_pilha();
      if ((c == ')' && t == '(') ||
          (c == ']' && t == '[') ||
          (c == '}' && t == '{')) {
        pop();
      } else {
        ok = 0;
        break;
      }
    }
  }

  if (!vazia()) ok = 0;

  if (ok) printf("sim\n");
  else printf("nao\n");

  return 0;
}
