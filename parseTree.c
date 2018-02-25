#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "parsetree.h"

Tree Tree_new(char c) {
	Tree tree = (Tree)malloc(sizeof(struct Node));
	tree->leftmostChild = NULL;
	tree->rightSibiling = NULL;
	data = c;
}

void Tree_free(Tree tree ) {
	if (tree->leftmostChild == NULL && tree->rightSibiling == NULL) {
		free(tree);
	}
	if (tree->leftmostChild != NULL) {
		Tree_free(tree->leftmostChild);
	} 
	if (tree->rightSibiling != NULL) {
		Tree_free(tree->rightSibiling);
	}
}

Tree Tree_getLeftmostLeaf(Tree root) {
	if (root->leftmostChild != NULL) {
		Tree temp = Tree_getLeftmostLeaf(root->leftmostChild);
		return temp;
	}
	if (root->rightSibiling != NULL) {
		if (root->rightSibiling->leftmostChild != NULL) {
			Tree temp = Tree_getLeftmostLeaf(root->rightSibiling->leftmostChild);
			return temp;
		}
	}
	if (root->data != NULL) {
		return root;
	}
	return NULL;
}

void Tree_print(Tree tree) {

}