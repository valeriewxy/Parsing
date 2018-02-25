
#include "calculator.h"

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

int evaluation_tree(Tree tree) {
	char exp[128];
	int result = 0;
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

	}
	else if (tree->data == 'n') {

	}
	else if (tree->data == 'D') {

	}
	else if (isOperand(tree->data)) {
		int n = tree->data;
		return n;
	}
	else if (isOperator(tree->data)) {

	}
	
	
}

int evaluation(Tree tree) {

}