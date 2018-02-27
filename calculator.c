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
	sprintf(exp, "%.0f%.0f", a, b);
	// printf("sprintf: %c %c\n", exp[0], exp[1]);
	// sscanf(exp, "%lf", &n);
	n = atof(exp);
	printf("combine: %f\n", n);
	return n;
}

double evaluation_tree(Tree tree) {
	// char exp[128];
	// double result = 0;
	if (tree->data == 'E') {
		printf("%s\n", "E");
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 't') {
		printf("%s\n", "t");
		// if (tree->leftmostChild->data=='e'){
		// 	return 0;
		// } else {
		// 	double result;
		// 	if (tree->leftmostChild->data=='+'){
	 //        	result= evaluation_tree(tree->leftmostChild->rightSibling)+evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
		// 	} else {
		// 		result= -evaluation_tree(tree->leftmostChild->rightSibling)-evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
		// 	}
		// 	return result;
		// }
		return 0;
	}
	else if (tree->data == 'T') {
		printf("%s\n", "T");
		if (tree->rightSibling->leftmostChild->data == '+')
			return evaluation_tree(tree->leftmostChild)+evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
		else if (tree->rightSibling->leftmostChild->data == '-')
			return evaluation_tree(tree->leftmostChild)-evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
		else
			return evaluation_tree(tree->leftmostChild);
		// return evaluation_tree(tree->leftmostChild)*evaluation_tree(tree->leftmostChild->rightSibling);
	}
	else if (tree->data == 'f') {
		printf("%s\n", "f");
		// if (tree->leftmostChild->data == 'e') {
		// 	return 1.0;
		// } else {
		// 	if (tree->leftmostChild->data == '*') {
		// 		return evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
		// 	} else {
		// 		return 1/(evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->leftmostChild->rightSibling->rightSibling));
		// 	}
		// }
		return 0;
	}
	else if (tree->data == 'F') {
		printf("%s\n", "F");
		if (tree->leftmostChild->data == '(') {
			if (tree->rightSibling->leftmostChild->data == '*')
				return evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
			else if(tree->rightSibling->leftmostChild->data == '/')
				return evaluation_tree(tree->leftmostChild->rightSibling)/evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
			else
				return evaluation_tree(tree->leftmostChild);
		} else {
			if (tree->rightSibling->leftmostChild->data == '*')
				return evaluation_tree(tree->leftmostChild)*evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
			else if (tree->rightSibling->leftmostChild->data == '/')
				return evaluation_tree(tree->leftmostChild)/evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
			else
				return evaluation_tree(tree->leftmostChild);
		}
		// return evaluation_tree(tree->leftmostChild);
	} 
	else if (tree->data == 'N') {
		printf("%s\n", "N");
		return evaluation_tree(tree->leftmostChild);
		// return combine(evaluation_tree(tree->leftmostChild), evaluation_tree(tree->leftmostChild->rightSibling));
	}
	else if (tree->data == 'n') {
		printf("%s\n", "n");
		// if (tree->rightSibling->leftmostChild->data == 'e') {
		// 	printf("%s\n", "0");
		// 	return 0;
		// } else {
		// 	printf("%s\n", "not e");
		// 	return evaluation_tree(tree->leftmostChild);
		// }
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 'D') {
		// printf("%s\n", "D");
		// int n = tree->data;

		if (tree->rightSibling->leftmostChild->data == 'e') {
			printf("%s\n", "0");
			return evaluation_tree(tree->leftmostChild);
		} else {
			printf("%s\n", "not e");
			return combine(evaluation_tree(tree->leftmostChild), evaluation_tree(tree->rightSibling));
		}

		// return n;
	} 
	else if (isOperand(tree->data)) {
		printf("Operand: %c\n", tree->data);
		switch (tree->data) {
			case '0':
				return 0;
				break;
			case '1':
				return 1;
				break;
			case '2':
				return 2;
				break;
			case '3':
				return 3;
				break;
			case '4':
				return 4;
				break;
			case '5':
				return 5;
				break;
			case '6':
				return 6;
				break;
			case '7':
				return 7;
				break;
			case '8':
				return 8;
				break;
			default:
				return 9;
				break;
		}
	}
	else {
		printf("%s%c\n", "else：", tree->data);
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

double evaluation(Tree tree) {
	return evaluation_tree(tree->leftmostChild);
}