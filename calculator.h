#ifndef _calculator_h
#define _calculator_h

#include <stdbool.h>

extern bool isOperand(char c);
extern bool isOperator(char c);
extern double combine (double a, double b);
extern double evaluation_tree(Tree tree);
extern double evaluation(Tree tree);

#endif