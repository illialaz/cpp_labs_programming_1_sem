#include <stdio.h>
#include <math.h>


int main(void){
  double x, m, a, b, h, n = 5, sum = 0;
  printf("Enter m_a_b_h\n");
  scanf("%le", &m);
  scanf("%le", &a);
  scanf("%le", &b);
  scanf("%le", &h);
  x = a;
  printf("__|x|__        sum\n");
  while(x <= b){
    printf("-------------------------\n");
    printf("__|%.2f|__", x);
    while(n <= m){
      sum += pow(x, n) * (sin(n * x) + cos(n * x)) / (2 * n);
      n++;
    }
    printf("    %.4f\n", sum);
    n = 5;
    sum = 1;
    x += h;
  }
  return 0;
}
