#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double arcsinx(double, double);

int main(void){
  double x, eps;
  int k;
  cin>>x>>k;
  if(abs(x) > 1){
    cout<<"Incorrect number"<<endl;
    return 0;
  } 
  eps = pow(10, -k);
  cout<<setprecision(5)<<setw(8)<<arcsinx(x, eps)<<endl;
  cout<<setw(8)<<asin(x)<<endl;
}

double arcsinx(double x, double eps){
  double sum = x, c = 1, n = 3, p = 1;
  while(c * p > eps){
    c = pow(x, n)/n;
    p = p * (n - 2)/(n - 1);
    sum = sum + c * p;
    n += 2;
  }
  return sum;
}
