#include <iostream>
using namespace std;

int main(void){
  int a, b, c;
  cout<<"Enter the number. The program will check if it is simple"<<endl;
  cin>>a;
  for(int i = 2; i < a; i++){
    b = a%i;
    if(b == 0){
      cout<<"False"<<endl;
      return 0;
    }
  }
  cout<<"True"<<endl;
  return 0;
}