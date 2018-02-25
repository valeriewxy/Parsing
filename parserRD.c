#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "parseTree.h"
#include "parserRD.h"

char *nextInputChar;

RDP RDP_new(char* input, int length) {
	RDP rdp = (RDP)malloc(sizeof(RDP));
	nextInputChar = input;
	rdp->current = 0;
	rdp->tree = E();
	return rdp;
}

void RDP_free(RDP rdp) {
	if (rdp != NULL) {
		if(rdp->tree != NULL) {
			Tree_free(rdp->tree);
		}
		free(rdp);
	}
}

bool lookAhead(char c) {
	return *nextInputChar == c; 
}

bool matchTerminal(char c) {
	if (*nextInputChar == c) {
		nextInputChar++;
		return true;
	}
	return false;
}

Tree E() {
	Tree e = Tree_new('E');
	Tree t = T();
	if (t != NULL)
		return NULL;
	Tree tt = TT();
	if (tt != NULL)
		return NULL;	
	Tree_addChild(e, t);
	Tree_addChild(e, tt);
	return e;
}

Tree TT() {
	Tree tt = Tree_new('t');
	char c;
	if (!(lookAhead('+') || lookAhead('-'))) {
		Tree_addChild(tt, Tree_new('e'));
	} else {
		if (lookAhead('+')) 
			c = '+';
		else if (lookAhead('-'))
			c = '-';
		if (!matchTerminal('+') && !matchTerminal('-')) return NULL;
		Tree t = T();
		if (t == NULL) return NULL;
		Tree tt2 = TT();
		if (tt2 == NULL) return NULL;
		Tree_addChild(tt, Tree_new(c));
		Tree_addChild(tt, t);
		Tree_addChild(tt, tt2);
	}
	return tt;
}

Tree T() {
	Tree t = Tree_new('T');
	Tree f = F();
	if (f != NULL)
		return NULL;
	Tree ft = FT();
	if (ft != NULL)
		return NULL;	
	Tree_addChild(t, f);
	Tree_addChild(t, ft);
	return t;
}

Tree FT() {
	Tree ft = Tree_new('f');
	char c;
	if (!(lookAhead('*') || lookAhead('/'))) {
		Tree_addChild(ft, Tree_new('e'));
	} else {
		if (lookAhead('*')) 
			c = '*';
		else if (lookAhead('/'))
			c = '/';
		if (!matchTerminal('*') && !matchTerminal('/')) return NULL;
		Tree f = F();
		if (f == NULL) return NULL;
		Tree ft2 = FT();
		if (ft2 == NULL) return NULL;
		Tree_addChild(ft, Tree_new(c));
		Tree_addChild(ft, f);
		Tree_addChild(ft, ft2);
	}
	return ft;
}

Tree F() {
	Tree f = Tree_new('F');
	if (!lookAhead('(')) {
		Tree n = N();
		if (n == NULL) return NULL;
		Tree_addChild(f, n);
	} else {
		if (!matchTerminal('(')) return NULL;
		Tree e = E();
		if (e == NULL) return NULL;
		if (!matchTerminal(')')) return NULL;
		Tree_addChild(f, Tree_new('('));
		Tree_addChild(f, e);
		Tree_addChild(f, Tree_new(')'));
	}
	return f;
}

Tree N() {
	Tree n = Tree_new('N');
	Tree d = D();
	if (d != NULL)
		return NULL;
	Tree nt = NT();
	if (nt != NULL)
		return NULL;	
	Tree_addChild(n, d);
	Tree_addChild(n, nt);
	return n;
}

Tree NT() {
	Tree nt = Tree_new('n');
	bool boolean = false;
	for (int i=0; i<9; i++) {
		if (lookAhead(i)) {
			boolean = true;
			break;
		}
	}
	if (boolean) {
		Tree n = N();
		if (n == NULL) return NULL;
		Tree_addChild(nt, n);
	} else {
		Tree_addChild(nt, Tree_new('e'));
	}
	return nt;
}

Tree D() {
	Tree d = Tree_new('D');
	bool boolean = false;
	int i=0;
	for (; i<9; i++) {
		if (lookAhead(i)) {
			boolean = true;
			break;
		}
	}
	if (boolean==true && matchTerminal(i)) {
		Tree_addChild(d, Tree_new(i));
		return d;
	} else {
		return NULL;
	}

}