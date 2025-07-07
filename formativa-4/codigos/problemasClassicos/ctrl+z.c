#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 101

char pilha[MAX][LEN];
int topo = -1;

void push(char *str) {
  if (topo + 1 < MAX) {
    topo++;
    strcpy(pilha[topo], str);
  }
}

char* pop() {
  if (topo == -1) return NULL;
  return pilha[topo--];
}

int main() {
  char linha[LEN + 10];
  while (fgets(linha, sizeof(linha), stdin)) {
    linha[strcspn(linha, "\n")] = '\0';
    if (strncmp(linha, "inserir ", 8) == 0) {
      push(linha + 8);
    } else if (strcmp(linha, "desfazer") == 0) {
      char *res = pop();
      if (res == NULL) printf("NULL\n");
      else printf("%s\n", res);
    }
  }
  return 0;
}
