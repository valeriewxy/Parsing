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
	rdp->tree = E(rdp);
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

bool lookAhead(RDP rdp, char c) {
	if (rdp->current < rdp->length) {
		return *nextInputChar == c; 
	}
	return '\0';
}

bool matchTerminal(char c) {
	if (*nextInputChar == c) {
		nextInputChar++;
		return true;
	}
	return false;
}

Tree E(RDP rdp) {
	Tree e = Tree_new('E');
	Tree t = T(rdp);
	if (t == NULL)
		return NULL;
	Tree tt = TT(rdp);
	if (tt == NULL)
		return NULL;	
	Tree_addChild(e, t);
	Tree_addChild(e, tt);
	return e;
}

Tree TT(RDP rdp) {
	Tree tt = Tree_new('t');
	char c;
	if (!(lookAhead(rdp,'+') || lookAhead(rdp,'-'))) {
		Tree_addChild(tt, Tree_new('e'));
	} else {
		if (lookAhead(rdp,'+')) 
			c = '+';
		else if (lookAhead(rdp,'-'))
			c = '-';
		if (!matchTerminal('+') && !matchTerminal('-')) return NULL;
		Tree t = T(rdp);
		if (t == NULL) return NULL;
		Tree tt2 = TT(rdp);
		if (tt2 == NULL) return NULL;
		Tree_addChild(tt, Tree_new(c));
		Tree_addChild(tt, t);
		Tree_addChild(tt, tt2);
	}
	return tt;
}

Tree T(RDP rdp) {
	Tree t = Tree_new('T');
	Tree f = F(rdp);
	if (f == NULL)
		return NULL;
	Tree ft = FT(rdp);
	if (ft == NULL)
		return NULL;	
	Tree_addChild(t, f);
	Tree_addChild(t, ft);
	return t;
}

Tree FT(RDP rdp) {
	Tree ft = Tree_new('f');
	char c;
	if (!(lookAhead(rdp,'*') || lookAhead(rdp,'/'))) {
		Tree_addChild(ft, Tree_new('e'));
	} else {
		if (lookAhead(rdp,'*')) 
			c = '*';
		else if (lookAhead(rdp,'/'))
			c = '/';
		if (!matchTerminal('*') && !matchTerminal('/')) return NULL;
		Tree f = F(rdp);
		if (f == NULL) return NULL;
		Tree ft2 = FT(rdp);
		if (ft2 == NULL) return NULL;
		Tree_addChild(ft, Tree_new(c));
		Tree_addChild(ft, f);
		Tree_addChild(ft, ft2);
	}
	return ft;
}

Tree F(RDP rdp) {
	Tree f = Tree_new('F');
	if (!lookAhead(rdp,'(')) {
		Tree n = N(rdp);
		if (n == NULL) return NULL;
		Tree_addChild(f, n);
	} else {
		if (!matchTerminal('(')) return NULL;
		Tree e = E(rdp);
		if (e == NULL) return NULL;
		if (!matchTerminal(')')) return NULL;
		Tree_addChild(f, Tree_new('('));
		Tree_addChild(f, e);
		Tree_addChild(f, Tree_new(')'));
	}
	return f;
}

Tree N(RDP rdp) {
	Tree n = Tree_new('N');
	Tree d = D(rdp);
	if (d == NULL)
		return NULL;
	Tree nt = NT(rdp);
	if (nt == NULL)
		return NULL;	
	Tree_addChild(n, d);
	Tree_addChild(n, nt);
	return n;
}

Tree NT(RDP rdp) {
	Tree nt = Tree_new('n');
	bool boolean = false;
	for (int i=0; i<9; i++) {
		if (lookAhead(rdp,i)) {
			boolean = true;
			break;
		}
	}
	if (boolean) {
		Tree n = N(rdp);
		if (n == NULL) return NULL;
		Tree_addChild(nt, n);
	} else {
		Tree_addChild(nt, Tree_new('e'));
	}
	return nt;
}

Tree D(RDP rdp) {
	Tree d = Tree_new('D');
	bool boolean = false;
	int i=0;
	for (; i<9; i++) {
		if (lookAhead(rdp,i)) {
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