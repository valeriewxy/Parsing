#include "parseTree.h"

typedef struct *RDParser
{
	Tree tree;
}RDP;

extern RDP RDP_new(char* input, int length);
extern char lookAhead(RDP rdp);
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