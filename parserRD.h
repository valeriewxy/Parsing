#include "parseTree.h"

typedef struct *RDParser
{
	Tree tree;
	int current;
	int length;
}RDP;

extern RDP RDP_new(char* input, int length);
extern void RDP_free(RDP rdp);
extern bool lookAhead(char c);
extern bool matchTerminal(char x);
extern Tree E();
extern Tree TT();
extern Tree T();
extern Tree FT();
extern Tree F();
extern Tree N();
extern Tree NT();
extern Tree D();

#endif