#include <iostream>
using namespace std;

int main(void){
  long a, b, i, d, sum=0, sum1;
  cin>>a;
  b = a;
  while(b != 0){
    b/=10;
    i++;
    if(i >= 10){
      cout<<"Incorrect value"<<endl;
      return 0;
    }
  }
  d = 2 * i - 1;
  b = a;
  while(b != 0){
    sum += b%10;
    b /= 10;
    sum = sum * 10 + 9;
    sum *= 10;
  }
  b = a;
  sum /= 100;
  while(sum != 0){
    sum1 += sum%10;
    sum /= 10;
    sum1 *= 10;
  }
  sum1 /= 10;
  cout<<sum1<<endl;
  return 0;
}
