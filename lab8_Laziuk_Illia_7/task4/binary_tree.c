//This application allows you to check the expression for the correct placement of quotes
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* right;
    struct Node* left;
};
typedef struct Node *PNode;

struct Tree {
  PNode This;
}

void init(struct Node* Tree) {
    Tree = NULL;
}

void AddToTree(struct Node* Tree, int data) {
    if (!Tree) {
        Tree = (struct Node*)malloc(1 * sizeof(struct Node));
        Tree->data = data;
        Tree->left = NULL;
        Tree->right = NULL;
        return;
    }

    if (data < Tree->data)
        AddToTree(Tree->left, data);
    else AddToTree(Tree->right, data);
}

void fullfill(struct Node* Tree) {
    int n;
    int x;
    printf("Enter n\n");
    scanf("%d", &n);
    printf("Enter %d numbers", n);
    for(int i = 0; i < n; i++) {
        printf("Enter x\n");
        scanf("%d", &x);
        AddToTree(Tree, x);
    }
}

void print_tree(struct Node* Tree) {
    if(!Tree) return;
    print_tree(Tree->left);
    printf("%d", Tree->data);
    print_tree(Tree->right);
}

int main(void) {
    struct Tree* Tree;
    init(Tree);
    fullfill(Tree);
    print_tree(Tree);
}
