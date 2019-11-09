#include <iostream>
using namespace std;

int main(void){
  unsigned int a, b, c;
  c = 0;
  cout<<"Enter a number to see if it is perfect"<<endl;
  cin>>a;
  for(int i = 1; i < a; i++){
    b = a%i;
    if(b == 0){
      c += i;
    }
  }
  if(c == a){
    cout<<"True"<<endl;
  } else {
    cout<<"False"<<endl;
  }
  return 0;
}