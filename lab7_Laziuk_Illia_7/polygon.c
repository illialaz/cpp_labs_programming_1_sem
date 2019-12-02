// The program analyzes which quarter the polygon is in and produces the result:
// 1, if the polygon is in the first quarter
// 2, if the polygon is in the second quarter
// 3, if the polygon is in the third quarter
// 4, if the polygon is in the forth quarter
// 5, if the polygon is in the fifth quarter
// Then the program sorts a mas of polygons by their quarters
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point{
  double x;
  double y;
};

struct polygon {
  struct point* point;
  int quarter;
};

int compare (const void* pa, const void* pb){
  int quarter_a = ((struct polygon*)pa)->quarter;
  int quarter_b = ((struct polygon*)pb)->quarter;

  return quarter_a - quarter_b;
}

void fullfill(struct polygon* polygon, int num_of_polygons, int num_of_points) {
  for(int i = 0; i < num_of_polygons; i++) {

    polygon[i].quarter = 0;

    for(int j = 0; j < num_of_points; j++) {
      polygon[i].point[j].x = (double)(rand()%9) + 0.123746521 * (double)(rand()%10) - (double)(rand()%10) + 0.0578291 * (double)(rand()%10) - 0.1048310387 *(double)(rand()%10);
      polygon[i].point[j].y = (double)(rand()%9) + 0.123746521 * (double)(rand()%10) - (double)(rand()%10) + 0.0578291 * (double)(rand()%10) - 0.1048310387 *(double)(rand()%10);
      // scanf("%lf%lf", polygon[i].point[j].x, polygon[i].point[j].y);
    }
  }
}

void in_which_quarter(struct polygon* polygon, int num_of_polygons, int num_of_points) {
for (int i = 0; i < num_of_polygons; i++) {
   for (int j = 0; j < num_of_points; j++) {
      if(polygon[i].point[j].x >= 0 && polygon[i].point[j].y >= 0) polygon[i].quarter += 1; // the point is in the 1 quarter
      else if (polygon[i].point[j].x < 0 && polygon[i].point[j].y > 0) polygon[i].quarter += 10;// the point is in the 2 quarter
      else if (polygon[i].point[j].x < 0 && polygon[i].point[j].y < 0) polygon[i].quarter += 100;// the point is in the 3 quater
      else if (polygon[i].point[j].x > 0 && polygon[i].point[j].y < 0) polygon[i].quarter += 1000;// the point si in the 4 quarter
   }
 }

  for (int i = 0; i < num_of_polygons; i++){
    if(polygon[i].quarter == num_of_points) polygon[i].quarter = 1;
    else if(polygon[i].quarter == num_of_points * 10) polygon[i].quarter = 2;
    else if(polygon[i].quarter == num_of_points * 100) polygon[i].quarter = 3;
    else if(polygon[i].quarter == num_of_points * 1000) polygon[i].quarter = 4;
    else polygon[i].quarter = 5;
  }
}

void print_polygons(struct polygon* polygon, int num_of_polygons, int num_of_points) {
  for(int i = 0; i < num_of_polygons; i++) {
    for(int j = 0; j < num_of_points; j++) {
      printf("(%.2lf, %.2lf) %d  ", polygon[i].point[j].x, polygon[i].point[j].y, polygon[i].quarter);
    }
    printf("\n");
  }
}

int main(void) {
  int num_of_points;
  int num_of_polygons;
  printf("Enter number of polygons and number of points\n");
  scanf("%d", &num_of_polygons);
  scanf("%d", &num_of_points);
  struct polygon* polygon = (struct polygon*)malloc(num_of_polygons * sizeof(struct polygon));
  for (int i = 0; i < num_of_polygons; i++) {
    polygon[i].point = (struct point*) malloc (num_of_points * sizeof(struct point));
  }

  srand(time(0));
  
  fullfill(polygon, num_of_polygons, num_of_points);

  in_which_quarter(polygon, num_of_polygons, num_of_points);

  qsort(polygon, num_of_polygons, sizeof(struct polygon), compare);

  print_polygons(polygon, num_of_polygons, num_of_points);

  return 0;
}