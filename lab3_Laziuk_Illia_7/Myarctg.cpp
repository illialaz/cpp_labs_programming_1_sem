#include <iostream>
#include <cmath>
#include <iomamp>

double Myarctg(double, double);

int main(void){
  double x, eps;
  int k;
  cin>>x>>k;
  if(abs(x) > 1){
    return 0;
  } 
  eps = pow(10, -k);
  cout<<setprecision(3)<<setw(8)<<Myarctg(x, eps)<<endl;
  cout<<setw(8)<<atan(x)<<endl;
}

double Myarclg(double x, double eps){
  int n = 1;
  double sum = 0, xk;
  do{
    xk = pow(-1, n - 1) * pow(x, 2 * n - 1)/
  }
}