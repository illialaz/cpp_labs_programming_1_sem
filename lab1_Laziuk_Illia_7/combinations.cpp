#include <iostream>
using namespace std;

int main(void){
  unsigned int k, n, z, C;
  double j, l, m;
  j = 1;
  l = 1;
  m = 1;
  cout<<"Enter N and K to find out the number of combinations"<<endl;
  cin>>n>>k;
  z = n - k;
  for(int i = 1; i <= n; i++){
    j *= i;
  }
  for(int i = 1; i <= k; i++){
    l *= i;
  }
  for(int i = 1; i <= z; i++){
    m *= i;
  }
  C = j / (l * m);
  cout<<"The number of combinations is: "<<C<<endl;
  return 0;
}
