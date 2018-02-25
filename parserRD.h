#include "parseTree.h"

typedef struct *RDParser
{
	Tree tree;
	int current;
}RDP;

extern RDP RDP_new(char* input, int length);
extern void RDP_free(RDP rdp);
extern char lookAhead(RDP rdp, char c);
extern bool matchTerminal(RDP rdp, char x);
extern TREE E(RDP rdp);
extern TREE TT(RDP rdp);
extern TREE T(RDP rdp);
extern TREE FT(RDP rdp);
extern TREE F(RDP rdp);
extern TREE N(RDP rdp);
extern TREE NT(RDP rdp);
extern TREE D(RDP rdp);

#endif