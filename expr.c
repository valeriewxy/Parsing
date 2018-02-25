#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parseTree.h"
#include "parserRD.h"
#include "parserTD.h"

int main(int argc, char const *argv[])
{
	printf("%s\n", "------ Recursive-descent Parser ------");
	bool cont = true;
	printf("%s", "Please enter a line of expression: ");
	char *input;
	RDP rdp;
	while(cont) {
		input = (char*)malloc(sizeof(char)*10);
		// char eof;
		scanf("%s", input);
		if (*input == 'q') {
			cont = false;
			break;
		}
		rdp = RDP_new(input, sizeof(char)*10);
		if (rdp->tree == NULL) {
			printf("%s\n", "INVALID INPUT");
		} else {
			Tree_print(rdp->tree);
		}
		printf("%s", "Please enter another expression to test, or enter 'q' to quit: ");
	}
	printf("%s\n", "Program Finished")
	free(input);
	RDP_free(rdp);
}