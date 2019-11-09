#include <stdio.h>
#include <math.h>

double arcsinx(double, double);

int main(void){
  double x, eps, total, sinx;
  int k;
  scanf("%lf", &x);
  scanf("%d", &k);
  if(fabs(x) > 1){
    return 0;
  }
  eps = pow(10, -k);
  sinx = asin(x);
  printf("%lf\n", arcsinx(x, eps));
  printf("%f\n", sinx);
}

double arcsinx(double x, double eps){
  double sum = x, c = 1, n = 3, p = 1;
  while(c * p > eps){
    c = pow(x, n)/n;
    p = p * (n - 2)/(n - 1);
    sum = sum + c * p;
    n+= 2;
  }
  return sum;
}