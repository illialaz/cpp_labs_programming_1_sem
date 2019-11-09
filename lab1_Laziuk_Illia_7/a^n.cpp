#include <iostream>
using namespace std;

int main(void){
  int a, n, b;
  b = 1;
  cout<<"Enter the number and degree"
  cin>>a>>n;
  for(int i = n; i > 0; i--){
    b *= a;
  }
  cout<<"a^n = "<<b<<endl;
  return 0;
}
