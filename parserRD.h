#ifndef _parserrd_h
#define _parserrd_h

#include <stdbool.h>
#include "parseTree.h"

typedef struct RDParser* RDP;

struct RDParser
{
	Tree tree;
	int current;
	int length;
};

extern RDP RDP_new(char* input, int length);
extern void RDP_free(RDP rdp);
extern bool lookAhead(RDP rdp, char c);
extern bool matchTerminal(char x);
extern Tree E(RDP rdp);
extern Tree TT(RDP rdp);
extern Tree T(RDP rdp);
extern Tree FT(RDP rdp);
extern Tree F(RDP rdp);
extern Tree N(RDP rdp);
extern Tree NT(RDP rdp);
extern Tree D(RDP rdp);

#endif