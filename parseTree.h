#include <stdlib.h>
#include <stdio.h>

typedef struct *Node Tree;
struct Node {
	Node leftmostChild;
	Node rightSibling;
	char data;
};

extern Tree Tree_new();
extern void Tree_free(Tree tree );
extern Tree Tree_getLeftmostLeaf(Tree root);
extern void Tree_print(Tree tree);

#endif