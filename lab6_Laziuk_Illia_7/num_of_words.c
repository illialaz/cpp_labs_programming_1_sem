#include <stdio.h>
#include <string.h>

int main(void){
  char words[50][20];
  char str[100];
  char separators[] = " .,?!:;";
  int counts[50] = {0};
  int i, nWords = 0;
  printf("This program counts the number of entries of each word in a string\n");
  printf("Enter your string\n");
  gets(str);
  char* word = strtok(str, separators);
  while(word != NULL){
    for(i = 0; i < nWords; i++){
      if(strcmp(words[i], word) == 0){
        break;
      }
    }
    if(i < nWords){
     ++(counts[i]);
    }
    else{
      strcpy(words[nWords], word);
      counts[nWords] = 1;
       ++nWords;
    }
    word = strtok(NULL, separators);
  }
  for(i = 0; i < nWords; i++){
    printf("The word \"%s\" occur in your string %d times\n", words[i], counts[i]);
    }
  return 0;
}
