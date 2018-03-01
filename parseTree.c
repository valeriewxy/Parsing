#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "parseTree.h"

Tree Tree_new(char c) {
	Tree tree = (Tree)malloc(sizeof(struct Node));
	tree->leftmostChild = NULL;
	tree->rightSibling = NULL;
	tree->data = c;
	return tree;
}

void Tree_free(Tree tree ) {
	if (tree != NULL) {
		if (tree->leftmostChild == NULL && tree->rightSibling == NULL) {
			free(tree); //segmentation fault
			tree = NULL;
		}
		if (tree->leftmostChild != NULL) {
			Tree_free(tree->leftmostChild);
		} 
		if (tree->rightSibling != NULL) {
			Tree_free(tree->rightSibling);
		}
	}
}

Tree Tree_addSibling(Tree tree, Tree sibl) {
	if (tree == NULL) {
		return NULL;
	}
	while (tree->rightSibling != NULL) {
		tree = tree->rightSibling;
	}
	// tree->rightSibiling = Tree_new(data);
	tree->rightSibling = sibl;
	return tree->rightSibling;
}

Tree Tree_addChild(Tree tree, Tree chil) {
	if (tree == NULL) {
		return NULL;
	}
	if (tree->leftmostChild == NULL) {
		// tree->leftmostChild = Tree_new(data);
		tree->leftmostChild = chil;
		return tree->leftmostChild;
	} else {
		return Tree_addSibling(tree->leftmostChild, chil);
	}
}

bool isTerminal(char c) {
	switch (c){
		case '0':
			return true;
		case '1':
			return true;
		case '2':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		case '+':
			return true;
		case '-':
			return true;
		case '*':
			return true;
		case '/':
			return true;
		case '(':
			return true;
		case ')':
			return true;
			break;
	}
	return false;
}

Tree Tree_getLeftmostNode(Tree root) {
	if (root == NULL) {
		printf("%s\n", "root null");
		return NULL;
	}
	if (!isTerminal(root->data) && root->leftmostChild == NULL && root->data != 'e') 
		return root;
	if (root->leftmostChild != NULL) {
		Tree temp = Tree_getLeftmostNode(root->leftmostChild);
		if (temp != NULL) {
			return temp;
		}
	}
	if (root->rightSibling != NULL) {
		// if (root->rightSibling->leftmostChild != NULL) {
		Tree temp = Tree_getLeftmostNode(root->rightSibling);
		if (temp != NULL) {
			return temp;
		}
	// }
	}
	printf("%s\n", "return null");
	return NULL;
}

void Tree_indent(Tree root, int indent) {
	if (root == NULL) {
		return;
	}
	for(int i=1; i<=indent; i++) {
		printf("  ");
	}
	printf("%c\n", root->data);
	if (root->leftmostChild != NULL) {
		Tree_indent(root->leftmostChild, indent+1);
	}
	if (root->rightSibling != NULL) {
		Tree_indent(root->rightSibling, indent);
	}
}

void Tree_print(Tree root) {
	Tree_indent(root, 0);
	printf("\n");
}
