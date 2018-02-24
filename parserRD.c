#include <stdlib.h>
#include <stdio.h>

RDP RDP_new(char* input, int length) {
	
}

void RDP_free(RDP rdp) {
	if(rdp->tree != NULL) {
		Tree_free(rdp->tree);
	}
	free(rdp);
}

char lookAhead(RDP rdp) {

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