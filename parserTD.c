#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parseTree.h"
#include "parserTD.h"

char *nextInputChar;
Tree stack[10];
int top = -1;
int parseTable[][] = {
  		// ( ) + - * / n \0
  /*E*/	{, , , , , , , }
  /*t*/	{, , , , , , , }
  /*T*/	{, , , , , , , }
  /*f*/	{, , , , , , , }
  /*F*/	{0, 0, 0, 0, 0, 0, 5, 5}
  /*N*/	{0, 0, 0, 0, 0, 0, 6, 6}
  /*n*/	{0, 0, 0, 0, 0, 0, 7, 7}
  /*D*/	{0, 0, 0, 0, 0, 0, 8, 0}
};

void push(Tree tree) {
	if (top < 9)
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
	for(int i=0; i<=9; i++){
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
    TD_buildStack(tdp);
	return tdp;
}

void TD_buildStack(TDP tdp) {
    push(Tree_new('E'));
    while(!isEmpty()) {
        Tree temp = pop();
    }
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

bool TD_lookAhead(TDP tdp, char c) {
	if (tdp->current < tdp->length) {
		return *nextInputChar == c; 
	}
	return '\0';
}

bool TD_matchTerminal(TDP tdp, char x) {
	if (*nextInputChar == x) {
		nextInputChar++;
		tdp->current++;
		return true;
	}
	return false;
}
