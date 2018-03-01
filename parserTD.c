#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parseTree.h"
#include "parserTD.h"

char *nextInputChar;
Tree stack[20];
int top = -1;
int parseTable[8][16] = {
  	   //0  1  2  3  4  5  6  7  8  9  (  )  +  -  *  /  
  /*E*/	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
  /*t*/	{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 3, 4, 4},
  /*T*/	{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0},
  /*f*/	{8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6, 7},
  /*F*/	{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 0, 0, 0, 0, 0},
  /*N*/	{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0},
  /*n*/	{12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13},
  /*D*/	{14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0, 0, 0}
};

int numSynCat(char c) {
	switch(c) {
    case 'E':
    	return 0;
    case 't':	
    	return 1;
    case 'T':
    	return 2;
    case 'f':
    	return 3;
    case 'F':
    	return 4;
    case 'N':
    	return 5;
    case 'n':
    	return 6;
    case 'D':
    	return 7;
    default:
    	return -1;
  	}
}

int numInput(char c) {
	switch(c) {
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
	case '9':
		return 9;
	case '(':
		return 10;
	case ')':
		return 11;
	case '+':
		return 12;
	case '-':
		return 13;
	case '*':
		return 14; 
	case '/':
		return 15;
    default:
    	return -1;
	}
}

void push(Tree tree) {
	if (top < 19)
    	stack[++top] = tree;
}

Tree peek() {
	return stack[top];
}

Tree pop() {
    if (top >= 0) {
        Tree temp = stack[top];
        stack[top--] = NULL;
        return temp;
    }
    return NULL;
}

bool isEmpty() {
	for(int i=0; i<=19; i++){
	    if (stack[i] != NULL) {
	      return false;
	    }
	}
	return true;
}

TDP TDP_new(char* input, int length) {
	TDP tdp = (TDP)malloc(sizeof(TDP));
	nextInputChar = input;
	tdp->current = 0;
	tdp->tree = Tree_new('E');
	tdp->length = length;
    if (!TDP_buildStack(tdp)) tdp->tree = NULL;
	return tdp;
}

bool TDP_buildStack(TDP tdp) {
    push(Tree_new('E'));
    while(!isEmpty()) {
    	if (TDP_lookAhead(tdp, '\0')) 
    		return false;
        Tree out = pop();
        if(isTerminal(out->data)) {
        	printf("%s%c\n", "consume ", out->data);
        	if (TDP_matchTerminal(tdp, out->data)) 
        		continue;
        }
        else {
        	printf("%s\n", "build stack non-term");
        	if (TDP_addProduction(tdp, out)) 
        		return true;
        	return false;
        }
    }
    if (!TDP_lookAhead(tdp, '\0')) 
    	return false;
    return true;
}

bool TDP_addProduction(TDP tdp, Tree tree) {
	printf("Next char: %c\n", *nextInputChar);
	int production;
	if(numInput(*nextInputChar) == -1) {
    	production = 0;
  	}
	production = parseTable[numSynCat(tree->data)][numInput(*nextInputChar)];
	printf("production: %d\n", production);
  	if (TDP_buildTree(tdp, production) != NULL) return true;
  	return false;
}

