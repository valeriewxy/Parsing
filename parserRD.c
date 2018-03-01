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
	rdp->length = length;
	rdp->tree = start(rdp);
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

bool matchTerminal(RDP rdp, char c) {
	if (*nextInputChar == c) {
		nextInputChar++;
		rdp->current++;
		return true;
	}
	return false;
}

Tree start(RDP rdp) {
	Tree s = E(rdp);
	if (!lookAhead(rdp, '\0')) return NULL;
	return s;
}

Tree E(RDP rdp) {
	printf("%s\n", "E");
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
	printf("%s\n", "TT");
	Tree tt = Tree_new('t');
	char c;
	if (!(lookAhead(rdp,'+') || lookAhead(rdp,'-'))) {
		Tree_addChild(tt, Tree_new('e'));
	} else {
		if (lookAhead(rdp,'+')) 
			c = '+';
		else if (lookAhead(rdp,'-'))
			c = '-';
		if (!matchTerminal(rdp, '+') && !matchTerminal(rdp, '-')) 
			return NULL;
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
	printf("%s\n", "T");
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
	printf("%s\n", "FT");
	Tree ft = Tree_new('f');
	char c;
	if (!(lookAhead(rdp,'*') || lookAhead(rdp,'/'))) {
		Tree_addChild(ft, Tree_new('e'));
	} else {
		printf("%s\n", "$$$$");
		if (lookAhead(rdp,'*')) 
			c = '*';
		else if (lookAhead(rdp,'/'))
			c = '/';
		if (!matchTerminal(rdp, '*') && !matchTerminal(rdp, '/')) 
			return NULL;
		Tree f = F(rdp);
		if (f == NULL) 
			return NULL;
		Tree ft2 = FT(rdp);
		if (ft2 == NULL) 
			return NULL;
		Tree_addChild(ft, Tree_new(c));
		printf("%c%s\n", c, "$$$$");
		Tree_addChild(ft, f);
		Tree_addChild(ft, ft2);
	}
	return ft;
}

Tree F(RDP rdp) {
	printf("%s\n", "F");
	Tree f = Tree_new('F');
	if (!lookAhead(rdp,'(')) {
		Tree n = N(rdp);
		if (n == NULL) 
			return NULL;
		Tree_addChild(f, n);
	} else {
		if (!matchTerminal(rdp, '(')) 
			return NULL;
		Tree e = E(rdp);
		if (e == NULL) 
			return NULL;
		if (!matchTerminal(rdp, ')')) 
			return NULL;
		Tree_addChild(f, Tree_new('('));
		Tree_addChild(f, e);
		Tree_addChild(f, Tree_new(')'));
	}
	return f;
}

Tree N(RDP rdp) {
	printf("%s\n", "N");
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
	printf("%s\n", "NT");
	Tree nt = Tree_new('n');
	// bool boolean = false;
	// for (int i=0; i<10; i++) {
	// 	if (lookAhead(rdp,i)) {
	// 		boolean = true;
	// 		break;
	// 	}
	// }
	if (*nextInputChar >= '0' && *nextInputChar <='9') {
		Tree n = N(rdp);
		if (n == NULL) 
			return NULL;
		Tree_addChild(nt, n);
	} else {
		Tree_addChild(nt, Tree_new('e'));
	}
	return nt;
}

Tree D(RDP rdp) {
	printf("%s\n", "D");
	Tree d = Tree_new('D');
	// int i=0;
	// for (; i<10; i++) {
	// 	char c = i;
	// 	if (lookAhead(rdp,c)) {
	// 		matchTerminal(rdp, c);
	// 		Tree_addChild(d, Tree_new(c));
	// 		return d;
	// 	}
	// }

	switch(*nextInputChar) {
		case '0':
			matchTerminal(rdp, '0');
			Tree_addChild(d, Tree_new('0'));
			break;
		case '1':
			matchTerminal(rdp, '1');
			Tree_addChild(d, Tree_new('1'));
			break;
		case '2':
			matchTerminal(rdp, '2');
			Tree_addChild(d, Tree_new('2'));
			break;
		case '3':
			matchTerminal(rdp, '3');
			Tree_addChild(d, Tree_new('3'));
			break;
		case '4':
			matchTerminal(rdp, '4');
			Tree_addChild(d, Tree_new('4'));
			break;
		case '5':
			matchTerminal(rdp, '5');
			Tree_addChild(d, Tree_new('5'));
			break;
		case '6':
			matchTerminal(rdp, '6');
			Tree_addChild(d, Tree_new('6'));
			break;
		case '7':
			matchTerminal(rdp, '7');
			Tree_addChild(d, Tree_new('7'));
			break;
		case '8':
			matchTerminal(rdp, '8');
			Tree_addChild(d, Tree_new('8'));
			break;
		case '9':
			matchTerminal(rdp, '9');
			Tree_addChild(d, Tree_new('9'));
			break;
		default:
			return NULL;
	}
	return d;
}