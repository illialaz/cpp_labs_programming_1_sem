#include <stdio.h>
#include <string.h>

int main(void){
  char* str;
  printf("Enter your string\n");
  gets(str);
  char* pch = strtok(str, " ");
  int count;
  for(count = 0; pch[count] != '\0'; count++);
  printf("Number of elements before the first space is %d\n", count);
  return 0;
}
