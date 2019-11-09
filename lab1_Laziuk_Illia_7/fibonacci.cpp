#include <iostream>
using namespace std;

int main(void){
  int a, b, c, d;
  a = 0;
  b = 1;
  cout<<"Enter the number of numeric in the fibonacci sequence"<<endl;
  cin>>d;
  for(int i = d; i > 2; i--){
    c = a + b;
    a = b;
    b = c;
  }
  cout<<"This numeric corresponds to the number "<<b<<endl;
  return 0;
}
