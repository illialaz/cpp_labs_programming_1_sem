//This application allows you to check the expression for the correct placement of quotes
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* previous;
  struct Node* next;
};
typedef struct Node *PNode;

struct Stack {
  PNode Head, Tail;
};

void Push(struct Stack* S, char x) {
  PNode NewNode = (struct Node*)malloc(1 * sizeof(struct Node));
  NewNode = (struct Node*)malloc(1 * sizeof(struct Node));
  NewNode->data = x;
  NewNode->next = S->Head;
  NewNode->previous = NULL;

  if(S->Head) S->Head->previous = NewNode;
  S->Head = NewNode;

  if(!S->Tail) S->Tail = S->Head;
}

char Pop(struct Stack* S) {
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
  struct Stack stack; // quotes: (), {}, []
  char c;
  char to_pop;

  while ((c = getchar()) != '\n') {
    if (c  == '{') Push(&stack, '}');
    else if (c == '[') Push(&stack, ']');
    else if (c == '(') Push(&stack, ')');

    if(c == '}' || c == ']' || c == ')') to_pop = Pop(&stack);
    
    if (c == '}') {
      if (to_pop == '\255' || c != to_pop) {
        printf("There are mistakes with quotes\n");
        return 0;
      }
    }
    else if (c == ')') {
      if (to_pop == '\255' || c != to_pop) {
        printf("There are mistakes with quotes\n");
        return 0;
      }
    }
    else if (c == ']') {
      if (to_pop == '\255' || c != to_pop) {
        printf("There are mistakes with quotes\n");
        return 0;
      }
    }
  }

  if(Pop(&stack) == '\255')  {
    printf("All is cool\n");
    return 0;
  }

  printf("There are mistakes with quotes\n");
  return 0;
}
