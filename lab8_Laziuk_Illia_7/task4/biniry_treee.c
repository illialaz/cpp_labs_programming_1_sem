#include<stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *left, *right;
};
typedef struct Node *PNode;

void AddToTree(PNode Tree, int data) {
	if (!Tree) {
		Tree = (struct Node*)malloc(sizeof(struct Node));
		Tree->key = data;
		Tree->left = NULL;
		Tree->right = NULL;
		return;
	}
	if (data < Tree->key)
		AddToTree(Tree->left, data);
	else AddToTree(Tree->right, data);
}

void PrintLKP(PNode Tree){
	if (!Tree) return;
	PrintLKP(Tree->left);
	printf("%d ", Tree->key);
	PrintLKP(Tree->right);
}

int main(void){
	int n;
	scanf("%d", &n);
	int *data = (int*)malloc(sizeof(int));
	PNode Tree=NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < n; i++) {
		int k = 1;
		for (int j = 0; j < i; j++) {
			if (data[i] == data[j]) { k = 0; break; }
		} 
		if (k) AddToTree(Tree, data[i]);
	}
	PrintLKP(Tree);
	
	return 0;
}