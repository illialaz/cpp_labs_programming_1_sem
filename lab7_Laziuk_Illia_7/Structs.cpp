#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct Point{
  double x;
  double y;
};

struct Triangle{
  double P;
  Point A,B,C;
};

int compare(const void* pa, const void* pb) {
	return ((((Triangle*)pa)->P)>(((Triangle*)pb)->P))?1:-1;
}

double Len(Point a, Point b){
  return sqrt(pow(a.x-b.x, 2.0)+pow(a.y-b.y,2.0));
}

int main(void){
  int n;
  cin >> n;
  Triangle *mas = new Triangle[n];
  srand(time(0));
  for (int i = 0; i < n; i++){
    mas[i].A.x = ((rand()% 100) - 50);
    mas[i].A.y = ((rand()% 100) - 50);
    mas[i].B.x = (rand()% 100) - 50;
    mas[i].B.y = (rand()% 100) - 50;
    mas[i].C.x = (rand()% 100) - 50;
    mas[i].C.y = (rand()% 100) - 50;
    mas[i].P = Len(mas[i].A, mas[i].B)+Len(mas[i].A, mas[i].C)+Len(mas[i].B, mas[i].C);
  }
  qsort(mas, n, sizeof(mas[0]), compare);
  for(int i = 0; i < n; i++){
    cout << mas[i].P << endl;
  }
  return 0;
}