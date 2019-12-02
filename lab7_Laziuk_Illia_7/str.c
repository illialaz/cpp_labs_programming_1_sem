#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main(void){

  FILE* file = fopen ("input.txt", "r");
  FILE* result = fopen ("output.txt", "w");
  char str[100];
  int isAble = TRUE;
  if(!file){
    printf("Error\n");
    isAble = FALSE;
  }
  if(isAble){
    while(fgets(str, 100, file)){
      int length = (int)strlen(str);
      for(int i = strlen(str); i > 1; i--){
        if(str[i] >= 'A' && str[i] <= 'z'){
          break;
        }
        length--;
      }
      for(int i = 0; i <= length; i++){
        fprintf(result, "%c", str[i]);
      }
      fprintf(result, "!\n");
    }
  }
    fclose(file);
    fclose(result);
    return 0;
}
