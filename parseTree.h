#include <stdlib.h>
#include <stdio.h>

typedef struct *Node Tree;
struct Node {
	Node leftmostChild;
	Node rightSibling;
	char data;
};

extern Node Node_new();
extern void Tree_free(Tree tree );
extern Node Tree_getLeftmostChild(Tree root);

#endif