Tree TDP_buildTree(TDP tdp, int prod) {
	Tree tree = Tree_getLeftmostNode(tdp->tree);
	switch(prod) {
	case 1:
		push(Tree_new('t'));
		push(Tree_new('T'));
		Tree_addChild(tree, Tree_new('T'));
		Tree_addChild(tree, Tree_new('t'));
		printf("%s\n", "prod 1");
		break;
	case 2:
		push(Tree_new('t'));
		push(Tree_new('T'));
		push(Tree_new('+'));
		Tree_addChild(tree, Tree_new('+'));
		Tree_addChild(tree, Tree_new('T'));
		Tree_addChild(tree, Tree_new('t'));
		printf("%s\n", "prod 2");
		break;
	case 3:
		push(Tree_new('t'));
		push(Tree_new('T'));
		push(Tree_new('-'));
		Tree_addChild(tree, Tree_new('-'));
		Tree_addChild(tree, Tree_new('T'));
		Tree_addChild(tree, Tree_new('t'));
		printf("%s\n", "prod 3");
		break;
	case 4:
	case 8:
	case 13:
		// push(Tree_new('e'));
		Tree_addChild(tree, Tree_new('e'));
		printf("%s\n", "prod 4/8/13");
		break;
	case 5:
		push(Tree_new('f'));
		push(Tree_new('F'));
		Tree_addChild(tree, Tree_new('F'));
		Tree_addChild(tree, Tree_new('f'));
		printf("%s\n", "prod 5");
		break;
	case 6:
		push(Tree_new('f'));
		push(Tree_new('F'));
		push(Tree_new('*'));
		Tree_addChild(tree, Tree_new('*'));
		Tree_addChild(tree, Tree_new('F'));
		Tree_addChild(tree, Tree_new('f'));
		printf("%s\n", "prod 6");
		break;
	case 7:
		push(Tree_new('f'));
		push(Tree_new('F'));
		push(Tree_new('/'));
		Tree_addChild(tree, Tree_new('/'));
		Tree_addChild(tree, Tree_new('F'));
		Tree_addChild(tree, Tree_new('f'));
		printf("%s\n", "prod 7");
	case 9:
	case 12:
		push(Tree_new('N'));
		Tree_addChild(tree, Tree_new('N'));
		printf("%s\n", "prod 9/12");
		break;
	case 10:
		push(Tree_new(')'));
		push(Tree_new('E'));
		push(Tree_new('('));
		Tree_addChild(tree, Tree_new('('));
		Tree_addChild(tree, Tree_new('E'));
		Tree_addChild(tree, Tree_new(')'));
		printf("%s\n", "prod 10");
		break;
	case 11:
		push(Tree_new('n'));
		push(Tree_new('D'));
		Tree_addChild(tree, Tree_new('D'));
		Tree_addChild(tree, Tree_new('n'));
		printf("%s\n", "prod 11");
		break;
	case 14:
		push(Tree_new('0'));
		Tree_addChild(tree, Tree_new('0'));
		printf("%s\n", "prod 14");
		break;
	case 15:
		push(Tree_new('1'));
		Tree_addChild(tree, Tree_new('1'));
		printf("%s\n", "prod 15");
		break;
	case 16:
		push(Tree_new('2'));
		Tree_addChild(tree, Tree_new('2'));
		printf("%s\n", "prod 16");
		break;
	case 17:
		push(Tree_new('3'));
		Tree_addChild(tree, Tree_new('3'));
		printf("%s\n", "prod 17");
		break;
	case 18:
		push(Tree_new('4'));
		Tree_addChild(tree, Tree_new('4'));
		printf("%s\n", "prod 18");
		break;
	case 19:
		push(Tree_new('5'));
		Tree_addChild(tree, Tree_new('5'));
		printf("%s\n", "prod 19");
		break;
	case 20:
		push(Tree_new('6'));
		Tree_addChild(tree, Tree_new('6'));
		printf("%s\n", "prod 20");
		break;
	case 21:
		push(Tree_new('7'));
		Tree_addChild(tree, Tree_new('7'));
		printf("%s\n", "prod 21");
		break;
	case 22:
		push(Tree_new('8'));
		Tree_addChild(tree, Tree_new('8'));
		printf("%s\n", "prod 22");
		break;
	case 23:
		push(Tree_new('9'));
		Tree_addChild(tree, Tree_new('9'));
		printf("%s\n", "prod 23");
		break;
	// case 0:
	// 	Tree_addChild(tree, Tree_new('e'));
	// 	// TDP->tree = NULL;
	// 	printf("%s\n", "prod 0");
	// 	break;
	default: return NULL;
	}
	return tree;
}

void TDP_free(TDP tdp) {
	for (int i=0; i<10; i++) {
		if (stack[i] != NULL) {
			Tree_free(stack[i]);
		}
	}
	if (tdp != NULL) {
		if (tdp->tree != NULL) {
			Tree_free(tdp->tree);
		}
		free(tdp);
		tdp = NULL;
	}
}

bool TDP_lookAhead(TDP tdp, char c) {
	if (tdp->current < tdp->length) {
		return *nextInputChar == c; 
	}
	return '\0';
}

bool TDP_matchTerminal(TDP tdp, char x) {
	if (*nextInputChar == x) {
		nextInputChar++;
		tdp->current++;
		return true;
	}
	return false;
}


