#include <stdio.h>
#include <string.h>

int main(void){
  char* str;
  printf("Enter your string\n");
  gets(str);
  char* pch = strtok(str, ".");
  int count = 0;
  for(int i = 0; pch[i] != '\0'; i++){
    printf("%c", pch[i]);
  }
  printf("\n");
  for(int i = 0; pch[i] != '\0'; i++){
    if(pch[i] >= 'a' && pch[i] <= 'z'){
      count++;
    }
  }
  printf("Number of lower letters before the first dot is %d\n", count);
  return 0;
}
