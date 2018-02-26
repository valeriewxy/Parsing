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
	// double result = 0;
	if (tree->data == 'E') {
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 't') {
		if (root->leftmostChild->label=='e'){
			return 0;
		} else {
			double result;
			if (n1->label=='+'){
	        	result= evaluation_tree(tree->leftmostChild->rightSibling) + evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
			} else {
				result= -evaluation_tree(tree->leftmostChild->rightSibling) -evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
			}
			return result;
		}
	}
	else if (tree->data == 'T') {
		return evaluation_tree(tree->leftmostChild) * evaluation_tree(tree->leftmostChild->rightSibling);
	}
	else if (tree->data == 'f') {
		if (tree->leftmostChild->data == 'e') {
			return 1.0;
		} else {
			if (tree->leftmostChild->data == '*') {
				return evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
			} else {
				return 1/(evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->leftmostChild->rightSibling->rightSibling));
			}
		}
	}
	else if (tree->data == 'F') {
		if (tree->leftmostChild->data == '(')
			return evaluation_tree(tree->leftmostChild->rightSibling);
		return evaluation_tree(tree->leftmostChild);
	} 
	else if (tree->data == 'N') {
		return combine(evaluation_tree(tree->leftmostChild), evaluation_tree(tree->leftmostChild->rightSibling));
	}
	else if (tree->data == 'n') {
		if (tree->rightSibling->leftmostChild->data == 'e') {
			return 0;
		} else {
			return evaluation_tree(tree->leftmostChild);
		}
	}
	else if (tree->data == 'D') {
		int n = tree->data;
		return n;
	} else {
		return 0;
	}
	// else if (isOperand(tree->data)) {
	// 	int n = tree->data;
	// 	return n;
	// }
	// else if (isOperator(tree->data)) {

	// }
	// return result;
	
}

int evaluation(Tree tree) {
	evaluation_tree(tree->leftmostChild);
}