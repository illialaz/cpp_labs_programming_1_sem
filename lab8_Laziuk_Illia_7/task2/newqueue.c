//This application allows you to check the expression for the correct placement of quotes
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node *PNode;

struct Queue {
    PNode Head, Tail;
};

void init(struct Queue* queue) {
    queue->Head = NULL;
    queue->Tail = NULL;
}

void Push(struct Queue* Q, int x) {
    PNode NewNode = (struct Node*)malloc(1 * sizeof(struct Node));
    NewNode->data = x;
    NewNode->next = NULL;
    if (Q->Tail) Q->Tail->next = NewNode;
    Q->Tail = NewNode;
    if (!Q->Head) Q->Head = Q->Tail;
}

int Pop(struct Queue* S) {
    PNode TopNode = S->Head;
    int x;

    if (!TopNode) return 0; // queue is empty
    x = TopNode->data;
    S->Head = TopNode->next;
    free(TopNode);
    return x;
}

int is_simple(int x) {
    for(int i = 2; (i * i) <= x; i++) {
        if(x % i == 0) return 0; // composite
    }
    return 1; // simple
}

int is_palindrome(int x) {
    if(x <= 10) return 0;
    int tmp = 0;
    int x1 = x;
    while(x1 != 0) {
        tmp = tmp * 10 + x1 % 10;
        x1 /= 10;
    }
    if(x == tmp) return 1; // palindrome
    return 0; // not a palindrome
}

int is_in_queue(struct Node* queue, int x) {

    if(queue == NULL) return 0; // isn't in queue

    return (x == queue->data) ? 1 : is_in_queue(queue->next, x); // is in queue
}

int main(void) {
    struct Queue simple, palindrome, result;
    init(&simple);
    init(&palindrome);
    init(&result);
    FILE* file = fopen("input.txt", "r");
    if(!file) return 1;
    char num_str[100];
    int num;
    while(fgets(num_str, 100, file)) {
        num = atoi(num_str);
        if(is_simple(num)) Push(&simple, num);
        if(is_palindrome(num)) Push(&palindrome, num);
    }

    // if data isn't in result, then push
    int c;
    while(simple.Head != NULL) {
        if(is_in_queue(result.Head, c = Pop(&simple)) == 0) {
            Push(&result, c);
        }
    }
    while(palindrome.Head != NULL) {
        if(is_in_queue(result.Head, c = Pop(&palindrome)) == 0) {
            Push(&result, c);
        }
    }

    while((c = Pop(&result))) printf("%d\t", c);
    return 0;
}
