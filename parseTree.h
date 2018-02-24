#include <stdlib.h>
#include <stdio.h>

typedef struct *node Node;
struct node {
	Node leftmostChild;
	Node rightSibling;
	char data;
};

typedef struct *tree Tree;
struct tree {
	Node root;
};

extern Node Node_new();
extern void Tree_free(Tree tree);
extern Node Tree_getLeftmostChild(Node root);