#include <iostream>
using namespace std;

int main(void){
  int a, b, j, i, c, n, sum;
  cout<<"Write a number and the program will find a number whose sum of cubes of digits is equal to a given number"<<endl;
  cin>>a;
  for(i = 100; i < 1000; i++){
    sum = 0;
    j = i;
    while(j != 0){
        n = j%10;
        j /=10;
        sum = sum + n * n * n;
    }
    if(sum == a){
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}
