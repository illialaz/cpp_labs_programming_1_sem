#include <stdio.h>
#include <ctype.h>

int main(){
  char* str;
  gets(str);
  for(int i = 0; str[i] != '\0'; i++){
    str[i] = toupper(str[i]);
  }
  puts(str);
  return 0;
}
