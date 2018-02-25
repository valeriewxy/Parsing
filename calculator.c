#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "calculator.h"
#include "parseTree.h"
#include "parserRD.h"

bool isOperand(char c) {
	return (c >= '0' && c <= '9');	
}

bool isOperator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
			break;
	}
	return false;
}

double combine (double a, double b) {
	char exp[128];
	double n;
	sprintf(exp, "%d %d", double a, double b);
	sscanf(exp, "%d", &n);
	return n;
}

double evaluation_tree(Tree tree) {
	// char exp[128];
	double result = 0;
	if (tree->data == 'E') {
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 't') {
		return evaluation_tree()
	}
	else if (tree->data == 'T') {
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 'f') {

	}
	else if (tree->data == 'F') {

	} 
	else if (tree->data == 'N') {
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 'n') {
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 'D') {
		if (tree->rightSibling->leftmostChild->data == 'e')
			return evaluation_tree(tree->leftmostChild);
		return combine(evaluation_tree(tree->leftmostChild, tree->rightSibling));
	}
	else if (isOperand(tree->data)) {
		int n = tree->data;
		return n;
	}
	else if (isOperator(tree->data)) {

	}
	return result;
	
}

int evaluation(Tree tree) {

}