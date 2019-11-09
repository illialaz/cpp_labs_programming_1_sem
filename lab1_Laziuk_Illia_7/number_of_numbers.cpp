#include <iostream>
using namespace std;

int main(void){
  int q = 0,w = 0,e = 0,r = 0,t = 0,y = 0,u = 0,i = 0,o = 0,p = 0;
  unsigned long a,b;
  cout<<"Wrile a number and the progrem will check the repetition of each digit in this number"<<endl;
  cin>>a;
  while(a != 0){
    b = a%10;
    a /= 10;
    if(b == 1){
      q++;
    } else if(b == 2){
      w++;
    } else if(b == 3){
      e++;
    } else if(b == 4){
      r++;
    } else if(b == 5){
      t++;
    } else if(b == 6){
      y++;
    } else if(b == 7){
      u++;
    } else if(b == 8){
      i++;
    } else if(b == 9){
      o++;
    } else{
      if(b == 0){
        p++;
      }
    }
  }
  cout<<q<<w<<e<<r<<t<<y<<u<<i<<o<<p<<endl;
  return 0;
}
