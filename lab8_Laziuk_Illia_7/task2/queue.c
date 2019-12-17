#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* previous;
  struct Node* next;
};
typedef struct Node *PNode;

struct Queue {
  PNode Head, Tail;
};

void Push(struct Queue* Q, char x) {
  PNode NewNode = (struct Node*)malloc(1 * sizeof(struct Node));
  NewNode->data = x;
  NewNode->previous = Q->Tail;
  NewNode->next = NULL;
  if (Q->Tail) Q->Tail->next = NewNode;
  Q->Tail = NewNode;
  if (!Q->Head) Q->Head = Q->Tail;
}

char Pop(struct Queue* S) {
  PNode TopNode = S->Head;
  char x;

  if (!TopNode) return '\255';
  x = TopNode->data;
  S->Head = TopNode->next;
  if (S->Head) S->Head->previous = NULL;
  else S->Tail = NULL;

  free(TopNode);
  return x;
}

int main(void) {
  struct Queue queue;
  char c;
  int i = 0;
  char* str = (char*)malloc(100 * sizeof(char));
  while((c = getchar()) != '\n') {
    Push(&queue, c);
    str[i] = Pop(&queue);
    i++;
  }
  str[i] = '\0';
  printf("%s\n", str);
  return 0;
}