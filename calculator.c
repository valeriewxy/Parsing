
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
	if (tree->data == 'E') {

	}
	else if (tree->data == 't') {

	}
	else if (tree->data == 'T') {

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
	
}

int evaluation(Tree tree) {

}