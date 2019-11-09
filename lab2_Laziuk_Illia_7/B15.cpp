#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  double x, m, a, b, h, n = 5, sum = 0;
  cout<<"Enter m_a_b_h"<<endl;
  cin>>m>>a>>b>>h;
  x = a;
  cout<<"__|x|__"<<setw(10)<<right<<"sum"<<endl;
  while(x < b + 1){
    cout<<"-------------------------"<<endl;
    cout<<"__|"<<setprecision(3)<<x<<"|__";
    while(n < m + 1){
      sum += pow(x, n) * (sin(n * x) + cos(n * x)) / (2 * n);
      n++;
    }
    cout<<"|"<<setprecision(7)<<setw(10)<<right<<sum<<"|"<<endl;
    n = 5;
    sum = 0;
    x += h;
  }
  return 0;
}
