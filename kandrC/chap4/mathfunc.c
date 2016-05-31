#include <math.h>
#include <string.h>
#include "calc.h"

double
mathfunc(char s[]) {
	// printf("mathfunc: %s\n", s);
	if (strcmp(s, "sin") == 0)
		return sin(pop());
	else if (strcmp(s, "cos") == 0)
		return cos(pop());
	else if (strcmp(s, "exp") == 0)
		return exp(pop());
	else if (strcmp(s, "pow") == 0) {
		double op1 = pop();
		return pow(pop(), op1);
	}
	else
		return -1.0;
}