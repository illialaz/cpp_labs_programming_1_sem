#include <iostream>
using namespace std;

int main(void){
  unsigned int a, b, c, d, e, f, g, h;
  g = 1;
  h = 1;

  cout<<"Write 2 numbers and the program will check if they are mutually simple"<<endl;
  cin>>a>>b;
  if(a < 0 || b < 0){
    cout<<"Incorrect value"<<endl;
    return 0;
  }
  if(a > b){
    c = a;
    e = b;
  } else if(b > a){
    c = b;
    e = a;
  }
  for(int i = 2; i < a; i++){
    g = c;
    h = i;
    while (g != 0){
    d = c%i;
    g /= i;
    }
    while (h != 0){
    f = e%i;
    h /= i;
    }
    if(d == 0){
      cout<<"False"<<endl;
      return 0;
    } else if(d != 0){
      if(f == 0){
        cout<<"False"<<endl;
        return 0;
      } 
    }
  }
  cout<<"True"<<endl;
  return 0;
}
