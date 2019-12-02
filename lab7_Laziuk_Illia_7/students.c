#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct student {
  char first_name[15];
  char last_name[15];
  int group;
  int number;
  int ma;
  int ga;
  int pr;
  double mark;
};

int compare_by_group_and_last_name(const void* pa, const void* pb) {
  int group_a = ((struct student*)pa) -> group;
  int group_b = ((struct student*)pb) -> group;
  char* last_name_a = ((struct student*)pa) -> last_name;
  char* last_name_b = ((struct student*)pb) -> last_name;

  if (group_a > group_b) return 1;
  if (group_a < group_b) return -1;

  int cmp = strcmp(last_name_a, last_name_b);
  if (cmp > 0) return 1;
  else if (cmp < 0) return -1;

  return 0;
}

void fullfill(FILE* group, char* str, struct student* stud, int i) {
    strcpy(stud[i].first_name, strtok(str, " "));
    strcpy(stud[i].last_name, strtok(NULL, " "));
    stud[i].group = atoi(strtok(NULL, " "));
    stud[i].number = atoi(strtok(NULL, " "));
    stud[i].ma = atoi(strtok(NULL, " "));
    stud[i].ga = atoi(strtok(NULL, " "));
    stud[i].pr = atoi(strtok(NULL, " "));
    stud[i].mark = (stud[i].ma + stud[i].ga + stud[i].pr) / 3.0;
}

void print_average_of_all_students(struct student* stud, int num_of_all_stud){
  for(int i = 0; i < num_of_all_stud; i++){
    printf("Average mark of student %s is %.2f\n", stud[i].last_name, stud[i].mark);
  }
}

void fprint_header(FILE* file){
  fprintf(file, "------------------------------------------------------------------\n");
  fprintf(
    file,
    "%-15s%-15s%-7s%-10s%-4s%-4s%-4s%-7s\n",
    "Last name",
    "First name",
    "Group",
    "Number",
    "MA",
    "GA",
    "PR",
    "Mark"
  );
  fprintf(file, "------------------------------------------------------------------\n");
}

void fprint_body( FILE* file, struct student* stud){
  fprintf(
    file,
    "%-15s%-15s%-7d%-10d%-4d%-4d%-4d%-7.2lf\n",
    stud->last_name,
    stud->first_name,
    stud->group,
    stud->number,
    stud->ma,
    stud->ga,
    stud->pr,
    stud->mark
    );
}

int main(void) {
  struct student* stud;
  stud = (struct student*)malloc(100*sizeof(struct student));
  char str[100];
  int i = 0;
  double average_mark_of_all_stud = 0;
  FILE* group = fopen("group.txt", "r");
  FILE* sort_group = fopen("sort_group.txt", "w");
  FILE* excellent_students = fopen("excellent_students.txt", "w");
  FILE* unsatisfactory_students = fopen("unsatisfactory_students.txt", "w");

  if (!group){
    printf("Error\n");
    return 1;
  }

  while (fgets(str, 100, group)){
    fullfill(group, str, stud, i);
    average_mark_of_all_stud += stud[i].mark;
    i++;
  }
  int num_of_all_stud = i;
  average_mark_of_all_stud  /= num_of_all_stud;
  print_average_of_all_students(stud, num_of_all_stud);
  printf("Average mark of all students is %.2f\n", average_mark_of_all_stud);

  fclose(group);

  qsort(stud, num_of_all_stud, sizeof(struct student), compare_by_group_and_last_name);
  fprint_header(sort_group);
  fprint_header(excellent_students);
  fprint_header(unsatisfactory_students);
  for(int i = 0; i < num_of_all_stud; i++){
    fprint_body(sort_group, &stud[i]);
    if(stud[i].ma <= 4 || stud[i].ga <= 4 || stud[i].pr <= 4) fprint_body(unsatisfactory_students, &stud[i]);
    if(stud[i].mark >= 9) fprint_body(excellent_students, &stud[i]);
  }

  free(stud);
  fclose(group);
  fclose(sort_group);
  return 0;
}
