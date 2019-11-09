#include <iostream>
using namespace std;

int main(void){
  int a,b,i = 0,j = 0,n = 0,sum = 0;
  cout<<"Write a number and program will find numbers equal to the sum of cubes of their numbers"<<endl;
  cin>>a;
  for(i = 1; i < a; i++){
    sum = 0;
    j = i;
    while(j != 0){
      n = j%10;
      j/=10;
      sum = sum + n * n * n;
    }
    if(sum == i){
      cout<<i<<endl;
    }
  }
  return 0;
}
