#ifndef _parsetree_h
#define _parsetree_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node* Tree;
struct Node {
	Tree leftmostChild;
	Tree rightSibling;
	char data;
};

extern Tree Tree_new(char c);
extern void Tree_free(Tree tree );
extern Tree Tree_addSibling(Tree tree, Tree sibl);
extern Tree Tree_addChild(Tree tree, Tree chil);
extern bool isTerminal(char c);
extern Tree Tree_getLeftmostNode(Tree root);
extern void Tree_indent(Tree root, int indent);
extern void Tree_print(Tree root);

#endif