#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parseTree.h"
#include "parserRD.h"
#include "parserTD.h"
#include "calculator.h"

int main(int argc, char const *argv[])
{
	printf("%s\n", ">>> Testing Part 1 & Part 3 >>>");
	printf("%s\n", "------ Recursive-descent Parser with Calculator------");
	bool cont = true;
	printf("%s", "Please enter a line of expression: ");
	char *input;
	RDP rdp;
	while(cont) {
		input = (char*)malloc(128);
		scanf("%s", input);
		if (*input == 'q') {
			cont = false;
			break;
		}
		rdp = RDP_new(input, 128);
		if (rdp->tree == NULL) {
			printf("%s\n", "INVALID INPUT");
		} else {
			Tree_print(rdp->tree);
			printf("%s\n", "after print");
			printf("Result: %f\n", evaluation(rdp->tree));
		}
		printf("%s", "Please enter another expression to test, or enter 'q' to quit: ");
	}
	printf("%s\n", "Program Finished");
	free(input);
	// RDP_free(rdp); //segmentation fault

	printf("%s\n", ">>> Testing Part 2 >>>");
	printf("%s\n", "------ Table-driven Parser ------");
	bool cont2 = true;
	printf("%s", "Please enter a line of expression: ");
	char *input2;
	TDP tdp;
	while(cont2) {
		input2 = (char*)malloc(128);
		scanf("%s", input);
		if (*input2 == 'q') {
			cont2 = false;
			break;
		}
		tdp = TDP_new(input, 128);
		if (tdp->tree == NULL) {
			printf("%s\n", "INVALID INPUT");
		} else {
			Tree_print(tdp->tree);
			// printf("Result: %f\n", evaluation(rdp->tree));
		}
		printf("%s", "Please enter another expression to test, or enter 'q' to quit: ");
	}
	printf("%s\n", "Program Finished");
	free(input2);
	// RDP_free(tdp); //segmentation fault
}