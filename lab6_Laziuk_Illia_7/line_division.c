#include <stdio.h>
#include <string.h>

int main(void){
  char str[] = "Это не баг, это фича.";
  printf("Разделение строки \"%s\" на лексемы", str);
  char* pch = strtok(str, " .,!?:;");
  printf("\nЛексемы:");
  while (pch != NULL) {
    printf("\n%s", pch);
    pch = strtok(NULL, " .,!?:;");
  }
  printf("\n");
  return 0;
}
