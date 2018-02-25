#include <stdlib.h>
#include <stdio.h>

char *nextInputChar;

RDP RDP_new(char* input, int length) {
	RDP rdp = (RDP)malloc(sizeof(struct RDParser));
	nextInputChar = input;
	rdp->current = 0;
	rdp->tree = E(rdp);
	return rdp;
}

void RDP_free(RDP rdp) {
	if(rdp->tree != NULL) {
		Tree_free(rdp->tree);
	}
	free(rdp);
}

char lookAhead(RDP rdp, char c) {
	if (*nextInputChar == c) {
		nextInputChar++:
		return true;
	} else {
		return false;
	}
}

bool matchTerminal(RDP rdp, char x) {

}

TREE E(RDP rdp) {

}

TREE TT(RDP rdp) {

}

TREE T(RDP rdp) {

}

TREE FT(RDP rdp) {

}

TREE F(RDP rdp) {

}

TREE N(RDP rdp) {

}

TREE NT(RDP rdp) {

}

TREE D(RDP rdp) {

}