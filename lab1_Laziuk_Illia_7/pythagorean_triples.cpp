#include <iostream>
using namespace std;

int main(void){
  int q = 0,w = 0,e = 0,r = 0,x;
  cout<<"Write a number and this porgram will display the same number of pythagorean triples"<<endl;
  cin>>x;
  for(int i = 1; i < 1000; i++){
    for(int c = 1; c < 1000; c++){
      for(int j = 1; j < 1000; j++){
        if(i * i + c * c == j * j){
          if(x > 0){
            cout<<i<<" "<<c<<" "<<j<<endl;
            x--;
          }else {
          break;
          }
        }
        if(x <= 0){
          break;
        }
      }
      if(x <= 0){
        break;
      }
    }
    if(x <= 0){
      break;
    }
  }
  return 0;
}
