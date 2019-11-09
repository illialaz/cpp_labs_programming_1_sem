#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  double e, x, y, z, a, b,eps;
  eps = 0.000001; 
  cin>>e>>x>>y>>z;
  if(e < eps){
    cout<<"wrong"<<endl;
  }else{
    a = pow((1 + y),2) * (pow(x,2) + 4)/(pow(e, (-x)) + pow(x,2) + 4);
    b = 1/((pow(x,4)/2) + pow(sin(z), 4) + 1);
    cout<<a<<"     "<<b<<endl;
    return 0;
  }
}
