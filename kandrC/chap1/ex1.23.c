#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int bool;

int
main() {
	int c;
	bool isSingleLineComment = FALSE, isMultilineComment = FALSE, checkForComment = FALSE, checkForCloseMultiline = FALSE;
	while ((c = getchar()) != EOF) {
		if (!(isMultilineComment || isSingleLineComment)) {
			if (c == '/' && !checkForComment)
				checkForComment = TRUE;
			else if(c == '/' && checkForComment)
				isSingleLineComment = TRUE;
			else if(c == '*' && checkForComment)
				isMultilineComment = TRUE;
			else if(checkForComment) {
				putchar('/');
				putchar(c);
				checkForComment = FALSE;
			}
			else
				putchar(c);
		}
		else if(isSingleLineComment) {
			if (c == '\n')
				isSingleLineComment = checkForComment = FALSE;
		}
		else if(isMultilineComment) {
			if (c == '*')
				checkForCloseMultiline = TRUE;
			else if(c == '/' && checkForCloseMultiline)
				isMultilineComment = checkForComment = checkForCloseMultiline = FALSE;
		}
	}
	return 0;
}