#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int bool;

// Single line comment
/* Single line comment with multiline quotes */
/*
Multiline Comment
*/

int
main() {
	int c;
	bool checkForComment = FALSE, isMultilineComment = FALSE, checkForCloseMultiline = FALSE;
	while ((c = getchar()) != EOF) {
		if (!isMultilineComment) {
			if (c == '/')
				checkForComment = TRUE;
			else if (c == '*' && checkForComment)
				isMultilineComment = TRUE;
			else if (checkForComment) {
				putchar('/');
				putchar(c);
				checkForComment = FALSE;
			}
			else
				putchar(c);
		}
		else {
			if (c == '*')
				checkForCloseMultiline = TRUE;
			else if(c == '/' && checkForCloseMultiline)
				isMultilineComment = checkForComment = checkForCloseMultiline = FALSE;

		}
	}
	return 0;
}