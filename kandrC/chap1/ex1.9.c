#include <stdio.h>

typedef unsigned int bool;

int
main() {
	int c;
	bool flag = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' && flag)
			continue;
		else if (c == ' ') {
			putchar(c);
			flag = 1;
		}
		else if (c == '\t')
			putchar(' ');
		else {
			putchar(c);
			flag = 0;
		}
	}
	printf("hello, wor\bl\bd\n");

}

/*
In C and in C++ single quotes identify a single character, while double quotes create a string literal.
'a' is a single a character literal, while "a" is a string literal containing an 'a' and a null terminator (that is a 2 char array).

Note that in C, the type of a character literal is int, and not char, that is sizeof 
'a' is 4 in an architecture where ints are 32bit (and CHAR_BIT is 8), while sizeof(char) is 1 everywhere.
*/