#ifndef _parsertd_h
#define _parsertd_h

#include <stdbool.h>
#include "parseTree.h"

typedef struct TDParser* TDP;

struct TDParser {
	// int parsingTable**;
	Tree tree;
	int current;
	int length;	
};

extern void push(Tree tree);
extern Tree peek();
extern Tree pop();
extern bool isEmpty();

extern TDP TDP_new(char* input, int length);
extern void TDP_free(TDP rdp);
extern bool TD_lookAhead(TDP rdp, char c);
extern bool TD_matchTerminal(TDP rdp, char x);


#endif
