
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

int evaluation(Tree tree) {

}

int evaluation_sub(Tree tree) {
	
}