#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char first_name[15];
  char last_name[15];
  int group;
  int number;
  int ma;
  int ga;
  int pr;
  double mark;
  struct Student* next_student;
};
typedef struct Student *PStudent;

struct List {
  PStudent Head;
  PStudent Tail;
};

int fullfill(struct List* L, FILE* group) {
  char str[100];
  int size = 0;;
  while(fgets(str, 100, group)) {
    PStudent NewStudent = (struct Student*)malloc(1 * sizeof(struct Student));
    strcpy(NewStudent->first_name, strtok(str, " "));
    strcpy(NewStudent->last_name, strtok(NULL, " "));
    NewStudent->group = atoi(strtok(NULL, " "));
    NewStudent->number = atoi(strtok(NULL, " "));
    NewStudent->ma = atoi(strtok(NULL, " "));
    NewStudent->ga = atoi(strtok(NULL, " "));
    NewStudent->pr = atoi(strtok(NULL, " "));
    NewStudent->mark = (NewStudent->ma + NewStudent->ga + NewStudent->pr) / 3.0;
    NewStudent->next_student = NULL;
    if (L->Tail) L->Tail->next_student = NewStudent;
    L->Tail = NewStudent;
    if (!L->Head) L->Head = L->Tail;
    size++;
  }
  return size;
}

void swap(struct Student* A, struct Student* B) {
  char first_name_tmp[15];
  strcpy(first_name_tmp, A->first_name);
  char last_name_tmp[15];
  strcpy(last_name_tmp, A->last_name);
  int group_tmp = A->group;
  int number_tmp = A->number;
  int ma_tmp = A->ma;
  int ga_tmp = A->ga;
  int pr_tmp = A->pr;
  double mark_tmp = A->mark;
  strcpy(A->first_name, B->first_name);
  strcpy(A->last_name, B->last_name);
  A->group =  B->group;
  A->number = B->number;
  A->ma = B->ma;
  A->ga = B->ga;
  A->pr = B->pr;
  A->mark = B->mark;
  strcpy(B->first_name, first_name_tmp);
  strcpy(B->last_name, last_name_tmp);
  B->group = group_tmp;
  B->number = number_tmp;
  B->ma = ma_tmp;
  B->ga = ga_tmp;
  B->pr = pr_tmp;
  B->mark = mark_tmp;
}

void  bubbleSort (struct List* L, int size) {
  PStudent ThisStudent = (struct Student*)malloc(1 * sizeof(struct Student));
  ThisStudent = L->Head;
  for(int j = 0; j < size - 2; j++) {
    for(int i = 0; i < size - 1 - j; i++) {
      if(ThisStudent->group > ThisStudent->next_student->group) {
        swap(ThisStudent, ThisStudent->next_student);
      } 
      ThisStudent = ThisStudent->next_student;
    }
     ThisStudent = L->Head;
  }
  for(int j = 0; j < size - 2; j++) {
    for(int i = 0; i < size - 1 - j; i++) {
      if(ThisStudent->group == ThisStudent->next_student->group
      && strcmp(ThisStudent->last_name, ThisStudent->next_student->last_name) > 0) {
        swap(ThisStudent, ThisStudent->next_student);
      }
      ThisStudent = ThisStudent->next_student;
    }
    ThisStudent = L->Head;
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

void fprint_body( FILE* file, struct Student* stud){
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

void print_all(struct List* student) {
  FILE* sort_group = fopen("sort_group.txt", "w");
  FILE* excellent_students = fopen("excellent_students.txt", "w");
  FILE* unsatisfactory_students = fopen("unsatisfactory_students.txt", "w");
  PStudent stud = student->Head;
  fprint_header(sort_group);
  fprint_header(excellent_students);
  fprint_header(unsatisfactory_students);
  while(stud != NULL) {
    fprint_body(sort_group, stud);
    if(stud->ma <= 4 || stud->ga <= 4 || stud->pr <= 4) {
      fprint_body(unsatisfactory_students, stud);
    }
    if(stud->ma >= 9 & stud->ga >= 9 && stud->pr >= 9) {
      fprint_body(excellent_students, stud);
    }
    stud = stud->next_student;
  }
}


int main(void) {
  struct List list;
  FILE* group = fopen("group.txt", "r");
  if (!group) {
    printf("Error\n");
    return 1;
  }
  int size = fullfill(&list, group);
  bubbleSort(&list, size);
  
  fclose(group);

  print_all(&list);
  return 0;
}