#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

int getop(char []);
void push(double);
double pop(void);
void show(void);
double mathfunc(char []);

/* reverse polish Calculator */
int
main(int argc, char *argv[]) {
	int type, c = 0;
	double op2, op1, v;
	char s[MAXOP];
	double variables[26];

	while ((type = getop(s)) != EOF) {
		// show();
		switch(type) {
			case NUMBER:
				push(atof(s));
				// show();
				break;
			case NAME:
				push(mathfunc(s));
				break;
			case '=':
				pop();
				if (c >= 'A' && c <= 'Z')
					variables[c - 'A'] = pop();
				else
					printf("Error: No variable name\n");
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				op1 = pop();
				// printf("op1 = %g\top2 = %g\n", op1, op2);
				push(op1 - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop()/op2);
				else
					printf("Error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;	
			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(variables[type - 'A']);
				else if (type == 'v')
					push(v);
				else 
					printf("Error: Unknown Command %s\n", s);
		}
		c = type;
	}
	return 0;
}
