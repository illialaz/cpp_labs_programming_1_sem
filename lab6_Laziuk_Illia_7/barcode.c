//  barcode correctness
//if length < 13 then error
//then the sum of all elements in even position, multiplied by 3, is considered and the last digit is remembered
//then the sum of all elements in odd position is considered and the last digit is remembered
//if sum of this 2 sums % 10 = 0, then the barcode is right, else not
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

int main(void){
    char* barcode;
  int count;
  int c = false;
  int sum_even = 0;
  int sum_odd = 0;
  int result = 0;
  while(!c){
    printf("Enter your barcode and the program will check if this code is true.\n"); 
    printf("Barcode should consists of 13 numbers\n");
    gets(barcode);
    if(strlen(barcode) == 13){
        for(int i = 0; barcode[i] != '\0'; i++){
            if(barcode[i] < '0' || barcode[i] > '9'){ 
                printf("Barcode must contain only numbers. Try again\n");
                c = false;
                break;
            } else {
                c = true;
            }
        }
    } else {
      printf("Barcode isn't correct. Try again\n");
    }
  }
  for(int i = 0; i < strlen(barcode); i ++, i++){
    sum_odd += (barcode[i] - '0');
  }
  for(int i = 1; i < strlen(barcode); i ++, i++){
    sum_even += (barcode[i] - '0');
  }
  result = (((sum_even * 3) % 10) + (sum_odd % 10));
  if(result % 10 == 0){
    printf("Barcode \"%s\" is correct\n", barcode);
  } else {
    printf("Barcode \"%s\" isn't correct\n", barcode);
  }
  return 0;
}
