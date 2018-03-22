#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "calculator.h"
#include "parseTree.h"
#include "parserRD.h"

bool isOperand(char c) {
	return (c >= '0' && c <= '9');	
}

double combine (double a, double b) {
	char exp[128];
	double n;
	sprintf(exp, "%.0f%.0f", a, b);
	n = atof(exp);
	// printf("combine: %f\n", n);
	return n;
}

double evaluation_tree(Tree tree) {
	if (tree->data == 'E') {
		// printf("%s\n", "E");
		return evaluation_tree(tree->leftmostChild);
		///////////////////////////////
		// if (tree->leftmostChild->rightSibling->leftmostChild->data == '+') {
		// 	return evaluation_tree(tree->leftmostChild)+evaluation_tree(tree->leftmostChild->rightSibling);
		// } else if (tree->leftmostChild->rightSibling->leftmostChild->data == '-') {
		// 	return evaluation_tree(tree->leftmostChild)-evaluation_tree(tree->leftmostChild->rightSibling);
		// } else  {
		// 	return evaluation_tree(tree->leftmostChild);
		// }
	}
	// else if (tree->data == 't') {
		// printf("%s\n", "t");
		// if (tree->leftmostChild->data == '+') {
		// 	return evaluation_tree(tree->leftmostChild->rightSibling)+evaluation_tree(tree->leftmostChild->rightSibling)
		// }
		
	// }
	else if (tree->data == 'T') {
		// printf("%s\n", "T");
		if (tree->rightSibling->leftmostChild->data == '-')
			return evaluation_tree(tree->leftmostChild)-evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
		else if (tree->rightSibling->leftmostChild->data == '+')
			return evaluation_tree(tree->leftmostChild)+evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
		else
			return evaluation_tree(tree->leftmostChild);
		// return evaluation_tree(tree->leftmostChild)*evaluation_tree(tree->leftmostChild->rightSibling);
	}
	// else if (tree->data == 'f') {
	// 	printf("%s\n", "f");
	// 	// if (tree->leftmostChild->data == 'e') {
	// 	// 	return 1.0;
	// 	// } else {
	// 	// 	if (tree->leftmostChild->data == '*') {
	// 	// 		return evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->leftmostChild->rightSibling->rightSibling);
	// 	// 	} else {
	// 	// 		return 1/(evaluation_tree(tree->leftmostChild->rightSibling)*evaluation_tree(tree->leftmostChild->rightSibling->rightSibling));
	// 	// 	}
	// 	// }
	// 	return 0;
	// }
	else if (tree->data == 'F') {
		// printf("%s\n", "F");
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
			else if (tree->rightSibling->leftmostChild->data == '/'){
				return evaluation_tree(tree->leftmostChild)/evaluation_tree(tree->rightSibling->leftmostChild->rightSibling);
			}
			else
				return evaluation_tree(tree->leftmostChild);
		}
		// return evaluation_tree(tree->leftmostChild);
	} 
	else if (tree->data == 'N') {
		// printf("%s\n", "N");
		return evaluation_tree(tree->leftmostChild);
		// return combine(evaluation_tree(tree->leftmostChild), evaluation_tree(tree->leftmostChild->rightSibling));
	}
	else if (tree->data == 'n') {
		// printf("%s\n", "n");
	
		return evaluation_tree(tree->leftmostChild);
	}
	else if (tree->data == 'D') {
		// printf("%s\n", "D");
		// int n = tree->data;

		if (tree->rightSibling->leftmostChild->data == 'e') {
			return evaluation_tree(tree->leftmostChild);
		} else {
			return combine(evaluation_tree(tree->leftmostChild), evaluation_tree(tree->rightSibling));
		}

		// return n;
	} 
	else if (isOperand(tree->data)) {
		// printf("Operand: %c\n", tree->data);
		switch (tree->data) {
			case '0':
				return 0;
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			default:
				return 9;
		}
	}
	else {
		// printf("%s%c\n", "else：", tree->data);
		return 0;
	}
}

double evaluation(Tree tree) {
	return evaluation_tree(tree->leftmostChild);
}