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
extern int numSynCat(char c);
extern int numInput(char c);
extern TDP TDP_new(char* input, int length);
extern void TDP_buildStack(TDP tdp);
extern void TDP_addProduction(TDP tdp, Tree tree);
extern void TDP_buildTree(TDP tdp, int prod);
extern void TDP_free(TDP rdp);
extern bool TDP_lookAhead(TDP rdp, char c);
extern bool TDP_matchTerminal(TDP rdp, char x);


#endif
